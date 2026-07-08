#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;




int main()
{
    cout << "Introduce la primera secuencia: ";
    string cadena_entrada_1;
    getline(cin, cadena_entrada_1);
    
    cout << "Introduce la segunda secuencia: ";
    string cadena_entrada_2;
    getline(cin, cadena_entrada_2);
    
    vector<int> numeros_1;
    vector<int> numeros_2;
    
    int localizador = 0;
    
    
    for (int i = 0; i < cadena_entrada_1.length(); i++){
        if (cadena_entrada_1[i] == ' '){
            char* start = &cadena_entrada_1[localizador];
            char* end = &cadena_entrada_1[i];
            
            int numero_elementos;
            numero_elementos = end - start;
            
            
            string numero_str;
            numero_str = cadena_entrada_1.substr(localizador, numero_elementos);
            
            
            
            int numero_a_incorporar;
            
            numero_a_incorporar = stoi(numero_str);
            
            numeros_1.push_back(numero_a_incorporar);
            
            localizador = i+1;
            
        }
        else if (i == (cadena_entrada_1.length()-1)){
            if (localizador == (cadena_entrada_1.length()-1)){
                char numero_c = cadena_entrada_1[i];
                
                int numero_a_incorporar;
                
                numero_a_incorporar = numero_c - '0';
                
                numeros_1.push_back(numero_a_incorporar);
            }
            else {
                char* start = &cadena_entrada_1[localizador];
                char* end = &cadena_entrada_1[i];
                int numero_elementos;
                numero_elementos = end - start;
                
                string numero_str;
                
                numero_str = cadena_entrada_1.substr(localizador, numero_elementos+1);
                
                
                
                int numero_a_incorporar;
                
                numero_a_incorporar = stoi(numero_str);
                
                numeros_1.push_back(numero_a_incorporar);
                
                
            }
            
        }
        else {
            continue;
        }
    }
    
    int localizador_2 = 0;
    
    
    for (int i = 0; i < cadena_entrada_2.length(); i++){
        if (cadena_entrada_2[i] == ' '){
            char* start = &cadena_entrada_2[localizador_2];
            char* end = &cadena_entrada_2[i];
            
            int numero_elementos;
            numero_elementos = end - start;
            
            
            string numero_str;
            numero_str = cadena_entrada_2.substr(localizador_2, numero_elementos);
            
            
            
            int numero_a_incorporar;
            
            numero_a_incorporar = stoi(numero_str);
            
            numeros_2.push_back(numero_a_incorporar);
            
            localizador_2 = i+1;
            
        }
        else if (i == (cadena_entrada_2.length()-1)){
            if (localizador_2 == (cadena_entrada_2.length()-1)){
                char numero_c = cadena_entrada_2[i];
                
                int numero_a_incorporar;
                
                numero_a_incorporar = numero_c - '0';
                
                numeros_2.push_back(numero_a_incorporar);
            }
            else {
                char* start = &cadena_entrada_2[localizador_2];
                char* end = &cadena_entrada_2[i];
                int numero_elementos;
                numero_elementos = end - start;
                
                string numero_str;
                
                numero_str = cadena_entrada_2.substr(localizador_2, numero_elementos+1);
                
                
                
                int numero_a_incorporar;
                
                numero_a_incorporar = stoi(numero_str);
                
                numeros_2.push_back(numero_a_incorporar);
                
                
            }
            
        }
        else {
            continue;
        }
    }
    
    vector<int> numeros;
    
    for (int i = 0; i < numeros_1.size(); i++){
        numeros.push_back(numeros_1[i]);
    }
    for (int i = 0; i < numeros_2.size(); i++){
        numeros.push_back(numeros_2[i]);
    }
    
    
    vector<int> numeros_sorted;
    
    
    
    while (numeros.size() > 0){
        vector<int> minimos;
        for (int k = 0; k < numeros.size(); k++){
            minimos.push_back(numeros[k]);
        }
        
        while (minimos.size() > 1){
            if (minimos.back() > minimos.front()){
                minimos.pop_back();
                
            }
            else {
                int valor_ultimo = minimos.back();
                int valor_primero = minimos.front();
                minimos.at(minimos.size()-1) = valor_primero;
                minimos.at(0) = valor_ultimo;
                minimos.pop_back();
                
            }
        }
        numeros_sorted.push_back(minimos.at(0));
        
        int indice_minimo = 0;
        
        for (int i = 0; i < numeros.size(); i++){
            if (numeros.at(i) == minimos.at(0)){
                indice_minimo = i;
            }
            else {
                continue;
            }
        }
        
        int valor_indice = numeros.at(indice_minimo);
        int last_value = numeros.back();
        
        numeros.at(indice_minimo) = last_value;
        numeros.at(numeros.size()-1) = valor_indice;
        numeros.pop_back();
        
    }
    
    
    
    double mediana;
    
    if (remainder(numeros_sorted.size(),2) != 0){
        for (int i = 0; i < numeros_sorted.size(); i++){
            int* start = &numeros_sorted.front();
            int* end = &numeros_sorted.back();
            int* posicion = &numeros_sorted.at(i);
            
            int elementos_izquierda, elementos_derecha;
            
            elementos_izquierda = posicion - start;
            elementos_derecha = end - posicion;
            
            if (elementos_izquierda == elementos_derecha){
                mediana = numeros_sorted.at(i);
                cout << "La mediana es: " << mediana << endl;
                break;
            }
            else {
                continue;
            }
        }
    }
    else {
        for (int i = 0; i < (numeros_sorted.size()-1); i++){
            int* start = &numeros_sorted.front();
            int* end = &numeros_sorted.back();
            int* posicion_izquierda = &numeros_sorted.at(i);
            int* posicion_derecha = &numeros_sorted.at(i+1);
            
            int elementos_izquierda, elementos_derecha;
            
            elementos_izquierda = posicion_izquierda - start;
            elementos_derecha = end - posicion_derecha;
            
            if (elementos_izquierda == elementos_derecha){
                mediana = (double)(numeros_sorted.at(i) + numeros_sorted.at(i+1))/2;
                cout << "La mediana es: " << mediana << endl;
                break;
            }
        }
    }
   
   
    
    
    
    
    
    
    
    return 0;
}

