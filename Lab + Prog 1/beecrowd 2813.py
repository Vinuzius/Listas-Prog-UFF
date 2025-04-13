dias = int(input("Quantos dias? "))

casa_comprar, trabalho_comprar = 0,0
casa_sobra, trabalho_sobra = 0,0

for i in range(dias):
    casa,trabalho = input().split() # Separando o texto das duas variáveis

    ## Vamos ver os casos, já que só haverá alteração caso chova, então momento de Sol passa batido
    if (casa == "chuva") and (casa_sobra == 0): 
        casa_comprar+=1 # Se chove e nao tenho guarda-chuva em casa, entao irei comprar e irá sobrar um no trabalho
        trabalho_sobra +=1
    elif (casa == "chuva") and (casa_sobra != 0):
        casa_sobra -=1 # Se tem um extra vou usar e vai sobrar um no trabalho
        trabalho_sobra +=1

    if (trabalho == "chuva") and (trabalho_sobra == 0):
        trabalho_comprar+=1 # Se chove e nao tenho um GC no trabalho, entao irei comprar e em casa terá sobra
        casa_sobra +=1
    elif (trabalho == "chuva") and (trabalho_sobra != 0):
        trabalho_sobra -=1 # Se tenho um extra vou usar e, vai sobrar um em casa
        casa_sobra +=1

print(f'{casa_comprar} {trabalho_comprar}')


