#pragma once


class Personnage
{

public:
    Personnage();
    explicit Personnage( float health, float maxHealth, int defense, float damage );
    ~Personnage() = default;

    [[nodiscard]] float GetHealth() const;
    [[nodiscard]] float GetMaxHealth() const;
    [[nodiscard]] int GetDefense() const;
    [[nodiscard]] float GetDamage() const;

    void SetHealth( float health );
    void SetMaxHealth( float maxHealth );
    void SetDefense( int defense );
    void SetDamage( float damage );

protected:
    float m_health;
    float m_maxHealth;
    int m_defense;
    float m_damage;

};
