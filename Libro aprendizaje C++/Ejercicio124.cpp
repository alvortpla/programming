
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double quadequation(double,double,double, double*,double*);

int main()
{
    double y1,y2;
    quadequation(2,-2,-1.5, &y1,&y2);
    return 0;
}

double quadequation(double a, double b, double c, double *x1, double *x2){
    if (pow(b,2)-4*a*c < 0)
    return false;
    else {
        *x1=(-b+pow(pow(b,2)-4*a*c,0.5))/(2*a);
        *x2=(-b-pow(pow(b,2)-4*a*c,0.5))/(2*a);
        cout <<"x1 = "<< *x1 << "  " << "x2 = "<<*x2 << endl;
        
        return true;
    }
    
}