#include "Polygon.h"

class Rectangle : public Polygon{
    private:
        double height;
        double width;
        Vector center_rect;
    public:
        Rectangle(std::vector<Vector> v, double h, double w, Vector c)
        {
            vertices = v;
            this->height = h;
            this->width = w;
            this->center_rect = c;
        }
        Rectangle()
        {
            vertices = {};
            this->height = 0;
            this->width = 0;
            this->center_rect = {};
        }
    public:
        double get_height(){
            return this->height;
        }

        double get_width(){
            return this->width;
        }

        Vector center(){
            return this->center_rect;
        }

        double perimeter(){
            double a = this->width;
            double b = this->height;

            return 2*(a + b);
        }

        double area(){
            return this->width * this->height;
        }
};