//////////////////////////////////////////////////////////////////////////////
// Programa: TAbm.prg
// Fecha Creación: 08/21/2023
// Hora: 08:09
// Proyecto en xMate: tree_2024
// Lista de funciones:
// Ultima actualizacion :>: 08/28/2023 16:51
// Historial:
//            >>:
//            08/21/23-08/28/23
//////////////////////////////////////////////////////////////////////////////

#include "fivewin.ch"
#include "debug.ch"

CLASS TAbm
   METHOD extraerItems( oItem, aRamas )
   METHOD insertarRama( oTree, oRama, vGets )
   METHOD buscaPos( a, nVal )
END CLASS

//------------------------------------------------------------------------------

METHOD extraerItems( aItems, aRamas ) CLASS TAbm
   LOCAL oItem, oItemEncontrado
   LOCAL n := 1

   WHILE ( n <= Len( aItems ) .and. oItemEncontrado == NIL )
      oItem := aItems[ n ]
      AAdd( aRamas, oItem:cprompt )
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

METHOD insertarRama( oTree, oRama, vGets ) CLASS TAbm

   LOCAL cPrompt := AllTrim( vGets[ 1 ] ) + " (" + AllTrim( vGets[ 2 ] ) + ")"
   LOCAL oItem
   LOCAL aRamas := { }
   LOCAL nHitem := 0, a

   IF  ( Len( oTree:aItems ) == 0 )

      oItem := oTree:ADD( cPrompt )
      oItem:cargo := { ;
                       "fecha" => vGets[ 1 ], ;
                       "nombre" => vGets[ 2 ], ;
                       "apellido" => vGets[ 3 ], ;
                       "hitem_parent" => IIf( oItem:oParent != NIL, oItem:oParent:hitem, 0 ) ;
                     }

   ELSE
      oRama := IIf( oRama == NIL, oTree, oRama )

      nHitem := ::buscaPos( oRama:aItems, CToD( vGets[ 1 ] ), oTree )

      IF ( nHitem > 0 )
         ? "mayor a 0"

         IF nHitem == 1
            oItem := oTree:scan( { | o | o:hitem == oRama:aItems[ 1 ]:hitem } )
            oItem := oTree:insertAfter( oItem, cPrompt )
            oItem:cargo := { ;
                             "fecha" => vGets[ 1 ], ;
                             "nombre" => vGets[ 2 ], ;
                             "apellido" => vGets[ 3 ], ;
                             "hitem_parent" => IIf( oItem:oParent != NIL, oItem:oParent:hitem, 0 ) ;
                           }

            oTree:Select( oItem )

         ELSE
            oItem := oTree:scan( { | o | o:hitem == nHitem } )
            oItem := oTree:insertAfter( oItem, cPrompt )
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




