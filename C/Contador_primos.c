
#include <stdio.h>
#include <math.h>

int isprime(int x);

int main()
{
    printf("Input a number: ");
    
    int numero;
    
    scanf("%d", &numero);
    
    int contador_primos = 0;
    
    for (int j = 1 ; j <= numero; j++){
        if (isprime(j) == 1){
            contador_primos++;
        }
    }
    
    
    printf("There are %d prime numbers which are less than or equal to %d", contador_primos, numero);

    return 0;
}

int isprime(int x){
    int contador_divisores = 0;
    for (int i = 1 ; i <= x ; i++){
        if (remainder(x,i) == 0){
            contador_divisores++;
        }
        else {
            continue;
        }
    }
    
    if (contador_divisores == 2){
        return 1;
    }
    else {
        return 0;
    }
    
}