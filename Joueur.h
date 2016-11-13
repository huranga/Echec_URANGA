/** 
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include <vector>
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

class Joueur { // non instanciable -> classe abstraite
 protected:
  vector<Piece*> m_pieces;
  //Piece m_pieces[16];
  
 public:
  Joueur();
  ~Joueur();
  Joueur(bool white);
  void affiche();
  virtual bool isWhite()=0; // methode virtuelle pure
  void placerPieces(Echiquier & e);
};

class JoueurBlanc : public Joueur {
 public:
  JoueurBlanc();
  bool isWhite();
};

class JoueurNoir : public Joueur {
 public:
  JoueurNoir();
  bool isWhite();
};

#endif
