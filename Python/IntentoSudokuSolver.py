from itertools import permutations, product


board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]


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



diccionario_combinaciones = {}

combinaciones_por_fila = []

for i in range(len(board)):
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
            







    






solucion = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]




indices = list(range(combinaciones_por_fila[0]))
indices_unidos = []
i = 1

while (i < 9):
    indices_iteracion = list(range(combinaciones_por_fila[i]))
    
    if (i == 1):
        producto_iteracion = list(product(indices, indices_iteracion))
        
        
        for x in producto_iteracion:
            solucion[0] = diccionario_combinaciones["CombFila0-"+str(x[0])]
            solucion[1] = diccionario_combinaciones["CombFila1-"+str(x[1])]
            
            if (requisitos(solucion) == 1):
                mi_lista = [x[0], x[1]]
                indices_unidos.append(mi_lista)
        
        i+=1
        
    else:
        producto_iteracion = list(product(indices_unidos, indices_iteracion))
        indices_unidos.clear()
        
        for x in producto_iteracion:
            for j in range(i+1):
                if (j != i):
                    solucion[j] = diccionario_combinaciones["CombFila"+str(j)+"-"+str(x[0][j])]
                else:
                    solucion[j] = diccionario_combinaciones["CombFila"+str(j)+"-"+str(x[1])]
        
        
        
            if (requisitos(solucion) == 1):
                mi_lista = list(x[0])
                mi_lista.append(x[1])
                indices_unidos.append(mi_lista)
                
                if (i == 8):
                    print(solucion)
                    break
                
        
        i+=1
