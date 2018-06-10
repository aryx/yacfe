#ifndef YY_FrontiereParser_h_included
#define YY_FrontiereParser_h_included

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
#line 21 "../include/FrontiereParser.h"
#define YY_FrontiereParser_LSP_NEEDED 
#define YY_FrontiereParser_ERROR_BODY  =0
#define YY_FrontiereParser_LEX_BODY  =0
#define YY_FrontiereParser_LTYPE  yyltype1
#define YY_FrontiereParser_MEMBERS  \
   public: \
      list<Frontiere*> *_listFrontiere;
#line 30 "FrontiereParser.y"

#include "CommunFichiers.h"

#include "Figures.h"

#include "Frontiere.h"

#include <list>
  // gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
  // un autre truc serai de modifier les sources du template file de  bison++
  // mais c'est porc aussi.
typedef
  struct yyltype1
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype1;


#line 57 "FrontiereParser.y"
typedef union {
  int                  entier;

  Frontiere::TypeParoi typ;
  Forme                *forme;
  list<Frontiere*>*  vecfront;
  Frontiere*           front;
  Ligne*               ligne;
  list<Ligne*>*      vecligne;
} yy_FrontiereParser_stype;
#define YY_FrontiereParser_STYPE yy_FrontiereParser_stype

#line 14 "/tmp/bison++/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_FrontiereParser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_FrontiereParser_COMPATIBILITY 1
#else
#define  YY_FrontiereParser_COMPATIBILITY 0
#endif
#endif

#if YY_FrontiereParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_FrontiereParser_LTYPE
#define YY_FrontiereParser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_FrontiereParser_STYPE 
#define YY_FrontiereParser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_FrontiereParser_DEBUG
#define  YY_FrontiereParser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_FrontiereParser_STYPE
#ifndef yystype
#define yystype YY_FrontiereParser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_FrontiereParser_USE_GOTO
#define YY_FrontiereParser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_FrontiereParser_USE_GOTO
#define YY_FrontiereParser_USE_GOTO 0
#endif

#ifndef YY_FrontiereParser_PURE

/* #line 63 "/tmp/bison++/lib/bison.h" */
#line 119 "../include/FrontiereParser.h"

#line 63 "/tmp/bison++/lib/bison.h"
/* YY_FrontiereParser_PURE */
#endif

/* #line 65 "/tmp/bison++/lib/bison.h" */
#line 126 "../include/FrontiereParser.h"

#line 65 "/tmp/bison++/lib/bison.h"
/* prefix */
#ifndef YY_FrontiereParser_DEBUG

/* #line 67 "/tmp/bison++/lib/bison.h" */
#line 133 "../include/FrontiereParser.h"

#line 67 "/tmp/bison++/lib/bison.h"
/* YY_FrontiereParser_DEBUG */
#endif
#ifndef YY_FrontiereParser_LSP_NEEDED

/* #line 70 "/tmp/bison++/lib/bison.h" */
#line 141 "../include/FrontiereParser.h"

#line 70 "/tmp/bison++/lib/bison.h"
 /* YY_FrontiereParser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_FrontiereParser_LSP_NEEDED
#ifndef YY_FrontiereParser_LTYPE
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

#define YY_FrontiereParser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_FrontiereParser_STYPE
#define YY_FrontiereParser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_FrontiereParser_PARSE
#define YY_FrontiereParser_PARSE yyparse
#endif
#ifndef YY_FrontiereParser_LEX
#define YY_FrontiereParser_LEX yylex
#endif
#ifndef YY_FrontiereParser_LVAL
#define YY_FrontiereParser_LVAL yylval
#endif
#ifndef YY_FrontiereParser_LLOC
#define YY_FrontiereParser_LLOC yylloc
#endif
#ifndef YY_FrontiereParser_CHAR
#define YY_FrontiereParser_CHAR yychar
#endif
#ifndef YY_FrontiereParser_NERRS
#define YY_FrontiereParser_NERRS yynerrs
#endif
#ifndef YY_FrontiereParser_DEBUG_FLAG
#define YY_FrontiereParser_DEBUG_FLAG yydebug
#endif
#ifndef YY_FrontiereParser_ERROR
#define YY_FrontiereParser_ERROR yyerror
#endif

#ifndef YY_FrontiereParser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_FrontiereParser_PARSE_PARAM
#ifndef YY_FrontiereParser_PARSE_PARAM_DEF
#define YY_FrontiereParser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_FrontiereParser_PARSE_PARAM
#define YY_FrontiereParser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_FrontiereParser_PURE
extern YY_FrontiereParser_STYPE YY_FrontiereParser_LVAL;
#endif


/* #line 143 "/tmp/bison++/lib/bison.h" */
#line 219 "../include/FrontiereParser.h"
#define	CLASSIQUE	258
#define	GENERATRICE	259
#define	ENTETEFRONTIERE	260
#define	LIGNE	261
#define	RECTANGLE	262
#define	ELLIPSE	263
#define	ARCELLIPSE	264
#define	POLYGONE	265
#define	NBR	266
#define	TOK_BAD	267


#line 143 "/tmp/bison++/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_FrontiereParser_CLASS
#define YY_FrontiereParser_CLASS FrontiereParser
#endif

#ifndef YY_FrontiereParser_INHERIT
#define YY_FrontiereParser_INHERIT
#endif
#ifndef YY_FrontiereParser_MEMBERS
#define YY_FrontiereParser_MEMBERS 
#endif
#ifndef YY_FrontiereParser_LEX_BODY
#define YY_FrontiereParser_LEX_BODY  
#endif
#ifndef YY_FrontiereParser_ERROR_BODY
#define YY_FrontiereParser_ERROR_BODY  
#endif
#ifndef YY_FrontiereParser_CONSTRUCTOR_PARAM
#define YY_FrontiereParser_CONSTRUCTOR_PARAM
#endif
/* choose between enum and const */
#ifndef YY_FrontiereParser_USE_CONST_TOKEN
#define YY_FrontiereParser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */
#endif
#if YY_FrontiereParser_USE_CONST_TOKEN != 0
#ifndef YY_FrontiereParser_ENUM_TOKEN
#define YY_FrontiereParser_ENUM_TOKEN yy_FrontiereParser_enum_token
#endif
#endif

class YY_FrontiereParser_CLASS YY_FrontiereParser_INHERIT
{
public:
#if YY_FrontiereParser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 182 "/tmp/bison++/lib/bison.h" */
#line 274 "../include/FrontiereParser.h"
static const int CLASSIQUE;
static const int GENERATRICE;
static const int ENTETEFRONTIERE;
static const int LIGNE;
static const int RECTANGLE;
static const int ELLIPSE;
static const int ARCELLIPSE;
static const int POLYGONE;
static const int NBR;
static const int TOK_BAD;


#line 182 "/tmp/bison++/lib/bison.h"
 /* decl const */
#else
enum YY_FrontiereParser_ENUM_TOKEN { YY_FrontiereParser_NULL_TOKEN=0

/* #line 185 "/tmp/bison++/lib/bison.h" */
#line 293 "../include/FrontiereParser.h"
	,CLASSIQUE=258
	,GENERATRICE=259
	,ENTETEFRONTIERE=260
	,LIGNE=261
	,RECTANGLE=262
	,ELLIPSE=263
	,ARCELLIPSE=264
	,POLYGONE=265
	,NBR=266
	,TOK_BAD=267


#line 185 "/tmp/bison++/lib/bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_FrontiereParser_PARSE(YY_FrontiereParser_PARSE_PARAM);
 virtual void YY_FrontiereParser_ERROR(char *msg) YY_FrontiereParser_ERROR_BODY;
#ifdef YY_FrontiereParser_PURE
#ifdef YY_FrontiereParser_LSP_NEEDED
 virtual int  YY_FrontiereParser_LEX(YY_FrontiereParser_STYPE *YY_FrontiereParser_LVAL,YY_FrontiereParser_LTYPE *YY_FrontiereParser_LLOC) YY_FrontiereParser_LEX_BODY;
#else
 virtual int  YY_FrontiereParser_LEX(YY_FrontiereParser_STYPE *YY_FrontiereParser_LVAL) YY_FrontiereParser_LEX_BODY;
#endif
#else
 virtual int YY_FrontiereParser_LEX() YY_FrontiereParser_LEX_BODY;
 YY_FrontiereParser_STYPE YY_FrontiereParser_LVAL;
#ifdef YY_FrontiereParser_LSP_NEEDED
 YY_FrontiereParser_LTYPE YY_FrontiereParser_LLOC;
#endif
 int YY_FrontiereParser_NERRS;
 int YY_FrontiereParser_CHAR;
#endif
#if YY_FrontiereParser_DEBUG != 0
public:
 int YY_FrontiereParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_FrontiereParser_CLASS(YY_FrontiereParser_CONSTRUCTOR_PARAM);
public:
 YY_FrontiereParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_FrontiereParser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_FrontiereParser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_FrontiereParser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_FrontiereParser_DEBUG 
#define YYDEBUG YY_FrontiereParser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "/tmp/bison++/lib/bison.h" */
#line 360 "../include/FrontiereParser.h"
#endif
