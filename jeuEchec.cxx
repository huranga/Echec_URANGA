#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare(const Piece &p1, const Piece &p2)
{
    return (p1.x()==p2.x()) && (p1.y()==p2.y());
}

bool echec(){
    int x, y;
    for(x = 0; x<9; x++)
    {
        for(y = 0; y<9; y++)
        {
            if(e.getPiece(x, y)->myChar() != 'r'){
                cout << "Joueur Blanc a gagne" << endl;
                return true;
            }
            else if(e.getPiece(x, y)->myChar() != 'R'){
                cout << "Joueur Noir a gagne" << endl;
                return true;
            }
            else if (e.getPiece(x, y)->myChar() == 'r' && e.getPiece(x, y)->myChar() == 'R'){
                return false;
                break;
            }
        }
        break;
    }
}

int main( int argc, char** argv )
{
    Echiquier e;
    JoueurBlanc jb;
    JoueurNoir jn;

    jb.affiche();
    jn.affiche();

    jb.placerPieces(e);
    jn.placerPieces(e);

    e.affiche();
    int x, y ;
    int m_x, m_y;

    while(!echec())
    {
        cout << "Au tour du joueur blanc"<< endl;

        cout<<"Coordonnees de la piece a deplacer: ";
        cin >> m_x;
        cin >> m_y;

        cout<<"Veuillez choisir les coordonnees de deplacement de la piece: ";
        cin>>x;
        cin>>y;

        if(e.getPiece(m_x, m_y)->mouvementValide(e, x, y))
        {
            e.deplacer(e.getPiece(m_x, m_y), x, y);
            e.enleverPiece(m_x, m_y);
        }
        else
            cout << "Mouvement Invalide" << endl;

        e.affiche();

        cout << "Au tour du joueur noir"<< endl;

        cout<<"Coordonnees de la piece a deplacer: ";
        cin >> m_x;
        cin >> m_y;

        cout<<"Veuillez choisir les coordonnees de deplacement de la piece: ";
        cin>>x;
        cin>>y;

        if(e.getPiece(m_x, m_y)->mouvementValide(e, x, y))
        {
            e.deplacer(e.getPiece(m_x, m_y), x, y);
            e.enleverPiece(m_x, m_y);
        }
        else
            cout << "Mouvement Invalide" << endl;

        e.affiche();
    }
}
