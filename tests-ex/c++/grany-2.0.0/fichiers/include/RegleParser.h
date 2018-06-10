#ifndef YY_RegleParser_h_included
#define YY_RegleParser_h_included

#line 1 "/tmp/bison++/lib/bison.h"
/* before anything */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#endif
#include <stdio.h>

/* #line 14 "/tmp/bison++/lib/bison.h" */
#line 21 "../include/RegleParser.h"
#define YY_RegleParser_LSP_NEEDED 
#define YY_RegleParser_ERROR_BODY  =0
#define YY_RegleParser_LEX_BODY  =0
#define YY_RegleParser_LTYPE  yyltype2
#define YY_RegleParser_MEMBERS  \
   public: \
       RegleExclusion * _regle;
#line 33 "RegleParser.y"

#include "CommunFichiers.h"

#include "RegleExclusion.h"

  // gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
  // un autre truc serai de modifier les sources du template file de  bison++
  // mais c'est porc aussi.
typedef
  struct yyltype2
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype2;



#line 58 "RegleParser.y"
typedef union {
  int                         entier;
  char*                       Nom;

  RegleExclusion::Contrainte  contr;
  RegleExclusion::Deplacement depl;
  RegleExclusion*             regle;
} yy_RegleParser_stype;
#define YY_RegleParser_STYPE yy_RegleParser_stype

#line 14 "/tmp/bison++/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_RegleParser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_RegleParser_COMPATIBILITY 1
#else
#define  YY_RegleParser_COMPATIBILITY 0
#endif
#endif

#if YY_RegleParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_RegleParser_LTYPE
#define YY_RegleParser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_RegleParser_STYPE 
#define YY_RegleParser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_RegleParser_DEBUG
#define  YY_RegleParser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_RegleParser_STYPE
#ifndef yystype
#define yystype YY_RegleParser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_RegleParser_USE_GOTO
#define YY_RegleParser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_RegleParser_USE_GOTO
#define YY_RegleParser_USE_GOTO 0
#endif

#ifndef YY_RegleParser_PURE

/* #line 63 "/tmp/bison++/lib/bison.h" */
#line 115 "../include/RegleParser.h"

#line 63 "/tmp/bison++/lib/bison.h"
/* YY_RegleParser_PURE */
#endif

/* #line 65 "/tmp/bison++/lib/bison.h" */
#line 122 "../include/RegleParser.h"

#line 65 "/tmp/bison++/lib/bison.h"
/* prefix */
#ifndef YY_RegleParser_DEBUG

/* #line 67 "/tmp/bison++/lib/bison.h" */
#line 129 "../include/RegleParser.h"

#line 67 "/tmp/bison++/lib/bison.h"
/* YY_RegleParser_DEBUG */
#endif
#ifndef YY_RegleParser_LSP_NEEDED

/* #line 70 "/tmp/bison++/lib/bison.h" */
#line 137 "../include/RegleParser.h"

#line 70 "/tmp/bison++/lib/bison.h"
 /* YY_RegleParser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_RegleParser_LSP_NEEDED
#ifndef YY_RegleParser_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_RegleParser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_RegleParser_STYPE
#define YY_RegleParser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_RegleParser_PARSE
#define YY_RegleParser_PARSE yyparse
#endif
#ifndef YY_RegleParser_LEX
#define YY_RegleParser_LEX yylex
#endif
#ifndef YY_RegleParser_LVAL
#define YY_RegleParser_LVAL yylval
#endif
#ifndef YY_RegleParser_LLOC
#define YY_RegleParser_LLOC yylloc
#endif
#ifndef YY_RegleParser_CHAR
#define YY_RegleParser_CHAR yychar
#endif
#ifndef YY_RegleParser_NERRS
#define YY_RegleParser_NERRS yynerrs
#endif
#ifndef YY_RegleParser_DEBUG_FLAG
#define YY_RegleParser_DEBUG_FLAG yydebug
#endif
#ifndef YY_RegleParser_ERROR
#define YY_RegleParser_ERROR yyerror
#endif

#ifndef YY_RegleParser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_RegleParser_PARSE_PARAM
#ifndef YY_RegleParser_PARSE_PARAM_DEF
#define YY_RegleParser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_RegleParser_PARSE_PARAM
#define YY_RegleParser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_RegleParser_PURE
extern YY_RegleParser_STYPE YY_RegleParser_LVAL;
#endif


/* #line 143 "/tmp/bison++/lib/bison.h" */
#line 215 "../include/RegleParser.h"
#define	NOM	258
#define	ENTETEREGLE	259
#define	CNULLE	260
#define	CMEMPHI	261
#define	CPHIINFERIEUR	262
#define	CPHIINFSOLIDE	263
#define	REGLES	264
#define	Depl_IMPOSSIBLE	265
#define	Depl_POSSIBLE	266
#define	TOK_BAD	267


#line 143 "/tmp/bison++/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_RegleParser_CLASS
#define YY_RegleParser_CLASS RegleParser
#endif

#ifndef YY_RegleParser_INHERIT
#define YY_RegleParser_INHERIT
#endif
#ifndef YY_RegleParser_MEMBERS
#define YY_RegleParser_MEMBERS 
#endif
#ifndef YY_RegleParser_LEX_BODY
#define YY_RegleParser_LEX_BODY  
#endif
#ifndef YY_RegleParser_ERROR_BODY
#define YY_RegleParser_ERROR_BODY  
#endif
#ifndef YY_RegleParser_CONSTRUCTOR_PARAM
#define YY_RegleParser_CONSTRUCTOR_PARAM
#endif
/* choose between enum and const */
#ifndef YY_RegleParser_USE_CONST_TOKEN
#define YY_RegleParser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */
#endif
#if YY_RegleParser_USE_CONST_TOKEN != 0
#ifndef YY_RegleParser_ENUM_TOKEN
#define YY_RegleParser_ENUM_TOKEN yy_RegleParser_enum_token
#endif
#endif

class YY_RegleParser_CLASS YY_RegleParser_INHERIT
{
public:
#if YY_RegleParser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 182 "/tmp/bison++/lib/bison.h" */
#line 270 "../include/RegleParser.h"
static const int NOM;
static const int ENTETEREGLE;
static const int CNULLE;
static const int CMEMPHI;
static const int CPHIINFERIEUR;
static const int CPHIINFSOLIDE;
static const int REGLES;
static const int Depl_IMPOSSIBLE;
static const int Depl_POSSIBLE;
static const int TOK_BAD;


#line 182 "/tmp/bison++/lib/bison.h"
 /* decl const */
#else
enum YY_RegleParser_ENUM_TOKEN { YY_RegleParser_NULL_TOKEN=0

/* #line 185 "/tmp/bison++/lib/bison.h" */
#line 289 "../include/RegleParser.h"
	,NOM=258
	,ENTETEREGLE=259
	,CNULLE=260
	,CMEMPHI=261
	,CPHIINFERIEUR=262
	,CPHIINFSOLIDE=263
	,REGLES=264
	,Depl_IMPOSSIBLE=265
	,Depl_POSSIBLE=266
	,TOK_BAD=267


#line 185 "/tmp/bison++/lib/bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_RegleParser_PARSE(YY_RegleParser_PARSE_PARAM);
 virtual void YY_RegleParser_ERROR(char *msg) YY_RegleParser_ERROR_BODY;
#ifdef YY_RegleParser_PURE
#ifdef YY_RegleParser_LSP_NEEDED
 virtual int  YY_RegleParser_LEX(YY_RegleParser_STYPE *YY_RegleParser_LVAL,YY_RegleParser_LTYPE *YY_RegleParser_LLOC) YY_RegleParser_LEX_BODY;
#else
 virtual int  YY_RegleParser_LEX(YY_RegleParser_STYPE *YY_RegleParser_LVAL) YY_RegleParser_LEX_BODY;
#endif
#else
 virtual int YY_RegleParser_LEX() YY_RegleParser_LEX_BODY;
 YY_RegleParser_STYPE YY_RegleParser_LVAL;
#ifdef YY_RegleParser_LSP_NEEDED
 YY_RegleParser_LTYPE YY_RegleParser_LLOC;
#endif
 int YY_RegleParser_NERRS;
 int YY_RegleParser_CHAR;
#endif
#if YY_RegleParser_DEBUG != 0
public:
 int YY_RegleParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_RegleParser_CLASS(YY_RegleParser_CONSTRUCTOR_PARAM);
public:
 YY_RegleParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_RegleParser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_RegleParser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_RegleParser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_RegleParser_DEBUG 
#define YYDEBUG YY_RegleParser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "/tmp/bison++/lib/bison.h" */
#line 356 "../include/RegleParser.h"
#endif
