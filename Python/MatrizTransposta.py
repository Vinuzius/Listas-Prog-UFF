def GerarMatriz(m,n):
    #m= int(input("Digite o número de linhas: "))
    #n= int(input("Digite o número de colunas: "))
    matriz = []
    for i in range (m):
        linhas = []
        for j in range (n):
            linhas.append(float(input(f'Digite {i},{j}: ')))
        matriz.append(linhas)
    return matriz

#### Gerando Matriz Original
m= int(input("Digite o número de linhas: "))
n= int(input("Digite o número de colunas: "))
Matriz = GerarMatriz(m,n)
print("Matriz Original")
for k in Matriz:
    print(k)
    
#### Gerando e Printando Matriz Transposta
MatrizT= []
if(m<n): ## Temos que comparar os tamanhos da linhas e colunas pra nao gerar erro.
    for i in range (m+1):
        aux = []
        for j in range (n-1):
            aux.append(Matriz[j][i])
        MatrizT.append(aux)
elif(m>n):
    for i in range (m-1):
        aux = []
        for j in range (n+1):
            aux.append(Matriz[j][i])
        MatrizT.append(aux)
else:
    for i in range (m):
        aux = []
        for j in range (n):
            aux.append(Matriz[j][i])
        MatrizT.append(aux)
print("----------------------")
for k in MatrizT:
    print(k)