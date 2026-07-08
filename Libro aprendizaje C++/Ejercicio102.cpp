
#include <iostream>

using namespace std;

inline double maximo(double x, double y){
    return (x>=y ? x : y);
    
}

inline char maximo(char x, char y){
    return (x>=y ? x : y);
    
}


int main()
{
double a,b;

char c,d;

cout << "Introduce un valor: " << endl;

cin >> a;
cout << "Introduce otro valor " << endl;

cin >> b;

cout << "Introduce un caracter: " << endl;

cin >> c;
cout << "Introduce otro caracter " << endl;

cin >> d;



cout << maximo (a,b) << endl;
cout << maximo (c,d) << endl;

    return 0;
}