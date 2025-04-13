###### Gerador de Matrizes MxN
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

########

l = ["1", "42", "31"]

c = list(map(int, l))

num1= int(input())
num2= (input())
print('0' in num2)
print(c)