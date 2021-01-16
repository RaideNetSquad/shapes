#pragma once

#include <iostream>
#include <math.h>
const double EPS = 1e-6;
struct Vector
{
    public:
        double x;
        double y;
    public:
        Vector(double x1, double y1)
        {
            this->x = x1;
            this->y = y1;
        }

        Vector()
    {
        this->x = 0;
        this->y = 0;
    }
    public:
        bool equal (double a, double b) {
            return std::fabs(a - b) < EPS;
        }
        bool operator ==(const Vector& v2)
        {
            bool bx = this->equal(this->x,v2.x);
            bool by = this->equal(this->y,v2.y);

            if( bx && by)
            {
                return true;
            }
                
            return false;

        }
        bool operator !=(const Vector& v2)
        {
            bool bx = this->equal(this->x,v2.x);
            bool by = this->equal(this->y,v2.y);

            if(!bx && !by)
            {
                return true;
            }
                
            return false;

        }
        Vector operator +(const Vector& v2) const
        {

            return Vector(this->x + v2.x, this->y + v2.y);
        }
        Vector operator -(const Vector& v2) const
        {

            return Vector(this->x - v2.x, this->y - v2.y);
        }
        double operator *(double scalar) const
        {
            //умножение вектора на двойной скаляр
            double double_scalar = scalar * 2;
            return (this->x * double_scalar + this->y * double_scalar);
        }
        double operator /(double scalar) const
        {
            //деление вектора на двойной скаляр
            double double_scalar = scalar * 2;
            return (this->x / double_scalar + this->y / double_scalar);
        }
        double length()
        {
            return sqrt(x*x + y*y);
        }
    
};
