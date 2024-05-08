tamanho = int(input())
aux=0
cont=1
calcada = int(input())
while aux < (tamanho -1):
    aux2 = calcada
    calcada = int(input())
    if (calcada != aux2):
        cont+=1
    aux+=1

print(cont)