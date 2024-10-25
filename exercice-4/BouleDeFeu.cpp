#include "BouleDeFeu.h"
#include <iostream>



BouleDeFeu::BouleDeFeu( const Vector2& position, const Vector2& direction,const float speed, const float damage, const float radius ):
    Projectile( position, direction, speed, damage ),
    m_radius( radius ) {}



void BouleDeFeu::OnImpact()
{
    std::cout << "Boule de feu explose aux coordonnees {" << m_position.x << "; " << m_position.y << "} avec un radius de " << m_radius << " !\n";
    m_speed = 0.0f;
}

