def GerarMatriz(n,m):
    #n= int(input("Digite o número de linhas: "))
    #m= int(input("Digite o número de colunas: "))
    matriz = []
    for i in range (n):
        linhas = []
        for j in range (m):
            linhas.append(float(input(f'Digite {i},{j}: ')))
        matriz.append(linhas)
    return matriz

pot = 0
MatrizN= []
N = int(input("Entre com a ordem da matriz: "))

for i in range (N):
    pot = 0
    linha = []
    for j in range (N):
        pot= j+i
        linha.append(2**pot)
    MatrizN.append(linha)



for i in range(N):
    espaco = len(str(MatrizN[N-1][N-1])) * " "
    imprimir = ""
    for j in range (N):

        if (j>0):
            aux= int(len(str(MatrizN[i][j]))) - int(len(str(MatrizN[i][j-1])))
            if(aux == 1):
                espaco = espaco[:-1]
        imprimir = imprimir + espaco + str(MatrizN[i][j])
    print(imprimir)