#include "env.h"
#include "lexico.h"
#include "gener.h"
#include "system.h"
{declaration des constantes,types,variables et procedures necessaires aux
 points de generation.

 NE PAS EMPLOYER d'identificateurs se terminant par le caractere '_' (sinon
 risque de conflit avec les identificateurs manipules par l'analyseur
 lexicographique et l'analyseur syntaxique)

 IDENTIFICATEURS RESERVES:
 ------------------------
         cf         configuration
         derlu
         errone
         idlu       impmess       instable
         lgid       lgmess        lib
         nberr      numid
         messerr
         placerid
         repid
         stable
         tligne     typid         typmess
         valnb      valreel

ces identificateurs ont la signification suivante:

const
  lgid=32; /longueur maximum d'un identificateur/
  lgmess=79; /longueur maximum d'un message d'erreur et d'un libelle/

type
  configuration=(errone,instable,stable);
           /indication sur l'etat de l'analyseur syntaxique:
            errone a la detection d'une erreur de syntaxe
            instable au cours de la reprise
            stable tant qu'aucune erreur de syntaxe n'est detectee ou
                   en cours de reprise apres 2 lectures consecutives correctes
           /
  typid=string[lgid]; /identificateur/
  typmess=string[lgmess]; /message d'erreur ou libelle/

var
  cf:configuration;
  derlu:integer; /code du dernier terminal lu/
  valnb:integer; /valeur du dernier nombre entier lu/
  idlu:typid;numid:integer; /dernier ident lu et son code/
  lib:typmess; /dernier libelle lu/
  valreel:real; /dernier reel lu/
  nberr:integer; /compteur du nombre d'erreurs detectees/

procedure impmess(m:typmess;etoile:boolean);
  /ecrit m a l'ecran et dans le .list, et , si etoile est vrai:
     .affichage des 2 dernieres lignes sources a l'ecran
     .etoile positionnee sous le dernier caractere du symbole errone
     .nberr+:=1
   (le cas etoile=false est destine a l'ecriture d'un "warning")
  /

procedure messerr(m:typmess);
  /impmess(m,true)/

procedure repid(nid:integer;var id:typid);
  /obtention de la representation d'un identificateur a partir de son code/

procedure placerid(id:typid;var nid:integer);
  /permet de placer l'identificateur id dans la table des idents et
   d'obtenir son code (utile pour placer ,en debut de compilation, des
   identificateurs predefinis
  /
}

procedure executer;
begin writeln('executer');
  case i of
  0:;
  1: writeln(1);
  2: writeln(2);
  otherwise {writeln('point de generation',i:5,' non ecrit')} end
end;{executer}

{
pc -o gener.o -c -C gener.p
}
