/*******************************************************************************
 *
 * Copyright (C) 1999-2000 by Y. Padioleau, G. Cottenceau, P. Garcia,
 *   G. LeGuelvouit, Y. Zemali, S. Crunchant, X. Michard.
 *
 * Please check out README.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 ******************************************************************************/


#ifndef _ENTREESORTIE_H_
#define _ENTREESORTIE_H_

#include "CommunFichiers.h"

#include "RegleExclusion.h"
#include "Frontiere.h"
#include "Couleur.h"


#include "Figures.h"
#include "Scene.h"


#include "ioManager.h"

#include "RegleCompiler.h"
#include "FrontiereCompiler.h"
#include "SceneCompiler.h"
#include "SimulCompiler.h"


/*
 * J'ai mis tous ca la pour pas que le moteur soit independant des fichiers.
 * J'aurais pu mettre tout ca dans le moteur, avec des methodes virtuelles
 * et tout est tout, mais au moins comme ca, tout ce qui touche au fichier
 * est au meme endroit. Si on change les specs des fichiers, on touchera pas
 * au moteur.
 *
 */

class RegleIoManager : public ioManager<RegleExclusion>
{
public:
  RegleExclusion* lire(istream& is);
  void ecrire(const RegleExclusion& reg, ostream& os) const;
};


ostream& operator<<(ostream& os,const list<Frontiere*> &liste);
istream& operator>>(istream& is,list<Frontiere*> &liste);

class StaticIOs
{
 public:
  static int parseMesFrontieres(istream &, list<Frontiere*> &);
  static int parseMaScene(istream &, Scene &);
  static int parseMaRegle(istream &, RegleExclusion &);
  static int parseMaSimul(istream &, Automate &);
};


// Les figures
class LigneIoManager : public ioManager<Ligne>
{
public:
  void ecrire(const Ligne& el, ostream& os) const;
};

class RectangleIoManager : public ioManager<Rectangle>
{
public:
  void ecrire(const Rectangle& el, ostream& os) const;
};

class PolygoneIoManager : public ioManager<Polygone>
{
public:
  void ecrire(const Polygone& el, ostream& os) const;
};
class EllipseIoManager : public ioManager<Ellipse>
{
public:
  void ecrire(const Ellipse& el, ostream& os) const;
};
class ArcEllipseIoManager : public ioManager<ArcEllipse>
{
public:
  void ecrire(const ArcEllipse& el, ostream& os) const;
};

// La scene
class SceneIoManager : public ioManager<Scene>
{
public:
  Scene* lire(istream& is);
  void ecrire(const Scene& el, ostream& os) const;
};


// couleur
class CouleurIoManager : public ioManager<Couleur>
{
public:
  void ecrire(const Couleur& el, ostream& os) const;
};

// Phase
class PhaseIoManager : public ioManager<Phase>
{
public:
  void ecrire(const Phase& el, ostream& os) const;
};

//Ponderation
class PonderationIoManager : public ioManager<Ponderation>
{
public:
  void ecrire(const Ponderation& el, ostream& os) const;
};

// zonage
class ZonageIoManager : public ioManager<Zonage>
{
public:
  void ecrire(const Zonage& el, ostream& os) const;
};

class ContientHorsSceneIoManager : public ioManager<ContientHorsScene>
{
public:
  void ecrire(const ContientHorsScene& el, ostream& os) const;
};

class ContientPhaseIoManager : public ioManager<ContientPhase>
{
public:
  void ecrire(const ContientPhase& el, ostream& os) const;
};


// Coloration
class ColorationIoManager : public ioManager<Coloration>
{
public:
  void ecrire(const Coloration& el, ostream& os) const;
};


// automate
class AutomateIoManager : public ioManager<Automate>
{
public:
  Automate* lire(istream& is);
  void ecrire(const Automate& el, ostream& os) const;
};


// Les cellules.
class CelluleHorsSceneIoManager : public ioManager<CelluleHorsScene>
{
public:
  void ecrire(const CelluleHorsScene& el, ostream& os) const;
};
class CelluleParoiIoManager : public ioManager<CelluleParoi>
{
public:
  void ecrire(const CelluleParoi& el, ostream& os) const;
};

class CelluleAvecParticuleIoManager : public ioManager<CelluleAvecParticule>
{
public:
  void ecrire(const CelluleAvecParticule& el, ostream& os) const;
};

class CelluleGeneratriceIoManager : public ioManager<CelluleGeneratrice>
{
public:
  void ecrire(const CelluleGeneratrice& el, ostream& os) const;
};


#endif

