"""
1) O escalonador de processo que utiliza o Round Robin deve ter as seguintes entradas: a. Time slice da CPU; 
b. Processos com seus respectivos tempos de CPU e, caso necessário, com a sua prioridade,  que deverá estar entre 0 e 10, sendo 0 processo com maior prioridade. 
Time slice: 10 
P1, 200 
P2, 300 
P3, 25 

"""     
#receber time slice
TimeSlice = int(input("Time slice: "))
MaxCPUTime=0

#Declarar um dicionário onde a chave é o progesso e o valor é uma lista contendo o tempo de CPU e a Prioridade
Processos={}

#declarar dicionário pra armazenar as filas de prioridades
Prioridades={}

#Lista com as prioridades existentes 
ListPrioridades=[]

#receber o número de processos
N_processos = int(input("Digite o número de processos: "))

#receber as informações sobre os processos 
print("Insira o tempo de CPU e, caso necessário ,a prioridade(0-10) de cada processo ex: 200 10 ou 200 (prioiridade 0: \n")
for i in range (N_processos):
    ListAux=list()
    ListAux=list(map(int,input(f"P{i+1}: ").split()))
    
    if len(ListAux)==1 : ListAux.append(0)
    Processos[f'P{i+1}']= ListAux
    if ListAux[1] not in ListPrioridades : ListPrioridades.append(ListAux[1])

print(ListPrioridades)


#percorre a lista de prioridades
for p in ListPrioridades: 

    aux=list()#lista auxiliar pra armazenar dicionários de processos de mesma prioridade

    #percorre a lista de processos
    for Process,Infos in Processos.items():
        dictAux=dict()#dicionário pra armazenar temporariamente o um dicionário de processo para ser adicionado em uma lista

        if Infos[1] == p :#verifica se a prioridade do processo é a mesma da lista de prioridades
            dictAux[Process]= Infos
            aux.append(dictAux.copy())

    Prioridades[p]=aux

for p,fila in Prioridades.items():
    print(f"Executando a fila de prioridade {p}")
    print(f"Fila : {fila}\n")
    TimeCurrent=TimeSlice
    ProcessosFinalizados=0
    while True:
        
        for n, processo in enumerate(fila) :
            if fila[n]== 0: #verifica se o processo já foi finalizado
                continue

            chave=list(processo.keys())[0]
            timeCPU=list(processo.values())[0][0]

            if TimeCurrent == timeCPU:#
                print(f"\033[31m{chave}:{TimeSlice}*\033[m",end="")
                fila[n]=0#se o processo foi finalizado ele recebe o valor 0 na fila
                ProcessosFinalizados+=1 
            elif (timeCPU - TimeCurrent) == -(timeCPU%TimeSlice): 
                print(f"\033[31m{chave}:{timeCPU%TimeSlice}* \033[m",end="")
                fila[n]=0
                ProcessosFinalizados+=1
            else:
                print(f"{chave}:{TimeSlice}, ",end="")
        
        if ProcessosFinalizados == len(fila):
                break
        TimeCurrent+=TimeSlice
        print("\n")