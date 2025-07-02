#ifndef _VECTOR_H_
#define _VECTOR_H_    

#include <cmath> // for sqrt

class Vector2
{
public:
    float x, y;
public:
    Vector2() = default;
    ~Vector2() = default;

    Vector2(float x, float y)
        : x(x), y(y) {
    }

    //��������أ�ʹ��ά�������������ֱ��
    Vector2 operator+(const Vector2& vec) const
    {
        return Vector2(x + vec.x, y + vec.y);
    }

    void operator+=(const Vector2& vec) {
        x += vec.x;
        y += vec.y;
    }

    Vector2 operator-(const Vector2& vec) const
    {
        return Vector2(x - vec.x, y - vec.y);
    }

    void operator-=(const Vector2& vec) {
        x -= vec.x;
        y -= vec.y;
    }

    float operator*(const Vector2& vec) const
    {
        return x * vec.x + y * vec.y; // ���
    }

    Vector2 operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    void operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
    }

    //������������
    float length() const
    {
        return sqrt(x * x + y * y);
    }

    //���������ĵ�λ����
    Vector2 normalized() const
    {
        float len = length();
        if (len == 0) return Vector2(0, 0); // ���������
        return Vector2(x / len, y / len);
    }

private:

};



#endif // !_VECTOR_H_