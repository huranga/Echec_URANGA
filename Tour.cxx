#include <iostream>
#include "Piece.h"
#include "Echiquier.h"
#include <cstddef>
#include <assert.h>

using namespace std;

Tour::Tour( bool white, bool left ) : Piece((left)?1:8,(white)?1:8,white)
{
  cout << "Construction Tour specialisee" << endl;
}

bool
Tour::mouvementValide(Echiquier & e, int x, int y)
{
    Piece* tmp = e.getPiece(x,y);

    assert(x<7 && x>0 && y<7 && y>0);

    if(m_y < y && m_white)
    {
        return true;
    }

    else if(m_x < x && m_white)
    {
        return true;
    }

    else if(m_y > y && !m_white){
        return true;
    }

    else if(m_x < y && !m_white){
        return true;
    }

   else if(tmp!= NULL)
    {
        if((tmp->isWhite() == true && this->isWhite() == true) || (tmp->isWhite()==false && this->isWhite()== false))
        {
            cout <<"Case occupée par une pièce "<<endl;
            return false;
        }
    }
    else if((tmp->isWhite() == true && this->isWhite() == false) || (tmp->isWhite() == false && this->isWhite()== true))
    {
        e.enleverPiece(x,y);
        e.deplacer(this,x,y);
        //cout <<"Manger!"<< endl;
        return true;
    }
}

char
Tour::myChar()
{
  return m_white?'T':'t';
}
