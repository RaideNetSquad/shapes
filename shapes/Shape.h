#pragma once
#include "../vector.h"
#include <vector>
#include <iostream>
#include <cmath>
#define PI 3.14

using namespace std;

class Shape
{
    public:
    std::vector<Vector> vertices;
    public:
        virtual Vector center(std::vector<Vector> diametr) const{
            double x1 = diametr[0].x;
            double x2 = diametr[1].x;
            double y1 = diametr[0].y;
            double y2 = diametr[1].y;

            double xC, yC;
            xC=x2+(x1-x2)/2;     
            yC=y2+(y1-y2)/2;

            return Vector(xC, yC);
        };
        virtual double perimeter() const;
        virtual double area() const;
        bool equal (double a, double b) {
            return std::fabs(a - b) < EPS;
        }
        virtual bool operator == (Shape& another){
            double n1, n2 = 0;
            for(int i = 0; i < this->vertices.size(); ++i)
            {
                n1 += this->vertices[i].length();
                n2 += another.vertices[i].length();
            }
            if(equal(n1,n2))
                return true;
            return false;
        };
        virtual bool operator != (Shape& another){
            double n1, n2 = 0;
            for(int i = 0; i < this->vertices.size(); ++i)
            {
                n1 += this->vertices[i].length();
                n2 += another.vertices[i].length();
            }
            if(!equal(n1,n2))
                return true;
            return false;
        };
        virtual bool congruent_to (Shape& another){
            double n1, n2 = 0;
            for(int i = 0; i < this->vertices.size(); ++i)
            {
                n1 = this->vertices[i].length();
                n2 = another.vertices[i].length();
                if(n1 != n2)
                    return false;
            }
            return true;
        };

        virtual void rotate(double angle){
            float cs = cos(angle),
                    sn = sin(angle);
            Vector center(0,0);
            int arr_len = this->vertices.size();
            std::vector<Vector> vectors = this->vertices;
            for (int i = 0; i < arr_len; i++)
            {
                    center.x += vectors[i].x;
                    center.y += vectors[i].y;
            }
            center.x /= arr_len;
            center.y /= arr_len;
    
            float dx, dy;
            while (arr_len--)
            {
                    dx = vectors[arr_len].x - center.x;
                    dy = vectors[arr_len].y - center.y;
                    vectors[arr_len].x = dx * cs - sn * dy + center.x;
                    vectors[arr_len].y = dx * sn + cs * dy + center.y;
            }
        };
        virtual void scale(double coefficient){
            Vector mass_center = Vector(0., 0.);

            for(int i = 0; i < vertices.size(); i++)
            {
            mass_center.x += vertices[i].x;
            mass_center.y += vertices[i].y;
            }

            mass_center.x /= vertices.size();
            mass_center.y /= vertices.size();

            for(int i = 0; i < vertices.size(); i++)
            {
                //this is a vector that leads from mass center to current vertex
                Vector vec = Vector(vertices[i].x - mass_center.x, vertices[i].y - mass_center.y);
                vertices[i].x = mass_center.x + coefficient * vec.x;
                vertices[i].y = mass_center.y + coefficient * vec.y;
            }
        };
        virtual void translate(Vector transform){
            for(int i = 0; i < vertices.size(); i++)
            {
                vertices[i].x = transform.x;
                vertices[i].y = transform.y;
            }
        };
        


};



