
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("Introduce una secuencia de números enteros separada por espacios: ");
    char cadena_entrada[30];
    fgets(cadena_entrada, sizeof(cadena_entrada), stdin);
    
    
    int contador_espacios = 0;
    
    for (int i = 0; i < strlen(cadena_entrada); i++){
        if (cadena_entrada[i] == ' '){
            contador_espacios++;
        }
    }
    
    printf("Hay %d espacios y %d números \n", contador_espacios, contador_espacios+1);
    
    
    int contador_digitos = 0;
    for (int i = 0; i < strlen(cadena_entrada); i++){
        if (isdigit(cadena_entrada[i])){
            contador_digitos++;
        }
    }
    
    printf("Hay %d dígitos \n", contador_digitos);
    
    char nueva_cadena_entrada[contador_digitos+contador_espacios+1];
    
    for (int i = 0; i < strlen(cadena_entrada); i++){
        if (i != (contador_digitos+contador_espacios)){
            nueva_cadena_entrada[i] = cadena_entrada[i];
        }
        else {
            nueva_cadena_entrada[i] = '\0';
        }
        
    }
    
    
    
    int numeros[contador_espacios+1];
    int localizador = 0;
    int loc_vector = 0;
    
    for (int i = 0; i < sizeof(nueva_cadena_entrada); i++){
        if (isdigit(nueva_cadena_entrada[i])){
            continue;
        }
        else {
            int numero_elementos = 0;
            char* start = &nueva_cadena_entrada[localizador];
            char* end = &nueva_cadena_entrada[i];
            numero_elementos = end - start;
            
            char numero[numero_elementos+1];
            
            for (int j = 0; j <= numero_elementos; j++){
                if (j != numero_elementos){
                    numero[j] = nueva_cadena_entrada[localizador+j];
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
    
    
    printf("Introduce el número objetivo: ");
    int target;
    scanf("%d", &target);
    
    
    
    for (int k = 0; k < (sizeof(numeros)/sizeof(numeros[0])); k++){
        for (int m = 0; m < (sizeof(numeros)/sizeof(numeros[0])); m++){
            if (k<m && (numeros[k]+numeros[m] == target)){
                printf("Índices que suman el valor objetivo %d \n", target);
                printf("%d %d", k, m);
            }
        
    }
    }
    
    

    
    
    
    
    
    
    
    return 0;
}