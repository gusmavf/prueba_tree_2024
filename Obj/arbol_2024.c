/*
 * Harbour 3.2.0dev (r2104281802)
 * Microsoft Visual C 19.30.30706 (64-bit)
 * Generated C source from "Source\arbol_2024.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( MAIN );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_ARBOL_2024 )
{ "MAIN", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( MAIN )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_ARBOL_2024, "Source\\arbol_2024.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_ARBOL_2024
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_ARBOL_2024 )
   #include "hbiniseg.h"
#endif

HB_FUNC( MAIN )
{
	static const HB_BYTE pcode[] =
	{
		36,20,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,3,0,2,0,116,3,0,4,0,0,82,1,0,
		100,82,2,0,7
	};

	hb_vmExecute( pcode, symbols );
}

