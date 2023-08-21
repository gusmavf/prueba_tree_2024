/*
 * Harbour 3.2.0dev (r2104281802)
 * Microsoft Visual C 19.30.30706 (64-bit)
 * Generated C source from "Source\tree_fw\ttreevie.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TTREEVIEW );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TCONTROL );
HB_FUNC_STATIC( TTREEVIEW_NEW );
HB_FUNC_STATIC( TTREEVIEW_REDEFINE );
HB_FUNC_STATIC( TTREEVIEW_ADD );
HB_FUNC_STATIC( SCANITEMS );
HB_FUNC_EXTERN( AEVAL );
HB_FUNC_EXTERN( TVGETEDITCONTROL );
HB_FUNC_STATIC( TTREEVIEW_GETSELECTED );
HB_FUNC_STATIC( TTREEVIEW_GETITEM );
HB_FUNC_STATIC( TTREEVIEW_GETITEMPOS );
HB_FUNC_STATIC( TTREEVIEW_INSERTAFTER );
HB_FUNC_EXTERN( TVSELECT );
HB_FUNC_EXTERN( TVGETSELTEXT );
HB_FUNC_STATIC( TTREEVIEW_GONEXT );
HB_FUNC_STATIC( TTREEVIEW_GOPREV );
HB_FUNC_EXTERN( LEN );
HB_FUNC_STATIC( TTREEVIEW_GOBOTTOM );
HB_FUNC_STATIC( TTREEVIEW_SETIMAGELIST );
HB_FUNC_EXTERN( TVDELALLITEMS );
HB_FUNC_STATIC( TTREEVIEW_HITTEST );
HB_FUNC_STATIC( TTREEVIEW_HANDLEEVENT );
HB_FUNC_EXTERN( TVSETCOLOR );
HB_FUNC_STATIC( TTREEVIEW_SWAPUP );
HB_FUNC_STATIC( TTREEVIEW_SWAPDOWN );
HB_FUNC_EXTERN( TVGETCHECK );
HB_FUNC_EXTERN( TVSETCHECK );
HB_FUNC_STATIC( TTREEVIEW_SETITEMS );
HB_FUNC_STATIC( TTREEVIEW_GENMENU );
HB_FUNC_STATIC( TTREEVIEW_LOADFROMMENU );
HB_FUNC_STATIC( TTREEVIEW_NOTIFY );
HB_FUNC_STATIC( TTREEVIEW_SCAN );
HB_FUNC_EXTERN( TVSETITEMIMAGE );
HB_FUNC_EXTERN( TVSETITEMHEIGHT );
HB_FUNC_STATIC( TTREEVIEW_COUNT );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_STATIC( ADDSUBITEMS );
HB_FUNC_EXTERN( ATAIL );
HB_FUNC_EXTERN( GETWNDDEFAULT );
HB_FUNC_EXTERN( GETSYSCOLOR );
HB_FUNC_EXTERN( FW_SETUNICODE );
HB_FUNC_EXTERN( NOR );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( TTVITEM );
HB_FUNC_EXTERN( TVINSERTITEM );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( AINS );
HB_FUNC_STATIC( SCANITEMSBLOCK );
HB_FUNC_EXTERN( MENUBEGIN );
HB_FUNC_STATIC( GENMENUITEMS );
HB_FUNC_EXTERN( MENUEND );
HB_FUNC_EXTERN( MENUADDITEM );
HB_FUNC_STATIC( SEARCHITEM );
HB_FUNC_EXTERN( TVGETSELECTED );
HB_FUNC_EXTERN( TVHITTEST );
HB_FUNC_EXTERN( GETNMHDRCODE );
HB_FUNC_EXTERN( NMTREEVIEWACTION );
HB_FUNC_EXTERN( NMTREEVIEWITEMNEW );
HB_FUNC_EXTERN( SENDMESSAGE );
HB_FUNC_EXTERN( GETWINDOWTEXT );
HB_FUNC_EXTERN( TVSETIMAGELIST );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TTREEVIE )
{ "TTREEVIEW", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCONTROL )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TTREEVIEW_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_NEW )}, NULL },
{ "TTREEVIEW_REDEFINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_REDEFINE )}, NULL },
{ "TTREEVIEW_ADD", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_ADD )}, NULL },
{ "ADDVIRTUAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SCANITEMS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SCANITEMS )}, NULL },
{ "AITEMS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETSELECTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MAKEVISIBLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "COLLAPSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EDIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AEVAL", {HB_FS_PUBLIC}, {HB_FUNCNAME( AEVAL )}, NULL },
{ "EXPAND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TVGETEDITCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVGETEDITCONTROL )}, NULL },
{ "HWND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TTREEVIEW_GETSELECTED", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_GETSELECTED )}, NULL },
{ "TTREEVIEW_GETITEM", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_GETITEM )}, NULL },
{ "TTREEVIEW_GETITEMPOS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_GETITEMPOS )}, NULL },
{ "TTREEVIEW_INSERTAFTER", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_INSERTAFTER )}, NULL },
{ "TVSELECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVSELECT )}, NULL },
{ "HITEM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TVGETSELTEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVGETSELTEXT )}, NULL },
{ "TTREEVIEW_GONEXT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_GONEXT )}, NULL },
{ "TTREEVIEW_GOPREV", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_GOPREV )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "SELECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TTREEVIEW_GOBOTTOM", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_GOBOTTOM )}, NULL },
{ "BCHANGED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TTREEVIEW_SETIMAGELIST", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_SETIMAGELIST )}, NULL },
{ "TVDELALLITEMS", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVDELALLITEMS )}, NULL },
{ "_AITEMS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TTREEVIEW_HITTEST", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_HITTEST )}, NULL },
{ "TTREEVIEW_HANDLEEVENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_HANDLEEVENT )}, NULL },
{ "INITIATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCLRTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCLRPANE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTOCHAR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TVSETCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVSETCOLOR )}, NULL },
{ "TTREEVIEW_SWAPUP", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_SWAPUP )}, NULL },
{ "TTREEVIEW_SWAPDOWN", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_SWAPDOWN )}, NULL },
{ "TOGGLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TVGETCHECK", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVGETCHECK )}, NULL },
{ "TVSETCHECK", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVSETCHECK )}, NULL },
{ "TTREEVIEW_SETITEMS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_SETITEMS )}, NULL },
{ "TTREEVIEW_GENMENU", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_GENMENU )}, NULL },
{ "TTREEVIEW_LOADFROMMENU", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_LOADFROMMENU )}, NULL },
{ "TTREEVIEW_NOTIFY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_NOTIFY )}, NULL },
{ "TTREEVIEW_SCAN", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_SCAN )}, NULL },
{ "TVSETITEMIMAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVSETITEMIMAGE )}, NULL },
{ "TVSETITEMHEIGHT", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVSETITEMHEIGHT )}, NULL },
{ "SETTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TTREEVIEW_COUNT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TTREEVIEW_COUNT )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DELETEALL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPROMPT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "BACTION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDSUBITEMS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( ADDSUBITEMS )}, NULL },
{ "ATAIL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ATAIL )}, NULL },
{ "GETWNDDEFAULT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETWNDDEFAULT )}, NULL },
{ "GETSYSCOLOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETSYSCOLOR )}, NULL },
{ "_LUNICODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_SETUNICODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_SETUNICODE )}, NULL },
{ "_NSTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( NOR )}, NULL },
{ "_NID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETNEWID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OWND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CMSG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NBOTTOM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NRIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDRAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LCAPTURED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NCLRTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NCLRPANE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BCHANGED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "ADDCONTROL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFCONTROL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFAULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHECKDOTS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REGISTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TTVITEM", {HB_FS_PUBLIC}, {HB_FUNCNAME( TTVITEM )}, NULL },
{ "TVINSERTITEM", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVINSERTITEM )}, NULL },
{ "_CPROMPT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NIMAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "SCAN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "AINS", {HB_FS_PUBLIC}, {HB_FUNCNAME( AINS )}, NULL },
{ "SCANITEMSBLOCK", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SCANITEMSBLOCK )}, NULL },
{ "MENUBEGIN", {HB_FS_PUBLIC}, {HB_FUNCNAME( MENUBEGIN )}, NULL },
{ "GENMENUITEMS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( GENMENUITEMS )}, NULL },
{ "MENUEND", {HB_FS_PUBLIC}, {HB_FUNCNAME( MENUEND )}, NULL },
{ "MENUADDITEM", {HB_FS_PUBLIC}, {HB_FUNCNAME( MENUADDITEM )}, NULL },
{ "GETTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEARCHITEM", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SEARCHITEM )}, NULL },
{ "TVGETSELECTED", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVGETSELECTED )}, NULL },
{ "GOBOTTOM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TVHITTEST", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVHITTEST )}, NULL },
{ "GETITEM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETNMHDRCODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETNMHDRCODE )}, NULL },
{ "BEXPANDED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NMTREEVIEWACTION", {HB_FS_PUBLIC}, {HB_FUNCNAME( NMTREEVIEWACTION )}, NULL },
{ "NMTREEVIEWITEMNEW", {HB_FS_PUBLIC}, {HB_FUNCNAME( NMTREEVIEWITEMNEW )}, NULL },
{ "_HEDIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SENDMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SENDMESSAGE )}, NULL },
{ "SETSELTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETWINDOWTEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETWINDOWTEXT )}, NULL },
{ "HEDIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OIMAGELIST", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TVSETIMAGELIST", {HB_FS_PUBLIC}, {HB_FUNCNAME( TVSETIMAGELIST )}, NULL },
{ "HIMAGELIST", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GONEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INSERTAFTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOPREV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HANDLEEVENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00003)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TTREEVIE, "Source\\tree_fw\\ttreevie.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TTREEVIE
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TTREEVIE )
   #include "hbiniseg.h"
#endif

HB_FUNC( TTREEVIEW )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,143,0,36,54,0,103,3,0,100,8,
		29,18,11,176,1,0,104,3,0,12,1,29,7,11,
		166,201,10,0,122,80,1,48,2,0,176,3,0,12,
		0,106,10,84,84,114,101,101,86,105,101,119,0,108,
		4,4,1,0,108,0,112,3,80,2,36,56,0,48,
		5,0,95,2,100,100,95,1,121,72,121,72,121,72,
		106,7,97,73,116,101,109,115,0,4,1,0,9,112,
		5,73,36,57,0,48,5,0,95,2,100,100,95,1,
		121,72,121,72,121,72,106,11,111,73,109,97,103,101,
		76,105,115,116,0,4,1,0,9,112,5,73,36,58,
		0,48,5,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,9,98,67,104,97,110,103,101,100,0,4,
		1,0,9,112,5,73,36,59,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,10,98,69,
		120,112,97,110,100,101,100,0,4,1,0,9,112,5,
		73,36,60,0,48,5,0,95,2,100,100,95,1,121,
		72,121,72,121,72,106,6,104,69,100,105,116,0,4,
		1,0,9,112,5,73,36,65,0,48,6,0,95,2,
		100,106,7,97,73,116,101,109,115,0,106,7,99,84,
		105,116,108,101,0,106,9,99,86,97,114,78,97,109,
		101,0,106,4,108,51,68,0,106,9,110,67,108,114,
		84,101,120,116,0,106,9,110,67,108,114,80,97,110,
		101,0,106,7,110,65,108,105,103,110,0,106,5,110,
		84,111,112,0,106,6,110,76,101,102,116,0,106,7,
		110,87,105,100,116,104,0,106,8,110,72,101,105,103,
		104,116,0,106,6,111,70,111,110,116,0,106,6,67,
		97,114,103,111,0,4,13,0,95,1,121,72,92,32,
		72,121,72,121,72,106,12,97,80,114,111,112,101,114,
		116,105,101,115,0,4,1,0,9,112,5,73,36,69,
		0,48,7,0,95,2,106,4,78,101,119,0,108,8,
		95,1,92,8,72,121,72,121,72,112,3,73,36,71,
		0,48,7,0,95,2,106,9,82,101,68,101,102,105,
		110,101,0,108,9,95,1,92,8,72,121,72,121,72,
		112,3,73,36,73,0,48,7,0,95,2,106,4,65,
		100,100,0,108,10,95,1,121,72,121,72,121,72,112,
		3,73,36,75,0,48,11,0,95,2,106,8,86,83,
		99,114,111,108,108,0,112,1,73,36,77,0,48,11,
		0,95,2,106,8,72,83,99,114,111,108,108,0,112,
		1,73,36,80,0,48,12,0,95,2,106,12,67,111,
		108,108,97,112,115,101,65,108,108,0,89,46,0,2,
		0,0,0,176,13,0,48,14,0,95,1,112,0,9,
		20,2,48,15,0,95,1,112,0,80,2,95,2,100,
		69,28,11,48,16,0,95,2,112,0,25,3,100,6,
		95,1,121,72,121,72,121,72,112,3,73,36,84,0,
		48,12,0,95,2,106,15,67,111,108,108,97,112,115,
		101,66,114,97,110,99,104,0,89,60,0,2,0,0,
		0,95,2,100,8,28,11,48,15,0,95,1,112,0,
		80,2,95,2,100,69,28,32,48,17,0,95,2,112,
		0,73,176,13,0,48,14,0,95,2,112,0,9,20,
		2,48,16,0,95,2,112,0,25,3,100,6,95,1,
		121,72,121,72,121,72,112,3,73,36,88,0,48,12,
		0,95,2,106,10,69,100,105,116,76,97,98,101,108,
		0,89,39,0,2,0,0,0,95,2,100,8,28,11,
		48,15,0,95,1,112,0,80,2,95,2,100,69,28,
		11,48,18,0,95,2,112,0,25,3,100,6,95,1,
		121,72,121,72,121,72,112,3,73,36,90,0,48,12,
		0,95,2,106,7,69,120,112,97,110,100,0,89,35,
		0,1,0,0,0,176,19,0,48,14,0,95,1,112,
		0,89,15,0,1,0,0,0,48,20,0,95,1,112,
		0,6,12,2,6,95,1,121,72,121,72,121,72,112,
		3,73,36,93,0,48,12,0,95,2,106,10,69,120,
		112,97,110,100,65,108,108,0,89,46,0,2,0,0,
		0,176,13,0,48,14,0,95,1,112,0,120,20,2,
		48,15,0,95,1,112,0,80,2,95,2,100,69,28,
		11,48,16,0,95,2,112,0,25,3,100,6,95,1,
		121,72,121,72,121,72,112,3,73,36,97,0,48,12,
		0,95,2,106,13,69,120,112,97,110,100,66,114,97,
		110,99,104,0,89,60,0,2,0,0,0,95,2,100,
		8,28,11,48,15,0,95,1,112,0,80,2,95,2,
		100,69,28,32,48,20,0,95,2,112,0,73,176,13,
		0,48,14,0,95,2,112,0,120,20,2,48,16,0,
		95,2,112,0,25,3,100,6,95,1,121,72,121,72,
		121,72,112,3,73,36,99,0,48,12,0,95,2,106,
		15,71,101,116,69,100,105,116,67,111,110,116,114,111,
		108,0,89,20,0,1,0,0,0,176,21,0,48,22,
		0,95,1,112,0,12,1,6,95,1,121,72,121,72,
		121,72,112,3,73,36,101,0,48,7,0,95,2,106,
		12,71,101,116,83,101,108,101,99,116,101,100,0,108,
		23,95,1,121,72,121,72,121,72,112,3,73,36,103,
		0,48,7,0,95,2,106,8,71,101,116,73,116,101,
		109,0,108,24,95,1,121,72,121,72,121,72,112,3,
		73,36,105,0,48,7,0,95,2,106,11,71,101,116,
		73,116,101,109,80,111,115,0,108,25,95,1,121,72,
		121,72,121,72,112,3,73,36,107,0,48,7,0,95,
		2,106,12,73,110,115,101,114,116,65,102,116,101,114,
		0,108,26,95,1,121,72,121,72,121,72,112,3,73,
		36,109,0,48,12,0,95,2,106,7,83,101,108,101,
		99,116,0,89,27,0,2,0,0,0,176,27,0,48,
		22,0,95,1,112,0,48,28,0,95,2,112,0,12,
		2,6,95,1,121,72,121,72,121,72,112,3,73,36,
		111,0,48,12,0,95,2,106,11,71,101,116,83,101,
		108,84,101,120,116,0,89,20,0,1,0,0,0,176,
		29,0,48,22,0,95,1,112,0,12,1,6,95,1,
		121,72,121,72,121,72,112,3,73,36,113,0,48,7,
		0,95,2,106,7,71,111,78,101,120,116,0,108,30,
		95,1,121,72,121,72,121,72,112,3,73,36,115,0,
		48,7,0,95,2,106,7,71,111,80,114,101,118,0,
		108,31,95,1,121,72,121,72,121,72,112,3,73,36,
		117,0,48,12,0,95,2,106,6,71,111,84,111,112,
		0,89,43,0,1,0,0,0,176,32,0,48,14,0,
		95,1,112,0,12,1,121,15,28,20,48,33,0,95,
		1,48,14,0,95,1,112,0,122,1,112,1,25,3,
		100,6,95,1,121,72,121,72,121,72,112,3,73,36,
		119,0,48,7,0,95,2,106,9,71,111,66,111,116,
		116,111,109,0,108,34,95,1,121,72,121,72,121,72,
		112,3,73,36,121,0,48,12,0,95,2,106,11,83,
		101,108,67,104,97,110,103,101,100,0,89,36,0,1,
		0,0,0,48,35,0,95,1,112,0,100,69,28,18,
		48,36,0,48,35,0,95,1,112,0,95,1,112,1,
		25,3,100,6,95,1,121,72,121,72,121,72,112,3,
		73,36,123,0,48,7,0,95,2,106,13,83,101,116,
		73,109,97,103,101,76,105,115,116,0,108,37,95,1,
		121,72,121,72,121,72,112,3,73,36,125,0,48,12,
		0,95,2,106,10,68,101,108,101,116,101,65,108,108,
		0,89,30,0,1,0,0,0,176,38,0,48,22,0,
		95,1,112,0,20,1,48,39,0,95,1,4,0,0,
		112,1,6,95,1,121,72,121,72,121,72,112,3,73,
		36,127,0,48,7,0,95,2,106,8,72,105,116,84,
		101,115,116,0,108,40,95,1,121,72,121,72,121,72,
		112,3,73,36,129,0,48,7,0,95,2,106,12,72,
		97,110,100,108,101,69,118,101,110,116,0,108,41,95,
		1,121,72,121,72,121,72,112,3,73,36,131,0,48,
		12,0,95,2,106,9,73,110,105,116,105,97,116,101,
		0,89,44,0,2,0,0,0,48,42,0,48,43,0,
		95,1,112,0,95,2,112,1,73,48,44,0,95,1,
		48,45,0,95,1,112,0,48,46,0,95,1,112,0,
		112,2,6,95,1,121,72,121,72,121,72,112,3,73,
		36,133,0,48,12,0,95,2,106,8,99,84,111,67,
		104,97,114,0,89,36,0,1,0,0,0,48,47,0,
		48,43,0,95,1,112,0,106,14,83,121,115,84,114,
		101,101,86,105,101,119,51,50,0,112,1,6,95,1,
		121,72,121,72,121,72,112,3,73,36,136,0,48,12,
		0,95,2,106,9,83,101,116,67,111,108,111,114,0,
		89,41,0,3,0,0,0,48,44,0,48,43,0,95,
		1,112,0,95,2,95,3,112,2,73,176,48,0,48,
		22,0,95,1,112,0,95,2,95,3,12,3,6,95,
		1,121,72,121,72,121,72,112,3,73,36,138,0,48,
		7,0,95,2,106,7,83,119,97,112,85,112,0,108,
		49,95,1,121,72,121,72,121,72,112,3,73,36,140,
		0,48,7,0,95,2,106,9,83,119,97,112,68,111,
		119,110,0,108,50,95,1,121,72,121,72,121,72,112,
		3,73,36,142,0,48,12,0,95,2,106,7,84,111,
		103,103,108,101,0,89,35,0,1,0,0,0,176,19,
		0,48,14,0,95,1,112,0,89,15,0,1,0,0,
		0,48,51,0,95,1,112,0,6,12,2,6,95,1,
		121,72,121,72,121,72,112,3,73,36,145,0,48,12,
		0,95,2,106,10,84,111,103,103,108,101,65,108,108,
		0,89,47,0,2,0,0,0,176,13,0,48,14,0,
		95,1,112,0,100,120,20,3,48,15,0,95,1,112,
		0,80,2,95,2,100,69,28,11,48,16,0,95,2,
		112,0,25,3,100,6,95,1,121,72,121,72,121,72,
		112,3,73,36,149,0,48,12,0,95,2,106,13,84,
		111,103,103,108,101,66,114,97,110,99,104,0,89,61,
		0,2,0,0,0,95,2,100,8,28,11,48,15,0,
		95,1,112,0,80,2,95,2,100,69,28,33,48,51,
		0,95,2,112,0,73,176,13,0,48,14,0,95,2,
		112,0,100,120,20,3,48,16,0,95,2,112,0,25,
		3,100,6,95,1,121,72,121,72,121,72,112,3,73,
		36,153,0,48,12,0,95,2,106,9,71,101,116,67,
		104,101,99,107,0,89,42,0,2,0,0,0,95,2,
		100,8,28,11,48,15,0,95,1,112,0,80,2,176,
		52,0,48,22,0,95,1,112,0,48,28,0,95,2,
		112,0,12,2,6,95,1,121,72,121,72,121,72,112,
		3,73,36,157,0,48,12,0,95,2,106,9,83,101,
		116,67,104,101,99,107,0,89,44,0,3,0,0,0,
		95,2,100,8,28,11,48,15,0,95,1,112,0,80,
		2,176,53,0,48,22,0,95,1,112,0,48,28,0,
		95,2,112,0,95,3,12,3,6,95,1,121,72,121,
		72,121,72,112,3,73,36,159,0,48,7,0,95,2,
		106,9,83,101,116,73,116,101,109,115,0,108,54,95,
		1,121,72,121,72,121,72,112,3,73,36,161,0,48,
		7,0,95,2,106,8,71,101,110,77,101,110,117,0,
		108,55,95,1,121,72,121,72,121,72,112,3,73,36,
		163,0,48,7,0,95,2,106,13,76,111,97,100,70,
		114,111,109,77,101,110,117,0,108,56,95,1,121,72,
		121,72,121,72,112,3,73,36,165,0,48,7,0,95,
		2,106,7,78,111,116,105,102,121,0,108,57,95,1,
		121,72,121,72,121,72,112,3,73,36,167,0,48,7,
		0,95,2,106,5,83,99,97,110,0,108,58,95,1,
		121,72,121,72,121,72,112,3,73,36,171,0,48,12,
		0,95,2,106,13,83,101,116,73,116,101,109,73,109,
		97,103,101,0,89,44,0,3,0,0,0,95,2,100,
		8,28,11,48,15,0,95,1,112,0,80,2,176,59,
		0,48,22,0,95,1,112,0,48,28,0,95,2,112,
		0,95,3,12,3,6,95,1,121,72,121,72,121,72,
		112,3,73,36,173,0,48,12,0,95,2,106,14,83,
		101,116,73,116,101,109,72,101,105,103,104,116,0,89,
		22,0,2,0,0,0,176,60,0,48,22,0,95,1,
		112,0,95,2,12,2,6,95,1,121,72,121,72,121,
		72,112,3,73,36,175,0,48,12,0,95,2,106,11,
		83,101,116,83,101,108,84,101,120,116,0,89,22,0,
		2,0,0,0,48,61,0,48,15,0,95,1,112,0,
		95,2,112,1,6,95,1,121,72,121,72,121,72,112,
		3,73,36,177,0,48,12,0,95,2,106,4,76,101,
		110,0,89,20,0,1,0,0,0,176,32,0,48,14,
		0,95,1,112,0,12,1,6,95,1,121,72,121,72,
		121,72,112,3,73,36,179,0,48,7,0,95,2,106,
		6,67,111,117,110,116,0,108,62,95,1,121,72,121,
		72,121,72,112,3,73,36,181,0,48,63,0,95,2,
		112,0,73,167,14,0,0,176,64,0,104,3,0,95,
		2,20,2,168,48,65,0,95,2,112,0,80,3,176,
		66,0,95,3,106,10,73,110,105,116,67,108,97,115,
		115,0,12,2,28,12,48,67,0,95,3,164,146,1,
		0,73,95,3,110,7,48,65,0,103,3,0,112,0,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_LOADFROMMENU )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,189,0,48,68,0,102,112,0,73,36,
		191,0,122,165,80,2,25,97,36,192,0,48,69,0,
		102,48,70,0,48,14,0,95,1,112,0,95,2,1,
		112,0,112,1,73,36,193,0,176,71,0,48,72,0,
		48,14,0,95,1,112,0,95,2,1,112,0,12,1,
		106,2,79,0,8,28,36,36,194,0,176,73,0,176,
		74,0,48,14,0,102,112,0,12,1,48,72,0,48,
		14,0,95,1,112,0,95,2,1,112,0,20,2,36,
		191,0,175,2,0,176,32,0,48,14,0,95,1,112,
		0,12,1,15,28,148,36,198,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( ADDSUBITEMS )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,206,0,122,165,80,3,25,99,36,207,
		0,48,69,0,95,1,48,70,0,48,14,0,95,2,
		112,0,95,3,1,112,0,112,1,73,36,208,0,176,
		71,0,48,72,0,48,14,0,95,2,112,0,95,3,
		1,112,0,12,1,106,2,79,0,8,28,37,36,209,
		0,176,73,0,176,74,0,48,14,0,95,1,112,0,
		12,1,48,72,0,48,14,0,95,2,112,0,95,3,
		1,112,0,20,2,36,206,0,175,3,0,176,32,0,
		48,14,0,95,2,112,0,12,1,15,28,146,36,213,
		0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,13,36,229,0,95,1,100,8,28,5,121,80,
		1,95,2,100,8,28,5,121,80,2,95,3,100,8,
		28,9,176,75,0,12,0,80,3,95,4,100,8,28,
		11,48,45,0,95,3,112,0,80,4,95,5,100,8,
		28,11,176,76,0,92,5,12,1,80,5,95,6,100,
		8,28,5,9,80,6,95,7,100,8,28,5,9,80,
		7,95,8,100,8,28,7,93,150,0,80,8,95,9,
		100,8,28,7,93,150,0,80,9,95,11,100,8,28,
		5,9,80,11,95,13,100,8,28,5,9,80,13,36,
		231,0,48,77,0,102,176,78,0,12,0,112,1,73,
		36,236,0,48,79,0,102,176,80,0,97,0,0,0,
		64,97,0,0,0,16,122,92,2,95,7,28,9,97,
		0,0,0,4,25,3,121,97,0,0,1,0,122,92,
		2,92,4,92,32,92,16,95,11,28,7,93,0,1,
		25,3,121,95,13,28,6,92,8,25,3,121,12,13,
		112,1,73,36,238,0,48,81,0,102,48,82,0,102,
		112,0,112,1,73,36,239,0,48,83,0,102,95,3,
		112,1,73,36,240,0,48,84,0,102,95,10,112,1,
		73,36,241,0,48,85,0,102,95,6,28,6,95,1,
		25,7,95,1,92,15,65,112,1,73,36,242,0,48,
		86,0,102,95,6,28,6,95,2,25,7,95,2,92,
		6,65,112,1,73,36,243,0,48,87,0,102,48,88,
		0,102,112,0,95,9,72,122,49,112,1,73,36,244,
		0,48,89,0,102,48,90,0,102,112,0,95,8,72,
		122,49,112,1,73,36,245,0,48,91,0,102,95,7,
		112,1,73,36,246,0,48,92,0,102,9,112,1,73,
		36,247,0,48,93,0,102,95,4,112,1,73,36,248,
		0,48,94,0,102,95,5,112,1,73,36,249,0,48,
		39,0,102,4,0,0,112,1,73,36,250,0,48,95,
		0,102,95,12,112,1,73,36,252,0,176,96,0,48,
		22,0,95,3,112,0,12,1,31,56,36,253,0,48,
		63,0,102,106,14,83,121,115,84,114,101,101,86,105,
		101,119,51,50,0,112,1,73,36,254,0,48,97,0,
		95,3,102,112,1,73,36,255,0,48,44,0,102,95,
		4,95,5,112,2,73,25,14,36,1,1,48,98,0,
		95,3,102,112,1,73,36,4,1,48,99,0,102,112,
		0,73,36,5,1,48,91,0,102,95,7,112,1,73,
		36,7,1,95,7,28,12,36,8,1,48,100,0,102,
		112,0,73,36,11,1,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_REDEFINE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,7,36,20,1,95,2,100,8,28,9,176,75,
		0,12,0,80,2,95,3,100,8,28,11,48,45,0,
		95,2,112,0,80,3,95,4,100,8,28,11,48,46,
		0,95,2,112,0,80,4,95,5,100,8,28,5,9,
		80,5,36,22,1,48,77,0,102,176,78,0,12,0,
		112,1,73,36,23,1,48,81,0,102,95,1,112,1,
		73,36,24,1,48,83,0,102,95,2,112,1,73,36,
		25,1,48,39,0,102,4,0,0,112,1,73,36,26,
		1,48,93,0,102,95,3,112,1,73,36,27,1,48,
		94,0,102,95,4,112,1,73,36,28,1,48,95,0,
		102,95,7,112,1,73,36,30,1,48,101,0,102,176,
		80,0,122,92,2,122,92,2,92,4,12,5,112,1,
		73,36,32,1,48,98,0,95,2,102,112,1,73,36,
		34,1,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_ADD )
{
	static const HB_BYTE pcode[] =
	{
		13,1,3,36,42,1,48,2,0,176,102,0,12,0,
		176,103,0,48,22,0,102,112,0,95,1,100,95,2,
		95,3,12,5,102,112,2,80,4,36,44,1,48,104,
		0,95,4,95,1,112,1,73,36,45,1,48,105,0,
		95,4,95,2,112,1,73,36,47,1,176,106,0,48,
		14,0,102,112,0,95,4,20,2,36,49,1,95,4,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_COUNT )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,55,1,121,80,1,89,15,0,1,0,
		1,0,1,0,96,255,255,170,9,6,80,2,36,57,
		1,48,107,0,102,95,2,112,1,73,36,59,1,95,
		1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_INSERTAFTER )
{
	static const HB_BYTE pcode[] =
	{
		13,3,4,36,67,1,48,2,0,176,102,0,12,0,
		176,103,0,48,22,0,102,112,0,95,2,48,28,0,
		48,108,0,95,1,112,0,112,0,95,3,95,4,48,
		28,0,95,1,112,0,12,6,102,112,2,80,5,36,
		69,1,48,104,0,95,5,95,2,112,1,73,36,70,
		1,48,105,0,95,5,95,3,112,1,73,36,71,1,
		48,109,0,95,5,48,108,0,95,1,112,0,112,1,
		73,36,73,1,176,110,0,48,14,0,48,108,0,95,
		1,112,0,112,0,89,25,0,1,0,1,0,1,0,
		48,28,0,95,255,112,0,48,28,0,95,1,112,0,
		8,6,12,2,165,80,6,121,69,28,92,36,74,1,
		176,74,0,48,14,0,48,108,0,95,1,112,0,112,
		0,12,1,80,7,36,75,1,176,111,0,48,14,0,
		48,108,0,95,1,112,0,112,0,95,6,122,72,20,
		2,36,76,1,176,106,0,48,14,0,48,108,0,95,
		1,112,0,112,0,95,7,20,2,36,77,1,95,5,
		48,14,0,48,108,0,95,1,112,0,112,0,95,6,
		122,72,2,36,81,1,95,5,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SCANITEMS )
{
	static const HB_BYTE pcode[] =
	{
		13,2,3,36,89,1,95,2,100,8,28,5,120,80,
		2,95,3,100,8,28,5,9,80,3,36,91,1,122,
		165,80,5,25,107,36,92,1,95,1,95,5,1,80,
		4,36,94,1,95,3,28,15,36,95,1,48,51,0,
		95,4,112,0,73,25,33,36,96,1,95,2,28,15,
		36,97,1,48,20,0,95,4,112,0,73,25,13,36,
		99,1,48,17,0,95,4,112,0,73,36,102,1,176,
		32,0,48,14,0,95,4,112,0,12,1,121,69,28,
		21,36,103,1,176,13,0,48,14,0,95,4,112,0,
		95,2,95,3,20,3,36,91,1,175,5,0,176,32,
		0,95,1,12,1,15,28,143,36,107,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SCANITEMSBLOCK )
{
	static const HB_BYTE pcode[] =
	{
		13,3,2,36,113,1,122,80,4,36,115,1,95,4,
		176,32,0,95,1,12,1,34,28,87,95,5,100,8,
		28,81,36,116,1,95,1,95,4,1,80,3,36,117,
		1,48,36,0,95,2,95,3,95,4,112,2,28,9,
		36,118,1,95,3,110,7,36,120,1,176,32,0,48,
		14,0,95,3,112,0,12,1,121,15,28,21,36,121,
		1,176,112,0,48,14,0,95,3,112,0,95,2,12,
		2,80,5,36,124,1,174,4,0,25,158,36,127,1,
		95,5,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_GENMENU )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,135,1,95,1,100,8,28,5,120,80,
		1,36,137,1,176,32,0,48,14,0,102,112,0,12,
		1,121,15,29,150,0,36,138,1,95,1,28,62,36,
		139,1,176,113,0,120,100,100,9,9,100,100,100,100,
		100,100,100,100,100,9,100,9,9,9,9,100,100,100,
		100,100,100,100,9,100,9,9,100,100,100,100,100,100,
		100,100,100,9,100,100,100,100,100,100,100,12,48,80,
		2,25,60,36,141,1,176,113,0,9,100,100,9,9,
		100,100,100,100,100,100,100,100,100,9,100,9,9,9,
		9,100,100,100,100,100,100,100,9,100,9,9,100,100,
		100,100,100,100,100,100,100,9,100,100,100,100,100,100,
		100,12,48,80,2,36,143,1,176,114,0,48,14,0,
		102,112,0,20,1,36,144,1,176,115,0,20,0,36,
		147,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( GENMENUITEMS )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,155,1,122,165,80,2,26,177,0,36,
		156,1,176,116,0,48,117,0,95,1,95,2,1,112,
		0,100,9,100,100,100,100,100,100,100,100,9,100,100,
		9,100,9,9,100,100,100,100,100,100,100,100,100,9,
		9,100,100,100,100,100,100,100,100,9,9,9,100,100,
		100,100,9,9,9,20,47,36,157,1,176,32,0,48,
		14,0,95,1,95,2,1,112,0,12,1,121,15,28,
		84,36,158,1,176,113,0,9,100,100,9,9,100,100,
		100,100,100,100,100,100,100,9,100,9,9,9,9,100,
		100,100,100,100,100,100,9,100,9,9,100,100,100,100,
		100,100,100,100,100,9,100,100,100,100,100,100,100,20,
		48,36,159,1,176,114,0,48,14,0,95,1,95,2,
		1,112,0,20,1,36,160,1,176,115,0,20,0,36,
		155,1,175,2,0,176,32,0,95,1,12,1,15,29,
		74,255,36,164,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_GETSELECTED )
{
	static const HB_BYTE pcode[] =
	{
		36,170,1,176,118,0,48,14,0,102,112,0,176,119,
		0,48,22,0,102,112,0,12,1,20,2,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_GETITEM )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,176,1,176,118,0,48,14,0,102,112,
		0,95,1,20,2,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_GETITEMPOS )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,182,1,176,110,0,48,14,0,102,112,
		0,89,15,0,1,0,1,0,1,0,95,1,95,255,
		8,6,20,2,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_GOBOTTOM )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,190,1,48,107,0,102,89,15,0,1,
		0,1,0,1,0,95,1,80,255,9,6,112,1,73,
		36,191,1,48,33,0,102,95,1,112,1,73,36,193,
		1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_GOPREV )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,201,1,48,15,0,102,112,0,165,80,
		1,100,69,28,93,36,203,1,48,107,0,102,89,48,
		0,1,0,2,0,1,0,2,0,48,28,0,95,1,
		112,0,48,28,0,95,255,112,0,69,28,6,95,1,
		80,254,48,28,0,95,1,112,0,48,28,0,95,255,
		112,0,8,6,112,1,73,36,204,1,95,2,100,69,
		28,16,36,205,1,48,33,0,102,95,2,112,1,73,
		25,12,36,207,1,48,120,0,102,112,0,73,36,211,
		1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_GONEXT )
{
	static const HB_BYTE pcode[] =
	{
		13,3,0,36,217,1,48,15,0,102,112,0,80,1,
		9,80,2,36,220,1,48,107,0,102,89,63,0,1,
		0,3,0,1,0,2,0,3,0,48,28,0,95,1,
		112,0,48,28,0,95,255,112,0,8,28,5,120,80,
		254,95,254,28,26,48,28,0,95,1,112,0,48,28,
		0,95,255,112,0,69,28,9,95,1,80,253,120,25,
		3,9,6,112,1,73,36,222,1,95,3,100,69,28,
		16,36,223,1,48,33,0,102,95,3,112,1,73,25,
		12,36,225,1,48,121,0,102,112,0,73,36,228,1,
		100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_HITTEST )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,236,1,176,122,0,48,22,0,102,112,
		0,95,1,95,2,12,3,80,3,36,238,1,95,3,
		121,15,28,15,36,239,1,48,123,0,102,95,3,112,
		1,110,7,36,242,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_NOTIFY )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,248,1,176,124,0,95,2,12,1,80,
		3,36,251,1,95,3,93,106,254,8,28,58,36,252,
		1,176,96,0,48,125,0,102,112,0,12,1,32,128,
		0,36,253,1,176,126,0,95,2,12,1,92,2,8,
		28,112,36,254,1,48,36,0,48,125,0,102,112,0,
		176,127,0,95,2,12,1,112,1,73,25,88,36,2,
		2,95,3,93,102,254,8,28,34,36,3,2,48,128,
		0,102,176,129,0,48,22,0,102,112,0,93,15,17,
		121,121,12,4,112,1,73,36,4,2,121,110,7,36,
		6,2,95,3,93,101,254,8,28,34,36,7,2,48,
		130,0,102,176,131,0,48,132,0,102,112,0,12,1,
		112,1,73,36,8,2,48,128,0,102,100,112,1,73,
		36,12,2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_SCAN )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,18,2,176,112,0,48,14,0,102,112,
		0,95,1,20,2,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_SETIMAGELIST )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,24,2,48,133,0,102,95,1,112,1,
		73,36,26,2,176,134,0,48,22,0,102,112,0,48,
		135,0,95,1,112,0,121,20,3,36,28,2,100,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_SWAPDOWN )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,34,2,48,15,0,102,112,0,80,1,
		48,70,0,95,1,112,0,80,2,36,36,2,48,136,
		0,102,112,0,73,36,37,2,48,137,0,95,1,112,
		0,73,36,38,2,48,33,0,102,48,138,0,102,48,
		15,0,102,112,0,95,2,112,2,112,1,73,36,40,
		2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_SWAPUP )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,46,2,48,15,0,102,112,0,80,1,
		48,70,0,95,1,112,0,80,2,36,48,2,48,139,
		0,102,112,0,73,36,49,2,48,139,0,102,112,0,
		73,36,50,2,48,137,0,95,1,112,0,73,36,51,
		2,48,33,0,102,48,138,0,102,48,15,0,102,112,
		0,95,2,112,2,112,1,73,36,53,2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_HANDLEEVENT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,62,2,95,1,93,2,1,8,28,18,
		36,63,2,95,2,92,13,8,28,8,36,64,2,122,
		110,7,36,68,2,48,140,0,48,43,0,102,112,0,
		95,1,95,2,95,3,112,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TTREEVIEW_SETITEMS )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,76,2,122,165,80,2,25,23,36,77,
		2,48,69,0,102,95,1,95,2,1,112,1,73,36,
		76,2,175,2,0,176,32,0,95,1,12,1,15,28,
		227,36,80,2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SEARCHITEM )
{
	static const HB_BYTE pcode[] =
	{
		13,2,2,36,88,2,122,165,80,3,25,92,36,89,
		2,176,32,0,48,14,0,95,1,95,3,1,112,0,
		12,1,121,15,28,36,36,90,2,176,118,0,48,14,
		0,95,1,95,3,1,112,0,95,2,12,2,165,80,
		4,100,69,28,9,36,91,2,95,4,110,7,36,94,
		2,48,28,0,95,1,95,3,1,112,0,95,2,8,
		28,12,36,95,2,95,1,95,3,1,110,7,36,88,
		2,175,3,0,176,32,0,95,1,12,1,15,28,158,
		36,99,2,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,143,0,3,0,116,143,0,4,0,0,82,1,0,
		100,82,2,0,7
	};

	hb_vmExecute( pcode, symbols );
}

