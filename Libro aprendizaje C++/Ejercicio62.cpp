#include <iostream>
#include <iomanip>


using namespace std;

int main()
{

cout << "\t\t MULTIPLICATION TABLE" << endl;

cout << "\n" << endl;



int i=1,j,k;
cout << "\t\t";
    for (k=1;k<=10;++k)
        cout << k << "\t";
    
    cout << endl;
    cout <<"------------------------------------------------------------------------------------------" << endl;

while (i<=10){

    cout << i << "\t|\t" ;
    for (j=1; j<=10;++j)
        cout << i*j << "\t";
    ++i;
    cout << endl;
    
}
    return 0;
}