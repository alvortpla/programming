#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    
    cout << "Introduce un número romano: ";
    
    string numero_romano;
    
    cin >> numero_romano;
    
    cout << "Mi número romano es " << numero_romano << endl;
    
    char symbols[7] = {'I', 'V', 'X', 'L', 'C', 'D','M'};
    string cadena_arabigos[7] = {"1", "5", "10", "50", "100", "500", "1000"};
    int arabigos[7] = {1, 5, 10, 50, 100, 500, 1000};
    
    
    int longitud = numero_romano.length();
    string cadena = " ";
    
    
    for (int i = 0; i < longitud ; i++){
        for (int j = 0 ; j < (sizeof(symbols)/sizeof(symbols[0])); j++){

            if (numero_romano[i] == symbols[j] && i != (longitud-1)){
                cadena = cadena + cadena_arabigos[j] + "-";
            }
            else if (numero_romano[i] == symbols[j] && i == (longitud-1)){
                cadena = cadena + cadena_arabigos[j] + ".";
            }
            else {
                continue;
                
            }
        }
    }
    
    
    
    cout << "La cadena de naturales es " << cadena << endl;
    
    int longitud_cadena = cadena.length();
    
    int localizador = 0;
    
    vector<int> numeros;
    
    for (int i = 0; i < longitud_cadena; i++){
        if (cadena[i] == '-'){
            string numero = " ";
            for (int j = localizador; j < i; j++){
                numero = numero + cadena[j];
            }
            
            
            
            int numero_a_incorporar;
            
            numero_a_incorporar = stoi(numero);
            
            numeros.push_back(numero_a_incorporar);
            
            localizador = i+1;
            
            
            
            
        }
        
        else if (cadena[i] == '.'){
            string numero = " ";
            for (int j = localizador; j < i; j++){
                numero = numero + cadena[j];
            }
            
            
            
            int numero_a_incorporar;
            
            numero_a_incorporar = stoi(numero);
            
            numeros.push_back(numero_a_incorporar);
            
            break;
        }
        
        else if (cadena[i] == '\0'){
            break;
        }
        
        else {
            continue;
        }
    }
    
    int resultado = 0;
    for (int k = 1; k < numeros.size(); k++){
        if (numeros[k] <= numeros[k-1] && k != (numeros.size()-1)){
            resultado = resultado + numeros[k-1];
        }
        else if (numeros[k] <= numeros[k-1] && k == (numeros.size()-1)){
            resultado = resultado + numeros[k-1] + numeros[k];    
        }
        else {
            int previo;
            previo = numeros[k]-numeros[k-1];
            resultado = resultado + previo;
            k++;
            if (k == (numeros.size()-1)){
                resultado = resultado + numeros[k];
                break;
            }
        }
    }
    
    cout << "El número arábigo equivalente es: " << resultado << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}