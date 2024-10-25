#include "Fleche.h"
#include <iostream>



Fleche::Fleche( const Vector2& position, const Vector2& direction, const float speed, const int damage ):
    Projectile<int>( position, direction, speed, damage ) {}



void Fleche::OnImpact()
{
    std::cout << "Fleche transperce un ennemi avec une vitesse de " << m_speed << " aux coordonnees {" << m_position.x << "; " << m_position.y << "} !\n";
    m_speed *= 0.4;
}
