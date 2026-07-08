#include <iostream>
#include <cstdlib>

using namespace std;

long sum (long, long, long, long);

int main()
{
srand(8);


cout << sum(rand()%100+1,rand()%100+1,0,0) << endl;
    return 0;
}

long sum(long a, long b, long c=0, long d=0)
{
   return (a+b+c+d); 
    
}