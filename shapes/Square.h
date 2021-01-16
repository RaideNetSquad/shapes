#include "Rectangle.h"
#include "Circle.h"

class Square : public Rectangle{
    private:
        std::vector<Vector> vertices;
        double side_len;
        Vector center;
    Square(std::vector<Vector> vertices, double l, Vector c)
    {
        this->vertices = vertices;
        this->side_len = l;
        this->center = c;
    };
    Square()
    {
        this->side_len = 0;
        this->center = {};
    };
    public:
        double get_sidelen(){
            return this->side_len;
        }


        Circle circumscribed_circle(std::vector<Vector> point_circle)
        {
            double r = this->side_len / 2;

            return Circle(point_circle, r, r*2);
        }
        Circle inscribed_circle(std::vector<Vector> point_circle)
        {
            double r = this->side_len / 2;

            return Circle(point_circle, r, r*2);
        }
        Vector get_center(){
            return this->center;
        }
        
        double perimeter(){
            double a = this->get_sidelen();

            return 4*a;
        }
        double area(){
            return this->side_len * 2;
        }
};