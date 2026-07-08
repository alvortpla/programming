import random
from itertools import permutations, product
import time

board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]

modificables = []

for i in range(len(board)):
    for j in range(len(board)):
        if (board[i][j] == "."):
            modificables.append([i,j])
            

numero_modificables = len(modificables)


"""
suma = 3

suma_filas = 0

suma_columnas = 0

suma_cajas = 0
"""

#while (suma != 0):
copia_board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]

#Columnas
columnas = []

for i in range(len(board)):
    columna = []
    for j in range(len(board)):
        columna.append(copia_board[j][i])
    columnas.append(columna)


#print(columnas)

#Cajas

cajas = []

limites = [[0,1,2], [3,4,5], [6,7,8]]

for i in limites:
    for j in limites:
        #print(i,j)
        caja = []
        for k in i:
            for m in j:
                caja.extend(columnas[k][m])
        
        cajas.append(caja)


def requisitos(sudoku):
    columnas_prueba = []

    for ii in range(9):
        columna_prueba = []
        for ji in range(9):
            columna_prueba.append(sudoku[ji][ii])
        columnas_prueba.append(columna_prueba)
        
    
    

    cajas_prueba = []

    limites = [[0,1,2], [3,4,5], [6,7,8]]

    for ia in limites:
        for ja in limites:
            #print(i,j)
            caja_prueba = []
            for ka in ia:
                for ma in ja:
                    caja_prueba.extend(columnas_prueba[ka][ma])
            
            cajas_prueba.append(caja_prueba)
                                            
    
    
    
    b = 0
    for ib in range(len(columnas_prueba)):
        for kb in range(1,10):
            if (columnas_prueba[ib].count(str(kb)) > 1):
                b+=1
            else:
                b+=0

    
    c = 0
    for ie in range(len(cajas_prueba)):
        for ke in range(1,10):
            if (cajas_prueba[ie].count(str(ke)) > 1):
                c+=1
    
    
    if ((b+c) == 0):
        return 1
    else:
        return 0





"""
a = [4,6,7]

print(list(permutations(a))[0][0])
"""
diccionario_combinaciones = {}

combinaciones_por_fila = []

for i in range(len(board)):
    #print("Fila {}".format(str(i)))
    mi_board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    numero = 0
    indice_numeros_en_la_fila = []
    numeros_en_la_fila = []
    for j in range(len(board)):
        if (mi_board[i][j] != "."):
            numeros_en_la_fila.append(int(mi_board[i][j]))
            indice_numeros_en_la_fila.append(j)
    numeros_no_en_la_fila = []
    for m in range(1,10):
        if (m not in numeros_en_la_fila):
            numeros_no_en_la_fila.append(m)
    indice_numeros_no_en_la_fila = []
    for v in range(len(board)):
        if (v not in indice_numeros_en_la_fila):
            indice_numeros_no_en_la_fila.append(v)
    permutaciones = list(permutations(numeros_no_en_la_fila))
    for n in range(len(permutaciones)):
        permutaciones[n] = list(permutaciones[n])
        for ni in range(len(permutaciones[n])):
            permutaciones[n][ni] = str(permutaciones[n][ni])
    #print(permutaciones)

    for no in range(len(permutaciones)):
        mi_querida_board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
        for k, w in zip(indice_numeros_no_en_la_fila, permutaciones[no]):
            mi_querida_board[i][k] = w
        
        
        if (requisitos(mi_querida_board) == 1):
            key = "CombFila"+str(i)+"-"+str(numero)
            diccionario_combinaciones[key] = mi_querida_board[i]
            numero+=1
            
        
        
        
        
    
    
    combinaciones_por_fila.append(numero)
    #print("Número de combinaciones de la fila "+str(i)+" : "+str(numero))        






#print(combinaciones_por_fila)
    






solucion = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
#print(solucion)


indices_0 = list(range(combinaciones_por_fila[0]))
indices_1 = list(range(combinaciones_por_fila[1]))


producto = list(product(indices_0,indices_1))


for i in range(len(producto)):
    producto[i] = list(producto[i])



indices_unidos = []

for x in producto:
    solucion[0] = diccionario_combinaciones["CombFila0-"+str(x[0])]
    solucion[1] = diccionario_combinaciones["CombFila1-"+str(x[1])]
    
    if (requisitos(solucion) == 1):
        indices_unidos.append(x)

#print(indices_unidos)
#print(len(indices_unidos))

indices_2 = list(range(combinaciones_por_fila[2]))

producto_2 = list(product(indices_unidos, indices_2))


#print(producto_2)



indices_unidos_2 = []

for x in producto_2:
    solucion[0] = diccionario_combinaciones["CombFila0-"+str(x[0][0])]
    solucion[1] = diccionario_combinaciones["CombFila1-"+str(x[0][1])]
    solucion[2] = diccionario_combinaciones["CombFila2-"+str(x[1])]
    
    if (requisitos(solucion) == 1):
        mi_lista = list(x[0])
        mi_lista.append(x[1])
        indices_unidos_2.append(mi_lista)
    
        
        
    
        


#print(indices_unidos_2)

indices_3 = list(range(combinaciones_por_fila[3]))

producto_3 = list(product(indices_unidos_2, indices_3))

#print(producto_3)

indices_unidos_3 = []

for x in producto_3:
    solucion[0] = diccionario_combinaciones["CombFila0-"+str(x[0][0])]
    solucion[1] = diccionario_combinaciones["CombFila1-"+str(x[0][1])]
    solucion[2] = diccionario_combinaciones["CombFila2-"+str(x[0][2])]
    solucion[3] = diccionario_combinaciones["CombFila3-"+str(x[1])]
    
    if (requisitos(solucion) == 1):
        mi_lista = list(x[0])
        mi_lista.append(x[1])
        indices_unidos_3.append(mi_lista)



#print(indices_unidos_3)

indices_4 = list(range(combinaciones_por_fila[4]))

producto_4 = list(product(indices_unidos_3, indices_4))

#print(producto_4)

indices_unidos_4 = []

for x in producto_4:
    solucion[0] = diccionario_combinaciones["CombFila0-"+str(x[0][0])]
    solucion[1] = diccionario_combinaciones["CombFila1-"+str(x[0][1])]
    solucion[2] = diccionario_combinaciones["CombFila2-"+str(x[0][2])]
    solucion[3] = diccionario_combinaciones["CombFila3-"+str(x[0][3])]
    solucion[4] = diccionario_combinaciones["CombFila4-"+str(x[1])]
    
    if (requisitos(solucion) == 1):
        mi_lista = list(x[0])
        mi_lista.append(x[1])
        indices_unidos_4.append(mi_lista)



#print(indices_unidos_4)

indices_5 = list(range(combinaciones_por_fila[5]))

producto_5 = list(product(indices_unidos_4, indices_5))

#print(producto_5)

indices_unidos_5 = []

for x in producto_5:
    solucion[0] = diccionario_combinaciones["CombFila0-"+str(x[0][0])]
    solucion[1] = diccionario_combinaciones["CombFila1-"+str(x[0][1])]
    solucion[2] = diccionario_combinaciones["CombFila2-"+str(x[0][2])]
    solucion[3] = diccionario_combinaciones["CombFila3-"+str(x[0][3])]
    solucion[4] = diccionario_combinaciones["CombFila4-"+str(x[0][4])]
    solucion[5] = diccionario_combinaciones["CombFila5-"+str(x[1])]
    
    if (requisitos(solucion) == 1):
        mi_lista = list(x[0])
        mi_lista.append(x[1])
        indices_unidos_5.append(mi_lista)



#print(indices_unidos_5)

indices_6 = list(range(combinaciones_por_fila[6]))

producto_6 = list(product(indices_unidos_5, indices_6))

#print(producto_6)

indices_unidos_6 = []

for x in producto_6:
    solucion[0] = diccionario_combinaciones["CombFila0-"+str(x[0][0])]
    solucion[1] = diccionario_combinaciones["CombFila1-"+str(x[0][1])]
    solucion[2] = diccionario_combinaciones["CombFila2-"+str(x[0][2])]
    solucion[3] = diccionario_combinaciones["CombFila3-"+str(x[0][3])]
    solucion[4] = diccionario_combinaciones["CombFila4-"+str(x[0][4])]
    solucion[5] = diccionario_combinaciones["CombFila5-"+str(x[0][5])]
    solucion[6] = diccionario_combinaciones["CombFila6-"+str(x[1])]
    
    if (requisitos(solucion) == 1):
        mi_lista = list(x[0])
        mi_lista.append(x[1])
        indices_unidos_6.append(mi_lista)



#print(indices_unidos_6)

indices_7 = list(range(combinaciones_por_fila[7]))

producto_7 = list(product(indices_unidos_6, indices_7))

#print(producto_7)

indices_unidos_7 = []

for x in producto_7:
    solucion[0] = diccionario_combinaciones["CombFila0-"+str(x[0][0])]
    solucion[1] = diccionario_combinaciones["CombFila1-"+str(x[0][1])]
    solucion[2] = diccionario_combinaciones["CombFila2-"+str(x[0][2])]
    solucion[3] = diccionario_combinaciones["CombFila3-"+str(x[0][3])]
    solucion[4] = diccionario_combinaciones["CombFila4-"+str(x[0][4])]
    solucion[5] = diccionario_combinaciones["CombFila5-"+str(x[0][5])]
    solucion[6] = diccionario_combinaciones["CombFila6-"+str(x[0][6])]
    solucion[7] = diccionario_combinaciones["CombFila7-"+str(x[1])]
    
    if (requisitos(solucion) == 1):
        mi_lista = list(x[0])
        mi_lista.append(x[1])
        indices_unidos_7.append(mi_lista)



#print(indices_unidos_7)

indices_8 = list(range(combinaciones_por_fila[8]))

producto_8 = list(product(indices_unidos_7, indices_8))

#print(producto_8)

indices_unidos_8 = []

for x in producto_8:
    solucion[0] = diccionario_combinaciones["CombFila0-"+str(x[0][0])]
    solucion[1] = diccionario_combinaciones["CombFila1-"+str(x[0][1])]
    solucion[2] = diccionario_combinaciones["CombFila2-"+str(x[0][2])]
    solucion[3] = diccionario_combinaciones["CombFila3-"+str(x[0][3])]
    solucion[4] = diccionario_combinaciones["CombFila4-"+str(x[0][4])]
    solucion[5] = diccionario_combinaciones["CombFila5-"+str(x[0][5])]
    solucion[6] = diccionario_combinaciones["CombFila6-"+str(x[0][6])]
    solucion[7] = diccionario_combinaciones["CombFila7-"+str(x[0][7])]
    solucion[8] = diccionario_combinaciones["CombFila8-"+str(x[1])]
    
    if (requisitos(solucion) == 1):
        mi_lista = list(x[0])
        mi_lista.append(x[1])
        indices_unidos_8.append(mi_lista)
        #print(solucion)
        break



print(indices_unidos_8)
print(solucion)