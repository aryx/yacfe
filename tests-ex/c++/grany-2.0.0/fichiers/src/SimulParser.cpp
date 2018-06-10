#define YY_SimulParser_h_included

/*  A Bison++ parser, made from SimulParser.y  */

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
#line 89 "SimulParser.cpp"
#define YY_SimulParser_LSP_NEEDED 
#define YY_SimulParser_ERROR_BODY  =0
#define YY_SimulParser_LTYPE  yyltype4
#define YY_SimulParser_LEX_BODY  =0
#define YY_SimulParser_MEMBERS  \
   public: \
     Automate* _automate; \
     private: \
     RegleExclusion* recherchePtrRegle(string nom); \
     Phase * recherchePtrPhase(string nomPhase); \
     list<RegleExclusion*>* listregles; \
     list<Phase*>* listphases;
#line 36 "SimulParser.y"

#include "CommunFichiers.h"

#include "RegleExclusion.h"
#include "Automate.h"
#include "Phase.h"
#include "Particule.h"

#include "Cellule.h"
#include "CelluleAvecParticule.h"
#include "CelluleGeneratrice.h"
#include "CelluleHorsScene.h"
#include "CelluleParoi.h"
#include "CelluleSansParticule.h"

#include "Couleur.h"

  // gros hack pourri pour ne pas avoir le conflit de nom sur yyltype
  // un autre truc serai de modifier les sources du template file de  bison++
  // mais c'est porc aussi.
typedef
  struct yyltype4
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype4;


#line 72 "SimulParser.y"
typedef union {
  int entier;
  float reel;
  char * Nom;
  bool Bool;

  /* From Scene without Change */ 
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

  Cellule*               cellule;
  Particule*             particule;
  EnumDirectionRequete   dirreq;

} yy_SimulParser_stype;
#define YY_SimulParser_STYPE yy_SimulParser_stype

#line 77 "/tmp/bison++/lib/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_SimulParser_BISON 1
#ifndef YY_SimulParser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_SimulParser_COMPATIBILITY 1
#else
#define  YY_SimulParser_COMPATIBILITY 0
#endif
#endif

#if YY_SimulParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_SimulParser_LTYPE
#define YY_SimulParser_LTYPE YYLTYPE
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_SimulParser_STYPE 
#define YY_SimulParser_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_SimulParser_DEBUG
#define  YY_SimulParser_DEBUG YYDEBUG
#endif
#endif
#ifdef YY_SimulParser_STYPE
#ifndef yystype
#define yystype YY_SimulParser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_SimulParser_USE_GOTO
#define YY_SimulParser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_SimulParser_USE_GOTO
#define YY_SimulParser_USE_GOTO 0
#endif

#ifndef YY_SimulParser_PURE

/* #line 121 "/tmp/bison++/lib/bison.cc" */
#line 217 "SimulParser.cpp"

#line 121 "/tmp/bison++/lib/bison.cc"
/*  YY_SimulParser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 125 "/tmp/bison++/lib/bison.cc" */
#line 226 "SimulParser.cpp"

#line 125 "/tmp/bison++/lib/bison.cc"
/* prefix */
#ifndef YY_SimulParser_DEBUG

/* #line 127 "/tmp/bison++/lib/bison.cc" */
#line 233 "SimulParser.cpp"

#line 127 "/tmp/bison++/lib/bison.cc"
/* YY_SimulParser_DEBUG */
#endif


#ifndef YY_SimulParser_LSP_NEEDED

/* #line 132 "/tmp/bison++/lib/bison.cc" */
#line 243 "SimulParser.cpp"

#line 132 "/tmp/bison++/lib/bison.cc"
 /* YY_SimulParser_LSP_NEEDED*/
#endif



/* DEFAULT LTYPE*/
#ifdef YY_SimulParser_LSP_NEEDED
#ifndef YY_SimulParser_LTYPE
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

#define YY_SimulParser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
      /* We used to use `unsigned long' as YY_SimulParser_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

#ifndef YY_SimulParser_STYPE
#define YY_SimulParser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_SimulParser_PARSE
#define YY_SimulParser_PARSE yyparse
#endif
#ifndef YY_SimulParser_LEX
#define YY_SimulParser_LEX yylex
#endif
#ifndef YY_SimulParser_LVAL
#define YY_SimulParser_LVAL yylval
#endif
#ifndef YY_SimulParser_LLOC
#define YY_SimulParser_LLOC yylloc
#endif
#ifndef YY_SimulParser_CHAR
#define YY_SimulParser_CHAR yychar
#endif
#ifndef YY_SimulParser_NERRS
#define YY_SimulParser_NERRS yynerrs
#endif
#ifndef YY_SimulParser_DEBUG_FLAG
#define YY_SimulParser_DEBUG_FLAG yydebug
#endif
#ifndef YY_SimulParser_ERROR
#define YY_SimulParser_ERROR yyerror
#endif
#ifndef YY_SimulParser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_SimulParser_PARSE_PARAM
#ifndef YY_SimulParser_PARSE_PARAM_DEF
#define YY_SimulParser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_SimulParser_PARSE_PARAM
#define YY_SimulParser_PARSE_PARAM void
#endif
#endif
#if YY_SimulParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_SimulParser_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_SimulParser_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_SimulParser_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_SimulParser_PURE
#ifndef YYPURE
#define YYPURE YY_SimulParser_PURE
#endif
#endif
#ifdef YY_SimulParser_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_SimulParser_DEBUG 
#endif
#endif
#ifndef YY_SimulParser_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_SimulParser_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_SimulParser_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_SimulParser_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 240 "/tmp/bison++/lib/bison.cc" */
#line 356 "SimulParser.cpp"
#define	ENTETEPARAMETRES	258
#define	ENTETEREGLES	259
#define	ENTETECOLORMAP	260
#define	ENTETEPHASES	261
#define	ENTETELOCALISATION	262
#define	NBPAS	263
#define	FREQAFF	264
#define	DIM	265
#define	GERME	266
#define	CNULLE	267
#define	CMEMPHI	268
#define	CPHIINFERIEUR	269
#define	CPHIINFSOLIDE	270
#define	Depl_IMPOSSIBLE	271
#define	Depl_POSSIBLE	272
#define	STRINGNOM	273
#define	PHI	274
#define	POND	275
#define	COUL	276
#define	REGLES	277
#define	INERTIE	278
#define	PROPAG	279
#define	PREEXCLUSION	280
#define	POSTEXCLUSION	281
#define	VRAI	282
#define	FAUX	283
#define	NOM	284
#define	NBRREEL	285
#define	NBR	286
#define	CP	287
#define	CG	288
#define	HS	289
#define	C	290
#define	CNC	291
#define	CN	292
#define	CS	293
#define	CNE	294
#define	CNO	295
#define	CSE	296
#define	CSO	297
#define	TOK_BAD	298


#line 240 "/tmp/bison++/lib/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
#ifndef YY_SimulParser_CLASS
#define YY_SimulParser_CLASS SimulParser
#endif
#ifndef YY_SimulParser_INHERIT
#define YY_SimulParser_INHERIT
#endif
#ifndef YY_SimulParser_MEMBERS
#define YY_SimulParser_MEMBERS 
#endif
#ifndef YY_SimulParser_LEX_BODY
#define YY_SimulParser_LEX_BODY  
#endif
#ifndef YY_SimulParser_ERROR_BODY
#define YY_SimulParser_ERROR_BODY  
#endif
#ifndef YY_SimulParser_CONSTRUCTOR_PARAM
#define YY_SimulParser_CONSTRUCTOR_PARAM
#endif
#ifndef YY_SimulParser_CONSTRUCTOR_CODE
#define YY_SimulParser_CONSTRUCTOR_CODE
#endif
#ifndef YY_SimulParser_CONSTRUCTOR_INIT
#define YY_SimulParser_CONSTRUCTOR_INIT
#endif
/* choose between enum and const */
#ifndef YY_SimulParser_USE_CONST_TOKEN
#define YY_SimulParser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */
#endif
#if YY_SimulParser_USE_CONST_TOKEN != 0
#ifndef YY_SimulParser_ENUM_TOKEN
#define YY_SimulParser_ENUM_TOKEN yy_SimulParser_enum_token
#endif
#endif

class YY_SimulParser_CLASS YY_SimulParser_INHERIT
{
public:
#if YY_SimulParser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 284 "/tmp/bison++/lib/bison.cc" */
#line 447 "SimulParser.cpp"
static const int ENTETEPARAMETRES;
static const int ENTETEREGLES;
static const int ENTETECOLORMAP;
static const int ENTETEPHASES;
static const int ENTETELOCALISATION;
static const int NBPAS;
static const int FREQAFF;
static const int DIM;
static const int GERME;
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
static const int REGLES;
static const int INERTIE;
static const int PROPAG;
static const int PREEXCLUSION;
static const int POSTEXCLUSION;
static const int VRAI;
static const int FAUX;
static const int NOM;
static const int NBRREEL;
static const int NBR;
static const int CP;
static const int CG;
static const int HS;
static const int C;
static const int CNC;
static const int CN;
static const int CS;
static const int CNE;
static const int CNO;
static const int CSE;
static const int CSO;
static const int TOK_BAD;


#line 284 "/tmp/bison++/lib/bison.cc"
 /* decl const */
#else
enum YY_SimulParser_ENUM_TOKEN { YY_SimulParser_NULL_TOKEN=0

/* #line 287 "/tmp/bison++/lib/bison.cc" */
#line 497 "SimulParser.cpp"
	,ENTETEPARAMETRES=258
	,ENTETEREGLES=259
	,ENTETECOLORMAP=260
	,ENTETEPHASES=261
	,ENTETELOCALISATION=262
	,NBPAS=263
	,FREQAFF=264
	,DIM=265
	,GERME=266
	,CNULLE=267
	,CMEMPHI=268
	,CPHIINFERIEUR=269
	,CPHIINFSOLIDE=270
	,Depl_IMPOSSIBLE=271
	,Depl_POSSIBLE=272
	,STRINGNOM=273
	,PHI=274
	,POND=275
	,COUL=276
	,REGLES=277
	,INERTIE=278
	,PROPAG=279
	,PREEXCLUSION=280
	,POSTEXCLUSION=281
	,VRAI=282
	,FAUX=283
	,NOM=284
	,NBRREEL=285
	,NBR=286
	,CP=287
	,CG=288
	,HS=289
	,C=290
	,CNC=291
	,CN=292
	,CS=293
	,CNE=294
	,CNO=295
	,CSE=296
	,CSO=297
	,TOK_BAD=298


#line 287 "/tmp/bison++/lib/bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_SimulParser_PARSE (YY_SimulParser_PARSE_PARAM);
 virtual void YY_SimulParser_ERROR(char *msg) YY_SimulParser_ERROR_BODY;
#ifdef YY_SimulParser_PURE
#ifdef YY_SimulParser_LSP_NEEDED
 virtual int  YY_SimulParser_LEX (YY_SimulParser_STYPE *YY_SimulParser_LVAL,YY_SimulParser_LTYPE *YY_SimulParser_LLOC) YY_SimulParser_LEX_BODY;
#else
 virtual int  YY_SimulParser_LEX (YY_SimulParser_STYPE *YY_SimulParser_LVAL) YY_SimulParser_LEX_BODY;
#endif
#else
 virtual int YY_SimulParser_LEX() YY_SimulParser_LEX_BODY;
 YY_SimulParser_STYPE YY_SimulParser_LVAL;
#ifdef YY_SimulParser_LSP_NEEDED
 YY_SimulParser_LTYPE YY_SimulParser_LLOC;
#endif
 int   YY_SimulParser_NERRS;
 int    YY_SimulParser_CHAR;
#endif
#if YY_SimulParser_DEBUG != 0
 int YY_SimulParser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_SimulParser_CLASS(YY_SimulParser_CONSTRUCTOR_PARAM);
public:
 YY_SimulParser_MEMBERS 
};
/* other declare folow */
#if YY_SimulParser_USE_CONST_TOKEN != 0

/* #line 318 "/tmp/bison++/lib/bison.cc" */
#line 575 "SimulParser.cpp"
const int YY_SimulParser_CLASS::ENTETEPARAMETRES=258;
const int YY_SimulParser_CLASS::ENTETEREGLES=259;
const int YY_SimulParser_CLASS::ENTETECOLORMAP=260;
const int YY_SimulParser_CLASS::ENTETEPHASES=261;
const int YY_SimulParser_CLASS::ENTETELOCALISATION=262;
const int YY_SimulParser_CLASS::NBPAS=263;
const int YY_SimulParser_CLASS::FREQAFF=264;
const int YY_SimulParser_CLASS::DIM=265;
const int YY_SimulParser_CLASS::GERME=266;
const int YY_SimulParser_CLASS::CNULLE=267;
const int YY_SimulParser_CLASS::CMEMPHI=268;
const int YY_SimulParser_CLASS::CPHIINFERIEUR=269;
const int YY_SimulParser_CLASS::CPHIINFSOLIDE=270;
const int YY_SimulParser_CLASS::Depl_IMPOSSIBLE=271;
const int YY_SimulParser_CLASS::Depl_POSSIBLE=272;
const int YY_SimulParser_CLASS::STRINGNOM=273;
const int YY_SimulParser_CLASS::PHI=274;
const int YY_SimulParser_CLASS::POND=275;
const int YY_SimulParser_CLASS::COUL=276;
const int YY_SimulParser_CLASS::REGLES=277;
const int YY_SimulParser_CLASS::INERTIE=278;
const int YY_SimulParser_CLASS::PROPAG=279;
const int YY_SimulParser_CLASS::PREEXCLUSION=280;
const int YY_SimulParser_CLASS::POSTEXCLUSION=281;
const int YY_SimulParser_CLASS::VRAI=282;
const int YY_SimulParser_CLASS::FAUX=283;
const int YY_SimulParser_CLASS::NOM=284;
const int YY_SimulParser_CLASS::NBRREEL=285;
const int YY_SimulParser_CLASS::NBR=286;
const int YY_SimulParser_CLASS::CP=287;
const int YY_SimulParser_CLASS::CG=288;
const int YY_SimulParser_CLASS::HS=289;
const int YY_SimulParser_CLASS::C=290;
const int YY_SimulParser_CLASS::CNC=291;
const int YY_SimulParser_CLASS::CN=292;
const int YY_SimulParser_CLASS::CS=293;
const int YY_SimulParser_CLASS::CNE=294;
const int YY_SimulParser_CLASS::CNO=295;
const int YY_SimulParser_CLASS::CSE=296;
const int YY_SimulParser_CLASS::CSO=297;
const int YY_SimulParser_CLASS::TOK_BAD=298;


#line 318 "/tmp/bison++/lib/bison.cc"
 /* const YY_SimulParser_CLASS::token */
#endif
/*apres const  */
YY_SimulParser_CLASS::YY_SimulParser_CLASS(YY_SimulParser_CONSTRUCTOR_PARAM) YY_SimulParser_CONSTRUCTOR_INIT
{
#if YY_SimulParser_DEBUG != 0
YY_SimulParser_DEBUG_FLAG=0;
#endif
YY_SimulParser_CONSTRUCTOR_CODE;
};
#endif

/* #line 329 "/tmp/bison++/lib/bison.cc" */
#line 633 "SimulParser.cpp"


#define	YYFINAL		183
#define	YYFLAG		-32768
#define	YYNTBASE	49

#define YYTRANSLATE(x) ((unsigned)(x) <= 298 ? yytranslate[x] : 72)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
    48,     2,     2,    47,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
    44,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
    36,    37,    38,    39,    40,    41,    42,    43
};

#if YY_SimulParser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,    24,    27,    29,    32,    34,    75,    77,    79,
    81,    83,    85,    87,    93,    97,    99,   109,   112,   115,
   117,   160,   164,   166,   167,   173,   175,   177,   179,   181,
   187,   191,   193,   195,   197,   203,   206,   215,   217,   219,
   221,   223,   225,   227,   229
};

static const short yyrhs[] = {    50,
    66,     0,     3,     8,    44,    31,    45,     9,    44,    31,
    45,    10,    44,    31,    45,    11,    44,    31,    45,    51,
    56,    59,     0,     4,    52,     0,     4,     0,    52,    53,
     0,    53,     0,    29,    44,    46,    46,    54,    47,    55,
    48,    47,    46,    54,    47,    55,    48,    47,    46,    54,
    47,    55,    48,    47,    46,    54,    47,    55,    48,    47,
    46,    54,    47,    55,    48,    47,    46,    54,    47,    55,
    48,    48,    45,     0,    14,     0,    12,     0,    15,     0,
    13,     0,    16,     0,    17,     0,     5,    46,    57,    48,
    45,     0,    57,    47,    58,     0,    58,     0,    46,    31,
    47,    31,    47,    31,    47,    31,    48,     0,     6,    60,
     0,    60,    61,     0,    61,     0,    18,    44,    29,    47,
    19,    44,    30,    47,    20,    44,    46,    31,    47,    31,
    47,    31,    47,    31,    47,    31,    47,    31,    48,    47,
    21,    44,    31,    47,    22,    44,    46,    62,    48,    47,
    23,    44,    31,    47,    24,    44,    65,    45,     0,    62,
    47,    63,     0,    63,     0,     0,    46,    29,    47,    64,
    48,     0,    25,     0,    26,     0,    27,     0,    28,     0,
     7,    46,    67,    48,    45,     0,    67,    47,    68,     0,
    68,     0,    34,     0,    32,     0,    33,    69,    47,    29,
    48,     0,    69,    48,     0,    46,    31,    47,    70,    47,
    29,    47,    71,     0,    36,     0,    37,     0,    38,     0,
    39,     0,    40,     0,    41,     0,    42,     0,    31,     0
};

#endif

#if YY_SimulParser_DEBUG != 0
static const short yyrline[] = { 0,
   159,   166,   182,   183,   185,   186,   190,   211,   212,   213,
   214,   216,   217,   223,   226,   227,   229,   236,   239,   240,
   242,   258,   259,   260,   261,   269,   270,   273,   274,   280,
   284,   285,   288,   289,   290,   299,   303,   315,   316,   317,
   318,   319,   320,   321,   324
};

static const char * const yytname[] = {   "$","error","$illegal.","ENTETEPARAMETRES",
"ENTETEREGLES","ENTETECOLORMAP","ENTETEPHASES","ENTETELOCALISATION","NBPAS",
"FREQAFF","DIM","GERME","CNULLE","CMEMPHI","CPHIINFERIEUR","CPHIINFSOLIDE","Depl_IMPOSSIBLE",
"Depl_POSSIBLE","STRINGNOM","PHI","POND","COUL","REGLES","INERTIE","PROPAG",
"PREEXCLUSION","POSTEXCLUSION","VRAI","FAUX","NOM","NBRREEL","NBR","CP","CG",
"HS","C","CNC","CN","CS","CNE","CNO","CSE","CSO","TOK_BAD","'='","';'","'('",
"','","')'","Simul","SimulDebut","RegleSection","Regles","Regle","Contrainte",
"Deplacement","ColorMapSection","Couleurs","Couleur","PhaseSection","Phases",
"Phase","NomRegles","NomRegle","PrePost","Booleen","LocalisationSection","Cellules",
"Cellule","ContenuCellule","Provenance","NumCouleur",""
};
#endif

static const short yyr1[] = {     0,
    49,    50,    51,    51,    52,    52,    53,    54,    54,    54,
    54,    55,    55,    56,    57,    57,    58,    59,    60,    60,
    61,    62,    62,    62,    63,    64,    64,    65,    65,    66,
    67,    67,    68,    68,    68,    68,    69,    70,    70,    70,
    70,    70,    70,    70,    71
};

static const short yyr2[] = {     0,
     2,    20,     2,     1,     2,     1,    40,     1,     1,     1,
     1,     1,     1,     5,     3,     1,     9,     2,     2,     1,
    42,     3,     1,     0,     5,     1,     1,     1,     1,     5,
     3,     1,     1,     1,     5,     2,     8,     1,     1,     1,
     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     1,     0,     0,     0,    34,     0,
    33,     0,     0,    32,     0,     0,     0,     0,     0,     0,
    36,     0,     0,     0,    31,    30,     0,     0,    38,    39,
    40,    41,    42,    43,    44,     0,     0,    35,     0,     0,
     0,     0,     0,     0,    45,    37,     0,     0,     0,     0,
     0,     0,     4,     0,     0,     3,     6,     0,     0,     0,
     5,     0,     0,     2,     0,     0,     0,    16,     0,    18,
    20,     0,     0,     0,     0,     0,    19,     9,    11,     8,
    10,     0,     0,    15,    14,     0,     0,     0,     0,    12,
    13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    17,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
     0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
    22,     0,     0,    26,    27,     0,     0,     0,    25,     0,
     0,     0,     7,     0,     0,     0,    28,    29,     0,    21,
     0,     0,     0
};

static const short yydefgoto[] = {   181,
     2,    54,    56,    57,    82,    92,    59,    67,    68,    64,
    70,    71,   153,   154,   166,   179,     5,    13,    14,    15,
    36,    46
};

static const short yypact[] = {    20,
    22,    26,    -7,    -8,-32768,    10,   -30,    -5,-32768,    -4,
-32768,    12,   -34,-32768,    -3,    35,    -1,     0,   -30,     3,
-32768,    11,    21,   -31,-32768,-32768,    18,     8,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    13,    14,-32768,    24,    44,
    15,    17,    27,    32,-32768,-32768,    19,    46,    23,    34,
    25,    62,    39,    64,    28,    39,-32768,    29,    65,    30,
-32768,    31,    55,-32768,    33,    43,   -26,-32768,    36,    55,
-32768,     5,    37,    31,    38,    49,-32768,-32768,-32768,-32768,
-32768,    40,    50,-32768,-32768,    41,     9,    42,    63,-32768,
-32768,    45,    54,    47,    48,    51,    56,    53,    59,    57,
     5,    52,    72,    58,-32768,    66,     9,    60,    61,    70,
    67,    68,    71,    76,     5,    69,    73,    77,     9,    74,
    75,    80,    78,    79,    81,    82,     5,    83,    84,    87,
     9,    85,    86,    88,    89,    91,    92,    93,     5,    97,
    94,    95,     9,   100,    96,    99,    98,   101,   102,   103,
     5,    90,   -19,-32768,   104,   105,   103,   106,     9,     6,
-32768,   109,   107,-32768,-32768,   108,   110,   111,-32768,   115,
   112,   113,-32768,   116,   114,     7,-32768,-32768,   117,-32768,
   124,   129,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,   118,  -100,  -107,-32768,-32768,   119,-32768,
-32768,   120,-32768,   -63,-32768,-32768,-32768,-32768,   131,   151,
-32768,-32768
};


#define	YYLAST		193


static const short yytable[] = {   109,
   104,     9,    10,    11,    29,    30,    31,    32,    33,    34,
    35,   121,    19,    20,   117,    12,    78,    79,    80,    81,
    74,    75,     1,   133,    90,    91,   129,   157,   158,     3,
   164,   165,     4,   177,   178,   145,     6,     7,   141,    16,
     8,    12,    18,    22,    21,    23,    24,    26,    37,    28,
   155,   163,    41,    42,    27,    38,    49,    45,    40,    39,
    44,    43,    47,    48,    51,    53,    50,    55,    58,    52,
    63,    60,    69,    73,    62,    65,    66,    86,    72,    76,
    88,    94,    85,    83,    96,   100,    87,    89,    93,   102,
    97,   106,    95,   161,    98,     0,     0,    99,   101,   105,
   112,     0,     0,   103,   107,   110,   116,   120,   111,   108,
   124,   138,   128,   113,   114,   118,   115,   132,   156,   119,
   122,   146,   123,   182,   125,   126,   127,   142,   183,   130,
   131,   167,   134,   135,   136,   137,   140,   139,     0,   175,
   143,   144,   148,   147,   149,   172,   150,   151,   152,    25,
   159,   160,   162,   170,   168,   169,   173,   176,   171,   174,
    17,   180,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
     0,     0,    84
};

static const short yycheck[] = {   107,
   101,    32,    33,    34,    36,    37,    38,    39,    40,    41,
    42,   119,    47,    48,   115,    46,    12,    13,    14,    15,
    47,    48,     3,   131,    16,    17,   127,    47,    48,     8,
    25,    26,     7,    27,    28,   143,    44,    46,   139,    45,
    31,    46,    31,     9,    48,    47,    47,    45,    31,    29,
   151,   159,    29,    10,    44,    48,    11,    31,    45,    47,
    44,    47,    31,    45,    31,     4,    44,    29,     5,    45,
     6,    44,    18,    31,    46,    46,    46,    29,    46,    44,
    31,    19,    45,    47,    31,    30,    47,    47,    47,    31,
    44,    20,    48,   157,    47,    -1,    -1,    47,    46,    48,
    31,    -1,    -1,    47,    47,    46,    31,    31,    48,    44,
    31,    21,    31,    47,    47,    47,    46,    31,    29,    47,
    47,    22,    48,     0,    47,    47,    46,    31,     0,    47,
    47,    23,    48,    48,    47,    47,    44,    46,    -1,    24,
    47,    47,    44,    48,    47,    31,    46,    46,    46,    19,
    47,    47,    47,    44,    48,    48,    45,    44,    48,    47,
    10,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
    -1,    -1,    74
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

#if YY_SimulParser_USE_GOTO != 0
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
#define yyclearin       (YY_SimulParser_CHAR = YYEMPTY)
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
  if (YY_SimulParser_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_SimulParser_CHAR = (token), YY_SimulParser_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_SimulParser_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_SimulParser_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_SimulParser_PURE
/* UNPURE */
#define YYLEX           YY_SimulParser_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_SimulParser_CHAR;                      /*  the lookahead symbol        */
YY_SimulParser_STYPE      YY_SimulParser_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_SimulParser_NERRS;                 /*  number of parse errors so far */
#ifdef YY_SimulParser_LSP_NEEDED
YY_SimulParser_LTYPE YY_SimulParser_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_SimulParser_LSP_NEEDED
#define YYLEX           YY_SimulParser_LEX(&YY_SimulParser_LVAL, &YY_SimulParser_LLOC)
#else
#define YYLEX           YY_SimulParser_LEX(&YY_SimulParser_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_SimulParser_DEBUG != 0
int YY_SimulParser_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
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
 YY_SimulParser_CLASS::
#endif
     YY_SimulParser_PARSE(YY_SimulParser_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_SimulParser_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_SimulParser_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_SimulParser_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_SimulParser_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_SimulParser_LSP_NEEDED
  YY_SimulParser_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_SimulParser_LTYPE *yyls = yylsa;
  YY_SimulParser_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_SimulParser_PURE
  int YY_SimulParser_CHAR;
  YY_SimulParser_STYPE YY_SimulParser_LVAL;
  int YY_SimulParser_NERRS;
#ifdef YY_SimulParser_LSP_NEEDED
  YY_SimulParser_LTYPE YY_SimulParser_LLOC;
#endif
#endif

  YY_SimulParser_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_SimulParser_DEBUG != 0
  if (YY_SimulParser_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_SimulParser_NERRS = 0;
  YY_SimulParser_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_SimulParser_LSP_NEEDED
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
      YY_SimulParser_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_SimulParser_LSP_NEEDED
      YY_SimulParser_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_SimulParser_LSP_NEEDED
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
#ifdef YY_SimulParser_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_SimulParser_ERROR("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YY_SimulParser_STYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YY_SimulParser_LSP_NEEDED
      yyls = (YY_SimulParser_LTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_SimulParser_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_SimulParser_DEBUG != 0
      if (YY_SimulParser_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_SimulParser_DEBUG != 0
  if (YY_SimulParser_DEBUG_FLAG)
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

  if (YY_SimulParser_CHAR == YYEMPTY)
    {
#if YY_SimulParser_DEBUG != 0
      if (YY_SimulParser_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_SimulParser_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_SimulParser_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_SimulParser_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_SimulParser_DEBUG != 0
      if (YY_SimulParser_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_SimulParser_CHAR);

#if YY_SimulParser_DEBUG != 0
      if (YY_SimulParser_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_SimulParser_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_SimulParser_CHAR, YY_SimulParser_LVAL);
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

#if YY_SimulParser_DEBUG != 0
  if (YY_SimulParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_SimulParser_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_SimulParser_CHAR != YYEOF)
    YY_SimulParser_CHAR = YYEMPTY;

  *++yyvsp = YY_SimulParser_LVAL;
#ifdef YY_SimulParser_LSP_NEEDED
  *++yylsp = YY_SimulParser_LLOC;
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

#if YY_SimulParser_DEBUG != 0
  if (YY_SimulParser_DEBUG_FLAG)
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
#line 1313 "SimulParser.cpp"

  switch (yyn) {

case 1:
#line 160 "SimulParser.y"
{ 
	      _automate->connecteCellules(); 
	      delete listphases; ; delete listregles; // plus besoin
	      DEBUG_COMPILER(cerr << "Parser:" << "Fin Simul\n";)
            ;
    break;}
case 2:
#line 172 "SimulParser.y"
{
	    _automate = new Automate(yyvsp[-4].entier,yyvsp[-8].entier,yyvsp[-16].entier,yyvsp[-12].entier,*yyvsp[-2].vecregle,*yyvsp[-1].veccoul,*yyvsp[0].vecphase);
	    delete yyvsp[-1].veccoul; // delete colormap 
	  ;
    break;}
case 3:
#line 182 "SimulParser.y"
{ yyval.vecregle = yyvsp[0].vecregle; /* side effect */ listregles = yyvsp[0].vecregle;;
    break;}
case 4:
#line 183 "SimulParser.y"
{ yyval.vecregle = new list<RegleExclusion*>; listregles = yyval.vecregle;;
    break;}
case 5:
#line 185 "SimulParser.y"
{ (yyvsp[-1].vecregle)->push_back(yyvsp[0].regle); yyval.vecregle = yyvsp[-1].vecregle; ;
    break;}
case 6:
#line 186 "SimulParser.y"
{ list<RegleExclusion*>* vectmp = new list<RegleExclusion*>; vectmp->push_back(yyvsp[0].regle); yyval.vecregle = vectmp; ;
    break;}
case 7:
#line 197 "SimulParser.y"
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
case 8:
#line 211 "SimulParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_PHIINFERIEUR; ;
    break;}
case 9:
#line 212 "SimulParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_NULLE; ;
    break;}
case 10:
#line 213 "SimulParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_PHIINFSOLIDE; ;
    break;}
case 11:
#line 214 "SimulParser.y"
{ yyval.contr = RegleExclusion::CONTRAINTE_MEMEPHI;       ;
    break;}
case 12:
#line 216 "SimulParser.y"
{ yyval.depl = RegleExclusion::DEPLIMPOSSIBLE; ;
    break;}
case 13:
#line 217 "SimulParser.y"
{ yyval.depl = RegleExclusion::DEPLPOSSIBLE; ;
    break;}
case 14:
#line 223 "SimulParser.y"
{ yyval.veccoul = yyvsp[-2].veccoul; ;
    break;}
case 15:
#line 226 "SimulParser.y"
{ (yyvsp[-2].veccoul)->push_back(yyvsp[0].couleur); yyval.veccoul = yyvsp[-2].veccoul; ;
    break;}
case 16:
#line 227 "SimulParser.y"
{ list<Couleur*>* vectmp = new list<Couleur*>; vectmp->push_back(yyvsp[0].couleur); yyval.veccoul = vectmp; ;
    break;}
case 17:
#line 230 "SimulParser.y"
{ yyval.couleur = new Couleur(yyvsp[-7].entier, yyvsp[-5].entier, yyvsp[-3].entier, yyvsp[-1].entier); ;
    break;}
case 18:
#line 236 "SimulParser.y"
{ yyval.vecphase = yyvsp[0].vecphase; /* side effect */ listphases = yyvsp[0].vecphase;;
    break;}
case 19:
#line 239 "SimulParser.y"
{ (yyvsp[-1].vecphase)->push_back(yyvsp[0].phase); yyval.vecphase = yyvsp[-1].vecphase; ;
    break;}
case 20:
#line 240 "SimulParser.y"
{ list<Phase*>* vectmp = new list<Phase*>; vectmp->push_back(yyvsp[0].phase); yyval.vecphase = vectmp; ;
    break;}
case 21:
#line 249 "SimulParser.y"
{ 
	    int tabPond[6] = {yyvsp[-30].entier,yyvsp[-28].entier,yyvsp[-26].entier,yyvsp[-24].entier,yyvsp[-22].entier,yyvsp[-20].entier};
	    yyval.phase = new Phase(yyvsp[-39].Nom, yyvsp[-35].reel, yyvsp[-1].Bool, yyvsp[-5].entier, Ponderation(tabPond) ,*(yyvsp[-10].vecRegleEtMode));
	    yyval.phase->setCouleur(yyvsp[-15].entier);
	    delete yyvsp[-10].vecRegleEtMode; // plus besoin
			   
	  ;
    break;}
case 22:
#line 258 "SimulParser.y"
{ (yyvsp[-2].vecRegleEtMode)->push_back(yyvsp[0].regleEtMode); yyval.vecRegleEtMode = yyvsp[-2].vecRegleEtMode; ;
    break;}
case 23:
#line 259 "SimulParser.y"
{ list<Phase::RegleEtMode>* vectmp = new list<Phase::RegleEtMode>; vectmp->push_back(yyvsp[0].regleEtMode); yyval.vecRegleEtMode = vectmp; ;
    break;}
case 24:
#line 260 "SimulParser.y"
{ list<Phase::RegleEtMode>* vectmp = new list<Phase::RegleEtMode>; yyval.vecRegleEtMode = vectmp; ;
    break;}
case 25:
#line 262 "SimulParser.y"
{ 
	     RegleExclusion* tmpRegle = recherchePtrRegle(yyvsp[-3].Nom);
	     yyval.regleEtMode.mode = yyvsp[-1].modeExclusion;
	     yyval.regleEtMode.regle = tmpRegle;
	   ;
    break;}
case 26:
#line 269 "SimulParser.y"
{ yyval.modeExclusion = RegleExclusion::PRE  ;;
    break;}
case 27:
#line 270 "SimulParser.y"
{ yyval.modeExclusion = RegleExclusion::POST ;;
    break;}
case 28:
#line 273 "SimulParser.y"
{ yyval.Bool = true; ;
    break;}
case 29:
#line 274 "SimulParser.y"
{ yyval.Bool = false; ;
    break;}
case 30:
#line 281 "SimulParser.y"
{ DEBUG_COMPILER(cerr << "Parser:" << "Fin Localisation\n";);
    break;}
case 31:
#line 284 "SimulParser.y"
{ _automate->ajoutCellule(yyvsp[0].cellule); DEBUG_COMPILER(cerr << "Parser:" << "Ajout Cellule2\n";);
    break;}
case 32:
#line 285 "SimulParser.y"
{ _automate->ajoutCellule(yyvsp[0].cellule); DEBUG_COMPILER(cerr << "Parser:" << "Ajout Cellule1\n";);
    break;}
case 33:
#line 288 "SimulParser.y"
{ yyval.cellule = new CelluleHorsScene(); DEBUG_COMPILER(cerr << "Parser:" << "Hs\n";);
    break;}
case 34:
#line 289 "SimulParser.y"
{ yyval.cellule = new CelluleParoi(); DEBUG_COMPILER(cerr << "Parser:" << "Cp\n";);
    break;}
case 35:
#line 291 "SimulParser.y"
{ 
	      Phase* phase = recherchePtrPhase(yyvsp[-1].Nom);
	      CelluleGeneratrice* cell;
	      cell = new CelluleGeneratrice(yyvsp[-3].particule,phase);
	      cell->setAutomate(_automate);
	      yyval.cellule = cell;

	    ;
    break;}
case 36:
#line 299 "SimulParser.y"
{ yyval.cellule = new CelluleAvecParticule(yyvsp[-1].particule); DEBUG_COMPILER(cerr << "Parser:" << "Norm\n";);
    break;}
case 37:
#line 304 "SimulParser.y"
{
		  DEBUG_COMPILER(cerr << "Parser:" << "Nom =" << yyvsp[-2].Nom << "\n";)
		  Phase * phase = recherchePtrPhase(yyvsp[-2].Nom);
		  
		  yyval.particule = new Particule(yyvsp[-6].entier, phase, NULL, Requete(yyvsp[-4].dirreq), false, yyvsp[0].entier);
		  _automate->ajoutParticule(yyval.particule);

		  DEBUG_COMPILER(cerr << "Parser:" << "Fin Contenu\n";)
		    ;
    break;}
case 38:
#line 315 "SimulParser.y"
{ yyval.dirreq = RIEN; DEBUG_COMPILER(cerr << "Parser:" << "Provenance NC\n";) ;
    break;}
case 39:
#line 316 "SimulParser.y"
{ yyval.dirreq = NORD; DEBUG_COMPILER(cerr << "Parser:" << "Provenance N\n";) ;
    break;}
case 40:
#line 317 "SimulParser.y"
{ yyval.dirreq = SUD;  DEBUG_COMPILER(cerr << "Parser:" << "Provenance S\n";) ;
    break;}
case 41:
#line 318 "SimulParser.y"
{ yyval.dirreq = NE;   DEBUG_COMPILER(cerr << "Parser:" << "Provenance NE\n";) ;
    break;}
case 42:
#line 319 "SimulParser.y"
{ yyval.dirreq = NW;   DEBUG_COMPILER(cerr << "Parser:" << "Provenance NO\n";) ;
    break;}
case 43:
#line 320 "SimulParser.y"
{ yyval.dirreq = SE;   DEBUG_COMPILER(cerr << "Parser:" << "Provenance SE\n";) ;
    break;}
case 44:
#line 321 "SimulParser.y"
{ yyval.dirreq = SW;   DEBUG_COMPILER(cerr << "Parser:" << "Provenance SO\n";) ;
    break;}
case 45:
#line 324 "SimulParser.y"
{ yyval.entier = yyvsp[0].entier; ;
    break;}
}

#line 783 "/tmp/bison++/lib/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_SimulParser_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_SimulParser_DEBUG != 0
  if (YY_SimulParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_SimulParser_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_SimulParser_LLOC.first_line;
      yylsp->first_column = YY_SimulParser_LLOC.first_column;
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
      ++YY_SimulParser_NERRS;

#ifdef YY_SimulParser_ERROR_VERBOSE
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
	      YY_SimulParser_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_SimulParser_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_SimulParser_ERROR_VERBOSE */
	YY_SimulParser_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_SimulParser_CHAR == YYEOF)
	YYABORT;

#if YY_SimulParser_DEBUG != 0
      if (YY_SimulParser_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_SimulParser_CHAR, yytname[yychar1]);
#endif

      YY_SimulParser_CHAR = YYEMPTY;
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
#ifdef YY_SimulParser_LSP_NEEDED
  yylsp--;
#endif

#if YY_SimulParser_DEBUG != 0
  if (YY_SimulParser_DEBUG_FLAG)
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

#if YY_SimulParser_DEBUG != 0
  if (YY_SimulParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_SimulParser_LVAL;
#ifdef YY_SimulParser_LSP_NEEDED
  *++yylsp = YY_SimulParser_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 982 "/tmp/bison++/lib/bison.cc" */
#line 1744 "SimulParser.cpp"
#line 327 "SimulParser.y"


RegleExclusion * SimulParser::recherchePtrRegle(string nomRegle)
{
    list<RegleExclusion*>::iterator it_regles;
    
    for (it_regles = listregles->begin(); it_regles != listregles->end(); it_regles++)
      if ((*it_regles)->getNom() == nomRegle) return (*it_regles) ;

    cerr << "recherchePtrRegle: Regle non connue" << endl;
    return NULL;
}

Phase * SimulParser::recherchePtrPhase(string nomPhase)
{
    DEBUG_COMPILER(cerr << "recherchePtrPhase:" << "Nom =" << nomPhase << "\n";)
    
    list<Phase*>::iterator it_phases ;

    for (it_phases = listphases->begin(); it_phases != listphases->end(); it_phases++)
      if ((*it_phases)->getNom() == nomPhase) return (*it_phases) ;

    cerr << "recherchePtrPhase: Phase non connue" << endl;
    return NULL;
}



