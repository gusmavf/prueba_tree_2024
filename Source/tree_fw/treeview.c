// Windows 95 TreeView control support C routines

#define UNICODE
#define _UNICODE

#define NONAMELESSUNION

#define _WIN32_IE 0x0500
#include <Windows.h>
#include <CommCtrl.h>
#include <hbapi.h>

#ifdef _MSC_VER
   #define TVM_GETITEMSTATE  (TV_FIRST + 39)
#endif

#ifdef __GNUC__
   #define TreeView_SetCheckState(hwndTV, hti, fCheck) TreeView_SetItemState(hwndTV, hti, INDEXTOSTATEIMAGEMASK((fCheck)?2:1), TVIS_STATEIMAGEMASK)
   #define TreeView_GetCheckState(hwndTV, hti) ((((UINT)(SNDMSG((hwndTV), TVM_GETITEMSTATE, (WPARAM)(hti), TVIS_STATEIMAGEMASK))) >> 12) -1)
#endif

#ifndef _WIN64
#define fw_parH( i )   ( (HANDLE) hb_parnl( i ) )
#define fw_retnll( l )  hb_retnl( (LONG) l )
#else
#define fw_parH( i )   ( (HANDLE) hb_parnll( i ) )
#define fw_retnll( l )  hb_retnll( (LONGLONG) l )
#endif

LPWSTR fw_parWide( int iParam );
LPSTR UTF16toSTR8( LPWSTR utf16, int iLen );
size_t wcslen( const wchar_t* wcs );

//-------------------------------------------------------------------------//

HB_FUNC( TVINSERTITEM ) // ( hWnd, cItemText, hItem, nImage, nValue, hItem )
{
   TV_INSERTSTRUCT is;
   HTREEITEM hItem;

   memset( ( char * ) &is, 0, sizeof( TV_INSERTSTRUCT ) );

   #ifndef _WIN64
      is.hParent      = ( HTREEITEM ) hb_parnl( 3 );
   #else
      is.hParent      = ( HTREEITEM ) hb_parnll( 3 );
   #endif

//    #if (_WIN32_IE >= 0x0400)
#ifdef __BORLANDC__

   #if __BORLANDC__ <= 1410

      is.DUMMYUNIONNAME.item.pszText = fw_parWide( 2 ); //hb_parc( 2 );
      is.DUMMYUNIONNAME.item.mask    = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
      is.DUMMYUNIONNAME.item.iImage  = hb_parnl( 4 );
      is.DUMMYUNIONNAME.item.iSelectedImage = hb_parnl( 4 );
      is.DUMMYUNIONNAME.item.lParam = hb_parnl( 5 );
   #else
      is.item.pszText = fw_parWide( 2 ); //hb_parc( 2 );
      is.item.mask    = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
      is.item.iImage  = hb_parnl( 4 );
      is.item.iSelectedImage = hb_parnl( 4 );
      is.item.lParam  = hb_parnl( 5 );
   #endif
#else
      is.u.item.pszText = fw_parWide( 2 ); //hb_parc( 2 );
      is.u.item.mask    = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
      is.u.item.iImage  = hb_parnl( 4 );
      is.u.item.iSelectedImage = hb_parnl( 4 );
      is.u.item.lParam  = hb_parnl( 5 );
#endif

   if( ( hb_pcount() > 5 ) && ( hItem = ( HTREEITEM ) hb_parnll( 6 ) ) )
   {
      is.hInsertAfter = hItem;
   }

   #ifndef _WIN64
      hb_retnl( SendMessage( ( HWND ) hb_parnl( 1 ), TVM_INSERTITEM, 0,
           ( LPARAM )( LPTV_INSERTSTRUCT )( &is ) ) );
   #else
      hb_retnll( SendMessage( ( HWND ) hb_parnll( 1 ), TVM_INSERTITEM, 0,
           ( LPARAM )( LPTV_INSERTSTRUCT )( &is ) ) );
   #endif

#ifdef __BORLANDC__
   #if __BORLANDC__ <= 1410
      hb_xfree( ( void * ) is.DUMMYUNIONNAME.item.pszText );
   #else
      hb_xfree( ( void * ) is.item.pszText );
   #endif
#else
      hb_xfree( ( void * ) is.u.item.pszText );
#endif
}

//-------------------------------------------------------------------------//

HB_FUNC( TVSETIMAGELIST ) // ( hWnd, hImageList, nType )
{
    #ifndef _WIN64
      hb_retnl( ( LONG ) TreeView_SetImageList( ( HWND ) hb_parnl( 1 ),
            ( HIMAGELIST ) hb_parnl( 2 ), hb_parnl( 3 ) ) );
   #else
      hb_retnll( ( LONGLONG ) TreeView_SetImageList( ( HWND ) hb_parnll( 1 ),
            ( HIMAGELIST ) hb_parnll( 2 ), hb_parnl( 3 ) ) );
   #endif
}

//-------------------------------------------------------------------------//

HB_FUNC( TVGETSELTEXT ) // ( hWnd ) --> cText
{
   #ifndef _WIN64
      HWND hWnd = ( HWND ) hb_parnl( 1 );
   #else
      HWND hWnd = ( HWND ) hb_parnll( 1 );
   #endif
   HTREEITEM hItem = TreeView_GetSelection( hWnd );
   TV_ITEM tvi;
   BYTE buffer[ 200 ];
   LPSTR szRet;

   if( hItem )
   {
      tvi.mask       = TVIF_TEXT;
      tvi.hItem      = hItem;
      tvi.pszText    = (LPWSTR) buffer; //( char * ) buffer;
      tvi.cchTextMax = 100;
      TreeView_GetItem( hWnd, &tvi );


//      hb_retc( tvi.pszText );
      szRet = UTF16toSTR8( (LPWSTR) buffer, wcslen( (LPWSTR) buffer ) );
      hb_retc( szRet );
      hb_xfree( ( void * ) szRet );
   }
   else
      hb_retc( "" );
}

//-------------------------------------------------------------------------//

HB_FUNC( TVGETTEXT ) // ( hWnd, hItem ) --> cText
{
    #ifndef _WIN64
      HTREEITEM hItem = ( HTREEITEM ) hb_parnl( 2 );
   #else
      HTREEITEM hItem = ( HTREEITEM ) hb_parnll( 2 );
   #endif
   TV_ITEM tvi;
   BYTE buffer[ 200 ];
   LPSTR szRet;

   tvi.mask       = TVIF_TEXT;
   tvi.hItem      = hItem;
   tvi.pszText    = (LPWSTR) buffer; //( char * ) buffer;
   tvi.cchTextMax = 100;
   #ifndef _WIN64
      TreeView_GetItem( ( HWND ) hb_parnl( 1 ), &tvi );
   #else
      TreeView_GetItem( ( HWND ) hb_parnll( 1 ), &tvi );
   #endif

//   hb_retc( tvi.pszText );

   szRet    = UTF16toSTR8( (LPWSTR) buffer, wcslen( (LPWSTR) buffer ) );
   hb_retc( szRet );
   hb_xfree( ( void * ) szRet );

}

//-------------------------------------------------------------------------//

HB_FUNC( TVSETITEMTEXT ) // ( hWnd, hItem, cText )
{
    #ifndef _WIN64
      HWND hWnd = ( HWND ) hb_parnl( 1 );
   #else
      HWND hWnd = ( HWND ) hb_parnll( 1 );
   #endif
   TV_ITEM tvi;
   BOOL bResult;
   BYTE buffer[ 200 ];

   #ifndef _WIN64
      tvi.hItem = ( HTREEITEM ) hb_parnl( 2 );
   #else
      tvi.hItem = ( HTREEITEM ) hb_parnll( 2 );
   #endif
   tvi.mask       = TVIF_TEXT;
   tvi.pszText    = (LPWSTR) buffer;  //( char * ) buffer;
   tvi.cchTextMax = 100; //sizeof( buffer );
   bResult = TreeView_GetItem( hWnd, &tvi );

   if( bResult )
   {
      tvi.mask       = TVIF_TEXT;
      #ifndef _WIN64
         tvi.hItem      = ( HTREEITEM ) hb_parnl( 2 );
      #else
         tvi.hItem      = ( HTREEITEM ) hb_parnll( 2 );
      #endif
      tvi.pszText    = fw_parWide( 3 ); //( LPSTR ) hb_parc( 3 );
      tvi.cchTextMax = wcslen( tvi.pszText ); //hb_parclen( 3 );
      TreeView_SetItem( hWnd, &tvi );

      hb_xfree( ( void * ) tvi.pszText );
   }
}

//-------------------------------------------------------------------------//

HB_FUNC( TVGETSELECTED ) // ( hWnd ) --> hItem
{
    #ifndef _WIN64
      hb_retnl( ( LONG ) TreeView_GetSelection( ( HWND ) hb_parnl( 1 ) ) );
   #else
      hb_retnll( ( LONGLONG ) TreeView_GetSelection( ( HWND ) hb_parnll( 1 ) ) );
   #endif
}

//-------------------------------------------------------------------------//

HB_FUNC( TVDELALLITEMS ) // ( hWnd ) --> lSuccess
{
    #ifndef _WIN64
      hb_retl( ( BOOL ) TreeView_DeleteAllItems( ( HWND ) hb_parnl( 1 ) ) );
   #else
      hb_retl( ( BOOL ) TreeView_DeleteAllItems( ( HWND ) hb_parnll( 1 ) ) );
   #endif
}

//-------------------------------------------------------------------------//

HB_FUNC( TVHITTEST ) // ( hWnd, nRow, nCol ) --> hItem
{
    #ifndef _WIN64
      HWND hWnd = ( HWND ) hb_parnl( 1 );
   #else
      HWND hWnd = ( HWND ) hb_parnll( 1 );
   #endif
   TV_HITTESTINFO lpht;
   HTREEITEM hItem;

   lpht.pt.x = hb_parnl( 3 );
   lpht.pt.y = hb_parnl( 2 );

   hItem = TreeView_HitTest( hWnd, &lpht );

   if( ( hItem != NULL ) && ( lpht.flags & TVHT_ONITEM ) )
    #ifndef _WIN64
       hb_retnl( ( LONG ) hItem );
    #else
       hb_retnll( ( LONGLONG ) hItem );
    #endif
   else
    hb_retnl( ( LONG ) 0 );
}

//-------------------------------------------------------------------------//

HB_FUNC( TVSELECT ) // ( hWnd, hItem ) --> lSuccess
{
    #ifndef _WIN64
      HWND hWnd = ( HWND ) hb_parnl( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnl( 2 );
   #else
      HWND hWnd = ( HWND ) hb_parnll( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnll( 2 );
   #endif

   hb_retl( ( BOOL ) TreeView_Select( hWnd, hItem, TVGN_CARET ) );
}

//-------------------------------------------------------------------------//

HB_FUNC( TVDELETEITEM ) // ( hWnd, hItem ) --> lSuccess
{
    #ifndef _WIN64
      HWND hWnd = ( HWND ) hb_parnl( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnl( 2 );
   #else
      HWND hWnd = ( HWND ) hb_parnll( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnll( 2 );
   #endif

   hb_retl( TreeView_DeleteItem( hWnd, hItem ) );
}

//-------------------------------------------------------------------------//

HB_FUNC( TVEDITLABEL ) // ( hWnd, hItem ) --> lSuccess
{
    #ifndef _WIN64
      HWND hWnd = ( HWND ) hb_parnl( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnl( 2 );
   #else
      HWND hWnd = ( HWND ) hb_parnll( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnll( 2 );
   #endif

   SetFocus( hWnd );
   TreeView_EditLabel( hWnd, hItem );
}

//-------------------------------------------------------------------------//

HB_FUNC( TVGETPARENT ) // ( hWnd, hItem ) --> hParentItem
{
    #ifndef _WIN64
      HWND hWnd = ( HWND ) hb_parnl( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnl( 2 );
   #else
      HWND hWnd = ( HWND ) hb_parnll( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnll( 2 );
   #endif

   #ifndef _WIN64
      hb_retnl( ( unsigned long ) TreeView_GetParent( hWnd, hItem ) );
   #else
      hb_retnll( ( LONGLONG ) TreeView_GetParent( hWnd, hItem ) );
   #endif
}

//-------------------------------------------------------------------------//

HB_FUNC( TVSETTEXTIMAGE ) // ( hWnd, hItem, cText, nImage )
{
    #ifndef _WIN64
      HWND hWnd = ( HWND ) hb_parnl( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnl( 2 );
   #else
      HWND hWnd = ( HWND ) hb_parnll( 1 );
      HTREEITEM hItem = ( HTREEITEM ) hb_parnll( 2 );
   #endif
   TV_ITEM tvi;

   tvi.hItem   = hItem;
   tvi.mask    = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
   tvi.pszText = fw_parWide( 3 ); //( LPSTR ) hb_parc( 3 );
   tvi.iImage  = hb_parnl( 4 );
   tvi.iSelectedImage = hb_parnl( 4 );
   TreeView_SetItem( hWnd, &tvi );

   hb_xfree( ( void * ) tvi.pszText );
}

//-------------------------------------------------------------------------//

HB_FUNC( TVSETCOLOR ) // hWnd, nClrFore, nClrBack
{
    #ifndef _WIN64
      COLORREF clr = TreeView_SetBkColor( ( HWND ) hb_parnl( 1 ), hb_parnl( 3 ) );
      COLORREF clr2 = TreeView_SetTextColor( ( HWND ) hb_parnl( 1 ), hb_parnl( 2 ) );
   #else
      COLORREF clr = TreeView_SetBkColor( ( HWND ) hb_parnll( 1 ), hb_parnl( 3 ) );
      COLORREF clr2 = TreeView_SetTextColor( ( HWND ) hb_parnll( 1 ), hb_parnl( 2 ) );
   #endif

   HB_SYMBOL_UNUSED( clr );
   HB_SYMBOL_UNUSED( clr2 );
}

//-------------------------------------------------------------------------//

HB_FUNC( TVSETCHECK ) // hTreeView, hItem, lOnOff
{
    #ifndef _WIN64
      TreeView_SetCheckState( ( HWND ) hb_parnl( 1 ),
                              ( HTREEITEM ) hb_parnl( 2 ), hb_parl( 3 ) );
   #else
      TreeView_SetCheckState( ( HWND ) hb_parnll( 1 ),
                              ( HTREEITEM ) hb_parnll( 2 ), hb_parl( 3 ) );
   #endif
}

//-------------------------------------------------------------------------//

HB_FUNC( TVGETCHECK ) // hTreeView, hItem --> lOnOff
{
    #ifndef _WIN64
      hb_retl( TreeView_GetCheckState( ( HWND ) hb_parnl( 1 ),
                                     ( HTREEITEM ) hb_parnl( 2 ) ) );
   #else
      hb_retl( TreeView_GetCheckState( ( HWND ) hb_parnll( 1 ),
                                     ( HTREEITEM ) hb_parnll( 2 ) ) );
   #endif
}

//-------------------------------------------------------------------------//

HB_FUNC( TVGETEDITCONTROL ) // hTreeView --> hEdit
{
    #ifndef _WIN64
      hb_retnl( ( HB_ULONG ) TreeView_GetEditControl( ( HWND ) hb_parnl( 1 ) ) );
   #else
      hb_retnll( ( HB_LONGLONG ) TreeView_GetEditControl( ( HWND ) hb_parnll( 1 ) ) );
   #endif
}

//-------------------------------------------------------------------------//

HB_FUNC( TVIPARAM ) // hItem --> nLParam
{
    #ifndef _WIN64
      hb_retnl( ( ( TV_ITEM * ) hb_parnl( 1 ) )->lParam );
   #else
      hb_retnll( ( ( TV_ITEM * ) hb_parnll( 1 ) )->lParam );
   #endif
}


//-------------------------------------------------------------------------//

HB_FUNC( TVSETITEMIMAGE ) // ( hWnd, hItem, iImage ) --> lSuccess
{
    #ifndef _WIN64
      HWND hWnd = ( HWND ) hb_parnl( 1 );
   #else
      HWND hWnd = ( HWND ) hb_parnll( 1 );
   #endif
   UINT iImage = hb_parni( 3 ) + 1;
   TV_ITEM pitem;

   #ifndef _WIN64
      pitem.hItem = ( HTREEITEM ) hb_parnl( 2 );
   #else
      pitem.hItem = ( HTREEITEM ) hb_parnll( 2 );
   #endif
   pitem.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE;
   pitem.iImage = iImage;
   pitem.iSelectedImage = iImage;

   hb_retl( TreeView_SetItem( hWnd, ( LPTV_ITEM )( &pitem ) ) );
}

//-------------------------------------------------------------------------//

HB_FUNC( TVSETITEMHEIGHT )// ( hWnd, cyItemn ) --> lSuccess
{
    #ifndef _WIN64
      hb_retl( TreeView_SetItemHeight( ( HWND ) hb_parnl( 1 ), hb_parni( 2 ) ) );
   #else
      hb_retl( TreeView_SetItemHeight( ( HWND ) hb_parnll( 1 ), hb_parni( 2 ) ) );
   #endif
}

//-------------------------------------------------------------------------//

HB_FUNC( TVSETITEMBOLD ) // ( hWnd, hTreeItem, lBold ) --> lSuccess
{
   UINT uiMask1, uiMask2 = 0, bBold = hb_parl( 3 );

   #ifndef _WIN64
      hb_retl( TreeView_GetItemState( ( HWND ) hb_parnl( 1 ), ( HTREEITEM ) hb_parnl( 2 ), &uiMask1 ) );
   #else
      hb_retl( TreeView_GetItemState( ( HWND ) hb_parnll( 1 ), ( HTREEITEM ) hb_parnll( 2 ), &uiMask1 ) );
   #endif

   if( bBold )
      uiMask2 = TVIS_BOLD;
   else
      uiMask1 = uiMask1 ^ TVIS_BOLD;

   #ifndef _WIN64
      TreeView_SetItemState( ( HWND ) hb_parnl( 1 ), ( HTREEITEM ) hb_parnl( 2 ), uiMask1, uiMask2 );
   #else
      TreeView_SetItemState( ( HWND ) hb_parnll( 1 ), ( HTREEITEM ) hb_parnll( 2 ), uiMask1, uiMask2 );
   #endif

   hb_retl( uiMask1 & TVIS_BOLD );
}

//-------------------------------------------------------------------------//
