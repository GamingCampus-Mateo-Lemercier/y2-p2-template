#include "Personnage.h"



Personnage::Personnage():
    m_health( 100.0f ),
    m_maxHealth( 100.0f ),
    m_defense( 5 ),
    m_damage( 10.0f ) {}

Personnage::Personnage( const float health, const float maxHealth, const int defense, const float damage ):
    m_health( health ),
    m_maxHealth( maxHealth ),
    m_defense( defense ),
    m_damage( damage ) {}



float Personnage::GetHealth() const { return m_health; }

float Personnage::GetMaxHealth() const { return m_maxHealth; }

int Personnage::GetDefense() const { return m_defense; }

float Personnage::GetDamage() const { return m_damage; }



void Personnage::SetHealth( const float health ) { m_health = health; }

void Personnage::SetMaxHealth( const float maxHealth ) { m_maxHealth = maxHealth; }

void Personnage::SetDefense( const int defense ) { m_defense = defense; }

void Personnage::SetDamage( const float damage ) { m_damage = damage; }

