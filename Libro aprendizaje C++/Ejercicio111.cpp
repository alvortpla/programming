#include <iostream>
#include <iomanip>
using namespace std;
int var = 0;
namespace Special { int var = 100; }
int main()
{
int var = 10;
cout << setw(10) << "1: "<< var; // 1. =10
{
int var = 20;
cout << setw(10) << "2: "<<var << endl; // 2. 20
{
++var;
cout << setw(10) <<"3: "<< var; // 3. 21
cout << setw(10) <<"4: "<< ++ ::var; // 4. 1
cout << setw(10) << "5: "<<Special::var * 2 // 5. 200
<< endl;
}
cout << setw(10) <<"6: "<< var - ::var; // 6. 20
}
cout << setw(10) <<"7: "<< var << endl; // 7. 21 ERROR: es 10 porque nos hemos salido del bloque
return 0;
}
