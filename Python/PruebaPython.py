
#Write a Python program to find all n-digit integers that start or end with 2.
def doses(n):
    lower=10**(n-1)
    upper=10**n
    lista=[]
    for i in range(lower,upper):
        cadena=str(i)
        if cadena[0] =="2" or cadena[-1]=="2":
            lista.append(i)


    return lista



#print(doses(3))

#Write a Python program to find the following strange sort of list of numbers: the first element is the smallest, the second is the largest of the remaining, the third is the smallest of the remaining, the fourth is the smallest of the remaining, etc.
def strange_order(lista_ini):
    lista_final=[]

    for i in range(len(lista_ini)):
        if i % 2 ==0:
            lista_final.append(min(lista_ini))
            lista_ini.remove(min(lista_ini))
        if i % 2 !=0:
            lista_final.append(max(lista_ini))
            lista_ini.remove(max(lista_ini))
        

    return lista_final


#print(strange_order([27, 3, 8, 5, 1, 31]))



#Write a Python program to find four positive even integers whose sum is a given integer. SOLUCIÓN 1: FUERZA BRUTA.
def super_suma(n):
    lista=[]
    lista_verdadera=[]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                for m in range(n):
                    lista=[i,j,k,m]
                    if i+j+k+m==n and i % 2 == 0 and j % 2 == 0 and k % 2 == 0 and m % 2 == 0 and i != 0 and j != 0 and k != 0 and m != 0:
                        lista_verdadera=lista
    #print(lista_verdadera)

    return lista_verdadera    

#print(super_suma(50))

#Write a Python program to find four positive even integers whose sum is a given integer. SOLUCIÓN 2: MÁS SUTIL (TRAS MIRAR LA SOLUCIÓN).
def super_suma_bis(n):
    lista=[]
    lista_verdadera=[]
    for i in range(n):
        if i % 2 != 0:
            continue
        for j in range(n):
            if j % 2 != 0:
                continue
            for k in range(n):
                if k % 2 != 0:
                    continue
                for m in range(n):
                    if m % 2 != 0:
                        continue
                    lista=[i,j,k,m]
                    if i+j+k+m==n and i % 2 == 0 and j % 2 == 0 and k % 2 == 0 and m % 2 == 0 and i != 0 and j != 0 and k != 0 and m != 0:
                        lista_verdadera=lista
                        return lista_verdadera
                        
    #print(lista_verdadera)

        

#print(super_suma_bis(1000))


#Write a Python program to find an integer (n >= 0) with the given number of even and odd digits
import random

def even_and_odd(neven, nodd):
    lista_par=[]
    lista_impar=[]
    cadena_par=""
    cadena_impar=""
    pares=[2,4,6,8]
    impares=[1,3,5,7,9]
    for i in range(neven):
        lista_par.append(str(random.choice(pares)))
        cadena_par=cadena_par+lista_par[i]
    for i in range(nodd):
        lista_impar.append(str(random.choice(impares)))
        cadena_impar=cadena_impar+lista_impar[i]

    return cadena_par+cadena_impar

#print(even_and_odd(1,1))

#Write a Python program to find the sublist of numbers from a given list of numbers with only odd digits in increasing order.
def only_odds_increasing(lista_ini):
    lista_final=[]
    for i in range(len(lista_ini)):
        if lista_ini[i] % 2 != 0:
            lista_final.append(lista_ini[i])
    lista_final.sort()
    
    return lista_final

#print(only_odds_increasing([1, 3, 79, 10, 4, 2, 39]))

#Write a Python program to find the indices of three numbers that sum to 0 in a given list of numbers.
def index_add_zero(lista_ini):
    lista_final=[]
    for i in range(len(lista_ini)):
            for j in range(len(lista_ini)):
                for k in range(len(lista_ini)):
                    if lista_ini[i]+lista_ini[j]+lista_ini[k]==0 and i!=j and i!=k and j!=k:
                        lista_final.extend([i,j,k])
                        return lista_final
                        
#print(index_add_zero([1, 2, 3, 4, 5, 6, -7]))

# Write a Python class named Rectangle constructed from length and width and a method that will compute the area of a rectangle.
class Rectangle:
    def __init__(self,length, width):
        self.length= length
        self.width=width
    
    def area(self):
        return self.length*self.width

r1 = Rectangle(5, 6)
#print(r1.area())

#Write a Python class Employee with attributes like emp_id, emp_name, emp_salary, and emp_department and methods like calculate_emp_salary, emp_assign_department, and print_employee_details.
class Employee:
    def __init__(self,emp_name,emp_id,emp_salary,emp_department):
        self.emp_name=emp_name
        self.emp_id=emp_id
        self.emp_salary=emp_salary
        self.emp_department=emp_department
    
    def print_employee_details(self):
        return self.emp_name, self.emp_id, self.emp_salary, self.emp_department
    
    def calculate_employee_salary(self, hours_worked):
        if hours_worked<=50:
            return self.emp_salary
        elif hours_worked>50:
            overtime=hours_worked-50
            overtime_amount=overtime*(self.emp_salary/50)
            total_salary=overtime_amount+self.emp_salary
            return total_salary


Employee1=Employee("Juan", 256,26000,"Accounting")
#print(Employee1.print_employee_details())
#print(Employee1.calculate_employee_salary(75))



def longest_string(list):
    lista_longitudes=[]
    for i in range(len(list)):
        lista_longitudes.append(len(list[i]))
    indice_mas_larga=lista_longitudes.index(max(lista_longitudes))
    return list[indice_mas_larga]        
 

        
#print(longest_string(["HOLA", "MUNDO"]))


#Write a function to check if a given number is a Pronic number or not.

def is_pronic(n):
    producto_si=[]
    for i in range(n):
        if i*(i+1) == n:
            producto_si.append(i)
    if producto_si==[]:
        return False
    else:
        return True
        
#print(is_pronic(42))

#Write a function to check if a number is Disarium or not
def is_disarium_number(num):
    num_str=str(num)
    calculo_disarium=0
    for i in range(len(num_str)):
        posicion=i+1
        calculo_disarium+=int(num_str[i])**posicion
    if calculo_disarium == num:
        return True
    else:
        return False

#print(is_disarium_number(175))
"""
import numpy as np
def coin_change(coins, amount):
    coefs_posibles=list(range(amount+1))
    productos_posibles=np.ones((len(coins),len(coefs_posibles)))
    for i in range(len(coins)):
        for j in range(len(coefs_posibles)):
            if coins[i]*coefs_posibles[j]<= amount:
                productos_posibles[i,j]=coins[i]*coefs_posibles[j]
            else:
                productos_posibles[i,j]=None

# Source - https://stackoverflow.com/a
# Posted by Robert Martin
# Retrieved 2025-12-12, License - CC BY-SA 3.0
    
    def loop_rec(y, n):
        if n >= 1:
            for x in range(y):
                loop_rec(y, n - 1)
        else:
        whatever()
    

print(coin_change([1,2,3],12))
"""

def move_zeroes_to_end(n):
    if type(n) != int:
        return print("ERROR: NO ES UN ENTERO")
    else:
        n_str=str(n)
        ceros=[]
        no_ceros=[]
        for i in range(len(n_str)):
            if n_str[i] != "0":
                no_ceros.append(n_str[i])
            else:
                ceros.append(n_str[i])
        
        numero_sin_ceros=""
        for j in range(len(no_ceros)):
            numero_sin_ceros=numero_sin_ceros+no_ceros[j]
        numero_con_ceros=numero_sin_ceros
        for k in range(len(ceros)):
            numero_con_ceros=numero_con_ceros+ceros[k]
    
        return numero_con_ceros


#print(move_zeroes_to_end(12004507))

def factorial(n):
    if n==0 or n==1:
        return 1
    elif n<0:
        return print("ERROR: Número negativo")
    else:
        return n*factorial(n-1)
    

#print(factorial(5))

def calculate_euler(n,precision):
    e=0
    for i in range(n):
        e+=1/factorial(i)
    e_str=str(e)
    before_dot=e_str.split(".")[0]
    post_dot=e_str.split(".")[-1]
    truncamiento=""
    for j in range(precision+1):
        truncamiento+=post_dot[j]
    redondeo=""
    if int(truncamiento[-1]) >= 5:
        numero_nuevo=int(truncamiento[-2])+1
        redondeo=truncamiento[0:precision-1]+str(numero_nuevo)
    else:
        redondeo=truncamiento[0:precision]
    e_final=before_dot+"."+redondeo        
    return e_final

#print(calculate_euler(50,5))

        
def jacobsthal(n):
    if n == 0:
        return 0
    elif n==1:
        return 1
    else:
        return jacobsthal(n-1)+2*jacobsthal(n-2)

#print(jacobsthal(6))

def max_min_product_triplets(lst):
    products_list=[]
    for i in range(len(lst)):
        for j in range(len(lst)):
            for k in range(len(lst)):
                if i != j and i != k and k != j:
                    products_list.append(lst[i]*lst[j]*lst[k])
    max_min_tuple=(max(products_list),min(products_list))
    return max_min_tuple

#print(max_min_product_triplets([-10,-10,1,3,2]))


def caesar_cipher(text,shift):
    eng_alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    cadena_cifrada=""
    for i in range(len(text)):
        for j in range(len(eng_alphabet)):
            if text[i] == eng_alphabet[j] and j+shift < len(eng_alphabet):
                cadena_cifrada+=eng_alphabet[j+shift]
            elif text[i] == eng_alphabet[j] and j+shift >= len(eng_alphabet):
                new_position=j+shift-26
                cadena_cifrada+=eng_alphabet[new_position]
    return cadena_cifrada


#print(caesar_cipher("HELLO",3))
   







        






        

    
        
        
        
        

