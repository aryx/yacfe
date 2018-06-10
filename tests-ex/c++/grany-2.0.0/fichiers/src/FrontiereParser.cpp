#define YY_FrontiereParser_h_included

/*  A Bison++ parser, made from FrontiereParser.y  */

 /* with Bison++ version bison++ Version 1.21-7, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "/tmp/bison++/lib/bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* HEADER SECTION */
#ifndef _MSDOS
#ifdef MSDOS
#define _MSDOS
#endif
#endif
/* turboc */
#ifdef __MSDOS__
#ifndef _MSDOS
#define _MSDOS
#endif
#endif

#ifndef alloca
#if defined( __GNUC__)
#define alloca __builtin_alloca

#elif (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)  || defined (__sgi)
#include <alloca.h>

#elif defined (_MSDOS)
#include <malloc.h>
#ifndef __TURBOC__
/* MS C runtime lib */
#define alloca _alloca
#endif

#elif defined(_AIX)
#include <malloc.h>
#pragma alloca

#elif defined(__hpux)
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */

#endif /* not _AIX  not MSDOS, or __TURBOC__ or _AIX, not sparc.  */
#endif /* alloca not defined.  */
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
#ifndef __STDC__
#define const
#endif
#endif
#include <stdio.h>
#define YYBISON 1  

/* #line 77 "/tmp/bison++/lib/bison.cc" */
#line 89 "FrontiereParser.cpp"
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

#line 77 "/tmp/bison++/lib/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_FrontiereParser_BISON 1
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
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_FrontiereParser_STYPE 
#define YY_FrontiereParser_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_FrontiereParser_DEBUG
#define  YY_FrontiereParser_DEBUG YYDEBUG
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

/* #line 121 "/tmp/bison++/lib/bison.cc" */
#line 182 "FrontiereParser.cpp"

#line 121 "/tmp/bison++/lib/bison.cc"
/*  YY_FrontiereParser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 125 "/tmp/bison++/lib/bison.cc" */
#line 191 "FrontiereParser.cpp"

#line 125 "/tmp/bison++/lib/bison.cc"
/* prefix */
#ifndef YY_FrontiereParser_DEBUG

/* #line 127 "/tmp/bison++/lib/bison.cc" */
#line 198 "FrontiereParser.cpp"

#line 127 "/tmp/bison++/lib/bison.cc"
/* YY_FrontiereParser_DEBUG */
#endif


#ifndef YY_FrontiereParser_LSP_NEEDED

/* #line 132 "/tmp/bison++/lib/bison.cc" */
#line 208 "FrontiereParser.cpp"

#line 132 "/tmp/bison++/lib/bison.cc"
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
      /* We used to use `unsigned long' as YY_FrontiereParser_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

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
#if YY_FrontiereParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_FrontiereParser_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_FrontiereParser_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_FrontiereParser_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_FrontiereParser_PURE
#ifndef YYPURE
#define YYPURE YY_FrontiereParser_PURE
#endif
#endif
#ifdef YY_FrontiereParser_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_FrontiereParser_DEBUG 
#endif
#endif
#ifndef YY_FrontiereParser_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_FrontiereParser_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_FrontiereParser_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_FrontiereParser_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 240 "/tmp/bison++/lib/bison.cc" */
#line 321 "FrontiereParser.cpp"
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


#line 240 "/tmp/bison++/lib/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
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
#ifndef YY_FrontiereParser_CONSTRUCTOR_CODE
#define YY_FrontiereParser_CONSTRUCTOR_CODE
#endif
#ifndef YY_FrontiereParser_CONSTRUCTOR_INIT
#define YY_FrontiereParser_CONSTRUCTOR_INIT
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

/* #line 284 "/tmp/bison++/lib/bison.cc" */
#line 381 "FrontiereParser.cpp"
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


#line 284 "/tmp/bison++/lib/bison.cc"
 /* decl const */
#else
enum YY_FrontiereParser_ENUM_TOKEN { YY_FrontiereParser_NULL_TOKEN=0

/* #line 287 "/tmp/bison++/lib/bison.cc" */
#line 400 "FrontiereParser.cpp"
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


#line 287 "/tmp/bison++/lib/bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_FrontiereParser_PARSE (YY_FrontiereParser_PARSE_PARAM);
 virtual void YY_FrontiereParser_ERROR(char *msg) YY_FrontiereParser_ERROR_BODY;
#ifdef YY_FrontiereParser_PURE
#ifdef YY_FrontiereParser_LSP_NEEDED
 virtual int  YY_FrontiereParser_LEX (YY_FrontiereParser_STYPE *YY_FrontiereParser_LVAL,YY_FrontiereParser_LTYPE *YY_FrontiereParser_LLOC) YY_FrontiereParser_LEX_BODY;
#else
 virtual int  YY_FrontiereParser_LEX (YY_FrontiereParser_STYPE *YY_FrontiereParser_LVAL) YY_FrontiereParser_LEX_BODY;
#endif
#else
 virtual int YY_FrontiereParser_LEX() YY_FrontiereParser_LEX_BODY;
 YY_FrontiereParser_STYPE YY_FrontiereParser_LVAL;
#ifdef YY_FrontiereParser_LSP_NEEDED
 YY_FrontiereParser_LTYPE YY_FrontiereParser_LLOC;
#endif
 int   YY_FrontiereParser_NERRS;
 int    YY_FrontiereParser_CHAR;
#endif
#if YY_FrontiereParser_DEBUG != 0
 int YY_FrontiereParser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_FrontiereParser_CLASS(YY_FrontiereParser_CONSTRUCTOR_PARAM);
public:
 YY_FrontiereParser_MEMBERS 
};
/* other declare folow */
#if YY_FrontiereParser_USE_CONST_TOKEN != 0

/* #line 318 "/tmp/bison++/lib/bison.cc" */
#line 447 "FrontiereParser.cpp"
const int YY_FrontiereParser_CLASS::CLASSIQUE=258;
const int YY_FrontiereParser_CLASS::GENERATRICE=259;
const int YY_FrontiereParser_CLASS::ENTETEFRONTIERE=260;
const int YY_FrontiereParser_CLASS::LIGNE=261;
const int YY_FrontiereParser_CLASS::RECTANGLE=262;
const int YY_FrontiereParser_CLASS::ELLIPSE=263;
const int YY_FrontiereParser_CLASS::ARCELLIPSE=264;
const int YY_FrontiereParser_CLASS::POLYGONE=265;
const int YY_FrontiereParser_CLASS::NBR=266;
const int YY_FrontiereParser_CLASS::TOK_BAD=267;


#line 318 "/tmp/bison++/lib/bison.cc"
 /* const YY_FrontiereParser_CLASS::token */
#endif
/*apres const  */
YY_FrontiereParser_CLASS::YY_FrontiereParser_CLASS(YY_FrontiereParser_CONSTRUCTOR_PARAM) YY_FrontiereParser_CONSTRUCTOR_INIT
{
#if YY_FrontiereParser_DEBUG != 0
YY_FrontiereParser_DEBUG_FLAG=0;
#endif
YY_FrontiereParser_CONSTRUCTOR_CODE;
};
#endif

/* #line 329 "/tmp/bison++/lib/bison.cc" */
#line 474 "FrontiereParser.cpp"


#define	YYFINAL		78
#define	YYFLAG		-32768
#define	YYNTBASE	17

#define YYTRANSLATE(x) ((unsigned)(x) <= 267 ? yytranslate[x] : 24)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    15,
    16,     2,     2,    13,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    14,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12
};

#if YY_FrontiereParser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     8,    13,    18,    29,    40,    51,    70,
    74,    76,    87,    89
};

static const short yyrhs[] = {     5,
    18,     0,    18,    19,     0,    19,     0,    20,    13,    23,
    14,     0,    10,    15,    21,    16,     0,     6,    15,    11,
    13,    11,    13,    11,    13,    11,    16,     0,     7,    15,
    11,    13,    11,    13,    11,    13,    11,    16,     0,     8,
    15,    11,    13,    11,    13,    11,    13,    11,    16,     0,
     9,    15,    11,    13,    11,    13,    11,    13,    11,    13,
    11,    13,    11,    13,    11,    13,    11,    16,     0,    21,
    13,    22,     0,    22,     0,     6,    15,    11,    13,    11,
    13,    11,    13,    11,    16,     0,     3,     0,     4,     0
};

#endif

#if YY_FrontiereParser_DEBUG != 0
static const short yyrline[] = { 0,
    87,    93,    94,    97,   100,   102,   104,   106,   108,   113,
   114,   117,   121,   122
};

static const char * const yytname[] = {   "$","error","$illegal.","CLASSIQUE",
"GENERATRICE","ENTETEFRONTIERE","LIGNE","RECTANGLE","ELLIPSE","ARCELLIPSE","POLYGONE",
"NBR","TOK_BAD","','","';'","'('","')'","file","Frontieres","Frontiere","Forme",
"Lignes","Ligne","Type",""
};
#endif

static const short yyr1[] = {     0,
    17,    18,    18,    19,    20,    20,    20,    20,    20,    21,
    21,    22,    23,    23
};

static const short yyr2[] = {     0,
     2,     2,     1,     4,     4,    10,    10,    10,    18,     3,
     1,    10,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     0,     1,     3,     0,     0,
     0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
     0,     0,    11,    13,    14,     0,     0,     0,     0,     0,
     0,     0,     5,     4,     0,     0,     0,     0,     0,    10,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     6,     7,     8,     0,     0,     0,     0,     0,    12,     0,
     0,     0,     0,     0,     9,     0,     0,     0
};

static const short yydefgoto[] = {    76,
     7,     8,     9,    22,    23,    26
};

static const short yypact[] = {     4,
    -6,    -5,    -4,    -3,    -2,    -1,    -6,-32768,     2,     5,
     6,     7,     8,    14,-32768,     3,     9,    10,    11,    12,
    13,    -8,-32768,-32768,-32768,    15,    16,    19,    20,    21,
    22,    14,-32768,-32768,    23,    24,    25,    26,    27,-32768,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    42,    43,    44,    45,    46,    18,    47,    48,    49,    52,
-32768,-32768,-32768,    50,    55,    54,    53,    57,-32768,    58,
    59,    60,    61,    62,-32768,    74,    75,-32768
};

static const short yypgoto[] = {-32768,
-32768,    28,-32768,-32768,   -11,-32768
};


#define	YYLAST		78


static const short yytable[] = {     2,
     3,     4,     5,     6,    32,    24,    25,    33,     1,    10,
    11,    12,    13,    14,    16,    17,    18,    19,    20,    21,
    40,    27,    28,    29,    30,     0,    35,    31,    34,    36,
    37,    38,    39,    61,    15,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,     0,     0,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
    66,    64,    62,    63,    65,    67,    68,    70,    69,    72,
    71,    74,    73,    77,    78,     0,     0,    75
};

static const short yycheck[] = {     6,
     7,     8,     9,    10,    13,     3,     4,    16,     5,    15,
    15,    15,    15,    15,    13,    11,    11,    11,    11,     6,
    32,    13,    13,    13,    13,    -1,    11,    15,    14,    11,
    11,    11,    11,    16,     7,    13,    13,    13,    13,    13,
    11,    11,    11,    11,    11,    -1,    -1,    13,    13,    13,
    13,    13,    11,    11,    11,    11,    11,    -1,    -1,    -1,
    11,    13,    16,    16,    13,    11,    13,    11,    16,    11,
    13,    11,    13,     0,     0,    -1,    -1,    16
};

#line 329 "/tmp/bison++/lib/bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */ 

#if YY_FrontiereParser_USE_GOTO != 0
/*
 SUPRESSION OF GOTO : on some C++ compiler (sun c++)
  the goto is strictly forbidden if any constructor/destructor
  is used in the whole function (very stupid isn't it ?)
 so goto are to be replaced with a 'while/switch/case construct'
 here are the macro to keep some apparent compatibility
*/
#define YYGOTO(lb) {yy_gotostate=lb;continue;}
#define YYBEGINGOTO  enum yy_labels yy_gotostate=yygotostart; \
                     for(;;) switch(yy_gotostate) { case yygotostart: {
#define YYLABEL(lb) } case lb: {
#define YYENDGOTO } }
#define YYBEGINDECLARELABEL enum yy_labels {yygotostart
#define YYDECLARELABEL(lb) ,lb
#define YYENDDECLARELABEL  };
#else
/* macro to keep goto */
#define YYGOTO(lb) goto lb
#define YYBEGINGOTO
#define YYLABEL(lb) lb:
#define YYENDGOTO
#define YYBEGINDECLARELABEL
#define YYDECLARELABEL(lb)
#define YYENDDECLARELABEL
#endif
/* LABEL DECLARATION */
YYBEGINDECLARELABEL
  YYDECLARELABEL(yynewstate)
  YYDECLARELABEL(yybackup)
/* YYDECLARELABEL(yyresume) */
  YYDECLARELABEL(yydefault)
  YYDECLARELABEL(yyreduce)
  YYDECLARELABEL(yyerrlab)   /* here on detecting error */
  YYDECLARELABEL(yyerrlab1)   /* here on error raised explicitly by an action */
  YYDECLARELABEL(yyerrdefault)  /* current state does not do anything special for the error token. */
  YYDECLARELABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */
  YYDECLARELABEL(yyerrhandle)
YYENDDECLARELABEL

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_FrontiereParser_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        return(0)
#define YYABORT         return(1)
#define YYERROR         YYGOTO(yyerrlab1)
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          YYGOTO(yyerrlab)
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_FrontiereParser_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_FrontiereParser_CHAR = (token), YY_FrontiereParser_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_FrontiereParser_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_FrontiereParser_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_FrontiereParser_PURE
/* UNPURE */
#define YYLEX           YY_FrontiereParser_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_FrontiereParser_CHAR;                      /*  the lookahead symbol        */
YY_FrontiereParser_STYPE      YY_FrontiereParser_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_FrontiereParser_NERRS;                 /*  number of parse errors so far */
#ifdef YY_FrontiereParser_LSP_NEEDED
YY_FrontiereParser_LTYPE YY_FrontiereParser_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_FrontiereParser_LSP_NEEDED
#define YYLEX           YY_FrontiereParser_LEX(&YY_FrontiereParser_LVAL, &YY_FrontiereParser_LLOC)
#else
#define YYLEX           YY_FrontiereParser_LEX(&YY_FrontiereParser_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_FrontiereParser_DEBUG != 0
int YY_FrontiereParser_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif

int
#ifdef YY_USE_CLASS
 YY_FrontiereParser_CLASS::
#endif
     YY_FrontiereParser_PARSE(YY_FrontiereParser_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_FrontiereParser_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_FrontiereParser_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_FrontiereParser_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_FrontiereParser_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_FrontiereParser_LSP_NEEDED
  YY_FrontiereParser_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_FrontiereParser_LTYPE *yyls = yylsa;
  YY_FrontiereParser_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_FrontiereParser_PURE
  int YY_FrontiereParser_CHAR;
  YY_FrontiereParser_STYPE YY_FrontiereParser_LVAL;
  int YY_FrontiereParser_NERRS;
#ifdef YY_FrontiereParser_LSP_NEEDED
  YY_FrontiereParser_LTYPE YY_FrontiereParser_LLOC;
#endif
#endif

  YY_FrontiereParser_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_FrontiereParser_DEBUG != 0
  if (YY_FrontiereParser_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_FrontiereParser_NERRS = 0;
  YY_FrontiereParser_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_FrontiereParser_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
YYLABEL(yynewstate)

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_FrontiereParser_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_FrontiereParser_LSP_NEEDED
      YY_FrontiereParser_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_FrontiereParser_LSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_FrontiereParser_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_FrontiereParser_ERROR("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YY_FrontiereParser_STYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YY_FrontiereParser_LSP_NEEDED
      yyls = (YY_FrontiereParser_LTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_FrontiereParser_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_FrontiereParser_DEBUG != 0
      if (YY_FrontiereParser_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_FrontiereParser_DEBUG != 0
  if (YY_FrontiereParser_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  YYGOTO(yybackup);
YYLABEL(yybackup)

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* YYLABEL(yyresume) */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yydefault);

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_FrontiereParser_CHAR == YYEMPTY)
    {
#if YY_FrontiereParser_DEBUG != 0
      if (YY_FrontiereParser_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_FrontiereParser_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_FrontiereParser_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_FrontiereParser_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_FrontiereParser_DEBUG != 0
      if (YY_FrontiereParser_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_FrontiereParser_CHAR);

#if YY_FrontiereParser_DEBUG != 0
      if (YY_FrontiereParser_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_FrontiereParser_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_FrontiereParser_CHAR, YY_FrontiereParser_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    YYGOTO(yydefault);

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrlab);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrlab);

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_FrontiereParser_DEBUG != 0
  if (YY_FrontiereParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_FrontiereParser_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_FrontiereParser_CHAR != YYEOF)
    YY_FrontiereParser_CHAR = YYEMPTY;

  *++yyvsp = YY_FrontiereParser_LVAL;
#ifdef YY_FrontiereParser_LSP_NEEDED
  *++yylsp = YY_FrontiereParser_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  YYGOTO(yynewstate);

/* Do the default action for the current state.  */
YYLABEL(yydefault)

  yyn = yydefact[yystate];
  if (yyn == 0)
    YYGOTO(yyerrlab);

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
YYLABEL(yyreduce)
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_FrontiereParser_DEBUG != 0
  if (YY_FrontiereParser_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


/* #line 783 "/tmp/bison++/lib/bison.cc" */
#line 1069 "FrontiereParser.cpp"

  switch (yyn) {

case 1:
#line 87 "FrontiereParser.y"
{ _listFrontiere = yyvsp[0].vecfront ;;
    break;}
case 2:
#line 93 "FrontiereParser.y"
{ (yyvsp[-1].vecfront)->push_back(yyvsp[0].front); yyval.vecfront = yyvsp[-1].vecfront; ;
    break;}
case 3:
#line 94 "FrontiereParser.y"
{ list<Frontiere*>* vectmp = new list<Frontiere*>; vectmp->push_back(yyvsp[0].front); yyval.vecfront = vectmp; ;
    break;}
case 4:
#line 97 "FrontiereParser.y"
{ yyval.front = new Frontiere(yyvsp[-3].forme, yyvsp[-1].typ) ;;
    break;}
case 5:
#line 101 "FrontiereParser.y"
{ yyval.forme = new Polygone(*yyvsp[-1].vecligne); delete yyvsp[-1].vecligne ;
    break;}
case 6:
#line 103 "FrontiereParser.y"
{ yyval.forme = new Ligne(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 7:
#line 105 "FrontiereParser.y"
{ yyval.forme = new Rectangle(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 8:
#line 107 "FrontiereParser.y"
{ yyval.forme = new Ellipse(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 9:
#line 109 "FrontiereParser.y"
{ yyval.forme = new ArcEllipse(yyvsp[-15].entier,yyvsp[-13].entier,yyvsp[-11].entier,yyvsp[-9].entier,yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 10:
#line 113 "FrontiereParser.y"
{ (yyvsp[-2].vecligne)->push_back(yyvsp[0].ligne); yyval.vecligne = yyvsp[-2].vecligne; ;
    break;}
case 11:
#line 114 "FrontiereParser.y"
{ list<Ligne*>* vectmp = new list<Ligne*>; vectmp->push_back(yyvsp[0].ligne); yyval.vecligne = vectmp; ;
    break;}
case 12:
#line 118 "FrontiereParser.y"
{yyval.ligne = new Ligne(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier);;
    break;}
case 13:
#line 121 "FrontiereParser.y"
{ yyval.typ = Frontiere::CLASSIQUE; ;
    break;}
case 14:
#line 122 "FrontiereParser.y"
{ yyval.typ = Frontiere::GENERATRICE; ;
    break;}
}

#line 783 "/tmp/bison++/lib/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_FrontiereParser_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_FrontiereParser_DEBUG != 0
  if (YY_FrontiereParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_FrontiereParser_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_FrontiereParser_LLOC.first_line;
      yylsp->first_column = YY_FrontiereParser_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  YYGOTO(yynewstate);

YYLABEL(yyerrlab)   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_FrontiereParser_NERRS;

#ifdef YY_FrontiereParser_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_FrontiereParser_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_FrontiereParser_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_FrontiereParser_ERROR_VERBOSE */
	YY_FrontiereParser_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_FrontiereParser_CHAR == YYEOF)
	YYABORT;

#if YY_FrontiereParser_DEBUG != 0
      if (YY_FrontiereParser_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_FrontiereParser_CHAR, yytname[yychar1]);
#endif

      YY_FrontiereParser_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  YYGOTO(yyerrhandle);

YYLABEL(yyerrdefault)  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) YYGOTO(yydefault);
#endif

YYLABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_FrontiereParser_LSP_NEEDED
  yylsp--;
#endif

#if YY_FrontiereParser_DEBUG != 0
  if (YY_FrontiereParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

YYLABEL(yyerrhandle)

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yyerrdefault);

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    YYGOTO(yyerrdefault);

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrpop);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrpop);

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_FrontiereParser_DEBUG != 0
  if (YY_FrontiereParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_FrontiereParser_LVAL;
#ifdef YY_FrontiereParser_LSP_NEEDED
  *++yylsp = YY_FrontiereParser_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 982 "/tmp/bison++/lib/bison.cc" */
#line 1333 "FrontiereParser.cpp"
#line 126 "FrontiereParser.y"


/* -------------- body section -------------- */
