#include <iostream>
using namespace std;
void swap( float *, float *); // Prototype of swap()
void swap1(float&, float&);
int main()
{
 float x = 11.1F;
 float y = 22.2F;
 
 swap( &x, &y );
 
 swap1(x,y);
 
  // p2 = &y
 cout << "x: " << x << endl;
 cout << "y: " << y << endl;
} // p1 = &x

/*
void swap(float *p1, float *p2)
{
float *temp; // Temporary variable
temp = p1;
p1 = p2;   ¿Por qué no las intercambia? Pues porque ESTAMOS TRABAJANDO CON LAS DIRECCIONES, NO CON LOS VALORES VERDADEROS
p2 = temp;
}
*/

void swap( float *p1, float *p2)
{
 float temp; // Temporary variable
 temp = *p1; // At the above call p1 points
 *p1 = *p2; // to x and p2 to y.
 *p2 = temp;
}

void swap1( float& a, float& b)
{
 float temp; // Temporary variable
 temp = a; // At the above call p1 points
 a = b; // to x and p2 to y.
 b = temp;
}
