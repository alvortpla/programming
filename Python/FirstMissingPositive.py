secuencia = input("Introduce una secuencia de números enteros: ")

lista_secuencia = secuencia.split(" ")

secuencia_numeros = []

for i in range(len(lista_secuencia)):
    secuencia_numeros.append(int(lista_secuencia[i]))
    

smallest_positive_missing = 1

while smallest_positive_missing in secuencia_numeros:
    smallest_positive_missing+=1
    

print("El número positivo más pequeño que no está es ", smallest_positive_missing)