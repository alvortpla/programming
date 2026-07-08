#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout<<"Introduce un número entero: ";
    int numero;
    cin >> numero;
    
    string numero_str;
    numero_str = to_string(numero);
    
    int numero_digitos;
    
    int negativo = 0;
    
    if (numero_str[0] == '-'){
        negativo = 1;
    }
    
    
    if (negativo == 1){
        numero_digitos = numero_str.length()-1;
    }
    else {
        numero_digitos = numero_str.length();
    }
    
    
    string numero_str_reversed = " ";
    int numero_reversed;
    
    if (numero_digitos == 1){
        numero_reversed = numero;
    }
    else if (numero_digitos > 1 && negativo == 0){
        for (int i = 0; i < numero_str.length(); i++){
            numero_str_reversed = numero_str_reversed + numero_str[numero_str.length()-1-i];
        }
        numero_reversed = stoi(numero_str_reversed);
    }
    else if (numero_digitos > 1 && negativo == 1){
        numero_str_reversed[0] = numero_str[0];
        for (int i = numero_str.length()-1; i > 0 ; i--){
            numero_str_reversed = numero_str_reversed + numero_str[i];
        }
        numero_reversed = stoi(numero_str_reversed);
    }
    else {
        cout << "CASO NO CONTEMPLADO" << endl;
    }
    
    
    cout << "El número entero reordenado es: " << numero_reversed << endl;
    
    
    return 0;
}