#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    cout<<"Introduce una secuencia de números enteros separada por espacios: "<<endl;
    string cadena_entrada;
    getline(cin, cadena_entrada);
    
    cout << "Esta es mi secuencia: " << cadena_entrada << endl;
    
    vector<int> numeros;
    string numero = "";
    
    for (int i = 0 ; i < cadena_entrada.length() ; i++){
        if (cadena_entrada[i] != ' ' && i != cadena_entrada.length()-1){
            numero = numero + cadena_entrada[i];
        }
        else if (cadena_entrada[i] != ' ' && i == cadena_entrada.length()-1){
            numero = numero + cadena_entrada[i];
            numeros.push_back(stoi(numero));
        }
        else {
            numeros.push_back(stoi(numero));
            numero = "";
        }
    }
    
    
    
    cout << "Introduce el número objetivo: " << endl;
    int target;
    cin >> target;
    
    
    for (int i = 0 ; i < numeros.size() ; i++){
        for (int j = 0 ; j < numeros.size() ; j++){
            if (i != j && (numeros[i]+numeros[j] == target) && i < j){
                cout << "Estos son los índices cuya suma da el objetivo: " << endl;
                cout << i << " " << j << endl;
            }
        }
    }

    
    return 0;
}