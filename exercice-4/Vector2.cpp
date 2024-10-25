#include "Vector2.h"
#include <cmath>




Vector2::Vector2():
    x( 0.0f ),
    y( 0.0f ) {}

Vector2::Vector2(const float x, const float y):
    x( x ),
    y( y ) {}



void Vector2::Normalize()
{
    const float norm = GetNorm();
    if ( norm == 0.0f ) return;
    const float invNorm = 1/norm;
    x *= invNorm;
    y *= invNorm;
}



float Vector2::GetNorm() const
{
    return std::sqrt( x * x + y * y );
}



void Vector2::operator+=( const Vector2& other )
{
    x += other.x;
    y += other.y;
}

void Vector2::operator*=( const float scalar )
{
    x *= scalar;
    y *= scalar;
}
