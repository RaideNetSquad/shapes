#include <iostream>
#include "vector.h"

double dotProduct(const Vector& vect_A, const Vector& vect_B);
double crossProduct(const Vector& Vector1,const Vector& Vector2);
bool collinear (const Vector& Vector1, const Vector& Vector2);
int main()
{
    double v1x = 0.0;
    double v1y = 10.0;

    double v2x = 10.0;
    double v2y = 6.1;

    Vector v1(v1x, v1y);
    Vector v2(v2x, v2y);

    std::cout << ((v1 == v2) ? "True" : "False") << std::endl;
    std::cout << ((v1 != v2) ? "True" : "False") << std::endl;

    Vector v3 = v1 + v2;
    std::cout << "x: " << v3.x << " y: " << v3.y << std::endl;

    Vector v4 = v3 - v2;
    std::cout << "x: " << v4.x << " y: " << v4.y << std::endl;

    std::cout << "Vector len is " << v3.length() << std::endl;

    std::cout << "* Vector on double scalar is " << v3 * 0.2 << std::endl;
    std::cout << "/ Vector on double scalar is " << v3 / 0.2 << std::endl;

    std::cout << "DotProduct v1 and v2 " << dotProduct(v1, v2) << std::endl; 
    std::cout << "CrossProduct v1 and v2 " << crossProduct(v1, v2) << std::endl; 
    std::cout << "Collinear v1 and v2 ? " << (collinear(v1, v2) ? "True" : "False") << std::endl; 
    return 0;
}
