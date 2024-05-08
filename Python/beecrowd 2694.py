caso = int(input())

for i in range (caso):
    calculadora = input()
    num1 = calculadora[2]+calculadora[3]
    num2 = calculadora[5]+calculadora[6]+calculadora[7]
    num3 = calculadora[11]+calculadora[12]
    s = [num1,num2,num3]
    soma = list(map(int,s))
    total = soma[0]+soma[1]+soma[2]
    print(total)