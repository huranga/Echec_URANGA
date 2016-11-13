#include <iostream>
#include <assert.h>
#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{
  cout << "Construction Joueur par defaut" << endl;
}

Joueur::Joueur(bool white)
{
  Roi *r = new Roi(white);
  m_pieces.push_back(r);
  Reine *q = new Reine(white);
  m_pieces.push_back(q);
  Tour *tg = new Tour(white,true);
  m_pieces.push_back(tg);
  Tour *td = new Tour(white,false);
  m_pieces.push_back(td);
  Cavalier *cg = new Cavalier(white,true);
  m_pieces.push_back(cg);
  Cavalier *cd = new Cavalier(white,false);
  m_pieces.push_back(cd);
  Fou *fg = new Fou(white,true);
  m_pieces.push_back(fg);
  Fou *fd = new Fou(white,false);
  m_pieces.push_back(fd);
  Pion *p;
  for (int i=1; i<=8; i++)
    {
      p  = new Pion(white,i);
      m_pieces.push_back(p);      
    }
  cout << "Construction Joueur specialise" << endl;
}

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
  cout << "Construction Joueur Blanc par defaut" << endl;
}

JoueurNoir::JoueurNoir() : Joueur(false)
{
  cout << "Construction Joueur Noir par defaut" << endl;
}

Joueur::~Joueur()
{
  cout << "Destruction Joueur" << endl;
}

void
Joueur::affiche()
{
  /*
  for (int i=0;i<16;i++)
    m_pieces[i]->affiche();
  */
  vector<Piece*>::iterator p=m_pieces.begin();
  while (p!=m_pieces.end())
    {
      (*p)->affiche();
      p++;
    }
}

/*
bool
Joueur::isWhite()
{
  return m_pieces[0].isWhite();
}
*/

bool
JoueurBlanc::isWhite()
{
  return true;
}

bool
JoueurNoir::isWhite()
{
  return false;
}

void
Joueur::placerPieces(Echiquier & e)
{
  for (int i=0;i<16;i++)
    {
      bool ok=e.placer(m_pieces[i]);
      assert(ok);
    }
}
