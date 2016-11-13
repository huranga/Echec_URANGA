#include <iostream>
#include "Piece.h"
#include <assert.h>

using namespace std;

Reine::Reine( bool white ) : Piece(4,(white?1:8),white), Fou(white,true), Tour(white,true)
{
  //  m_x = 4;
  //  m_y = (white)?1:8;
  //  m_white = white;
  cout << "Construction Reine specialisee" << endl;
}

bool
Reine::mouvementValide(Echiquier & e, int x, int y)
{
  return Fou::mouvementValide(e,x,y) || Tour::mouvementValide(e,x,y);
}

char
Reine::myChar()
{
  return m_white?'Q':'q';
}
