#include <iostream>
#include <cmath>

using namespace std;
#define PI 3.1416

void circle(const double&, double&, double&);


int main()
{
double rad, plane, circuit;
cout << "Radio: "  << "\t\t" << "Área" << "\t\t" << "Perímetro" << endl;
for(rad=1.0;rad<=10.0;++rad)
circle(rad,plane,circuit);


return 0;
}

void circle(const double& radio, double& area, double& perimeter){
   area=PI*radio*radio;
   perimeter=2*PI*radio;
   cout << radio  << "\t\t" << area << "\t\t" << perimeter << endl;

}