//////////////////////////////////////////////////////////////////////////////
// Programa: debug.prg
// Fecha Creaci�n: 05/18/2006
// Hora: 23:03
// Proyecto en xMate: debug
// Lista de funciones:
// Ultima modificaci�n :>: 04/17/2012 12:31
// Historico: >>:
// 04/17/12
// 08/01/11
// 09/11/06
// 07/25/06-07/27/06
// 05/18/06
//////////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------

#include "SET.CH"

#define CRLF chr(13)+chr(10)

STATIC row_counter := 0

*-----------------------------------------------------------------------------*

function _trace(c)

   local cn

   if valtype(c)=='C'
     cn:=c //:classname()
   endif

   OutputDebugString(if(empty(cn),'',cn+':')+procname(1)+'('+alltrim(str(procline(1)))+')'+;
   ' <- '+procname(2)+'('+alltrim(str(procline(2)))+')'+;
   ' <- '+procname(3)+'('+alltrim(str(procline(3)))+')'+;
   ' <- '+procname(4)+'('+alltrim(str(procline(4)))+')'+;
   ' <- '+procname(5)+'('+alltrim(str(procline(5)))+')'+;
   CRLF)

   return(NIL)

*------------------------------------------------------------------------------*
* goos Hace una linea divisoria
*------------------------------------------------------------------------------*

FUNCTION L_DVIEW
   OutputDebugString( '*------------------------------------------------------------------------------*' + CRLF )
//   OutputDebugString( '**********************************************************************' + CRLF + CRLF )

RETURN ( NIL )

*------------------------------------------------------------------------------*
* limpia el visor del debubview
*------------------------------------------------------------------------------*

FUNCTION _DVCLEAR
   OutputDebugString("DBGVIEWCLEAR")
   RETURN NIL


//------------------------------------------------------------------------------
// solo muestra lo que se envia.
//------------------------------------------------------------------------------

FUNCTION _DVSIMPLE
   PARAM p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18

   LOCAL no_of_param, x, dbg_array, half
   LOCAL t_call_status

   no_of_param := PCOUNT( )
   half := no_of_param / 2

   L_DVIEW()

   BEGIN SEQUENCE
      FOR x := 1 TO half
         dbg_array = "p" + lTrim( STR( x, 2, 0 ) )
         OutputDebugString( &dbg_array)
      NEXT
   END

   RETURN NIL

*------------------------------------------------------------------------------*
* PARAM is used here on purpose to allow for macro expansion of the
* parameters which are passed here as private !!!!!!!!!
*------------------------------------------------------------------------------*
FUNCTION _DVIEW
   PARAM p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18

   LOCAL no_of_param, x, dbg_array, description, half
   LOCAL t_call_status

   no_of_param := PCOUNT( )
   half := no_of_param / 2

   L_DVIEW()

   BEGIN SEQUENCE
      FOR x := 1 TO half
         dbg_array = "p" + lTrim( STR( x, 2, 0 ) )
         description = "p" + lTrim( STR( x + half, 2, 0 ) )
         DLIST( &dbg_array, &description )
      NEXT
   END
   RETURN NIL

*------------------------------------------------------------------------------*
STATIC FUNCTION DLIST( dbg_array, description )
*------------------------------------------------------------------------------*
   LOCAL heading, x, a_len, data_type, value

   IF ValType( dbg_array ) $ 'AOS'
         a_len = Len( dbg_array )
         DQOUT( '     Array:', description, '', IF( a_len == 0, {}, dbg_array ) , Len( dbg_array ) )
         FOR x := 1 TO a_len
            heading := description + "[" + STR( x, 3, 0 ) + "]"
            data_type := ValType( dbg_array[ x] )
            value := dbg_array[ x]
            DSINGLE_VIEW( heading, data_type, value )
         NEXT
   ELSE
      heading := description
      data_type := ValType( dbg_array )
      value := dbg_array
      DSINGLE_VIEW( heading, data_type, value )
   ENDIF
   RETURN NIL

*------------------------------------------------------------------------------*
STATIC FUNCTION DSINGLE_VIEW( heading, data_type, value )
*------------------------------------------------------------------------------*
   DO CASE
   CASE data_type == "A"
      DLIST( value, heading )
   CASE data_type == "B"
      DQOUT( "Code Block:", heading, " => ", value )
   CASE data_type == "C"
      DQOUT( " Character:", heading, " => ", value, .T. )
   CASE data_type == "D"
      DQOUT( "      Date:", heading, " => ", value )
   CASE data_type == "L"
      DQOUT( "   Logical:", heading, " => ", value )
   CASE data_type == "M"
      DQOUT( "      Memo:", heading, " => ", value )
   CASE data_type == "N"
      DQOUT( "   Numeric:", heading, " => ", value )
   CASE data_type == "O"
      OutputDebugString( "  Object vv" +CRLF) // arrows don't show in Windows
      DLIST( value, heading )
      OutputDebugString( "  Object ^^" +CRLF) // arrows don't show in windows
   CASE data_type == "U"
      DQOUT( "Undefinded:", heading, " => ", value )
   OTHERWISE
      OutputDebugString( "Unknown data type returned by VALTYPE()" +CRLF)
   ENDCASE
   RETURN NIL

*------------------------------------------------------------------------------*
STATIC FUNCTION DQOUT( a, b, c, d, show_len )
*------------------------------------------------------------------------------*
   LOCAL e := ''

   IF ValType( show_len ) == 'L' .AND. show_len
      e := ' (' + LEFT(ALLTRIM(a),1)+ ALLTRIM(STR( Len( d ) , 4, 0 ))+')'
   ELSEIF ValType( show_len ) == 'N'
         e := ' ('+ LEFT(ALLTRIM(a),1) + AllTrim( STR( show_len, 10, 0 ) )+')'
   ELSE
     e:=' ('+LEFT(ALLTRIM(a),1)+')'
   ENDIF
   OutputDebugString( b + e + c + asstring( d ) +CRLF)
   RETURN NIL

*-----------------------------------------------------------------------------*
STATIC FUNCTION asString( x )
   local v := ValType( x )

   DO CASE
   CASE v == "C"
      RETURN '"' + x + '"'
   CASE v $ "NP"
      RETURN AllTrim( str( x ) )
   CASE v == "L"
      IF x
         RETURN ".T."
      ELSE
         RETURN ".F."
      ENDIF
   CASE v == "D"
      RETURN dtoc( x )
   CASE v == "U"
      RETURN "NIL"
   CASE v == "A"
      IF Len( x) == 0
         RETURN " => {}"
      ELSE
         RETURN "<Array>"
      ENDIF
   CASE v == "O"
      RETURN "<Object " + x:classname( ) + ">"
   CASE v == "B"
      RETURN "<Block>"
   OTHERWISE
      RETURN ""
   END CASE

   RETURN( x )








