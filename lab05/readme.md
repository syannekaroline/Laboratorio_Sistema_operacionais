Implementar 02 (dois) escalonadores de processos: Round Robin e Fila única com prioridades(Linux).  Alguns requisitos que precisam ser atendidos pelo simulador: 

1) O escalonador de processo que utiliza o Round Robin deve ter as seguintes entradas:

a. Time slice da CPU;

b. Processos com seus respectivos tempos de CPU e, caso necessário, com a sua prioridade,  que deverá estar entre 0 e 10, sendo 0 processo com maior prioridade. 
Time slice: 10 
P1, 200 
P2, 300 
P3, 25 

2) A saída do escalonador deverá ser o processo que está usando a CPU e o tempo ocupado na CPU; CPU: P1, 10; P2, 10; P3, 10;  
P1, 10; P2, 10; P3, 10; 
P1, 10; P2, 10; P3, 5*; 
P1, 10; P2, 10; 
P1, 10; P2, 10;

3) No Round Robin um processo saído da CPU que não foi finalizado deverá entrar no final de fila e  aguardar a próxima vez que deverá ocupar a CPU. Quando o processo for finalizado, deverá ser  indicado através do caractere *. 

4) No algoritmo com prioridade, os processos devem ser reconduzidos para a sua faixa de prioridade,  sendo colocado no final da sua faixa de prioridade quando o tempo de CPU não for suficiente para  sua execução. Quando o processo for finalizado, deverá ser indicado através do caractere *.
