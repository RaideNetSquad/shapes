#include "Shape.h"
#include <vector>
#include "../vector.h"
class Polygon : public Shape{
    public:
    Polygon(std::vector<Vector> v)
    {
        vertices = v;
    };
    Polygon()
    {
        vertices = {};
    };
    public:
        int vertices_count(){
            int c = 0;
            for(int i = 0; i < vertices.size(); ++i)
                c += i;
            return c;
        };
        std::vector<Vector> get_vertices(){
            return this->vertices;
        };
        double perimeter(){
            double p=0;
            int n = this->vertices_count();
            
            p = n * this->vertices[0].length();
            return p;
        }
        double area(){
            int n = this->vertices_count();
            double S = 0.0;
            for(size_t i = 0; i < n; ++i)
            {
                if(i != n - 1)
                    S += (this->vertices[i].x * this->vertices[i + 1].y - this->vertices[i].y * this->vertices[i + 1].x);
                else
                    S += (this->vertices[i].x * this->vertices[0].y - this->vertices[i].y * this->vertices[0].x);        
            }
        }
        
};
