#pragma once


struct Vector2
{
public:
    float x, y;

public:
    Vector2();
    explicit Vector2(float x, float y);

    void Normalize();

    [[nodiscard]] float GetNorm() const;

    void operator+=(const Vector2& other);
    void operator*=(float scalar);

};
