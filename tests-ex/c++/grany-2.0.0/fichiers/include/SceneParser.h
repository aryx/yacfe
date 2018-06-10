#ifndef YY_SceneParser_h_included
#define YY_SceneParser_h_included

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
#line 21 "../include/SceneParser.h"
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

#line 14 "/tmp/bison++/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
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
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_SceneParser_STYPE 
#define YY_SceneParser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_SceneParser_DEBUG
#define  YY_SceneParser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
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

/* #line 63 "/tmp/bison++/lib/bison.h" */
#line 172 "../include/SceneParser.h"

#line 63 "/tmp/bison++/lib/bison.h"
/* YY_SceneParser_PURE */
#endif

/* #line 65 "/tmp/bison++/lib/bison.h" */
#line 179 "../include/SceneParser.h"

#line 65 "/tmp/bison++/lib/bison.h"
/* prefix */
#ifndef YY_SceneParser_DEBUG

/* #line 67 "/tmp/bison++/lib/bison.h" */
#line 186 "../include/SceneParser.h"

#line 67 "/tmp/bison++/lib/bison.h"
/* YY_SceneParser_DEBUG */
#endif
#ifndef YY_SceneParser_LSP_NEEDED

/* #line 70 "/tmp/bison++/lib/bison.h" */
#line 194 "../include/SceneParser.h"

#line 70 "/tmp/bison++/lib/bison.h"
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

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_SceneParser_PURE
extern YY_SceneParser_STYPE YY_SceneParser_LVAL;
#endif


/* #line 143 "/tmp/bison++/lib/bison.h" */
#line 272 "../include/SceneParser.h"
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


#line 143 "/tmp/bison++/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
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

/* #line 182 "/tmp/bison++/lib/bison.h" */
#line 353 "../include/SceneParser.h"
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


#line 182 "/tmp/bison++/lib/bison.h"
 /* decl const */
#else
enum YY_SceneParser_ENUM_TOKEN { YY_SceneParser_NULL_TOKEN=0

/* #line 185 "/tmp/bison++/lib/bison.h" */
#line 398 "../include/SceneParser.h"
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


#line 185 "/tmp/bison++/lib/bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_SceneParser_PARSE(YY_SceneParser_PARSE_PARAM);
 virtual void YY_SceneParser_ERROR(char *msg) YY_SceneParser_ERROR_BODY;
#ifdef YY_SceneParser_PURE
#ifdef YY_SceneParser_LSP_NEEDED
 virtual int  YY_SceneParser_LEX(YY_SceneParser_STYPE *YY_SceneParser_LVAL,YY_SceneParser_LTYPE *YY_SceneParser_LLOC) YY_SceneParser_LEX_BODY;
#else
 virtual int  YY_SceneParser_LEX(YY_SceneParser_STYPE *YY_SceneParser_LVAL) YY_SceneParser_LEX_BODY;
#endif
#else
 virtual int YY_SceneParser_LEX() YY_SceneParser_LEX_BODY;
 YY_SceneParser_STYPE YY_SceneParser_LVAL;
#ifdef YY_SceneParser_LSP_NEEDED
 YY_SceneParser_LTYPE YY_SceneParser_LLOC;
#endif
 int YY_SceneParser_NERRS;
 int YY_SceneParser_CHAR;
#endif
#if YY_SceneParser_DEBUG != 0
public:
 int YY_SceneParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_SceneParser_CLASS(YY_SceneParser_CONSTRUCTOR_PARAM);
public:
 YY_SceneParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_SceneParser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_SceneParser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_SceneParser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_SceneParser_DEBUG 
#define YYDEBUG YY_SceneParser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "/tmp/bison++/lib/bison.h" */
#line 491 "../include/SceneParser.h"
#endif
