candidatos = int(input())

voto= int(input())
carlos = voto
saida = 'S'
for i in range(1,candidatos):
    voto = int(input())
    if voto > carlos:
        saida = 'N'
print(saida)