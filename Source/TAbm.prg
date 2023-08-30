//////////////////////////////////////////////////////////////////////////////
// Programa: TAbm.prg
// Fecha Creación: 08/21/2023
// Hora: 08:09
// Proyecto en xMate: tree_2024
// Lista de funciones:
// Ultima actualizacion :>: 08/30/2023 12:08
// Historial:
//            >>:
//            08/21/23-08/30/23
//////////////////////////////////////////////////////////////////////////////

#include "fivewin.ch"
#include "debug.ch"

CLASS TAbm
   METHOD extraerItems( oItem, aRamas )
   METHOD insertarRama( oTree, oRama, vGets )
   METHOD buscaPos( a, nVal )
   METHOD swap( oItemArriba, oItemAPasar, oTree, vGets, nHitemOriginal )
END CLASS

//------------------------------------------------------------------------------

METHOD extraerItems( aItems, aRamas ) CLASS TAbm
   LOCAL oItem, oItemEncontrado
   LOCAL n := 1

   WHILE ( n <= Len( aItems ) .and. oItemEncontrado == NIL )
      oItem := aItems[ n ]
      AAdd( aRamas, oItem )
      IF ( Len( oItem:aItems ) > 0 )
         oItemEncontrado := ::extraerItems( oItem:aItems, aRamas )
      ENDIF
      n ++
   END

   RETURN ( oItemEncontrado )

//------------------------------------------------------------------------------

METHOD buscaPos( a, nVal ) CLASS TAbm

   LOCAL nResult := - 1
   LOCAL cMenor  := ""

   IF Len( a ) > 0
      AScan( ASort( AClone( a ) ), ;
             { | n, nPos | ;
               IF( nVal < CToD( n:cargo[ "fecha" ] ), ;
                   ( cMenor := n:cargo[ "fecha" ], nResult := AScan( a, { | o | o:cargo[ "fecha" ] == cMenor } ) ) , ), ;
               CToD( n:cargo[ "fecha" ] ) > nVal } )
   ENDIF

   IF nResult == 1
   ELSEIF nResult > - 1
      nResult := a[ nResult - 1 ]:hitem
   ENDIF

   RETURN ( nResult )
//------------------------------------------------------------------------------


METHOD swap( oItemArriba, oItemAPasar, oTree, vGets, nHitemOriginal ) CLASS TAbm
   LOCAL oItem, oElemento
   LOCAL nHitemAnterior := 0
   LOCAL aItemsExtraidos := { }

   ::extraerItems( oItemArriba:aItems, aItemsExtraidos )

   oItem := oTree:scan( { | o | o:hitem == oItemAPasar:hitem } )
   oItem := oTree:insertAfter( oItem, oItemArriba:cprompt + " cambio primero" )
   oItem:cargo := { ;
                    "fecha"         => oItemArriba:cargo[ "fecha" ], ;
                    "nombre"        => oItemArriba:cargo[ "nombre" ], ;
                    "apellido"      => oItemArriba:cargo[ "apellido" ], ;
                    "hitem_parent"  => IIf( oItem:oParent != NIL, oItem:oParent:hitem, 0 ) ;
                  }

   AScan( aItemsExtraidos, ;
          { | a, i | ;
            IIf( a:cargo[ "hitem_parent" ] == nHitemOriginal, ;
                 a:cargo[ "hitem_parent" ] := oItem:hitem, ;
                 a:cargo[ "hitem_parent" ] ) } )


   FOR EACH oElemento IN aItemsExtraidos

      nHitemAnterior := oElemento:hitem

      oItem := oTree:scan( { | o | o:hitem == oElemento:cargo[ "hitem_parent" ] } )
      oItem := oItem:ADD( oElemento:cPrompt + " cambio en for" )
      oItem:cargo := { ;
                       "fecha"         => oElemento:cargo[ "fecha" ], ;
                       "nombre"        => oElemento:cargo[ "nombre" ], ;
                       "apellido"      => oElemento:cargo[ "apellido" ], ;
                       "hitem_parent"  => IIf( oItem:oParent != NIL, oItem:oParent:hitem, 0 ) ;
                     }

      AScan( aItemsExtraidos, ;
             { | a, i | ;
               IIf( a:cargo[ "hitem_parent" ] == nHitemAnterior, ;
                    a:cargo[ "hitem_parent" ] := oItem:hitem, ;
                    a:cargo[ "hitem_parent" ] ) } )

   NEXT

   RETURN ( NIL )

//------------------------------------------------------------------------------

METHOD insertarRama( oTree, oRama, vGets ) CLASS TAbm

   LOCAL cPrompt := AllTrim( vGets[ 1 ] ) + " (" + AllTrim( vGets[ 2 ] ) + ")"
   LOCAL oItem, oItemArriba
   LOCAL aRamas := { }
   LOCAL nHitem := 0

   VIEWCL

   IF  ( Len( oTree:aItems ) == 0 )

      oItem := oTree:ADD( cPrompt + " len == 0" )
      oItem:cargo := { ;
                       "fecha" => vGets[ 1 ], ;
                       "nombre" => vGets[ 2 ], ;
                       "apellido" => vGets[ 3 ], ;
                       "hitem_parent" => IIf( oItem:oParent != NIL, oItem:oParent:hitem, 0 ) ;
                     }

   ELSE
      oRama := IIf( oRama == NIL, oTree, oRama )

      FWDBG "no es cero nibien arranca", oRama:aItems, oTree, oRama

      nHitem := ::buscaPos( oRama:aItems, CToD( vGets[ 1 ] ), oTree )

      IF ( nHitem > 0 )
         IF nHitem == 1
            oItem := oTree:scan( { | o | o:hitem == oRama:aItems[ 1 ]:hitem } )
            oItemArriba := oItem
            oItem := oTree:insertAfter( oItem, cPrompt + " nHitem == 1" )
            oItem:cargo := { ;
                             "fecha" => vGets[ 1 ], ;
                             "nombre" => vGets[ 2 ], ;
                             "apellido" => vGets[ 3 ], ;
                             "hitem_parent" => IIf( oItem:oParent != NIL, oItem:oParent:hitem, 0 ) ;
                           }

            ::swap( oItemArriba, oItem, oTree, vGets, oRama:aItems[ 1 ]:hitem )

            oItemArriba:END()
         ELSE
            oItem := oTree:scan( { | o | o:hitem == nHitem } )
            oItem := oTree:insertAfter( oItem, cPrompt + " nHitem > 1" )
            oItem:cargo := { ;
                             "fecha" => vGets[ 1 ], ;
                             "nombre" => vGets[ 2 ], ;
                             "apellido" => vGets[ 3 ], ;
                             "hitem_parent" => IIf( oItem:oParent != NIL, oItem:oParent:hitem, 0 ) ;
                           }
         ENDIF

      ELSE
         oItem := oRama:ADD( cPrompt )
         oItem:cargo := { ;
                          "fecha" => vGets[ 1 ], ;
                          "nombre" => vGets[ 2 ], ;
                          "apellido" => vGets[ 3 ], ;
                          "hitem_parent" => IIf( oItem:oParent != NIL, oItem:oParent:hitem, 0 ) ;
                        }
      ENDIF

   ENDIF


   RETURN ( oItem )

//------------------------------------------------------------------------------




