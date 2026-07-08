def mergeKLists(lists):
    
    lista_1 = []
    
    for i in range(len(lists)):
        lista_1.extend(lists[i])
        
    
    lista_1.sort()
    
    return lista_1
    


lista_prueba = [[1,4,5], [1,3,4],[2,6]]
print(mergeKLists(lista_prueba))