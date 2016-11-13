#include <iostream>
#include "Piece.h"
#include "Echiquier.h"
#include <cstddef>
#include <assert.h>

using namespace std;

Pion::Pion( bool white, int p ) : Piece(p,(white)?2:7,white)
{
    cout << "Construction Pion specialisee" << endl;
}

bool
Pion::mouvementValide(Echiquier& e, int x, int y)
{
    Piece* tmp = e.getPiece(x,y);
    assert(x<7 && x>0 && y<7 && y>0);

    if(tmp == NULL)
    {
        if(m_y == y - 1 && m_white)
            return true;
        else if(m_y == y + 1 && !m_white)
            return true;
    }

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
Pion::myChar()
{
    return m_white?'P':'p';
}
