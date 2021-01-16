
#include "vector.h"
// Function that return 
// dot product of two vector array. 
double dotProduct(const Vector& vect_A, const Vector& vect_B) 
{ 
  
    double product = 0; 
    product = vect_A.x * vect_B.x + vect_A.y * vect_B.y; 
    return product; 
} 
  
// Function to find 
// cross product of two vector array. 
double crossProduct(const Vector& Vector1,const Vector& Vector2)   
{ 
    double res = (Vector1.x * Vector2.y) - (Vector1.y * Vector2.x);
    return res; 
} 
//checks if two vectors are collinear
bool collinear (const Vector& Vector1, const Vector& Vector2)
{
    if((Vector1.x == 0) && (Vector2.x == 0))
        return false;
    if((Vector1.y == 0) && (Vector2.y == 0))
        return false;
    
    bool res = ((Vector1.x / Vector2.x) == (Vector1.y / Vector2.y));
    return res;
}