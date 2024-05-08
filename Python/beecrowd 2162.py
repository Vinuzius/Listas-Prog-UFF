altura= []
cont = 0
medida = int(input("Quantas tem? "))
#altura= [int(x) for x in input("Digite as Alturas: ").split()]
altura= input("Digite as Alturas: ").split()
for i in range (medida):
    altura[i] = int(altura[i])

for j in range (medida-1):
    if(j%2==0) and (altura[j+1] > altura[j]):
        cont+=1    
    elif(j%2==1) and (altura[j+1] < altura[j]):
        cont+= 1    
    else:
        for j in range (medida-1):
            if(j%2==0) and (altura[j+1] < altura[j]):
                cont+=1    
            elif(j%2==1) and (altura[j+1] > altura[j]):
                cont+= 1
            else:
                break            
        break
if cont == (medida-1):
    print(1)
else:
    print(0)
