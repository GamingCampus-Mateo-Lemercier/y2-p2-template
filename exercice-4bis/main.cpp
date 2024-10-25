#include "main.hpp"
#include "Personnage.h"
#include <iostream>
#include <random>


void GetHealths( const Personnage pPersonnages[], float healthArray[], const int size )
{
    for ( int i = 0; i < size; i++ )
        healthArray[i] = pPersonnages[i].GetHealth();
}

void GetMaxHealths( const Personnage pPersonnages[], float maxHealthArray[], const int size )
{
    for ( int i = 0; i < size; i++ )
        maxHealthArray[i] = pPersonnages[i].GetMaxHealth();
}

void GetDefenses( const Personnage pPersonnages[], int defenseArray[], const int size )
{
    for ( int i = 0; i < size; i++ )
        defenseArray[i] = pPersonnages[i].GetDefense();
}

void GetDamages( const Personnage pPersonnages[], float damageArray[], const int size )
{
    for ( int i = 0; i < size; i++ )
        damageArray[i] = pPersonnages[i].GetDamage();
}


int main()
{
    Personnage* pPersonnages = new Personnage[5];
    for ( int i = 0; i < 5; i++ )
    {
        const int maxHealth = rand()%251;
        const int health = rand()%(maxHealth+1);
        const int defense = rand()%11;
        const int damage = rand()%51;
        pPersonnages[i].SetMaxHealth( static_cast<float>( maxHealth ) );
        pPersonnages[i].SetHealth( static_cast<float>( health ) );
        pPersonnages[i].SetDefense( defense );
        pPersonnages[i].SetDamage( static_cast<float>( damage ) );
        std::cout << "Personage" << i << ": health=" << health << ", maxHealth=" << maxHealth << ", defense=" << defense << ", damage=" << damage << std::endl;
    }
    float healthArray[5];
    float maxHealthArray[5];
    int defenseArray[5];
    float damageArray[5];
    GetHealths( pPersonnages, healthArray, 5 );
    GetMaxHealths( pPersonnages, maxHealthArray, 5 );
    GetDefenses( pPersonnages, defenseArray, 5 );
    GetDamages( pPersonnages, damageArray, 5 );
    std::cout << "Health: " << calculStatistique( healthArray, 5 ) << std::endl;
    std::cout << "MaxHealth: " << calculStatistique( maxHealthArray, 5 ) << std::endl;
    std::cout << "Defense: " << calculStatistique( defenseArray, 5 ) << std::endl;
    std::cout << "Damage: " << calculStatistique( damageArray, 5 ) << std::endl;
    return 0;
}