matriz=[]

l=int(input("Linhas: "))                                                         #Usuario digita o nº de linhas.
c=int(input("Colunas: "))                                                        #Usuario digita o nº de colulas.

def cmatriz(l, c, matriz):                                                       #Comando para a criação de uma matriz(Linhas, colunas, nmatriz)
    for a in range(l):                                                           #Começa do 0, caso contrario (n, n+l)
        linha=[]                                                                 #Função linha
        for b in range(c):                                                       #Começa do 0, caso contrario (n, n+c)
            x = int(input("Digite o elemento L%i:C%i da matriz: " %(a, b)))      #O %i mudará de acordo o (a,b)
            linha.append(x)                                                      #Faz com que todos os numeros da lista fiquem em linha
        matriz.append(linha)                                                     #Faz com que todos os numeros da matriz fiquem em linha
cmatriz(l,c, matriz)

print("\n",matriz)                 #Imprime a Matriz

pp=input("\nDeseja procurar L:C? ")
while pp == ('s') or pp==('sim'):
    p=int(input("\nProcurar na Linha: "))
    q=int(input("Procurar na Coluna: "))
    print("\nO valor da linha",p,"e coluna",q,"é: ",matriz[p][q])
    pp=input("\nDeseja procurar L:C? ")
else:
    print("------------------#--------------------#--------------------#--------")

ppp=input("Deseja inserir algo na Matriz? ")
while ppp == ('s') or ppp==('sim'):    
    n=int(input("\nInserir na linha: "))
    m=int(input("Inserir na coluna: "))
    o=int(input("\nValor a inserir: "))
    (matriz[n][m]) = o
    print("\nA matriz será:",matriz)
    ppp=input("\nDeseja inserir algo na Matriz? ")
else:
    print("\nA matriz será:",matriz)
    print("\nFim do programa")
