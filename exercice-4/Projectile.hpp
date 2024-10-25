#pragma once
#include "Vector2.h"


template <typename damageType>
class Projectile
{

public:
    explicit Projectile( const Vector2& position, const Vector2& direction, float speed, damageType damage );
    virtual ~Projectile() = default;

    [[nodiscard]] const Vector2& GetPosition() const;
    [[nodiscard]] const Vector2& GetDirection() const;
    [[nodiscard]] float GetSpeed() const;
    [[nodiscard]] damageType GetDamage() const;

    void SetPosition( const Vector2& position );
    void SetDirection( const Vector2& direction );
    void SetSpeed( float speed );
    void SetDamage( damageType damage );

    void Move();
    virtual void OnImpact() = 0;

protected:
    Vector2 m_position;
    Vector2 m_direction;
    float m_speed;
    damageType m_damage;

};





template <typename damageType>
Projectile<damageType>::Projectile( const Vector2& position, const Vector2& direction, const float speed, const damageType damage ):
    m_position( position ),
    m_direction( direction ),
    m_speed( speed ),
    m_damage( damage )
{
    m_direction.Normalize();
}



template <typename damageType>
const Vector2& Projectile<damageType>::GetPosition() const { return m_position; }

template <typename damageType>
const Vector2& Projectile<damageType>::GetDirection() const { return m_direction; }

template <typename damageType>
float Projectile<damageType>::GetSpeed() const { return m_speed; }

template <typename damageType>
damageType Projectile<damageType>::GetDamage() const { return m_damage; }



template <typename damageType>
void Projectile<damageType>::SetPosition( const Vector2& position ) { m_position = position; }

template <typename damageType>
void Projectile<damageType>::SetDirection( const Vector2& direction ) { m_direction = direction; }

template <typename damageType>
void Projectile<damageType>::SetSpeed( const float speed ) { m_speed = speed; }

template <typename damageType>
void Projectile<damageType>::SetDamage( const damageType damage ) { m_damage = damage; }




template <typename damageType>
void Projectile<damageType>::Move()
{
    Vector2 movement = m_direction;
    movement *= m_speed;
    m_position += movement;
}