
paginas = int(input())
digitos = 0
for i in range (1,paginas+1,1):
    aux = str(i)
    digitos += len(aux)

print(digitos)