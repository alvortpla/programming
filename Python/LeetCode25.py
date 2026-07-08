def reverseKGroup(head, k):
    
    nueva_lista = []
    
    if (len(head) % k == 0):
        for i in range(0,len(head), k):
            for j in range(k):
                nueva_lista.append(head[i+k-j-1])
        
        return nueva_lista
    else:
        for i in range(0, len(head), k):
            if (i+k < len(head)):
                for j in range(k):
                    nueva_lista.append(head[i+k-j-1])

            else:
                nueva_lista.extend(head[i:len(head)])
        
        return nueva_lista
        


print(reverseKGroup([1,2,3,4,5], 3))