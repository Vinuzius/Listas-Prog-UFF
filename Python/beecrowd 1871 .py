while True:
    num = [int(x) for x in input().split()]
    if (num[0]==0) and (num[1]==0):
        break

    soma = str(num[0]+num[1])
    aux = soma
    if '0' in soma: 
        aux = '' 
        for i in range (len(soma)):
            if soma[i] != '0':
                aux += soma[i] 
    print(aux)
        

