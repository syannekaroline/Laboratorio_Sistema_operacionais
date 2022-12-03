from time import sleep

def GeraFila(ListPrioridades, Processos):
    '''o descritor do processo é inserido no final da fila correspondente à sua  prioridade.'''

    #declarar dicionário pra armazenar as filas de prioridades
    FilaPrioridades={}

    #percorre a lista de prioridades -- Organiza pro processos nas filas de acordo com sua prioridade
    for p in sorted(ListPrioridades): 
        aux=list()#lista auxiliar pra armazenar dicionários de processos de mesma prioridade

        #percorre a lista de processos
        for Process,Infos in Processos.items():
            dictAux=dict()#dicionário pra armazenar temporariamente o um dicionário de processo para ser adicionado em uma lista

            if Infos[1] == p :#verifica se a prioridade do processo é a mesma da lista de prioridades
                dictAux[Process]= Infos
                aux.append(dictAux.copy())

        FilaPrioridades[p]=aux
    return FilaPrioridades

def RoundRobin(FilaPrioridades):
    sleep(1)
    print(f"\n\033[32m{'=-'*35}\nROUND ROBIN ALGORITMO\n{'=-'*35}\033[m")

    for p,fila in FilaPrioridades.items():
        print(f"\n\033[34m{'=-'*35}\nExecutando a fila de processom com prioridade {p}\n{'=-'*35}\033[m")
        sleep(1)
        print(f"Fila : {fila}\n")
        TimeCurrent=TimeSlice
        ProcessosFinalizados=0

        while ProcessosFinalizados != len(fila):
            for n, processo in enumerate(fila) :
                if fila[n]== 0: #verifica se o processo já foi finalizado
                    continue

                chave=list(processo.keys())[0]
                timeCPU=list(processo.values())[0][0]

                if TimeCurrent == timeCPU:#
                    print(f"\033[31m{chave}:{TimeSlice}*\033[m",end="")
                    fila[n]=0#se o processo foi finalizado ele recebe o valor 0 na fila
                    ProcessosFinalizados+=1

                elif (timeCPU - TimeCurrent) < 0: 
                    print(f"\033[31m{chave}:{timeCPU%TimeSlice}* \033[m",end="")
                    fila[n]=0
                    ProcessosFinalizados+=1

                else:
                    print(f"{chave}:{TimeSlice}, ",end="")
            
            TimeCurrent+=TimeSlice
            print("\n")
            sleep(1)

def FilaUnicaPrioridades(Processos):
    print(Processos)
    FilaUnicaProcessos= sorted(Processos.items(), key= lambda item : item[1][1])#organiza os processos de acordo com a prioridade
    sleep(1)
    print(f"\n\033[32m{'=-'*35}\nFILA ÚNICA COM PRIORIDADES - ALGORITMO\n{'=-'*35}\033[m")
    print(f'Fila de processamento : {FilaUnicaProcessos}')

    for processo in FilaUnicaProcessos:
        TimeCurrent = 0
        while TimeCurrent < processo[1][0] :
            TimeCurrent+=TimeSlice
            if TimeCurrent == processo[1][0]:#
                print(f"\033[31m{processo[0]}:{TimeSlice}*\033[m")
                sleep(0)
                break
            elif processo[1][0]-TimeCurrent < 0: 
                print(f"\033[31m{processo[0]}:{processo[1][0]%TimeSlice}* \033[m")
                sleep(1)
                break
            else:
                print(f"{processo[0]}:{TimeSlice}")
            sleep(1)


#receber time slice
TimeSlice = int(input("Time slice: "))

#Declarar um dicionário onde a chave é o processo e o valor é uma lista contendo o tempo de CPU e a Prioridade
Processos={}

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

print(f"\nPrioridade(s) existente(s) : {ListPrioridades}")

if len(ListPrioridades) > 1:
  FilaUnicaPrioridades(Processos)
    
FilaPrioridades=GeraFila(ListPrioridades,Processos)
RoundRobin(FilaPrioridades)



