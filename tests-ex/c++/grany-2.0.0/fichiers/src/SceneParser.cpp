#define YY_SceneParser_h_included

/*  A Bison++ parser, made from SceneParser.y  */

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
#line 89 "SceneParser.cpp"
#define YY_SceneParser_LSP_NEEDED 
#define YY_SceneParser_ERROR_BODY  =0
#define YY_SceneParser_LTYPE  yyltype3
#define YY_SceneParser_LEX_BODY  =0
#define YY_SceneParser_MEMBERS  \
   public: \
	 Scene * _scene; \
     private: \
     RegleExclusion* recherchePtrRegle(string nom); \
     Phase * recherchePtrPhase(string nomPhase); \
     list<RegleExclusion*>* listregles; \
     list<Phase*>* listphases;
#line 37 "SceneParser.y"

#include "CommunFichiers.h"

#include "Figures.h"

#include "Couleur.h"
#include "Frontiere.h"
#include "RegleExclusion.h"
#include "Phase.h"

#include "Zonage.h"
#include "ContenuZonage.h"
#include "ContientPhase.h"
#include "ContientHorsScene.h"
#include "PhasePourcent.h"

#include "Coloration.h"

#include "Scene.h"

  // gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
  // un autre truc serai de modifier les sources du template file de  bison++
  // mais c'est porc aussi.
typedef
  struct yyltype3
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype3;


#line 76 "SceneParser.y"
typedef union {
  int    entier;
  float  reel;
  char*  Nom;
  bool   Bool;

  /* Frontiere */
  Frontiere::TypeParoi typ;
  Forme*               forme;
  list<Frontiere*>*    vecfront;
  Frontiere*           front;
  Ligne*               ligne;
  list<Ligne*>*        vecligne;

  /* Regle */
  RegleExclusion::Contrainte  contr;
  RegleExclusion::Deplacement depl;
  RegleExclusion*             regle;


  /* Rajout */
  list<RegleExclusion*>* vecregle;

  Couleur*               couleur;
  list<Couleur*>*        veccoul;

  Phase*                 phase;
  list<Phase*>*          vecphase;

  Phase::RegleEtMode     regleEtMode;
  list<Phase::RegleEtMode>* vecRegleEtMode;

  RegleExclusion::ModeExclusion modeExclusion;

  Zonage*                zonage;
  list<Zonage*>*         veczonage;
  FormeFermee*           formefermee;
  ContenuZonage*         contenuZonage;
  
  PhasePourcent          phasePourcent;
  vector<PhasePourcent>*   vecPhasePourcent;

  Coloration*            coloration;
  list<Coloration*>*     vecColoration;
  
} yy_SceneParser_stype;
#define YY_SceneParser_STYPE yy_SceneParser_stype

#line 77 "/tmp/bison++/lib/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_SceneParser_BISON 1
#ifndef YY_SceneParser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_SceneParser_COMPATIBILITY 1
#else
#define  YY_SceneParser_COMPATIBILITY 0
#endif
#endif

#if YY_SceneParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_SceneParser_LTYPE
#define YY_SceneParser_LTYPE YYLTYPE
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_SceneParser_STYPE 
#define YY_SceneParser_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_SceneParser_DEBUG
#define  YY_SceneParser_DEBUG YYDEBUG
#endif
#endif
#ifdef YY_SceneParser_STYPE
#ifndef yystype
#define yystype YY_SceneParser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_SceneParser_USE_GOTO
#define YY_SceneParser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_SceneParser_USE_GOTO
#define YY_SceneParser_USE_GOTO 0
#endif

#ifndef YY_SceneParser_PURE

/* #line 121 "/tmp/bison++/lib/bison.cc" */
#line 235 "SceneParser.cpp"

#line 121 "/tmp/bison++/lib/bison.cc"
/*  YY_SceneParser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 125 "/tmp/bison++/lib/bison.cc" */
#line 244 "SceneParser.cpp"

#line 125 "/tmp/bison++/lib/bison.cc"
/* prefix */
#ifndef YY_SceneParser_DEBUG

/* #line 127 "/tmp/bison++/lib/bison.cc" */
#line 251 "SceneParser.cpp"

#line 127 "/tmp/bison++/lib/bison.cc"
/* YY_SceneParser_DEBUG */
#endif


#ifndef YY_SceneParser_LSP_NEEDED

/* #line 132 "/tmp/bison++/lib/bison.cc" */
#line 261 "SceneParser.cpp"

#line 132 "/tmp/bison++/lib/bison.cc"
 /* YY_SceneParser_LSP_NEEDED*/
#endif



/* DEFAULT LTYPE*/
#ifdef YY_SceneParser_LSP_NEEDED
#ifndef YY_SceneParser_LTYPE
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

#define YY_SceneParser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
      /* We used to use `unsigned long' as YY_SceneParser_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

#ifndef YY_SceneParser_STYPE
#define YY_SceneParser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_SceneParser_PARSE
#define YY_SceneParser_PARSE yyparse
#endif
#ifndef YY_SceneParser_LEX
#define YY_SceneParser_LEX yylex
#endif
#ifndef YY_SceneParser_LVAL
#define YY_SceneParser_LVAL yylval
#endif
#ifndef YY_SceneParser_LLOC
#define YY_SceneParser_LLOC yylloc
#endif
#ifndef YY_SceneParser_CHAR
#define YY_SceneParser_CHAR yychar
#endif
#ifndef YY_SceneParser_NERRS
#define YY_SceneParser_NERRS yynerrs
#endif
#ifndef YY_SceneParser_DEBUG_FLAG
#define YY_SceneParser_DEBUG_FLAG yydebug
#endif
#ifndef YY_SceneParser_ERROR
#define YY_SceneParser_ERROR yyerror
#endif
#ifndef YY_SceneParser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_SceneParser_PARSE_PARAM
#ifndef YY_SceneParser_PARSE_PARAM_DEF
#define YY_SceneParser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_SceneParser_PARSE_PARAM
#define YY_SceneParser_PARSE_PARAM void
#endif
#endif
#if YY_SceneParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_SceneParser_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_SceneParser_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_SceneParser_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_SceneParser_PURE
#ifndef YYPURE
#define YYPURE YY_SceneParser_PURE
#endif
#endif
#ifdef YY_SceneParser_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_SceneParser_DEBUG 
#endif
#endif
#ifndef YY_SceneParser_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_SceneParser_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_SceneParser_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_SceneParser_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 240 "/tmp/bison++/lib/bison.cc" */
#line 374 "SceneParser.cpp"
#define	ENTETEFRONTIERE	258
#define	ENTETEREGLES	259
#define	ENTETECOLORMAP	260
#define	ENTETEPHASES	261
#define	ENTETEZONAGE	262
#define	ENTETECOLORATION	263
#define	POLYGONE	264
#define	LIGNE	265
#define	RECTANGLE	266
#define	ELLIPSE	267
#define	ARCELLIPSE	268
#define	CLASSIQUE	269
#define	GENERATRICE	270
#define	CNULLE	271
#define	CMEMPHI	272
#define	CPHIINFERIEUR	273
#define	CPHIINFSOLIDE	274
#define	Depl_IMPOSSIBLE	275
#define	Depl_POSSIBLE	276
#define	STRINGNOM	277
#define	PHI	278
#define	POND	279
#define	COUL	280
#define	INERTIE	281
#define	REGLES	282
#define	PROPAG	283
#define	PREEXCLUSION	284
#define	POSTEXCLUSION	285
#define	VRAI	286
#define	FAUX	287
#define	HS	288
#define	NOM	289
#define	NBRREEL	290
#define	NBR	291
#define	TOK_BAD	292
#define	TYPEGENERATRICE	293


#line 240 "/tmp/bison++/lib/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
#ifndef YY_SceneParser_CLASS
#define YY_SceneParser_CLASS SceneParser
#endif
#ifndef YY_SceneParser_INHERIT
#define YY_SceneParser_INHERIT
#endif
#ifndef YY_SceneParser_MEMBERS
#define YY_SceneParser_MEMBERS 
#endif
#ifndef YY_SceneParser_LEX_BODY
#define YY_SceneParser_LEX_BODY  
#endif
#ifndef YY_SceneParser_ERROR_BODY
#define YY_SceneParser_ERROR_BODY  
#endif
#ifndef YY_SceneParser_CONSTRUCTOR_PARAM
#define YY_SceneParser_CONSTRUCTOR_PARAM
#endif
#ifndef YY_SceneParser_CONSTRUCTOR_CODE
#define YY_SceneParser_CONSTRUCTOR_CODE
#endif
#ifndef YY_SceneParser_CONSTRUCTOR_INIT
#define YY_SceneParser_CONSTRUCTOR_INIT
#endif
/* choose between enum and const */
#ifndef YY_SceneParser_USE_CONST_TOKEN
#define YY_SceneParser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */
#endif
#if YY_SceneParser_USE_CONST_TOKEN != 0
#ifndef YY_SceneParser_ENUM_TOKEN
#define YY_SceneParser_ENUM_TOKEN yy_SceneParser_enum_token
#endif
#endif

class YY_SceneParser_CLASS YY_SceneParser_INHERIT
{
public:
#if YY_SceneParser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 284 "/tmp/bison++/lib/bison.cc" */
#line 460 "SceneParser.cpp"
static const int ENTETEFRONTIERE;
static const int ENTETEREGLES;
static const int ENTETECOLORMAP;
static const int ENTETEPHASES;
static const int ENTETEZONAGE;
static const int ENTETECOLORATION;
static const int POLYGONE;
static const int LIGNE;
static const int RECTANGLE;
static const int ELLIPSE;
static const int ARCELLIPSE;
static const int CLASSIQUE;
static const int GENERATRICE;
static const int CNULLE;
static const int CMEMPHI;
static const int CPHIINFERIEUR;
static const int CPHIINFSOLIDE;
static const int Depl_IMPOSSIBLE;
static const int Depl_POSSIBLE;
static const int STRINGNOM;
static const int PHI;
static const int POND;
static const int COUL;
static const int INERTIE;
static const int REGLES;
static const int PROPAG;
static const int PREEXCLUSION;
static const int POSTEXCLUSION;
static const int VRAI;
static const int FAUX;
static const int HS;
static const int NOM;
static const int NBRREEL;
static const int NBR;
static const int TOK_BAD;
static const int TYPEGENERATRICE;


#line 284 "/tmp/bison++/lib/bison.cc"
 /* decl const */
#else
enum YY_SceneParser_ENUM_TOKEN { YY_SceneParser_NULL_TOKEN=0

/* #line 287 "/tmp/bison++/lib/bison.cc" */
#line 505 "SceneParser.cpp"
	,ENTETEFRONTIERE=258
	,ENTETEREGLES=259
	,ENTETECOLORMAP=260
	,ENTETEPHASES=261
	,ENTETEZONAGE=262
	,ENTETECOLORATION=263
	,POLYGONE=264
	,LIGNE=265
	,RECTANGLE=266
	,ELLIPSE=267
	,ARCELLIPSE=268
	,CLASSIQUE=269
	,GENERATRICE=270
	,CNULLE=271
	,CMEMPHI=272
	,CPHIINFERIEUR=273
	,CPHIINFSOLIDE=274
	,Depl_IMPOSSIBLE=275
	,Depl_POSSIBLE=276
	,STRINGNOM=277
	,PHI=278
	,POND=279
	,COUL=280
	,INERTIE=281
	,REGLES=282
	,PROPAG=283
	,PREEXCLUSION=284
	,POSTEXCLUSION=285
	,VRAI=286
	,FAUX=287
	,HS=288
	,NOM=289
	,NBRREEL=290
	,NBR=291
	,TOK_BAD=292
	,TYPEGENERATRICE=293


#line 287 "/tmp/bison++/lib/bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_SceneParser_PARSE (YY_SceneParser_PARSE_PARAM);
 virtual void YY_SceneParser_ERROR(char *msg) YY_SceneParser_ERROR_BODY;
#ifdef YY_SceneParser_PURE
#ifdef YY_SceneParser_LSP_NEEDED
 virtual int  YY_SceneParser_LEX (YY_SceneParser_STYPE *YY_SceneParser_LVAL,YY_SceneParser_LTYPE *YY_SceneParser_LLOC) YY_SceneParser_LEX_BODY;
#else
 virtual int  YY_SceneParser_LEX (YY_SceneParser_STYPE *YY_SceneParser_LVAL) YY_SceneParser_LEX_BODY;
#endif
#else
 virtual int YY_SceneParser_LEX() YY_SceneParser_LEX_BODY;
 YY_SceneParser_STYPE YY_SceneParser_LVAL;
#ifdef YY_SceneParser_LSP_NEEDED
 YY_SceneParser_LTYPE YY_SceneParser_LLOC;
#endif
 int   YY_SceneParser_NERRS;
 int    YY_SceneParser_CHAR;
#endif
#if YY_SceneParser_DEBUG != 0
 int YY_SceneParser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_SceneParser_CLASS(YY_SceneParser_CONSTRUCTOR_PARAM);
public:
 YY_SceneParser_MEMBERS 
};
/* other declare folow */
#if YY_SceneParser_USE_CONST_TOKEN != 0

/* #line 318 "/tmp/bison++/lib/bison.cc" */
#line 578 "SceneParser.cpp"
const int YY_SceneParser_CLASS::ENTETEFRONTIERE=258;
const int YY_SceneParser_CLASS::ENTETEREGLES=259;
const int YY_SceneParser_CLASS::ENTETECOLORMAP=260;
const int YY_SceneParser_CLASS::ENTETEPHASES=261;
const int YY_SceneParser_CLASS::ENTETEZONAGE=262;
const int YY_SceneParser_CLASS::ENTETECOLORATION=263;
const int YY_SceneParser_CLASS::POLYGONE=264;
const int YY_SceneParser_CLASS::LIGNE=265;
const int YY_SceneParser_CLASS::RECTANGLE=266;
const int YY_SceneParser_CLASS::ELLIPSE=267;
const int YY_SceneParser_CLASS::ARCELLIPSE=268;
const int YY_SceneParser_CLASS::CLASSIQUE=269;
const int YY_SceneParser_CLASS::GENERATRICE=270;
const int YY_SceneParser_CLASS::CNULLE=271;
const int YY_SceneParser_CLASS::CMEMPHI=272;
const int YY_SceneParser_CLASS::CPHIINFERIEUR=273;
const int YY_SceneParser_CLASS::CPHIINFSOLIDE=274;
const int YY_SceneParser_CLASS::Depl_IMPOSSIBLE=275;
const int YY_SceneParser_CLASS::Depl_POSSIBLE=276;
const int YY_SceneParser_CLASS::STRINGNOM=277;
const int YY_SceneParser_CLASS::PHI=278;
const int YY_SceneParser_CLASS::POND=279;
const int YY_SceneParser_CLASS::COUL=280;
const int YY_SceneParser_CLASS::INERTIE=281;
const int YY_SceneParser_CLASS::REGLES=282;
const int YY_SceneParser_CLASS::PROPAG=283;
const int YY_SceneParser_CLASS::PREEXCLUSION=284;
const int YY_SceneParser_CLASS::POSTEXCLUSION=285;
const int YY_SceneParser_CLASS::VRAI=286;
const int YY_SceneParser_CLASS::FAUX=287;
const int YY_SceneParser_CLASS::HS=288;
const int YY_SceneParser_CLASS::NOM=289;
const int YY_SceneParser_CLASS::NBRREEL=290;
const int YY_SceneParser_CLASS::NBR=291;
const int YY_SceneParser_CLASS::TOK_BAD=292;
const int YY_SceneParser_CLASS::TYPEGENERATRICE=293;


#line 318 "/tmp/bison++/lib/bison.cc"
 /* const YY_SceneParser_CLASS::token */
#endif
/*apres const  */
YY_SceneParser_CLASS::YY_SceneParser_CLASS(YY_SceneParser_CONSTRUCTOR_PARAM) YY_SceneParser_CONSTRUCTOR_INIT
{
#if YY_SceneParser_DEBUG != 0
YY_SceneParser_DEBUG_FLAG=0;
#endif
YY_SceneParser_CONSTRUCTOR_CODE;
};
#endif

/* #line 329 "/tmp/bison++/lib/bison.cc" */
#line 631 "SceneParser.cpp"


#define	YYFINAL		266
#define	YYFLAG		-32768
#define	YYNTBASE	44

#define YYTRANSLATE(x) ((unsigned)(x) <= 293 ? yytranslate[x] : 78)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
    42,     2,     2,    39,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    40,     2,
    43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38
};

#if YY_SceneParser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     8,    11,    14,    16,    21,    26,    37,    48,    59,
    78,    82,    84,    95,    97,    99,   102,   104,   107,   109,
   150,   152,   154,   156,   158,   160,   162,   168,   172,   174,
   184,   187,   190,   192,   235,   239,   241,   242,   248,   250,
   252,   254,   256,   259,   262,   264,   269,   274,   285,   296,
   298,   302,   306,   308,   314,   320,   323,   325,   328,   330,
   335,   338
};

static const short yyrhs[] = {    45,
    52,    57,    60,    67,    74,    77,     0,     3,    46,     0,
    46,    47,     0,    47,     0,    48,    39,    51,    40,     0,
     9,    41,    49,    42,     0,    10,    41,    36,    39,    36,
    39,    36,    39,    36,    42,     0,    11,    41,    36,    39,
    36,    39,    36,    39,    36,    42,     0,    12,    41,    36,
    39,    36,    39,    36,    39,    36,    42,     0,    13,    41,
    36,    39,    36,    39,    36,    39,    36,    39,    36,    39,
    36,    39,    36,    39,    36,    42,     0,    49,    39,    50,
     0,    50,     0,    10,    41,    36,    39,    36,    39,    36,
    39,    36,    42,     0,    14,     0,    15,     0,     4,    53,
     0,     4,     0,    53,    54,     0,    54,     0,    34,    43,
    41,    41,    55,    39,    56,    42,    39,    41,    55,    39,
    56,    42,    39,    41,    55,    39,    56,    42,    39,    41,
    55,    39,    56,    42,    39,    41,    55,    39,    56,    42,
    39,    41,    55,    39,    56,    42,    42,    40,     0,    18,
     0,    16,     0,    19,     0,    17,     0,    20,     0,    21,
     0,     5,    41,    58,    42,    40,     0,    58,    39,    59,
     0,    59,     0,    41,    36,    39,    36,    39,    36,    39,
    36,    42,     0,     6,    61,     0,    61,    62,     0,    62,
     0,    22,    43,    34,    39,    23,    43,    35,    39,    24,
    43,    41,    36,    39,    36,    39,    36,    39,    36,    39,
    36,    39,    36,    42,    39,    25,    43,    36,    39,    27,
    43,    41,    63,    42,    39,    26,    43,    36,    39,    28,
    43,    66,    40,     0,    63,    39,    64,     0,    64,     0,
     0,    41,    34,    39,    65,    42,     0,    29,     0,    30,
     0,    31,     0,    32,     0,     7,    68,     0,    68,    69,
     0,    69,     0,    70,    39,    71,    40,     0,     9,    41,
    49,    42,     0,    11,    41,    36,    39,    36,    39,    36,
    39,    36,    42,     0,    12,    41,    36,    39,    36,    39,
    36,    39,    36,    42,     0,    33,     0,    41,    72,    42,
     0,    72,    39,    73,     0,    73,     0,    41,    34,    39,
    35,    42,     0,    41,    34,    39,    36,    42,     0,     8,
    75,     0,     8,     0,    75,    76,     0,    76,     0,    70,
    39,    36,    40,     0,    38,    34,     0,     0
};

#endif

#if YY_SceneParser_DEBUG != 0
static const short yyrline[] = { 0,
   194,   210,   215,   216,   219,   222,   224,   226,   228,   230,
   235,   236,   239,   243,   244,   250,   251,   252,   253,   257,
   278,   279,   280,   281,   283,   284,   290,   293,   294,   296,
   303,   306,   307,   309,   325,   326,   327,   328,   336,   337,
   340,   341,   346,   349,   350,   353,   356,   358,   360,   365,
   366,   369,   370,   373,   379,   390,   391,   393,   394,   398,
   404,   405
};

static const char * const yytname[] = {   "$","error","$illegal.","ENTETEFRONTIERE",
"ENTETEREGLES","ENTETECOLORMAP","ENTETEPHASES","ENTETEZONAGE","ENTETECOLORATION",
"POLYGONE","LIGNE","RECTANGLE","ELLIPSE","ARCELLIPSE","CLASSIQUE","GENERATRICE",
"CNULLE","CMEMPHI","CPHIINFERIEUR","CPHIINFSOLIDE","Depl_IMPOSSIBLE","Depl_POSSIBLE",
"STRINGNOM","PHI","POND","COUL","INERTIE","REGLES","PROPAG","PREEXCLUSION","POSTEXCLUSION",
"VRAI","FAUX","HS","NOM","NBRREEL","NBR","TOK_BAD","TYPEGENERATRICE","','","';'",
"'('","')'","'='","Scene","FrontiereSection","Frontieres","Frontiere","Forme",
"Lignes","Ligne","Type","RegleSection","Regles","Regle","Contrainte","Deplacement",
"ColorMapSection","Couleurs","Couleur","PhaseSection","Phases","Phase","NomRegles",
"NomRegle","PrePost","Booleen","ZonageSection","Zones","Zone","FormeFermee",
"TypeZone","NomPhases","NomPhase","ColorationSection","Colors","Color","TypeGeneratriceSection",
""
};
#endif

static const short yyr1[] = {     0,
    44,    45,    46,    46,    47,    48,    48,    48,    48,    48,
    49,    49,    50,    51,    51,    52,    52,    53,    53,    54,
    55,    55,    55,    55,    56,    56,    57,    58,    58,    59,
    60,    61,    61,    62,    63,    63,    63,    64,    65,    65,
    66,    66,    67,    68,    68,    69,    70,    70,    70,    71,
    71,    72,    72,    73,    73,    74,    74,    75,    75,    76,
    77,    77
};

static const short yyr2[] = {     0,
     7,     2,     2,     1,     4,     4,    10,    10,    10,    18,
     3,     1,    10,     1,     1,     2,     1,     2,     1,    40,
     1,     1,     1,     1,     1,     1,     5,     3,     1,     9,
     2,     2,     1,    42,     3,     1,     0,     5,     1,     1,
     1,     1,     2,     2,     1,     4,     4,    10,    10,     1,
     3,     3,     1,     5,     5,     2,     1,     2,     1,     4,
     2,     0
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     0,     0,     2,     4,     0,
    17,     0,     0,     0,     0,     0,     0,     3,     0,     0,
    16,    19,     0,     0,     0,     0,    12,     0,     0,     0,
     0,    14,    15,     0,     0,    18,     0,     0,     0,     0,
     0,     6,     0,     0,     0,     0,     5,     0,     0,     0,
    29,     0,    31,    33,     0,     0,     0,    11,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
     0,    43,    45,     0,    57,    62,     0,     0,     0,     0,
     0,    22,    24,    21,    23,     0,     0,    28,    27,     0,
     0,     0,     0,    44,     0,     0,    56,    59,     0,     1,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    50,     0,     0,     0,    58,    61,     0,     0,     0,
     0,     0,    25,    26,     0,     0,     0,    47,     0,     0,
     0,     0,    53,    46,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    51,    60,     0,
     7,     8,     9,     0,     0,     0,     0,     0,     0,     0,
    52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    13,     0,     0,    30,     0,     0,     0,    54,    55,     0,
     0,     0,     0,     0,     0,     0,     0,    48,    49,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    37,     0,     0,     0,    36,     0,     0,     0,
     0,     0,     0,    35,     0,     0,    39,    40,     0,     0,
     0,    38,     0,     0,     0,    20,     0,     0,     0,    41,
    42,     0,    34,     0,     0,     0
};

static const short yydefgoto[] = {   264,
     2,     8,     9,    10,    26,    27,    34,    12,    21,    22,
    86,   125,    24,    50,    51,    39,    53,    54,   236,   237,
   249,   262,    56,    72,    73,    74,   114,   132,   133,    76,
    97,    98,   100
};

static const short yypact[] = {    25,
    -5,    30,   -21,     1,     4,     7,     8,    -5,-32768,    13,
    19,    45,    41,    18,    20,    21,    23,-32768,    17,    22,
    19,-32768,    14,    54,    26,   -24,-32768,    27,    29,    32,
    33,-32768,-32768,    24,    28,-32768,    34,    39,    55,    37,
    41,-32768,    38,    40,    42,    43,-32768,    36,    44,   -20,
-32768,    46,    39,-32768,     5,    73,    47,-32768,    48,    49,
    51,    52,    -6,    53,    34,    56,    50,-32768,    57,    58,
    59,     5,-32768,    62,     5,    64,    61,    67,    68,    69,
    70,-32768,-32768,-32768,-32768,    71,    72,-32768,-32768,    74,
    41,    75,    76,-32768,   -32,    77,     5,-32768,    60,-32768,
    78,    79,    80,    81,    82,    16,    83,    84,   -18,    85,
    86,-32768,    87,    89,    90,-32768,-32768,    91,    94,    95,
    96,    97,-32768,-32768,    92,    99,    66,-32768,   100,   101,
   104,   -13,-32768,-32768,   102,   105,    98,   103,   106,   107,
   108,   110,    88,   111,   112,   113,    87,-32768,-32768,   117,
-32768,-32768,-32768,   118,   114,   120,   119,   121,   123,     3,
-32768,   122,   124,    -6,   125,   115,   126,   127,   128,   129,
-32768,   132,   130,-32768,   131,   136,   137,-32768,-32768,   138,
    16,   134,   139,   140,   142,   141,   143,-32768,-32768,   145,
   146,   147,   144,   135,   151,   148,    -6,   149,-32768,   150,
   155,    16,   153,   152,   157,   156,   158,   159,   160,    -6,
   162,   163,   167,    16,   164,   165,   166,   169,   116,   168,
   161,    -6,   174,   172,   173,    16,   133,   171,   175,   176,
   178,   179,   180,    -6,   109,   -12,-32768,   177,   183,   180,
   184,    16,    11,-32768,   188,   182,-32768,-32768,   185,   186,
   189,-32768,   181,   190,   187,-32768,    65,   191,    12,-32768,
-32768,   192,-32768,   198,   199,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   154,-32768,    -9,   194,-32768,-32768,-32768,    93,
  -164,  -179,-32768,-32768,   193,-32768,-32768,   195,-32768,  -157,
-32768,-32768,-32768,-32768,   170,   -72,-32768,-32768,   -62,-32768,
-32768,    -2,-32768
};


#define	YYLAST		258


static const short yytable[] = {   173,
   112,   186,    96,     3,     4,     5,     6,     7,   113,    82,
    83,    84,    85,    69,    41,    70,    71,    42,    65,    13,
    41,    66,   204,   128,    96,   147,   240,     1,   148,   241,
    32,    33,   200,    11,   216,   123,   124,   169,   170,   247,
   248,    14,   260,   261,    15,   212,   228,    16,    17,    23,
    25,    19,    20,    28,    37,    29,    30,   224,    31,    38,
    52,    55,   246,    47,    35,    43,    40,    44,    48,   238,
    45,    46,    57,    59,    49,    60,    63,    61,    62,    64,
    75,   109,   244,    90,   161,    77,    78,    79,    67,    80,
    81,    87,   258,   117,   116,    89,   101,    91,    92,    93,
    95,    99,   102,   103,   104,   105,   127,   107,   143,   106,
   110,   111,   108,    36,     0,   115,   118,   119,   120,   121,
   122,   126,   157,   129,   130,   135,   136,   131,   134,   137,
   138,   139,   140,   141,   142,   144,   145,   146,   175,   151,
   221,   149,   239,   150,   152,   154,   155,   153,   156,   158,
   159,   160,   162,   163,   164,   165,   167,   166,   168,   229,
     0,    18,   172,   171,   176,   177,   174,   180,   181,   178,
   179,   183,   184,   182,   187,   197,   185,   190,   192,   196,
   188,   189,   191,   193,   194,   195,   198,   201,   202,   199,
   203,   205,   207,   206,   208,   211,   209,   265,   266,   210,
   213,   214,   215,   223,   219,   217,   218,   220,   222,   225,
   226,   227,   230,   250,   232,   242,   255,   231,   233,   234,
   235,   243,   245,   251,     0,   257,   252,     0,   253,   256,
   254,   263,     0,   259,    58,     0,     0,     0,     0,     0,
     0,    94,     0,     0,     0,     0,     0,    68,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    88
};

static const short yycheck[] = {   164,
    33,   181,    75,     9,    10,    11,    12,    13,    41,    16,
    17,    18,    19,     9,    39,    11,    12,    42,    39,    41,
    39,    42,   202,    42,    97,    39,    39,     3,    42,    42,
    14,    15,   197,     4,   214,    20,    21,    35,    36,    29,
    30,    41,    31,    32,    41,   210,   226,    41,    41,     5,
    10,    39,    34,    36,    41,    36,    36,   222,    36,     6,
    22,     7,   242,    40,    43,    39,    41,    39,    41,   234,
    39,    39,    36,    36,    41,    36,    41,    36,    36,    36,
     8,    91,   240,    34,   147,    39,    39,    39,    43,    39,
    39,    39,    28,    34,    97,    40,    36,    41,    41,    41,
    39,    38,    36,    36,    36,    36,    23,    36,    43,    39,
    36,    36,    39,    21,    -1,    39,    39,    39,    39,    39,
    39,    39,    35,    39,    39,    36,    36,    41,    40,    36,
    36,    36,    36,    42,    36,    36,    36,    34,    24,    42,
    25,    40,    34,    39,    42,    39,    39,    42,    39,    39,
    39,    39,    36,    36,    41,    36,    36,    39,    36,    27,
    -1,     8,    39,    42,    39,    39,    42,    36,    39,    42,
    42,    36,    36,    43,    41,    41,    39,    36,    36,    36,
    42,    42,    42,    39,    39,    39,    36,    39,    39,    42,
    36,    39,    36,    42,    39,    36,    39,     0,     0,    41,
    39,    39,    36,    43,    39,    42,    42,    39,    41,    36,
    39,    39,    42,    26,    39,    39,    36,    43,    41,    41,
    41,    39,    39,    42,    -1,    39,    42,    -1,    43,    40,
    42,    40,    -1,    43,    41,    -1,    -1,    -1,    -1,    -1,
    -1,    72,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65
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

#if YY_SceneParser_USE_GOTO != 0
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
#define yyclearin       (YY_SceneParser_CHAR = YYEMPTY)
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
  if (YY_SceneParser_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_SceneParser_CHAR = (token), YY_SceneParser_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_SceneParser_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_SceneParser_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_SceneParser_PURE
/* UNPURE */
#define YYLEX           YY_SceneParser_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_SceneParser_CHAR;                      /*  the lookahead symbol        */
YY_SceneParser_STYPE      YY_SceneParser_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_SceneParser_NERRS;                 /*  number of parse errors so far */
#ifdef YY_SceneParser_LSP_NEEDED
YY_SceneParser_LTYPE YY_SceneParser_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_SceneParser_LSP_NEEDED
#define YYLEX           YY_SceneParser_LEX(&YY_SceneParser_LVAL, &YY_SceneParser_LLOC)
#else
#define YYLEX           YY_SceneParser_LEX(&YY_SceneParser_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_SceneParser_DEBUG != 0
int YY_SceneParser_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
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
 YY_SceneParser_CLASS::
#endif
     YY_SceneParser_PARSE(YY_SceneParser_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_SceneParser_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_SceneParser_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_SceneParser_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_SceneParser_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_SceneParser_LSP_NEEDED
  YY_SceneParser_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_SceneParser_LTYPE *yyls = yylsa;
  YY_SceneParser_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_SceneParser_PURE
  int YY_SceneParser_CHAR;
  YY_SceneParser_STYPE YY_SceneParser_LVAL;
  int YY_SceneParser_NERRS;
#ifdef YY_SceneParser_LSP_NEEDED
  YY_SceneParser_LTYPE YY_SceneParser_LLOC;
#endif
#endif

  YY_SceneParser_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_SceneParser_DEBUG != 0
  if (YY_SceneParser_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_SceneParser_NERRS = 0;
  YY_SceneParser_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_SceneParser_LSP_NEEDED
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
      YY_SceneParser_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_SceneParser_LSP_NEEDED
      YY_SceneParser_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_SceneParser_LSP_NEEDED
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
#ifdef YY_SceneParser_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_SceneParser_ERROR("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YY_SceneParser_STYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YY_SceneParser_LSP_NEEDED
      yyls = (YY_SceneParser_LTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_SceneParser_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_SceneParser_DEBUG != 0
      if (YY_SceneParser_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_SceneParser_DEBUG != 0
  if (YY_SceneParser_DEBUG_FLAG)
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

  if (YY_SceneParser_CHAR == YYEMPTY)
    {
#if YY_SceneParser_DEBUG != 0
      if (YY_SceneParser_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_SceneParser_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_SceneParser_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_SceneParser_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_SceneParser_DEBUG != 0
      if (YY_SceneParser_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_SceneParser_CHAR);

#if YY_SceneParser_DEBUG != 0
      if (YY_SceneParser_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_SceneParser_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_SceneParser_CHAR, YY_SceneParser_LVAL);
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

#if YY_SceneParser_DEBUG != 0
  if (YY_SceneParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_SceneParser_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_SceneParser_CHAR != YYEOF)
    YY_SceneParser_CHAR = YYEMPTY;

  *++yyvsp = YY_SceneParser_LVAL;
#ifdef YY_SceneParser_LSP_NEEDED
  *++yylsp = YY_SceneParser_LLOC;
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

#if YY_SceneParser_DEBUG != 0
  if (YY_SceneParser_DEBUG_FLAG)
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
#line 1362 "SceneParser.cpp"

  switch (yyn) {

case 1:
#line 201 "SceneParser.y"
{ 
	  _scene = new Scene(*yyvsp[-6].vecfront, *yyvsp[-5].vecregle, *yyvsp[-4].veccoul, *yyvsp[-3].vecphase, *yyvsp[-2].veczonage, *yyvsp[-1].vecColoration, yyvsp[0].phase); 
	  delete yyvsp[-6].vecfront; delete yyvsp[-5].vecregle; delete yyvsp[-4].veccoul; delete yyvsp[-3].vecphase; delete yyvsp[-2].veczonage; delete yyvsp[-1].vecColoration; ;
    break;}
case 2:
#line 210 "SceneParser.y"
{ yyval.vecfront = yyvsp[0].vecfront; ;
    break;}
case 3:
#line 215 "SceneParser.y"
{ (yyvsp[-1].vecfront)->push_back(yyvsp[0].front); yyval.vecfront = yyvsp[-1].vecfront;;
    break;}
case 4:
#line 216 "SceneParser.y"
{ list<Frontiere*>* vectmp = new list<Frontiere*>; vectmp->push_back(yyvsp[0].front); yyval.vecfront = vectmp; ;
    break;}
case 5:
#line 219 "SceneParser.y"
{ yyval.front = new Frontiere(yyvsp[-3].forme, yyvsp[-1].typ) ;;
    break;}
case 6:
#line 223 "SceneParser.y"
{ yyval.forme = new Polygone(*yyvsp[-1].vecligne); delete yyvsp[-1].vecligne ;
    break;}
case 7:
#line 225 "SceneParser.y"
{ yyval.forme = new Ligne(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 8:
#line 227 "SceneParser.y"
{ yyval.forme = new Rectangle(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 9:
#line 229 "SceneParser.y"
{ yyval.forme = new Ellipse(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 10:
#line 231 "SceneParser.y"
{ yyval.forme = new ArcEllipse(yyvsp[-15].entier,yyvsp[-13].entier,yyvsp[-11].entier,yyvsp[-9].entier,yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 11:
#line 235 "SceneParser.y"
{ (yyvsp[-2].vecligne)->push_back(yyvsp[0].ligne); yyval.vecligne = yyvsp[-2].vecligne; ;
    break;}
case 12:
#line 236 "SceneParser.y"
{ list<Ligne*>* vectmp = new list<Ligne*>; vectmp->push_back(yyvsp[0].ligne); yyval.vecligne = vectmp; ;
    break;}
case 13:
#line 240 "SceneParser.y"
{yyval.ligne = new Ligne(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier);;
    break;}
case 14:
#line 243 "SceneParser.y"
{ yyval.typ = Frontiere::CLASSIQUE; ;
    break;}
case 15:
#line 244 "SceneParser.y"
{ yyval.typ = Frontiere::GENERATRICE; ;
    break;}
case 16:
#line 250 "SceneParser.y"
{ yyval.vecregle = yyvsp[0].vecregle; /* side effect */ listregles = yyvsp[0].vecregle;;
    break;}
case 17:
#line 251 "SceneParser.y"
{ yyval.vecregle = new list<RegleExclusion*>; listregles = yyval.vecregle;;
    break;}
case 18:
#line 252 "SceneParser.y"
{ (yyvsp[-1].vecregle)->push_back(yyvsp[0].regle); yyval.vecregle = yyvsp[-1].vecregle; ;
    break;}
case 19:
#line 253 "SceneParser.y"
{ list<RegleExclusion*>* vectmp = new list<RegleExclusion*>; vectmp->push_back(yyvsp[0].regle); yyval.vecregle = vectmp; ;
    break;}
case 20:
#line 264 "SceneParser.y"
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
case 21:
#line 278 "SceneParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_PHIINFERIEUR; ;
    break;}
case 22:
#line 279 "SceneParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_NULLE; ;
    break;}
case 23:
#line 280 "SceneParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_PHIINFSOLIDE; ;
    break;}
case 24:
#line 281 "SceneParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_MEMEPHI;       ;
    break;}
case 25:
#line 283 "SceneParser.y"
{ yyval.depl = RegleExclusion::DEPLIMPOSSIBLE; ;
    break;}
case 26:
#line 284 "SceneParser.y"
{ yyval.depl = RegleExclusion::DEPLPOSSIBLE; ;
    break;}
case 27:
#line 290 "SceneParser.y"
{ yyval.veccoul = yyvsp[-2].veccoul; ;
    break;}
case 28:
#line 293 "SceneParser.y"
{ (yyvsp[-2].veccoul)->push_back(yyvsp[0].couleur); yyval.veccoul = yyvsp[-2].veccoul; ;
    break;}
case 29:
#line 294 "SceneParser.y"
{ list<Couleur*>* vectmp = new list<Couleur*>; vectmp->push_back(yyvsp[0].couleur); yyval.veccoul = vectmp; ;
    break;}
case 30:
#line 297 "SceneParser.y"
{ yyval.couleur = new Couleur(yyvsp[-7].entier, yyvsp[-5].entier, yyvsp[-3].entier, yyvsp[-1].entier); ;
    break;}
case 31:
#line 303 "SceneParser.y"
{ yyval.vecphase = yyvsp[0].vecphase; /* side effect */ listphases = yyvsp[0].vecphase;;
    break;}
case 32:
#line 306 "SceneParser.y"
{ (yyvsp[-1].vecphase)->push_back(yyvsp[0].phase); yyval.vecphase = yyvsp[-1].vecphase; ;
    break;}
case 33:
#line 307 "SceneParser.y"
{ list<Phase*>* vectmp = new list<Phase*>; vectmp->push_back(yyvsp[0].phase); yyval.vecphase = vectmp; ;
    break;}
case 34:
#line 316 "SceneParser.y"
{ 
	    int tabPond[6] = {yyvsp[-30].entier,yyvsp[-28].entier,yyvsp[-26].entier,yyvsp[-24].entier,yyvsp[-22].entier,yyvsp[-20].entier};
	    yyval.phase = new Phase(yyvsp[-39].Nom, yyvsp[-35].reel, yyvsp[-1].Bool, yyvsp[-5].entier, Ponderation(tabPond) ,*(yyvsp[-10].vecRegleEtMode));
	    yyval.phase->setCouleur(yyvsp[-15].entier);
	    delete yyvsp[-10].vecRegleEtMode; // plus besoin
			   
	  ;
    break;}
case 35:
#line 325 "SceneParser.y"
{ (yyvsp[-2].vecRegleEtMode)->push_back(yyvsp[0].regleEtMode); yyval.vecRegleEtMode = yyvsp[-2].vecRegleEtMode; ;
    break;}
case 36:
#line 326 "SceneParser.y"
{ list<Phase::RegleEtMode>* vectmp = new list<Phase::RegleEtMode>; vectmp->push_back(yyvsp[0].regleEtMode); yyval.vecRegleEtMode = vectmp; ;
    break;}
case 37:
#line 327 "SceneParser.y"
{ list<Phase::RegleEtMode>* vectmp = new list<Phase::RegleEtMode>; yyval.vecRegleEtMode = vectmp; ;
    break;}
case 38:
#line 329 "SceneParser.y"
{ 
	     RegleExclusion* tmpRegle = recherchePtrRegle(yyvsp[-3].Nom);
	     yyval.regleEtMode.mode = yyvsp[-1].modeExclusion;
	     yyval.regleEtMode.regle = tmpRegle;
	   ;
    break;}
case 39:
#line 336 "SceneParser.y"
{ yyval.modeExclusion = RegleExclusion::PRE  ;;
    break;}
case 40:
#line 337 "SceneParser.y"
{ yyval.modeExclusion = RegleExclusion::POST ;;
    break;}
case 41:
#line 340 "SceneParser.y"
{ yyval.Bool = true; ;
    break;}
case 42:
#line 341 "SceneParser.y"
{ yyval.Bool = false; ;
    break;}
case 43:
#line 346 "SceneParser.y"
{ yyval.veczonage = yyvsp[0].veczonage; ;
    break;}
case 44:
#line 349 "SceneParser.y"
{ (yyvsp[-1].veczonage)->push_back(yyvsp[0].zonage); yyval.veczonage = yyvsp[-1].veczonage; ;
    break;}
case 45:
#line 350 "SceneParser.y"
{ list<Zonage*>* vectmp = new list<Zonage*>; vectmp->push_back(yyvsp[0].zonage); yyval.veczonage = vectmp; ;
    break;}
case 46:
#line 353 "SceneParser.y"
{ yyval.zonage = new Zonage(yyvsp[-3].formefermee, yyvsp[-1].contenuZonage); ;
    break;}
case 47:
#line 357 "SceneParser.y"
{ yyval.formefermee = new Polygone(*yyvsp[-1].vecligne); delete yyvsp[-1].vecligne;
    break;}
case 48:
#line 359 "SceneParser.y"
{ yyval.formefermee = new Rectangle(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 49:
#line 361 "SceneParser.y"
{ yyval.formefermee = new Ellipse(yyvsp[-7].entier,yyvsp[-5].entier,yyvsp[-3].entier,yyvsp[-1].entier); ;
    break;}
case 50:
#line 365 "SceneParser.y"
{ yyval.contenuZonage = new ContientHorsScene(); ;
    break;}
case 51:
#line 366 "SceneParser.y"
{ yyval.contenuZonage = new ContientPhase(*(yyvsp[-1].vecPhasePourcent)); delete yyvsp[-1].vecPhasePourcent; /* plus besoin */ ;
    break;}
case 52:
#line 369 "SceneParser.y"
{ (yyvsp[-2].vecPhasePourcent)->push_back(yyvsp[0].phasePourcent); yyval.vecPhasePourcent = yyvsp[-2].vecPhasePourcent; ;
    break;}
case 53:
#line 370 "SceneParser.y"
{ vector<PhasePourcent>* vectmp = new vector<PhasePourcent>; vectmp->push_back(yyvsp[0].phasePourcent); yyval.vecPhasePourcent = vectmp; ;
    break;}
case 54:
#line 374 "SceneParser.y"
{ 
	     Phase* phase = recherchePtrPhase(yyvsp[-3].Nom);
	     yyval.phasePourcent.phase = phase;
	     yyval.phasePourcent.pourcentage = yyvsp[-1].reel;
	   ;
    break;}
case 55:
#line 380 "SceneParser.y"
{ 
	     Phase* phase = recherchePtrPhase(yyvsp[-3].Nom);
	     yyval.phasePourcent.phase = phase;
	     yyval.phasePourcent.pourcentage = yyvsp[-1].entier;
	   ;
    break;}
case 56:
#line 390 "SceneParser.y"
{ yyval.vecColoration = yyvsp[0].vecColoration; ;
    break;}
case 57:
#line 391 "SceneParser.y"
{ yyval.vecColoration = new list<Coloration*>;;
    break;}
case 58:
#line 393 "SceneParser.y"
{ (yyvsp[-1].vecColoration)->push_back(yyvsp[0].coloration); yyval.vecColoration = yyvsp[-1].vecColoration; ;
    break;}
case 59:
#line 394 "SceneParser.y"
{ list<Coloration*>* vectmp = new list<Coloration*>; vectmp->push_back(yyvsp[0].coloration); yyval.vecColoration = vectmp; ;
    break;}
case 60:
#line 398 "SceneParser.y"
{ yyval.coloration = new Coloration(yyvsp[-3].formefermee, yyvsp[-1].entier); ;
    break;}
case 61:
#line 404 "SceneParser.y"
{ yyval.phase = recherchePtrPhase(yyvsp[0].Nom);;
    break;}
case 62:
#line 405 "SceneParser.y"
{ yyval.phase = NULL; ;
    break;}
}

#line 783 "/tmp/bison++/lib/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_SceneParser_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_SceneParser_DEBUG != 0
  if (YY_SceneParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_SceneParser_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_SceneParser_LLOC.first_line;
      yylsp->first_column = YY_SceneParser_LLOC.first_column;
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
      ++YY_SceneParser_NERRS;

#ifdef YY_SceneParser_ERROR_VERBOSE
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
	      YY_SceneParser_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_SceneParser_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_SceneParser_ERROR_VERBOSE */
	YY_SceneParser_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_SceneParser_CHAR == YYEOF)
	YYABORT;

#if YY_SceneParser_DEBUG != 0
      if (YY_SceneParser_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_SceneParser_CHAR, yytname[yychar1]);
#endif

      YY_SceneParser_CHAR = YYEMPTY;
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
#ifdef YY_SceneParser_LSP_NEEDED
  yylsp--;
#endif

#if YY_SceneParser_DEBUG != 0
  if (YY_SceneParser_DEBUG_FLAG)
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

#if YY_SceneParser_DEBUG != 0
  if (YY_SceneParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_SceneParser_LVAL;
#ifdef YY_SceneParser_LSP_NEEDED
  *++yylsp = YY_SceneParser_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 982 "/tmp/bison++/lib/bison.cc" */
#line 1849 "SceneParser.cpp"
#line 407 "SceneParser.y"


RegleExclusion * SceneParser::recherchePtrRegle(string nomRegle)
{
    list<RegleExclusion*>::iterator it_regles;
    
    for (it_regles = listregles->begin(); it_regles != listregles->end(); it_regles++)
      if ((*it_regles)->getNom() == nomRegle) return (*it_regles) ;

    cerr << "recherchePtrRegle: Regle non connue" << endl;
    return NULL;
}

Phase * SceneParser::recherchePtrPhase(string nomPhase)
{

    list<Phase*>::iterator it_phases ;

    for (it_phases = listphases->begin(); it_phases != listphases->end(); it_phases++)
      if ((*it_phases)->getNom() == nomPhase) return (*it_phases) ;

    cerr << "recherchePtrPhase: Phase non connue" << endl;
    return NULL;
}

