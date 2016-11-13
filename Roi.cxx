#include <iostream>
#include "Piece.h"
#include "Echiquier.h"
#include <cstddef>
#include <assert.h>

using namespace std;

Roi::Roi( bool white ) : Piece(5,(white)?1:8,white)
{
  cout << "Construction Roi specialisee" << endl;
}

bool
Roi::mouvementValide(Echiquier & e, int x, int y)
{
  Piece* tmp = e.getPiece(x,y);
    assert(x<7 && x>0 && y<7 && y>0);
    if((m_y == y - 1 || m_x == x - 1 || m_y == y + 1 || m_x == x + 1 ) && tmp == NULL)
        return true;
    else if(tmp!= NULL)
    {
        if((tmp->isBlack() == true && this->isBlack() == true) || (tmp->isBlack()==false && this->isBlack()== false))
        {
            cout <<"Case occupée par une pièce "<<endl;
            return false;
        }
    }
    else if((tmp->isBlack() == true && this->isBlack() == false) || (tmp->isBlack() == false && this->isBlack()== true))
    {
        e.enleverPiece(x,y);
        e.deplacer(this,x,y);
        //cout <<"Manger!"<< endl;
        return true;
    }
}

char
Roi::myChar()
{
  return m_white?'R':'r';
}

void
Roi::roque(bool left)
{
  cout << "roque " << (left?"gauche":"droit") << " de Roi" << endl;
}
