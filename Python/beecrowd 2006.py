cha = str(input())
chutes = input().split()
aux = 0
acerto = 0
while aux < 5:
    if chutes[aux] == cha:
        acerto+=1
    aux+=1
print(acerto)