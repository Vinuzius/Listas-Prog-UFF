def GerarAluno (num = 2):
    t={}
    while True:
        nome = input("Digite nome do aluno: ") 
        if nome == "": # Se nome for vazio ele para
            break
        nota=[]
        for i in range (num): #Criando nome e adicionando as notas
            nota.append(int(input(f'Digite a nota {i+1}: ')))
        aluno = dict([(nome,nota)]) #Criando uma tupla com nome e nota então criando um dicionario
        t.update(aluno) #Adiciona na turma
    return t

def MediaAluno (turma,nome):
    soma= 0
    for j in range (len(turma[nome])): # J vai variar de acordo com o nomero de notas
        soma+= turma[nome][j]
    media=( soma/len(turma[nome]) ) #Faz a média normalmente
    print(f'A média do aluno {nome} foi: ',media)

#### Main
#num = int(input("Digite quantas notas quer adicionar: "))
turma=GerarAluno()
print("-----------------------------------------------------")
while True: #Irá loopar de acordo com o nome do aluno inserido, até ser vazio
    nome = input("Digite o nome do Aluno: ")
    if(nome == ""):
        break
    MediaAluno(turma,nome)

    


