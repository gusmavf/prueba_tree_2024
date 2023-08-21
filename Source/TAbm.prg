//////////////////////////////////////////////////////////////////////////////
// Programa: TAbm.prg
// Fecha Creación: 08/21/2023
// Hora: 08:09
// Proyecto en xMate: tree_2024
// Lista de funciones:
// Ultima actualizacion :>: 08/21/2023 21:18
// Historial:
//            >>:
//            08/21/23
//////////////////////////////////////////////////////////////////////////////

#include "fivewin.ch"
#include "debug.ch"

CLASS TAbm
   DATA aItems
   METHOD extraerItems( oItem )
   METHOD insertarRama( oTree, vGets )
END CLASS

//------------------------------------------------------------------------------

METHOD extraerItems( oItem ) CLASS TAbm
   LOCAL oElemento

   FOR EACH oElemento IN oItem:aitems
      VIEW oElemento:cprompt
   NEXT

   RETURN ( NIL )

//------------------------------------------------------------------------------

METHOD insertarRama( oTree, vGets ) CLASS TAbm

   LOCAL cPrompt := AllTrim( vGets[ 1 ] ) + " (" + AllTrim( vGets[ 2 ] ) + ")"
   LOCAL oItem

   VIEWCL
   ::aItems := { }
   ::extraerItems( oTree )

   oItem := oTree:ADD( cPrompt )
   oItem:cargo := { ;
                    "fecha" => vGets[ 1 ], ;
                    "nombre" => vGets[ 2 ], ;
                    "apellido" => vGets[ 3 ] ;
                  }

   RETURN ( oItem )

//------------------------------------------------------------------------------




