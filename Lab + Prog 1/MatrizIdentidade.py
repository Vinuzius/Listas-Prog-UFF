def GerarMatriz(n):
    #m= int(input("Digite o número de linhas: "))
    #n= int(input("Digite o número de colunas: "))
    matriz = []
    for i in range (n):
        linhas = [0]*n
        #linhas[i] = 1  ## Se colocar essa linha ele faz sem a necessidade de um segundo For
        matriz.append(linhas)
    return matriz

#### Gerar Matriz de Zeros
n = int(input("Digite o valor de N: "))
matrizI= GerarMatriz(n)
for i in matrizI:
    print(i)
print("------------------------")

##### Gerar Matriz Identidade
for j in range (n):
    matrizI[j][j] = 1
for k in matrizI:
    print(k)