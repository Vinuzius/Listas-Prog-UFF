
testes= int(input())
for k in range (testes):
    espelho = ''
    aux = ''
    x = input().split()
    for i in range(int(x[0]), int(x[1])+1, 1 ):
        espelho+= str(i)
        
    for j in range(len(espelho)-1,-1,-1 ):
        aux += str(espelho[j])

    print(espelho+aux)