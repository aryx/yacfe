#define YY_RegleParser_h_included

/*  A Bison++ parser, made from RegleParser.y  */

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
#line 89 "RegleParser.cpp"
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

#line 77 "/tmp/bison++/lib/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_RegleParser_BISON 1
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
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_RegleParser_STYPE 
#define YY_RegleParser_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_RegleParser_DEBUG
#define  YY_RegleParser_DEBUG YYDEBUG
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

/* #line 121 "/tmp/bison++/lib/bison.cc" */
#line 178 "RegleParser.cpp"

#line 121 "/tmp/bison++/lib/bison.cc"
/*  YY_RegleParser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 125 "/tmp/bison++/lib/bison.cc" */
#line 187 "RegleParser.cpp"

#line 125 "/tmp/bison++/lib/bison.cc"
/* prefix */
#ifndef YY_RegleParser_DEBUG

/* #line 127 "/tmp/bison++/lib/bison.cc" */
#line 194 "RegleParser.cpp"

#line 127 "/tmp/bison++/lib/bison.cc"
/* YY_RegleParser_DEBUG */
#endif


#ifndef YY_RegleParser_LSP_NEEDED

/* #line 132 "/tmp/bison++/lib/bison.cc" */
#line 204 "RegleParser.cpp"

#line 132 "/tmp/bison++/lib/bison.cc"
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
      /* We used to use `unsigned long' as YY_RegleParser_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

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
#if YY_RegleParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_RegleParser_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_RegleParser_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_RegleParser_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_RegleParser_PURE
#ifndef YYPURE
#define YYPURE YY_RegleParser_PURE
#endif
#endif
#ifdef YY_RegleParser_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_RegleParser_DEBUG 
#endif
#endif
#ifndef YY_RegleParser_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_RegleParser_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_RegleParser_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_RegleParser_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 240 "/tmp/bison++/lib/bison.cc" */
#line 317 "RegleParser.cpp"
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


#line 240 "/tmp/bison++/lib/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
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
#ifndef YY_RegleParser_CONSTRUCTOR_CODE
#define YY_RegleParser_CONSTRUCTOR_CODE
#endif
#ifndef YY_RegleParser_CONSTRUCTOR_INIT
#define YY_RegleParser_CONSTRUCTOR_INIT
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

/* #line 284 "/tmp/bison++/lib/bison.cc" */
#line 377 "RegleParser.cpp"
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


#line 284 "/tmp/bison++/lib/bison.cc"
 /* decl const */
#else
enum YY_RegleParser_ENUM_TOKEN { YY_RegleParser_NULL_TOKEN=0

/* #line 287 "/tmp/bison++/lib/bison.cc" */
#line 396 "RegleParser.cpp"
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


#line 287 "/tmp/bison++/lib/bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_RegleParser_PARSE (YY_RegleParser_PARSE_PARAM);
 virtual void YY_RegleParser_ERROR(char *msg) YY_RegleParser_ERROR_BODY;
#ifdef YY_RegleParser_PURE
#ifdef YY_RegleParser_LSP_NEEDED
 virtual int  YY_RegleParser_LEX (YY_RegleParser_STYPE *YY_RegleParser_LVAL,YY_RegleParser_LTYPE *YY_RegleParser_LLOC) YY_RegleParser_LEX_BODY;
#else
 virtual int  YY_RegleParser_LEX (YY_RegleParser_STYPE *YY_RegleParser_LVAL) YY_RegleParser_LEX_BODY;
#endif
#else
 virtual int YY_RegleParser_LEX() YY_RegleParser_LEX_BODY;
 YY_RegleParser_STYPE YY_RegleParser_LVAL;
#ifdef YY_RegleParser_LSP_NEEDED
 YY_RegleParser_LTYPE YY_RegleParser_LLOC;
#endif
 int   YY_RegleParser_NERRS;
 int    YY_RegleParser_CHAR;
#endif
#if YY_RegleParser_DEBUG != 0
 int YY_RegleParser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_RegleParser_CLASS(YY_RegleParser_CONSTRUCTOR_PARAM);
public:
 YY_RegleParser_MEMBERS 
};
/* other declare folow */
#if YY_RegleParser_USE_CONST_TOKEN != 0

/* #line 318 "/tmp/bison++/lib/bison.cc" */
#line 443 "RegleParser.cpp"
const int YY_RegleParser_CLASS::NOM=258;
const int YY_RegleParser_CLASS::ENTETEREGLE=259;
const int YY_RegleParser_CLASS::CNULLE=260;
const int YY_RegleParser_CLASS::CMEMPHI=261;
const int YY_RegleParser_CLASS::CPHIINFERIEUR=262;
const int YY_RegleParser_CLASS::CPHIINFSOLIDE=263;
const int YY_RegleParser_CLASS::REGLES=264;
const int YY_RegleParser_CLASS::Depl_IMPOSSIBLE=265;
const int YY_RegleParser_CLASS::Depl_POSSIBLE=266;
const int YY_RegleParser_CLASS::TOK_BAD=267;


#line 318 "/tmp/bison++/lib/bison.cc"
 /* const YY_RegleParser_CLASS::token */
#endif
/*apres const  */
YY_RegleParser_CLASS::YY_RegleParser_CLASS(YY_RegleParser_CONSTRUCTOR_PARAM) YY_RegleParser_CONSTRUCTOR_INIT
{
#if YY_RegleParser_DEBUG != 0
YY_RegleParser_DEBUG_FLAG=0;
#endif
YY_RegleParser_CONSTRUCTOR_CODE;
};
#endif

/* #line 329 "/tmp/bison++/lib/bison.cc" */
#line 470 "RegleParser.cpp"


#define	YYFINAL		52
#define	YYFLAG		-32768
#define	YYNTBASE	18

#define YYTRANSLATE(x) ((unsigned)(x) <= 267 ? yytranslate[x] : 22)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    14,
    16,     2,     2,    15,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    17,     2,
    13,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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

#if YY_RegleParser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     5,    46,    48,    50,    52,    54,    56
};

static const short yyrhs[] = {     4,
    19,     0,    19,     0,     3,    13,    14,    14,    20,    15,
    21,    16,    15,    14,    20,    15,    21,    16,    15,    14,
    20,    15,    21,    16,    15,    14,    20,    15,    21,    16,
    15,    14,    20,    15,    21,    16,    15,    14,    20,    15,
    21,    16,    16,    17,     0,     7,     0,     5,     0,     8,
     0,     6,     0,    10,     0,    11,     0
};

#endif

#if YY_RegleParser_DEBUG != 0
static const short yyrline[] = { 0,
    84,    85,    90,   111,   112,   113,   114,   116,   117
};

static const char * const yytname[] = {   "$","error","$illegal.","NOM","ENTETEREGLE",
"CNULLE","CMEMPHI","CPHIINFERIEUR","CPHIINFSOLIDE","REGLES","Depl_IMPOSSIBLE",
"Depl_POSSIBLE","TOK_BAD","'='","'('","','","')'","';'","file","Regle","Contrainte",
"Deplacement",""
};
#endif

static const short yyr1[] = {     0,
    18,    18,    19,    20,    20,    20,    20,    21,    21
};

static const short yyr2[] = {     0,
     2,     1,    40,     1,     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     2,     0,     1,     0,     0,     5,     7,     4,
     6,     0,     0,     8,     9,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
     0,     0
};

static const short yydefgoto[] = {    50,
     3,    12,    16
};

static const short yypact[] = {     5,
     1,    12,-32768,     2,-32768,     3,    -3,-32768,-32768,-32768,
-32768,     6,     0,-32768,-32768,     4,     7,     9,    -3,    11,
     0,    13,    15,    14,    -3,    16,     0,    17,    19,    18,
    -3,    20,     0,    21,    23,    22,    -3,    24,     0,    25,
    27,    26,    -3,    28,     0,    29,    30,    10,-32768,    44,
    47,-32768
};

static const short yypgoto[] = {-32768,
    46,   -19,   -20
};


#define	YYLAST		48


static const short yytable[] = {    20,
    22,     8,     9,    10,    11,    26,    28,     1,     2,    14,
    15,    32,    34,     4,     1,     6,     7,    38,    40,    17,
    13,    18,    19,    44,    46,    21,    49,    25,    23,    24,
    27,    31,    29,    30,    33,    37,    35,    36,    39,    43,
    41,    42,    45,    51,    47,    48,    52,     5
};

static const short yycheck[] = {    19,
    21,     5,     6,     7,     8,    25,    27,     3,     4,    10,
    11,    31,    33,    13,     3,    14,    14,    37,    39,    16,
    15,    15,    14,    43,    45,    15,    17,    14,    16,    15,
    15,    14,    16,    15,    15,    14,    16,    15,    15,    14,
    16,    15,    15,     0,    16,    16,     0,     2
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

#if YY_RegleParser_USE_GOTO != 0
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
#define yyclearin       (YY_RegleParser_CHAR = YYEMPTY)
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
  if (YY_RegleParser_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_RegleParser_CHAR = (token), YY_RegleParser_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_RegleParser_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_RegleParser_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_RegleParser_PURE
/* UNPURE */
#define YYLEX           YY_RegleParser_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_RegleParser_CHAR;                      /*  the lookahead symbol        */
YY_RegleParser_STYPE      YY_RegleParser_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_RegleParser_NERRS;                 /*  number of parse errors so far */
#ifdef YY_RegleParser_LSP_NEEDED
YY_RegleParser_LTYPE YY_RegleParser_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_RegleParser_LSP_NEEDED
#define YYLEX           YY_RegleParser_LEX(&YY_RegleParser_LVAL, &YY_RegleParser_LLOC)
#else
#define YYLEX           YY_RegleParser_LEX(&YY_RegleParser_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_RegleParser_DEBUG != 0
int YY_RegleParser_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
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
 YY_RegleParser_CLASS::
#endif
     YY_RegleParser_PARSE(YY_RegleParser_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_RegleParser_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_RegleParser_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_RegleParser_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_RegleParser_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_RegleParser_LSP_NEEDED
  YY_RegleParser_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_RegleParser_LTYPE *yyls = yylsa;
  YY_RegleParser_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_RegleParser_PURE
  int YY_RegleParser_CHAR;
  YY_RegleParser_STYPE YY_RegleParser_LVAL;
  int YY_RegleParser_NERRS;
#ifdef YY_RegleParser_LSP_NEEDED
  YY_RegleParser_LTYPE YY_RegleParser_LLOC;
#endif
#endif

  YY_RegleParser_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_RegleParser_DEBUG != 0
  if (YY_RegleParser_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_RegleParser_NERRS = 0;
  YY_RegleParser_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_RegleParser_LSP_NEEDED
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
      YY_RegleParser_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_RegleParser_LSP_NEEDED
      YY_RegleParser_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_RegleParser_LSP_NEEDED
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
#ifdef YY_RegleParser_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_RegleParser_ERROR("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YY_RegleParser_STYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YY_RegleParser_LSP_NEEDED
      yyls = (YY_RegleParser_LTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_RegleParser_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_RegleParser_DEBUG != 0
      if (YY_RegleParser_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_RegleParser_DEBUG != 0
  if (YY_RegleParser_DEBUG_FLAG)
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

  if (YY_RegleParser_CHAR == YYEMPTY)
    {
#if YY_RegleParser_DEBUG != 0
      if (YY_RegleParser_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_RegleParser_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_RegleParser_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_RegleParser_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_RegleParser_DEBUG != 0
      if (YY_RegleParser_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_RegleParser_CHAR);

#if YY_RegleParser_DEBUG != 0
      if (YY_RegleParser_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_RegleParser_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_RegleParser_CHAR, YY_RegleParser_LVAL);
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

#if YY_RegleParser_DEBUG != 0
  if (YY_RegleParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_RegleParser_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_RegleParser_CHAR != YYEOF)
    YY_RegleParser_CHAR = YYEMPTY;

  *++yyvsp = YY_RegleParser_LVAL;
#ifdef YY_RegleParser_LSP_NEEDED
  *++yylsp = YY_RegleParser_LLOC;
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

#if YY_RegleParser_DEBUG != 0
  if (YY_RegleParser_DEBUG_FLAG)
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
#line 1048 "RegleParser.cpp"

  switch (yyn) {

case 1:
#line 84 "RegleParser.y"
{_regle = yyvsp[0].regle;;
    break;}
case 2:
#line 85 "RegleParser.y"
{_regle = yyvsp[0].regle;;
    break;}
case 3:
#line 97 "RegleParser.y"
{ 
  RegleExclusion* _tmpRegle = new RegleExclusion();
 
  _tmpRegle->setNom(yyvsp[-39].Nom);
  _tmpRegle->ajoutPaire(yyvsp[-33].depl,  yyvsp[-35].contr);
  _tmpRegle->ajoutPaire(yyvsp[-27].depl, yyvsp[-29].contr);
  _tmpRegle->ajoutPaire(yyvsp[-21].depl, yyvsp[-23].contr);
  _tmpRegle->ajoutPaire(yyvsp[-15].depl, yyvsp[-17].contr);
  _tmpRegle->ajoutPaire(yyvsp[-9].depl, yyvsp[-11].contr);
  _tmpRegle->ajoutPaire(yyvsp[-3].depl, yyvsp[-5].contr);
  yyval.regle = _tmpRegle;
;
    break;}
case 4:
#line 111 "RegleParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_PHIINFERIEUR; ;
    break;}
case 5:
#line 112 "RegleParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_NULLE; ;
    break;}
case 6:
#line 113 "RegleParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_PHIINFSOLIDE; ;
    break;}
case 7:
#line 114 "RegleParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_MEMEPHI;       ;
    break;}
case 8:
#line 116 "RegleParser.y"
{ yyval.depl = RegleExclusion::DEPLIMPOSSIBLE; ;
    break;}
case 9:
#line 117 "RegleParser.y"
{ yyval.depl = RegleExclusion::DEPLPOSSIBLE; ;
    break;}
}

#line 783 "/tmp/bison++/lib/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_RegleParser_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_RegleParser_DEBUG != 0
  if (YY_RegleParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_RegleParser_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_RegleParser_LLOC.first_line;
      yylsp->first_column = YY_RegleParser_LLOC.first_column;
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
      ++YY_RegleParser_NERRS;

#ifdef YY_RegleParser_ERROR_VERBOSE
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
	      YY_RegleParser_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_RegleParser_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_RegleParser_ERROR_VERBOSE */
	YY_RegleParser_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_RegleParser_CHAR == YYEOF)
	YYABORT;

#if YY_RegleParser_DEBUG != 0
      if (YY_RegleParser_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_RegleParser_CHAR, yytname[yychar1]);
#endif

      YY_RegleParser_CHAR = YYEMPTY;
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
#ifdef YY_RegleParser_LSP_NEEDED
  yylsp--;
#endif

#if YY_RegleParser_DEBUG != 0
  if (YY_RegleParser_DEBUG_FLAG)
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

#if YY_RegleParser_DEBUG != 0
  if (YY_RegleParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_RegleParser_LVAL;
#ifdef YY_RegleParser_LSP_NEEDED
  *++yylsp = YY_RegleParser_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 982 "/tmp/bison++/lib/bison.cc" */
#line 1303 "RegleParser.cpp"
#line 119 "RegleParser.y"


/* -------------- body section -------------- */

