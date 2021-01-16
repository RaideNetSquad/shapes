#include "Shape.h"

class Circle : Shape{
    private:
        double radius;
        double diametr;
    public:
        Circle(std::vector<Vector> v, double r, double d){
            vertices = v;
            this->radius = r;
            this->diametr = d;
        }
        Circle(){
        vertices = {};
        this->radius = 0;
        this->diametr = 0;
    }
    public:
        double get_radius(){
            return this->radius;
        };
        double get_diametr(){
            double d = this->radius * 2;
            this->diametr = d;
            return this->diametr;
        };
        double perimeter(){
            return 2 * PI * this->radius;
        }
        double area(){
            return PI * (this->radius * this->radius);
        }
};
