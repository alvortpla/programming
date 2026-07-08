
#include <iostream>
#include <cmath>

using namespace std;

long double factorial (unsigned int);

int main()
{

cout << "n \t\t\t Factorial of n"<<endl;
cout << "\n" << endl;
unsigned int m=20;

for(unsigned int j=0;j<=m;++j)
cout << j << "\t\t\t"<< factorial(j)<<endl; 
    return 0;
}

long double factorial (unsigned int n) {
    long double fact;
    if (n!=0)
    fact=n*factorial(n-1);

    if (n==0)
    fact=1;
    
    return fact;
    }