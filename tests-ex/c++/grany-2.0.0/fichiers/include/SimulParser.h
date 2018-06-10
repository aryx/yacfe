#ifndef YY_SimulParser_h_included
#define YY_SimulParser_h_included

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
#line 21 "../include/SimulParser.h"
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

#line 14 "/tmp/bison++/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
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
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_SimulParser_STYPE 
#define YY_SimulParser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_SimulParser_DEBUG
#define  YY_SimulParser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
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

/* #line 63 "/tmp/bison++/lib/bison.h" */
#line 154 "../include/SimulParser.h"

#line 63 "/tmp/bison++/lib/bison.h"
/* YY_SimulParser_PURE */
#endif

/* #line 65 "/tmp/bison++/lib/bison.h" */
#line 161 "../include/SimulParser.h"

#line 65 "/tmp/bison++/lib/bison.h"
/* prefix */
#ifndef YY_SimulParser_DEBUG

/* #line 67 "/tmp/bison++/lib/bison.h" */
#line 168 "../include/SimulParser.h"

#line 67 "/tmp/bison++/lib/bison.h"
/* YY_SimulParser_DEBUG */
#endif
#ifndef YY_SimulParser_LSP_NEEDED

/* #line 70 "/tmp/bison++/lib/bison.h" */
#line 176 "../include/SimulParser.h"

#line 70 "/tmp/bison++/lib/bison.h"
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

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_SimulParser_PURE
extern YY_SimulParser_STYPE YY_SimulParser_LVAL;
#endif


/* #line 143 "/tmp/bison++/lib/bison.h" */
#line 254 "../include/SimulParser.h"
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


#line 143 "/tmp/bison++/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
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

/* #line 182 "/tmp/bison++/lib/bison.h" */
#line 340 "../include/SimulParser.h"
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


#line 182 "/tmp/bison++/lib/bison.h"
 /* decl const */
#else
enum YY_SimulParser_ENUM_TOKEN { YY_SimulParser_NULL_TOKEN=0

/* #line 185 "/tmp/bison++/lib/bison.h" */
#line 390 "../include/SimulParser.h"
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


#line 185 "/tmp/bison++/lib/bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_SimulParser_PARSE(YY_SimulParser_PARSE_PARAM);
 virtual void YY_SimulParser_ERROR(char *msg) YY_SimulParser_ERROR_BODY;
#ifdef YY_SimulParser_PURE
#ifdef YY_SimulParser_LSP_NEEDED
 virtual int  YY_SimulParser_LEX(YY_SimulParser_STYPE *YY_SimulParser_LVAL,YY_SimulParser_LTYPE *YY_SimulParser_LLOC) YY_SimulParser_LEX_BODY;
#else
 virtual int  YY_SimulParser_LEX(YY_SimulParser_STYPE *YY_SimulParser_LVAL) YY_SimulParser_LEX_BODY;
#endif
#else
 virtual int YY_SimulParser_LEX() YY_SimulParser_LEX_BODY;
 YY_SimulParser_STYPE YY_SimulParser_LVAL;
#ifdef YY_SimulParser_LSP_NEEDED
 YY_SimulParser_LTYPE YY_SimulParser_LLOC;
#endif
 int YY_SimulParser_NERRS;
 int YY_SimulParser_CHAR;
#endif
#if YY_SimulParser_DEBUG != 0
public:
 int YY_SimulParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_SimulParser_CLASS(YY_SimulParser_CONSTRUCTOR_PARAM);
public:
 YY_SimulParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_SimulParser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_SimulParser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_SimulParser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_SimulParser_DEBUG 
#define YYDEBUG YY_SimulParser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "/tmp/bison++/lib/bison.h" */
#line 488 "../include/SimulParser.h"
#endif
