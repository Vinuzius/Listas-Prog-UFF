competidores = int(input("Total Competidores: "))
minimo = int(input("Mínimo para próxima fase: "))
nota = []
passa = []
cont1 = 0
cont2 = 0
for i in range (competidores):
    aux = int(input("Entre com a nota "))
    nota.append(aux)
nota.sort()
for j in range (-1,(-minimo)-1 ,-1):
    passa.append(nota [j])
if (passa [-1] in nota):
    for l in range (len(nota)):
        if (passa [-1] == nota[l]):
            cont1 += 1
    for l in range (len(passa)):
        if (passa [l] == passa [-1]):
            cont2 += 1

final = len(passa) + (cont1-cont2)
print ("Vão passar na próxima fase: ", final )
