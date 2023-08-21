// Win95 Class TTreeView items support ( TTVItem --> TreeViewItem )

#include "FiveWin.ch"

#define TV_FIRST          4352   // 0x1100
#define TVM_EXPAND        TV_FIRST + 2

#define TVE_COLLAPSE      1
#define TVE_EXPAND        2
#define TVE_TOGGLE        3

#define TVM_ENSUREVISIBLE TV_FIRST + 20
#define TVM_GETITEMSTATE  TV_FIRST + 39

//item state
#define TVIS_SELECTED           0x0002
#define TVIS_CUT                0x0004
#define TVIS_DROPHILITED        0x0008
#define TVIS_BOLD               0x0010
#define TVIS_EXPANDED           0x0020
#define TVIS_EXPANDEDONCE       0x0040

//----------------------------------------------------------------------------//

CLASS TTVItem

   DATA   oParent
   DATA   hItem
   DATA   oTree
   DATA   aItems
   DATA   cPrompt
   DATA   nImage
   DATA   Cargo
   DATA   lBold   INIT .F.

   METHOD New( hItem, oTree, Cargo ) CONSTRUCTOR

   METHOD Add( cPrompt, nImage, Cargo )

   METHOD Bold() INLINE TVSetItemBold( ::oTree:hWnd, ::hItem, .T. )

   METHOD Normal() INLINE TVSetItemBold( ::oTree:hWnd, ::hItem, .F. )

   METHOD DeleteBranches()

   METHOD DelItemPos( nPos )

   METHOD Edit() INLINE TVEditLabel( ::oTree:hWnd, ::hItem )

   METHOD Expand() INLINE ;
      SendMessage( ::oTree:hWnd, TVM_EXPAND, TVE_EXPAND, ::hItem )

   METHOD Collapse() INLINE ;
      SendMessage( ::oTree:hWnd, TVM_EXPAND, TVE_COLLAPSE, ::hItem )

   METHOD GetItemPos( oItem )

   METHOD GetParent() INLINE ;
      ::oTree:GetItem( TVGetParent( ::oTree:hWnd, ::hItem ) )

   METHOD IsExpanded() INLINE nAnd( ::GetState(), TVIS_EXPANDED ) > 0

   METHOD IsSelected() INLINE nAnd( ::GetState(), TVIS_SELECTED ) > 0

   METHOD ItemLevel( nPrevLevel )

   METHOD SetText( cText ) INLINE ;
      TVSetItemText( ::oTree:hWnd, ::hItem, cText )

   METHOD Set( cText, nImage )

   METHOD Toggle() INLINE ;
      SendMessage( ::oTree:hWnd, TVM_EXPAND, TVE_TOGGLE, ::hItem )

   METHOD MakeVisible() INLINE ;
      SendMessage( ::oTree:hWnd, TVM_ENSUREVISIBLE, 0, ::hItem )

   METHOD SetCheck( lOnOff ) INLINE ::oTree:SetCheck( Self, lOnOff )

   METHOD GetCheck() INLINE ::oTree:GetCheck( Self )

   METHOD GetState() INLINE SendMessage( ::oTree:hWnd, TVM_GETITEMSTATE, ::hItem, 0 )

   METHOD GetText() INLINE TVGetText( ::oTree:hWnd, ::hItem )

   METHOD SetText( cText ) INLINE TVSetItemText( ::oTree:hWnd, ::hItem, cText )

   ACCESS cPrompt INLINE TVGetText( ::oTree:hWnd, ::hItem )

   ASSIGN cPrompt( cText ) INLINE TVSetItemText( ::oTree:hWnd, ::hItem, cText )

   METHOD End()

   METHOD Len() INLINE Len( ::aItems )

   METHOD Count()

ENDCLASS

//----------------------------------------------------------------------------//

METHOD New( hItem, oTree, Cargo, cPrompt, nImage, oParent ) CLASS TTVItem

   ::aItems  = {}
   ::hItem   = hItem
   ::oTree   = oTree
   ::Cargo   = Cargo
   ::cPrompt = cPrompt
   ::nImage  = nImage

   ::oParent = oParent

return Self

//----------------------------------------------------------------------------//

METHOD Add( cPrompt, nImage, Cargo ) CLASS TTVItem

   local oItem := TTVItem():New( TVInsertItem( ::oTree:hWnd, cPrompt,;
                     ::hItem, nImage ), ::oTree, Cargo, cPrompt, nImage, Self )

   AAdd( ::aItems, oItem )

   oItem:oParent = Self

return oItem

//----------------------------------------------------------------------------//

METHOD Count() CLASS TTVItem

   local oItem, nItems := 1

   for each oItem in ::aItems
      nItems += 1 + If( ! Empty( oItem:aItems ), ( oItem:Count() - 1 ), 0 )
   next

return nItems

//----------------------------------------------------------------------------//

METHOD DeleteBranches() CLASS TTVItem

   AEval( ::aItems, { | o | TVDeleteItem( ::oTree:hWnd, o:hItem ) } )

   ::aItems  = {}

return nil

//----------------------------------------------------------------------------//

METHOD DelItemPos( nPos ) CLASS TTVItem

   if nPos > 0 .and. nPos <= Len( ::aItems )
      TVDeleteItem( ::oTree:hWnd, ::aItems[ nPos ]:hItem )
      ADel( ::aItems, nPos )
      ASize( ::aItems, Len( ::aItems ) - 1 )
   endif

return nil

//----------------------------------------------------------------------------//

METHOD End() CLASS TTVItem

   local nAt := 0

   if ! Empty( ::oParent )
      nAt := AScan( ::oParent:aItems, { | o | o == Self } )
   endif

   if nAt != 0
      if ::oParent:IsKindOf( "TTREEVIEW" )
         ADel( ::oTree:aItems, nAt )
         ASize( ::oTree:aItems, Len( ::oTree:aItems ) - 1 )
      else
         ADel( ::oParent:aItems, nAt )
         ASize( ::oParent:aItems, Len( ::oParent:aItems ) - 1 )
      endif
   endif

   TVDeleteItem( ::oTree:hWnd, ::hItem )

return nil

//----------------------------------------------------------------------------//

METHOD GetItemPos( oItem ) CLASS TTVItem

return AScan( ::aItems, { | o | o == oItem } )

//----------------------------------------------------------------------------//

METHOD ItemLevel( nPrevLevel ) CLASS TTVItem

   DEFAULT nPrevLevel := 0

   if ::oParent != NIL
      ++nPrevLevel
      ::oParent:ItemLevel( @nPrevLevel )
   endif

RETURN nPrevLevel

//----------------------------------------------------------------------------//

METHOD Set( cPrompt, nImage ) CLASS TTVItem

   DEFAULT cPrompt := ::cPrompt, nImage := ::nImage

   TVSetTextImage( ::oTree:hWnd, ::hItem, cPrompt, nImage )

return nil

//----------------------------------------------------------------------------//
