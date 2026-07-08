#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
    printf("Introduce la primera secuencia: ");
    char cadena_entrada_1[30];
    
    fgets(cadena_entrada_1, sizeof(cadena_entrada_1), stdin);
    
    printf("Introduce la segunda secuencia: ");
    char cadena_entrada_2[30];
    
    fgets(cadena_entrada_2, sizeof(cadena_entrada_2), stdin);
    
    int contador_espacios_1 = 0;
    int contador_digitos_1 = 0;
    
    for (int i = 0; i < strlen(cadena_entrada_1); i++){
        if (cadena_entrada_1[i] == ' '){
            contador_espacios_1++;
        }
        else if (isdigit(cadena_entrada_1[i])){
            contador_digitos_1++;
        }
        else {
            continue;
        }
    }
    
    char new_string_1[contador_espacios_1+contador_digitos_1+1];
    
    for (int i = 0; i < strlen(cadena_entrada_1); i++){
        if (i != (contador_espacios_1+contador_digitos_1)){
            new_string_1[i] = cadena_entrada_1[i];
        }
        else {
            new_string_1[i] = '\0';
        }
    }
    
    int numeros_1[contador_espacios_1+1];
    
    int localizador = 0;
    
    int loc_vector = 0;
    
    for (int i = 0; i < sizeof(new_string_1); i++){
        if (isdigit(new_string_1[i])){
            continue;
        }
        else {
            char* start = &new_string_1[localizador];
            char* end = &new_string_1[i];
            int numero_elementos = end - start;
            
            char numero_str[numero_elementos+1];
            
            for (int j = 0; j <= numero_elementos; j++){
                if (j != numero_elementos){
                    numero_str[j] = new_string_1[localizador+j];
                }
                else {
                    numero_str[j] = '\0';
                }
            }
            
            int numero;
            numero = atoi(numero_str);
            numeros_1[loc_vector] = numero;
            
            
            localizador = i+1;
            loc_vector++;
            
            
        }
    }
    
    int contador_espacios_2 = 0;
    int contador_digitos_2 = 0;
    
    for (int i = 0; i < strlen(cadena_entrada_2); i++){
        if (cadena_entrada_2[i] == ' '){
            contador_espacios_2++;
        }
        else if (isdigit(cadena_entrada_2[i])){
            contador_digitos_2++;
        }
        else {
            continue;
        }
    }
    
    char new_string_2[contador_espacios_2+contador_digitos_2+1];
    
    for (int i = 0; i < strlen(cadena_entrada_2); i++){
        if (i != (contador_espacios_2+contador_digitos_2)){
            new_string_2[i] = cadena_entrada_2[i];
        }
        else {
            new_string_2[i] = '\0';
        }
    }
    
    int numeros_2[contador_espacios_2+1];
    
    int localizador_2 = 0;
    
    int loc_vector_2 = 0;
    
    for (int i = 0; i < sizeof(new_string_2); i++){
        if (isdigit(new_string_2[i])){
            continue;
        }
        else {
            char* start = &new_string_2[localizador_2];
            char* end = &new_string_2[i];
            int numero_elementos = end - start;
            
            char numero_str[numero_elementos+1];
            
            for (int j = 0; j <= numero_elementos; j++){
                if (j != numero_elementos){
                    numero_str[j] = new_string_2[localizador_2+j];
                }
                else {
                    numero_str[j] = '\0';
                }
            }
            
            int numero;
            numero = atoi(numero_str);
            numeros_2[loc_vector_2] = numero;
            
            
            localizador_2 = i+1;
            loc_vector_2++;
            
            
        }
    }
    
    int concat_arrays[contador_espacios_1+contador_espacios_2+2];
    int long_concat = contador_espacios_1+contador_espacios_2+2;
    
    for (int k = 0; k < long_concat; k++){
        if (k <= contador_espacios_1){
            concat_arrays[k] = numeros_1[k];
        }
        else {
            concat_arrays[k] = numeros_2[k-contador_espacios_1-1];
        }
    }
    
    
    int suma = 1;
    
    
    
    while (suma != 0){
        int check[long_concat-1];
    
        for (int i = 0; i <= (long_concat-2); i++){
            if (concat_arrays[i] <= concat_arrays[i+1]){
                check[i] = 0;
            }
            else {
                check[i] = 1;
            }
        }
        
        for (int j = 0; j <= (long_concat-2); j++){
            if (check[j] == 1){
                int valor_mayor = concat_arrays[j];
                int valor_menor = concat_arrays[j+1];
                concat_arrays[j] = valor_menor;
                concat_arrays[j+1] = valor_mayor;
            }
            else {
                continue;
            }
        }
        
        int nuevo_check[long_concat-1];
        
        for (int i = 0; i <= (long_concat-2); i++){
            if (concat_arrays[i] <= concat_arrays[i+1]){
                nuevo_check[i] = 0;
            }
            else {
                nuevo_check[i] = 1;
            }
        }
        
        int resultado = 0;
        for (int k = 0; k < (long_concat-1); k++){
            resultado = resultado + nuevo_check[k];
        }
        
        suma = resultado;
        
        
        
        
    }
    
    for (int i = 0; i < long_concat; i++){
        printf(" %d ", concat_arrays[i]);
    }
    
    printf("\n");
    
    double mediana;
    
    int elementos = sizeof(concat_arrays) / sizeof(concat_arrays[0]);
    
    if (remainder(elementos, 2) != 0){
        for (int i = 0; i < long_concat; i++){
            int* start = &concat_arrays[0];
            int* end = &concat_arrays[long_concat-1];
            int* posicion = &concat_arrays[i];
            
            int elementos_izquierda, elementos_derecha;
            
            elementos_izquierda = posicion - start;
            elementos_derecha = end - posicion;
            
            if (elementos_izquierda == elementos_derecha){
                mediana = concat_arrays[i];
                printf("La mediana es: %lf", mediana);
                break;
            }
            else {
                continue;
            }
            
        }
    }
    else {
        for (int i = 0; i < (long_concat-1); i++){
            int* start = &concat_arrays[0];
            int* end = &concat_arrays[long_concat-1];
            int* posicion_izquierda = &concat_arrays[i];
            int* posicion_derecha = &concat_arrays[i+1];
            
            int elementos_izquierda, elementos_derecha;
            
            elementos_izquierda = posicion_izquierda - start;
            elementos_derecha = end - posicion_derecha;
            
            
            if (elementos_izquierda == elementos_derecha){
                mediana = (double)(concat_arrays[i]+concat_arrays[i+1])/2;
                printf("La mediana es: %lf", mediana);
                break;
            }
            
            
        }
    }
    
    
    
    
    
    

    return 0;
}