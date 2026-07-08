
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int iseven(int x);

int main()
{
    
    printf("Introduce una secuencia de números naturales separada por espacios: ");
    char cadena_entrada[30];
    fgets(cadena_entrada, sizeof(cadena_entrada), stdin);
    
    int contador_espacios = 0;
    int contador_digitos = 0;
    
    for (int i = 0; i < strlen(cadena_entrada); i++){
        if (isdigit(cadena_entrada[i])){
            contador_digitos++;
        }
        else if (cadena_entrada[i] == ' '){
            contador_espacios++;
        }
        else {
            continue;
        }
    }
    
    printf("Hay %d espacios, %d números y %d dígitos \n", contador_espacios, contador_espacios+1, contador_digitos);
    
    int size_new_string = contador_espacios + contador_digitos + 1;
    
    char new_string[size_new_string];
    
    
    
    for (int i = 0; i < size_new_string; i++){
        if (i != (size_new_string-1)){
            new_string[i] = cadena_entrada[i];
        }
        else {
            new_string[i] = '\0';
        }
    }
    
    printf("%s \n", new_string);
    
    
    int numeros[contador_espacios+1];
    
    int localizador = 0;
    
    int loc_vector = 0;
    
    
    for (int i = 0; i < sizeof(new_string); i++){
        if (isdigit(new_string[i])){
            continue;
        }
        else {
            int numero_elementos;
            char* start = &new_string[localizador];
            char* end = &new_string[i];
            numero_elementos = end - start;
            
            char numero[numero_elementos+1];
            
            for (int j = 0; j<= numero_elementos; j++){
                if (j != numero_elementos){
                    numero[j] = new_string[localizador+j];
                }
                else {
                    numero[j] = '\0';
                }
            }
            
            int numero_a_incorporar;
            
            numero_a_incorporar = atoi(numero);
            
            numeros[loc_vector] = numero_a_incorporar;
            
            localizador = i+1;
            loc_vector++;
            
        }
    }
    
    
    int contador_pares = 0;
    int contador_impares = 0;
    
    for (int k = 0; k < (sizeof(numeros)/sizeof(numeros[0])); k++){
        if (iseven(numeros[k])){
            contador_pares++;
        }
        else {
            contador_impares++;
        }
    }
    
    printf("Hay %d números pares y %d números impares \n", contador_pares, contador_impares);
    
    int numeros_pares[contador_pares];
    int numeros_impares[contador_impares];
    
    int loc_pares = 0;
    int loc_impares = 0;
    
    for (int i = 0; i < (sizeof(numeros)/sizeof(numeros[0])); i++){
        if (iseven(numeros[i])){
            numeros_pares[loc_pares] = numeros[i];
            loc_pares++;
        }
        else {
            numeros_impares[loc_impares] = numeros[i];
            loc_impares++;
        }
    }
    
    int array_ordenado[contador_pares+contador_impares];
    
    for (int i = 0; i < (contador_pares+contador_impares); i++){
        if (i < contador_pares){
            array_ordenado[i] = numeros_pares[i];
        }
        else {
            array_ordenado[i] = numeros_impares[i-contador_pares];
        }
    }
    
    printf("Elements in the new array are: ");
    for (int m = 0; m < (sizeof(array_ordenado)/sizeof(array_ordenado[0])); m++){
        printf(" %d ,", array_ordenado[m]);
    }
    
    printf("\n");
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
    
}

int iseven(int x){
    if (remainder(x,2) == 0){
        return 1;
    }
    else {
        return 0;
    }
    
}