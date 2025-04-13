def PrintOrdem(par,impar):
    p = par[:]
    i = impar[:]
    p.sort()
    i.sort(reverse=True)
    lista = p +i
    for i in lista:
        print(i)
#### Main
par =[]
impar= []
num= int(input("Quantos números? "))
for i in range (num):
    x = int(input("Digite o número: "))
    if x%2 == 0:
        par.append(x)
    else:
        impar.append(x)
PrintOrdem(par,impar)
