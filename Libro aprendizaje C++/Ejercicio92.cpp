#include <iostream>
#include <string>


using namespace std;

int main()
{
string text;

    while (true) {
     
     getline(cin,text);
     int longitud=text.length();
     for(int i=0; i<=longitud;++i)
     text[i]=toupper(text[i]);
     
     
     string reversed="";
     for (int j=(longitud-1); j>=0; --j)
     reversed+=text[j];     
     

     cout << "Original: "<< text << endl;
     cout << "Longitud: " << longitud << endl;
     cout << "Revertido: " << reversed << endl;
     
     if (text == reversed)
     cout << "¡Es un palíndromo!" << endl;
     else
     cout << "No es un palíndromo" << endl;

    }
    
    return 0;
}