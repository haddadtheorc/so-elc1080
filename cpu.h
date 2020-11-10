#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int reg_cont_prog;
    int reg_acum;

    int code_interrup; /* 0=normal; 1=i.ilegal; 2=v.memoria*/

    int mem_dados[50];
    char *mem_prog[50];

}cpu;

typedef struct {
    char estado;
}cpu_estado;

/*inicializar o estado interno da CPU (PC=0, A=0, estado=normal)*/
void cpu_estado_inicializa(cpu *c, cpu_estado *e){
    (*c).reg_cont_prog = 0;
    (*c).reg_acum = 0;
    (*c).code_interrup = 0;
    (*e).estado = "normal";
};

/*alterar o conteúdo da memória de programa (recebe um vetor de strings)*/
void cpu_altera_mem_programa(cpu *c, int tam, char *m[tam]){
    int i = 0;
    for(i = 0; i<tam; i++){
        (*c).mem_prog[i] = m[i];
    }
}

/*alterar o conteúdo da memória de dados (recebe um vetor de inteiros, que é alterado pela execução das instruções)*/
void cpu_altera_mem_dados(cpu* c, int tam, int m[tam]){
    int i=0;
    for(i=0; i<tam; i++){
        (*c).mem_dados[i] = m[i];
    }
}

/*ler o modo de interrupção da CPU (normal ou um motivo de interrupção)*/
char cpu_interrupcao(cpu *c){
    return (*c).code_interrup;
};

/*executar uma instrução (só executa se estiver em modo normal)*/
void cpu_executa(cpu *c){
    if((*c).code_interrup == 0){


    }
    else{
        printf("CPU FORA DO MODO NORMAL!\n");
    }
}


/*alterar o estado interno da CPU (copia para os registradores da cpu os valores recebidos)*/
void cpu_altera_estado(cpu *c, cpu_estado *e);

void cpu_salva_dados(cpu *c, int tam, int m[tam]); /*obter o conteúdo da memória de dados (retorna um vetor de inteiros que é o conteúdo atual da memória – não precisa desta função caso o vetor passado pela função acima seja alterado “in loco”)*/

void cpu_retorna_interrupcao(cpu *c); /*colocar a CPU em modo normal (coresponde ao retorno de interrupção) – muda para modo normal e incrementa o PC; se já estiver em modo normal, não faz nada*/

char *cpu_instrucao(cpu *c); /*obter a instrução em PC (que pode ser inválida se PC estiver fora da memória de programa)*/

void cpu_salva_estado(cpu *c, cpu_estado *e); /*obter o estado interno da CPU (retorna o valor de todos os registradores)*/



void cpu_inicia(){

    int dados[50] = {0};
    cpu c;
    cpu_estado e;
    char *programa[] = {"CARGI 10", "ARMM 2", "CARGI 32", "SOMA 2", "ARMM 0", "PARA"};

    cpu_estado_inicializa(&c, &e);
    cpu_altera_mem_programa(&c, 6, programa);
    cpu_altera_mem_dados(&c, 50, dados);

    while(cpu_interrupcao(&c) == 0){
        cpu_executa(&c);
    }

    printf("CPU parou na instrucao %s \n", c.mem_prog[c.reg_cont_prog]);
    printf("O valor da memoria de dados eh %d \n", c.mem_dados[0]);

}
