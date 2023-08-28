// Win32 TreeView support

#include "FiveWin.ch"
#include "Constant.ch"

#define TV_FIRST                4352    //0x1100
#define TVM_GETEDITCONTROL      ( TV_FIRST + 15 )
#define TVM_EDITLABELA          ( TV_FIRST + 14 )
#define TVM_EDITLABELW          ( TV_FIRST + 65 )
#ifdef UNICODE
#define TVN_BEGINLABELEDITW     ( TVN_FIRST - 59 )
#define TVN_ENDLABELEDITW       ( TVN_FIRST - 60 )
#define TVM_EDITLABEL           TVM_EDITLABELW
#define TVN_BEGINLABELEDIT      TVN_BEGINLABELEDITW
#define TVN_ENDLABELEDIT        TVN_ENDLABELEDITW
#else
#define TVN_BEGINLABELEDITA     ( TVN_FIRST - 10 )
#define TVN_ENDLABELEDITA       ( TVN_FIRST - 11 )
#define TVM_EDITLABEL           TVM_EDITLABELA
#define TVN_BEGINLABELEDIT      TVN_BEGINLABELEDITA
#define TVN_ENDLABELEDIT        TVN_ENDLABELEDITA
#endif

#define TVN_FIRST               -400
#define TVN_ITEMEXPANDED        (TVN_FIRST-6)

#define COLOR_WINDOW            5
#define COLOR_WINDOWTEXT        8
#define COLOR_BTNFACE           15
#define COLOR_BTNSHADOW         16
#define COLOR_BTNHIGHLIGHT      20

#define FD_BORDER               8
#define FD_HEIGHT               22

#define DT_CENTER               1
#define DT_VCENTER              4

#define WINDING                 2
#define SC_KEYMENU              61696 //  0xF100

#define TVS_HASBUTTONS          1
#define TVS_HASLINES            2
#define TVS_LINESATROOT         4
#define TVS_SHOWSELALWAYS       32 //  0x0020
#define TVS_DISABLEDRAGDROP     16 //  0x0010
#define TVS_CHECKBOXES          256 //  0x0100
#define TVS_EDITLABELS          8

#define CTRL_NAME "SysTreeView32"

//----------------------------------------------------------------------------//

CLASS TTreeView FROM TControl

   DATA   aItems
   DATA   oImageList
   DATA   bChanged
   DATA   bExpanded
   DATA   hEdit

   CLASSDATA aProperties ;
      INIT { "aItems", "cTitle", "cVarName", "l3D", "nClrText",;
             "nClrPane", "nAlign", "nTop", "nLeft",;
             "nWidth", "nHeight", "oFont", "Cargo" }

   METHOD New( nTop, nLeft, oWnd, nClrFore,;
               nClrBack, lPixel, lDesign, nWidth, nHeight,;
               cMsg, lCheckBoxes, bChange, lEditable ) CONSTRUCTOR

   METHOD ReDefine( nId, oWnd, nClrFore, nClrBack, lDesign, cMsg ) CONSTRUCTOR

   METHOD Add( cPrompt, nImage, nValue )

   METHOD VScroll( nWParam, nLParam ) VIRTUAL   // standard behavior requested

   METHOD HScroll( nWParam, nLParam ) VIRTUAL

   METHOD CollapseAll( oItem ) INLINE ScanItems( ::aItems, .f. ),;
      oItem := ::GetSelected(), if( oItem <> nil, oItem:MakeVisible(), nil )

   METHOD CollapseBranch( oItem ) INLINE ;
      If( oItem == nil, oItem := ::GetSelected(),), ;
      If( oItem != nil, ( oItem:Collapse(), ScanItems( oItem:aItems, .f. ), oItem:MakeVisible() ),)

   METHOD EditLabel( oItem ) INLINE ;
      If( oItem == nil, oItem := ::GetSelected(),), ;
      If( oItem != nil, oItem:Edit(),)

   METHOD Expand() INLINE AEval( ::aItems, { | oItem | oItem:Expand() } )

   METHOD ExpandAll( oItem ) INLINE ScanItems( ::aItems, .t. ),;
      oItem := ::GetSelected(), if( oItem <> nil, oItem:MakeVisible(), nil )

   METHOD ExpandBranch( oItem ) INLINE ;
      If( oItem == nil, oItem := ::GetSelected(), nil ), ;
      If( oItem != nil, ( oItem:Expand(), ScanItems( oItem:aItems, .t. ), oItem:MakeVisible() ), nil )

   METHOD GetEditControl() INLINE TVGetEditControl( ::hWnd )

   METHOD GetSelected()

   METHOD GetItem( hItem )

   METHOD GetItemPos( oItem )

   METHOD InsertAfter( oItemParent, cPrompt, nImage, nValue )

   METHOD Select( oItem ) INLINE TVSelect( ::hWnd, oItem:hItem )

   METHOD GetSelText() INLINE TVGetSelText( ::hWnd )

   METHOD GoNext()

   METHOD GoPrev()

   METHOD GoTop() INLINE If( Len( ::aItems ) > 0, ::Select( ::aItems[ 1 ] ),)

   METHOD GoBottom()

   METHOD SelChanged() INLINE If( ::bChanged != nil, Eval( ::bChanged, Self ), nil )

   METHOD SetImageList( oImageList )

   METHOD DeleteAll() INLINE ( TVDelAllItems( ::hWnd ), ::aItems := {} )

   METHOD HitTest( nRow, nCol )

   METHOD HandleEvent( nMsg, nWParam, nLParam )

   METHOD Initiate( hDlg ) INLINE ::Super:Initiate( hDlg ), ::SetColor( ::nClrText, ::nClrPane )

   METHOD cToChar() INLINE ::Super:cToChar( CTRL_NAME )

   METHOD SetColor( nClrText, nClrPane ) INLINE ;
      ::Super:SetColor( nClrText, nClrPane ), TVSetColor( ::hWnd, nClrText, nClrPane )

   METHOD SwapUp()

   METHOD SwapDown()

   METHOD Toggle() INLINE AEval( ::aItems, { | oItem | oItem:Toggle() } )

   METHOD ToggleAll( oItem ) INLINE ScanItems( ::aItems, , .t. ), ;
      oItem := ::GetSelected(), If( oItem <> nil, oItem:MakeVisible(), nil )

   METHOD ToggleBranch( oItem ) INLINE ;
      If( oItem == nil, oItem := ::GetSelected(), nil ), ;
      If( oItem != nil, ( oItem:Toggle(), ScanItems( oItem:aItems, , .t. ), oItem:MakeVisible() ), nil )

   METHOD GetCheck( oItem ) INLINE ;
      If( oItem == nil, oItem := ::GetSelected(), nil ), ;
      TVGetCheck( ::hWnd, oItem:hItem )

   METHOD SetCheck( oItem, lOnOff ) INLINE ;
      If( oItem == nil, oItem := ::GetSelected(), nil ), ;
      TVSetCheck( ::hWnd, oItem:hItem, lOnOff )

   METHOD SetItems( aItems )

   METHOD GenMenu( lPopup )

   METHOD LoadFromMenu( oMenu )

   METHOD Notify( nIdCtrl, nPtrNMHDR )

   METHOD Scan( bAction )

   METHOD SetItemImage( oItem, nImage ) INLINE ;
      If( oItem == nil, oItem := ::GetSelected(), nil ), ;
      TVSetItemImage( ::hWnd, oItem:hItem, nImage )

   METHOD SetItemHeight( nHeight ) INLINE TvSetItemHeight( ::hWnd, nHeight )

   METHOD SetSelText( cText ) INLINE ::GetSelected():SetText( cText )

   METHOD Len() INLINE Len( ::aItems )

   METHOD Count()

ENDCLASS

//----------------------------------------------------------------------------//

METHOD LoadFromMenu( oMenu ) CLASS TTreeView

   local n

   ::DeleteAll()

   for n = 1 to Len( oMenu:aItems )
      ::Add( oMenu:aItems[ n ]:cPrompt )
      if ValType( oMenu:aItems[ n ]:bAction ) == "O"
         AddSubItems( ATail( ::aItems ), oMenu:aItems[ n ]:bAction )
      endif
   next

return nil

//----------------------------------------------------------------------------//

static function AddSubItems( oItem, oSubMenu )

   local n

   for n = 1 to Len( oSubMenu:aItems )
      oItem:Add( oSubMenu:aItems[ n ]:cPrompt )
      if ValType( oSubMenu:aItems[ n ]:bAction ) == "O"
         AddSubItems( ATail( oItem:aItems ), oSubMenu:aItems[ n ]:bAction )
      endif
   next

return nil

//----------------------------------------------------------------------------//

METHOD New( nTop, nLeft, oWnd, nClrFore,;
            nClrBack, lPixel, lDesign, nWidth, nHeight, cMsg, lCheckBoxes, bChange, lEditable ) CLASS TTreeView

   DEFAULT nTop        := 0, nLeft := 0,;
           oWnd        := GetWndDefault(),;
           nClrFore    := oWnd:nClrText,;
           nClrBack    := GetSysColor( COLOR_WINDOW ),;
           lPixel      := .f.,;
           lDesign     := .f.,;
           nWidth      := 150,;
           nHeight     := 150,;
           lCheckBoxes := .F.,;
           lEditable   := .F.

    ::lUnicode  = FW_SetUnicode()
   ::nStyle    = nOR( WS_CHILD, WS_VISIBLE, CS_VREDRAW, CS_HREDRAW,;
                      If( lDesign, WS_CLIPSIBLINGS, 0 ), WS_TABSTOP,;
                      TVS_HASBUTTONS, TVS_HASLINES, TVS_LINESATROOT, TVS_SHOWSELALWAYS, TVS_DISABLEDRAGDROP,;
                      If( lCheckBoxes, TVS_CHECKBOXES, 0 ),;
                      If( lEditable, TVS_EDITLABELS, 0 ) )

   ::nId       = ::GetNewId()
   ::oWnd      = oWnd
   ::cMsg      = cMsg
   ::nTop      = If( lPixel, nTop, nTop * SAY_CHARPIX_H )
   ::nLeft     = If( lPixel, nLeft, nLeft * SAY_CHARPIX_W )
   ::nBottom   = ::nTop + nHeight - 1
   ::nRight    = ::nLeft + nWidth - 1
   ::lDrag     = lDesign
   ::lCaptured = .f.
   ::nClrText  = nClrFore
   ::nClrPane  = nClrBack
   ::aItems    = {}
   ::bChanged  = bChange

   if ! Empty( oWnd:hWnd )
      ::Create( CTRL_NAME )
      oWnd:AddControl( Self )
      ::SetColor( nClrFore, nClrBack )
   else
      oWnd:DefControl( Self )
   endif

   ::Default()
   ::lDrag = lDesign

   if lDesign
      ::CheckDots()
   endif

return Self

//----------------------------------------------------------------------------//

METHOD ReDefine( nId, oWnd, nClrFore, nClrBack, lDesign, cMsg, bChange ) CLASS TTreeView

   DEFAULT oWnd     := GetWndDefault(),;
           nClrFore := oWnd:nClrText,;
           nClrBack := oWnd:nClrPane,; // GetSysColor( COLOR_WINDOW ),;
           lDesign  := .f.

    ::lUnicode  = FW_SetUnicode()
   ::nId      = nId
   ::oWnd     = oWnd
   ::aItems   = {}
   ::nClrText = nClrFore
   ::nClrPane = nClrBack
   ::bChanged = bChange

   ::Register( nOR( CS_VREDRAW, CS_HREDRAW, TVS_HASBUTTONS, TVS_HASLINES, TVS_LINESATROOT ) )

   oWnd:DefControl( Self )

return Self

//----------------------------------------------------------------------------//

METHOD Add( cPrompt, nImage, nValue ) CLASS TTreeView

   local oItem

   oItem := TTVItem():New( TVInsertItem( ::hWnd, cPrompt,, nImage, nValue ), Self )

   oItem:cPrompt := cPrompt
   oItem:nImage  := nImage

   AAdd( ::aItems, oItem )

return oItem

//----------------------------------------------------------------------------//

METHOD Count() CLASS TTreeView

   local nItems := 0, bAction := { | oItem | nItems++, .F. }

   ::Scan( bAction )

return nItems

//----------------------------------------------------------------------------//

METHOD InsertAfter( oItem, cPrompt, nImage, nValue ) CLASS TTreeView

   local oNewItem, nAt, oLastItem

   oNewItem := TTVItem():New( TVInsertItem( ::hWnd, cPrompt, oItem:oParent:hItem, nImage, nValue, oItem:hItem ), Self )

   oNewItem:cPrompt := cPrompt
   oNewItem:nImage  := nImage
   oNewItem:oParent := oItem:oParent

   if ( nAt := AScan( oItem:oParent:aItems, { | oIt | oItem:hItem == oIt:hItem } ) ) != 0
      oLastItem = ATail( oItem:oParent:aItems )
      AIns( oItem:oParent:aItems, nAt + 1 )
      AAdd( oItem:oParent:aItems, oLastItem )
      oItem:oParent:aItems[ nAt + 1 ] = oNewItem
      // XBrowse( oItem:oParent:aItems )
   endif

return oNewItem

//----------------------------------------------------------------------------//

static function ScanItems( aItems, lExpand, lToggle )

   local oItem, i

   DEFAULT lExpand := .t., lToggle := .f.

   for i := 1 to Len( aItems )
       oItem = aItems[ i ]

       if lToggle
          oItem:Toggle()
       elseif lExpand
          oItem:Expand()
       else
          oItem:Collapse()
       endif

       if Len( oItem:aItems ) != 0
          ScanItems( oItem:aItems, lExpand, lToggle )
       endif
   next

return nil

//----------------------------------------------------------------------------//

static function ScanItemsBlock( aItems, bAction )

   local oItem, n := 1, oItemFound

   while n <= Len( aItems ) .and. oItemFound == nil
      oItem = aItems[ n ]
      if Eval( bAction, oItem, n )
         return oItem
      else
         if Len( oItem:aItems ) > 0
            oItemFound = ScanItemsBlock( oItem:aItems, bAction )
         endif
      endif
      n++
   end

return oItemFound

//----------------------------------------------------------------------------//

METHOD GenMenu( lPopup ) CLASS TTreeView

   local oMenu

   DEFAULT lPopup := .T.

   if Len( ::aItems ) > 0
      if lPopup
         MENU oMenu POPUP
      else
         MENU oMenu
      endif
      GenMenuItems( ::aItems )
      ENDMENU
   endif

return oMenu

//----------------------------------------------------------------------------//

static function GenMenuItems( aItems )

   local n

   for n = 1 to Len( aItems )
      MENUITEM aItems[ n ]:GetText()
      if Len( aItems[ n ]:aItems ) > 0
         MENU
            GenMenuItems( aItems[ n ]:aItems )
         ENDMENU
      endif
   next

return nil

//----------------------------------------------------------------------------//

METHOD GetSelected() CLASS TTreeView

return SearchItem( ::aItems, TVGetSelected( ::hWnd ) )

//----------------------------------------------------------------------------//

METHOD GetItem( hItem ) CLASS TTreeView

return SearchItem( ::aItems, hItem )

//----------------------------------------------------------------------------//

METHOD GetItemPos( oItem ) CLASS TTreeView

return AScan( ::aItems, { | o | o == oItem } )

//----------------------------------------------------------------------------//

METHOD GoBottom() CLASS TTreeView

   local oLastItem

   ::Scan( { | oItem | oLastItem := oItem, .F. } )
   ::Select( oLastItem )

return nil

//----------------------------------------------------------------------------//

METHOD GoPrev() CLASS TTreeView

   local oSelItem, oPrevItem

   if ( oSelItem := ::GetSelected() ) != nil
      ::Scan( { | oItem | If( oItem:hItem != oSelItem:hItem, oPrevItem := oItem,),;
                              oItem:hItem == oSelItem:hItem } )
      if oPrevItem != nil
         ::Select( oPrevItem )
      else
         ::GoBottom()
      endif
   endif

return nil

//----------------------------------------------------------------------------//

METHOD GoNext() CLASS TTreeView

   local oSelItem := ::GetSelected(), lStop := .F., oNextItem

   ::Scan( { | oItem | If( oItem:hItem == oSelItem:hItem, lStop := .T.,),;
                       If( lStop .and. oItem:hItem != oSelItem:hItem, ( oNextItem := oItem, .T. ), .F. ) } )

   if oNextItem != nil
      ::Select( oNextItem )
   else
      ::GoTop()
   endif

return nil

//----------------------------------------------------------------------------//

METHOD HitTest( nRow, nCol ) CLASS TTreeView

   local hItem

   hItem := TVHitTest( ::hWnd, nRow, nCol )

   If hItem > 0
      return ::GetItem( hItem )
   Endif

return nil

//----------------------------------------------------------------------------//

METHOD Notify( nIdCtrl, nPtrNMHDR ) CLASS TTreeView

   local nCode := GetNMHDRCode( nPtrNMHDR )

   do case
      case nCode == TVN_ITEMEXPANDED
           if ! Empty( ::bExpanded )
              if NMTREEVIEWAction( nPtrNMHDR ) == 2 // Expanded
                 Eval( ::bExpanded, NMTREEVIEWItemNew( nPtrNMHDR ) ) // hItem
              endif
           endif

      case nCode == TVN_BEGINLABELEDIT
           ::hEdit  := SendMessage( ::hWnd, TVM_GETEDITCONTROL, 0, 0 )
           return 0

      case nCode == TVN_ENDLABELEDIT
           ::SetSelText( GetWindowText( ::hEdit ) )
           ::hEdit := nil

   endcase

return nil

//----------------------------------------------------------------------------//

METHOD Scan( bAction ) CLASS TTreeView

return ScanItemsBlock( ::aItems, bAction )

//----------------------------------------------------------------------------//

METHOD SetImageList( oImageList ) CLASS TTreeView

   ::oImageList = oImageList

   TVSetImageList( ::hWnd, oImageList:hImageList, 0 )

return nil

//----------------------------------------------------------------------------//

METHOD SwapDown() CLASS TTreeView

   local oSelItem := ::GetSelected(), cPrompt := oSelItem:cPrompt

   ::GoNext()
   oSelItem:End()
   ::Select( ::InsertAfter( ::GetSelected(), cPrompt ) )

return nil

//----------------------------------------------------------------------------//

METHOD SwapUp() CLASS TTreeView

   local oSelItem := ::GetSelected(), cPrompt := oSelItem:cPrompt

   ::GoPrev()
   ::GoPrev()

   oSelItem:End()
   ::Select( ::InsertAfter( ::GetSelected(), cPrompt ) )

return nil

//----------------------------------------------------------------------------//

METHOD HandleEvent( nMsg, nWParam, nLParam ) CLASS TTreeView

   local oItem

   do case
      case nMsg == WM_CHAR
           if nWParam == VK_RETURN
              return 1
           endif
   endcase

return ::Super:HandleEvent( nMsg, nWParam, nLParam )

//----------------------------------------------------------------------------//

METHOD SetItems( aItems ) CLASS TTreeView

   local n

   for n = 1 to Len( aItems )
      ::Add( aItems[ n ] )
   next

return nil

//----------------------------------------------------------------------------//

static function SearchItem( aItems, hItem )

   local n, oItem

   for n = 1 to Len( aItems )
      if Len( aItems[ n ]:aItems ) > 0
         if ( oItem := SearchItem( aItems[ n ]:aItems, hItem ) ) != nil
            return oItem
         endif
      endif
      if aItems[ n ]:hItem == hItem
         return aItems[ n ]
      endif
   next

return nil

//----------------------------------------------------------------------------//
