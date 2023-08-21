//////////////////////////////////////////////////////////////////////////////
// Programa: arbol_2024.prg
// Fecha Creación: 08/20/2023
// Hora: 23:47
// Proyecto en xMate: tree_2024
// Lista de funciones:
// Ultima actualizacion :>: 08/21/2023 21:53
// Historial:
//            >>:
//            08/20/23-08/21/23
//////////////////////////////////////////////////////////////////////////////

#include "fivewin.ch"      // utilizo la version 21.02
#include "debug.ch"        // lo utilizo para poder ver en el DebugView algudos datos

CLASS TApp

   METHOD pantalla()
   METHOD inicializar( oGets, vGets )
   METHOD insertarRama( oTree, oRama, vGets )
   METHOD seleccionarRama( oTree, nRow, nCol, nKeyFlags )
   METHOD mostrarDatosRama( oRama, oGets, vGets )
   METHOD menuPopup( oTree, oRama, oGets, vGets, nRow, nCol )

ENDCLASS

//------------------------------------------------------------------------------

METHOD insertarRama( oTree, oRama, vGets ) CLASS Tapp
   LOCAL oABM := TABM():new()
   LOCAL oItem

   oItem := oABM:insertarRama( IIf( oRama == NIL, oTree, oRama ), vGets )

   oTree:refresh()
   oTree:expandAll()

   RETURN ( oItem )

//------------------------------------------------------------------------------

METHOD mostrarDatosRama( oRama, oGets, vGets ) CLASS TApp

   vGets[ 1 ] := oRama:cargo[ "fecha" ]
   vGets[ 2 ] := oRama:cargo[ "nombre" ]
   vGets[ 3 ] := oRama:cargo[ "apellido" ]

   AEval( oGets, { | o | o:refresh() } )

   RETURN ( NIL )

//------------------------------------------------------------------------------

METHOD menuPopup( oTree, oRama, oGets, vGets, nRow, nCol ) CLASS TApp

   Menu oMenu POPUP

   IF ( Len( oTree:aitems ) != 0 )
      IF ( oRama != NIL )

         MenuItem "Mostrar datos" ACTION ::mostrarDatosRama( oRama, oGets, vGets )
      ENDIF
   ENDIF

   EndMenu

   ACTIVATE POPUP oMenu At nRow, nCol OF oTree

   RETURN ( NIL )

//------------------------------------------------------------------------------

METHOD seleccionarRama( oTree, nRow, nCol, nKeyFlags ) CLASS TApp
   LOCAL oRama := oTree:hitTest( nRow, nCol )

   IF oRama != NIL
      VIEW oRama:cprompt
   ENDIF

   RETURN ( oRama )

//------------------------------------------------------------------------------

METHOD inicializar( oGets, vGets ) CLASS TApp

   /*
   en el caso de la fecha  la inicializo como space y no como date para
   que  permita omitr: dia, mes,  anio.
   */

   vGets[ 1 ] := Space( 10 )     // fecha
   vGets[ 2 ] := Space( 10 )     // nombre
   vGets[ 3 ] := Space( 10 )     // apellido

   AEval( oGets, { | o | o:refresh() } )

   RETURN( NIL )

//------------------------------------------------------------------------------

METHOD pantalla() CLASS TApp
   LOCAL oDlg
   LOCAL oRama := NIL
   LOCAL this  := Self

   LOCAL oGets := Array( 3 )
   LOCAL vGets := Array( 3 )
   LOCAL oBtns := Array( 3 )
   LOCAL oTree

   DEFINE DIALOG oDlg resource "DLG_ARBOL"

   oTree = TTreeView():REDEFINE( 100, oDlg, CLR_BLACK, CLR_WHITE, .F., "" )

   REDEFINE GET oGets[ 1 ] VAR vGets[ 1 ]  PICTURE '99/99/9999' ID 101 OF oDlg    // fecha
   REDEFINE GET oGets[ 2 ] VAR vGets[ 2 ]  PICTURE '@!'         ID 102 OF oDlg    // nombre
   REDEFINE GET oGets[ 3 ] VAR vGets[ 3 ]  PICTURE '@!'         ID 103 OF oDlg    // apellido

   REDEFINE BUTTON oBtns[ 1 ] ID 200 OF oDlg   // agregar
   REDEFINE BUTTON oBtns[ 2 ] ID 201 OF oDlg   // guardar el arbol
   REDEFINE BUTTON oBtns[ 3 ] ID 202 OF oDlg   // cargar el arbol guardado

   //----------( )----------

   oTree:blclicked := { | nRow, nCol, nKeyFlags | oRama:= ::seleccionarRama( oTree, nRow, nCol, nKeyFlags ) }

   //----------( )----------

   oBtns[ 1 ]:bAction := { || oRama := ::insertarRama( oTree, oRama, vGets ), ::inicializar( oGets, vGets ), oGets[ 1 ]:SETfocus() }

   //----------( )----------

   oTree:SetItemHeight( 22 )

   ACTIVATE DIALOG oDlg CENTERED ON INIT( this:inicializar( oGets, vGets ) )

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




