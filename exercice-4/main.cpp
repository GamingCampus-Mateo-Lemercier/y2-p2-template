#include <iostream>
#include "Vector2.h"
#include "Projectile.hpp"
#include "Fleche.h"
#include "BouleDeFeu.h"



int main()
{
    Fleche fleche( Vector2(-10.128f, 0.0f), Vector2(1.0f, 0.0f), 2.0f, 5 );
    BouleDeFeu bouleDeFeu( Vector2(9.0f, 0.0f), Vector2(-1.0f, 0.0f), 0.75f, 10.0f, 5.0f );
    for ( int i = 0; i < 12; i++ )
    {
        fleche.Move();
        if ( i == 2 || i == 5 || i == 10 )
            fleche.OnImpact();
        bouleDeFeu.Move();
        if ( fleche.GetSpeed() <= 0.1f )
        {
            std::cout << "Fleche s'est arretee aux coordonnees {" << fleche.GetPosition().x << "; " << fleche.GetPosition().y << "}\n";
            fleche.SetSpeed( 0.0f );
        }
    }
    fleche.OnImpact();
    bouleDeFeu.OnImpact();
    return 0;
}