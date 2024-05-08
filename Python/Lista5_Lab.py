figurinha = int(input("Entre com o total de figurinhas do álbum: "))
comprado = int(input("Entre com o total de figurinhas compradas: "))
completar = []

for i in range (comprado):
    aux = int(input("Número da figurinha: "))

    if (aux not in completar):
        completar.append(aux)
aux2 = figurinha - len(completar)
print( f'Faltam {aux2} figurinhas' )

# aux = 0
# soma = 0
# teste = int(input("Digite o total de testes: "))
# while (teste > 20 or teste < 0):
#     print ("Testes tem que ser de 1 até 20")
#     teste = int(input("Digite o total de testes: "))

# while (aux < teste):
#     numero = int(input("Digite o número desejado: "))
#     for i in range (1,(numero//2)+1,1):
#         if (numero%i ==0):
#             soma += i
    
#     if (numero == soma):
#         print(str(numero) + " eh perfeito")
#     else:
#         print(str(numero) + " nao eh perfeito")
#     soma = 0
#     aux+=1


    