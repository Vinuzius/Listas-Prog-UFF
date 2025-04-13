def Contvogal (vog):
    while True:
        texto = input("Digite um texto: ").lower()
        if (texto) == "parou":
            break
        else:
            for i in range (len(texto)):
                    if texto[i] == 'a':
                        vog["a"] +=1
                    elif texto[i] == 'e':
                        vog["e"] +=1
                    elif texto[i] == 'i':
                        vog["i"] +=1
                    elif texto[i] == 'o':
                        vog["o"] +=1 
                    elif texto[i] == 'u':
                        vog["u"] +=1 
            print(vog)
            for j in vog:
                vog[j] = 0

vogal = {"a": 0, "e":0, "i": 0, "o":0, "u":0 }
Contvogal(vogal)