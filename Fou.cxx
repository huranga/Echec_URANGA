#include <iostream>
#include "Piece.h"
#include <assert.h>
#include "Echiquier.h"
#include <cstddef>

using namespace std;

Fou::Fou( bool white, bool left ) : Piece((left)?3:6,(white)?1:8,white)
{
    cout << "Construction Fou specialisee" << endl;
}

bool
Fou::mouvementValide(Echiquier & e, int x, int y)
{
    Piece* tmp = e.getPiece(x,y);
    assert(x<7 && x>0 && y<7 && y>0);

    if(tmp == NULL)
    {
        if(m_y == y + 1 && m_white)
        {
            if(m_x == x + 1 || m_x == x - 1)
                return true;
        }

        else if(m_y == y - 1 && !m_white)
        {
            if(m_x == x + 1 || m_x == x - 1)
                return true;
        }

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

    /* cout << "mouvementValide de Fou" << endl;
     return false; */
}

char
Fou::myChar()
{
    return m_white?'F':'f';
}
