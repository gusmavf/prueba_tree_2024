//////////////////////////////////////////////////////////////////////////////
// Programa: arbol_2024.prg
// Fecha Creación: 08/20/2023
// Hora: 23:47
// Proyecto en xMate: tree_2024
// Lista de funciones:
// Ultima actualizacion :>: 08/21/2023 08:19
// Historial:
//            >>:
//            08/20/23-08/21/23
//////////////////////////////////////////////////////////////////////////////

#include "fivewin.ch"      // utilizo la version 21.02
#include "debug.ch"        // lo utilizo para poder ver en el DebugView algudos datos

CLASS TApp

   METHOD pantalla()

ENDCLASS

//------------------------------------------------------------------------------

METHOD pantalla() CLASS TApp
   LOCAL oDlg
   LOCAL oGets := Array( 3 )
   LOCAL vGets := Array( 3 )
   LOCAL oBtns := Array( 3 )
   LOCAL oTree

   DEFINE DIALOG oDlg resource "DLG_ARBOL"

   oTree = TTreeView():REDEFINE( 100, oDlg, CLR_BLACK, CLR_WHITE, .F., "" )

   REDEFINE GET oGets[ 1 ] VAR vGets[ 1 ]  ID 101 OF oDlg    // fecha
   REDEFINE GET oGets[ 2 ] VAR vGets[ 2 ]  ID 102 OF oDlg    // nombre
   REDEFINE GET oGets[ 3 ] VAR vGets[ 3 ]  ID 103 OF oDlg    // apellido

   REDEFINE BUTTON oBtns[ 1 ] ID 200 OF oDlg   // agregar
   REDEFINE BUTTON oBtns[ 2 ] ID 201 OF oDlg   // guardar el arbol
   REDEFINE BUTTON oBtns[ 3 ] ID 202 OF oDlg   // cargar el arbol guardado

   ACTIVATE DIALOG oDlg CENTERED

   RETURN ( NIL )

//------------------------------------------------------------------------------

FUNCTION main()
   LOCAL oApp

   SET Date FORMAT "dd/mm/yyyy"
   SET Time FORMAT "hh:mm:ss"

   SET EPOCH TO 1950

   SET( _SET_INSERT, .T. )

   TGet():lClrFocus      := ( .T. )
   TMultiGet():lClrFocus := .T.

   TGet():nClrFocus      := nRGB( 245, 254, 194 )
   TMultiGet():nClrFocus := nRGB( 255, 255, 198 )

   oApp := TApp():new()
   oApp:pantalla()

   RETURN ( NIL )

//------------------------------------------------------------------------------




