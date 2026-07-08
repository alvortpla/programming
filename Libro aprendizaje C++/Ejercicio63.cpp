#include <iostream>
#include <iomanip>
#include <cstdlib> 

using namespace std;



int main()
{

unsigned int seed;

cout << "Introduce a positive integer: " << endl;
cin >> seed;

srand(seed);
int i;
cout << "20 números aleatorios" << endl;

for (i=1;i<=20; ++i)
    cout << rand() % 100 + 1 << "\t";



    return 0;
}


