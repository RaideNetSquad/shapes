#include "Polygon.h"
#include "Circle.h"
class Triangle : public Polygon{
    private:
        std::vector<Vector> vertices;
    Triangle(std::vector<Vector> vertices)
    {
        this->vertices = vertices;
    };
    Triangle()
    {
        this->vertices = {};
    };
    Circle circumscribed_circle(std::vector<Vector> points_circle)
    {
        float a = vertices[0].length();
        float b = vertices[1].length();
        float c = vertices[2].length();

        if (a + b >= c && b + c >= a && a + c >= b) //проверяем, существует ли треугольник 
        {
            double p = (a + b + c) / 2;
            double S = sqrt(p * (p - a) * (p - b) * (p - c)); //формула Герона 
 
            double R = a* b * c / (4 * S);
            
            cout<<"circumscribed_circle radius "<<R<<endl;
            return Circle(points_circle, R, R*2);
        }
        else //если не существует:
            cout<<"not Triangle"<<endl;
    }
    Circle inscribed_circle(std::vector<Vector> points_circle)
    {
        float a = vertices[0].length();
        float b = vertices[1].length();
        float c = vertices[2].length();

        if (a + b >= c && b + c >= a && a + c >= b) //проверяем, существует ли треугольник 
        {
            double p = (a + b + c) / 2;
            double S = sqrt(p * (p - a) * (p - b) * (p - c)); //формула Герона 
            double r = S / p;
            cout<<"inscribed_circle radius"<<r<<endl;
            return Circle(points_circle, r, r*2);
        }
        else //если не существует:
            cout<<"not Triangle"<<endl;
    }
    double perimeter(){
        double a = this->vertices[0].length();
        double b = this->vertices[1].length();
        double c = this->vertices[2].length();

        return a + b + c;
    }
    double area(){
        double a = this->vertices[0].length();
        double b = this->vertices[1].length();
        double c = this->vertices[2].length();

        return sqrt((double)((a+b+c)/2*((a+b+c)/2-a)*((a+b+c)/2-b)*((a+b+c)/2-c)));
    }
};