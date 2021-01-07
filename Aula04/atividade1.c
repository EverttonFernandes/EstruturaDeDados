#include<stdio.h>
#include<stdlib.h>

#define N 100

/** Implemente as funções básicas de operação de filas vistas anteriormente, adicionando também uma função de impressão
 (do início para o final da fila).
 • Simule uma sequência de inserções e remoções proposta, verificando a adequação através de chamadas à função de impressão criada.
Estruturas  **/

typedef struct fila Fila;

struct fila{
    int n; /// numero de elementos da fila
    int ini; /// posição do próximo elemento da fila
    float vet[N];
};

Fila *fila_cria(void){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->n=0; /// inicializa a fila como vazia
    f->ini=0; /// escolhe uma posição inicial
    return f;
}
void insere_fila(Fila *f){
    int fim;
    float v;
    printf("Digite um numero para inserir na fila: \n");
    scanf("%f",&v);
    if(f->n==N){
        printf("Fila cheia! \n");
        exit(1);
    }
        fim = (f->ini+f->n)%N;
        f->vet[fim] = v;
        f->n++;

}
float remove_fila(Fila *f){
    float v;
    if(f->n==0){
        printf("Fila vazia!\n");
        exit(1);
    }
    v = f->vet[f->ini];
    f->ini=(f->ini+1)%N;
    f->n--;

    return v;

}

void imprimi_fila(Fila *f){
    if(f->n==0){
        printf("Fila vazia!\n");
        system("pause");
        system("cls");

    }
    int fim = (f->ini+f->n)%N;
    int inicio = f->ini;
    int i;
    for(i = inicio; i < fim; i++){
        printf("Elemento: %.2f \n",f->vet[i]);
    }
}
main(){
    int opc;
    ///float valor;
    Fila *f = fila_cria();
    for(;;){
        printf("1)INSERIR\n2)REMOVER\n3)LISTAR\n4)SAIR \n");
        scanf("%i",&opc);
        if(opc==1){
            insere_fila(f);
            system("cls");
           /// break;
        }
        if(opc==2){
            float numero = remove_fila(f);
            printf("Valor que foi removido: %.2f \n",numero);
            system("cls");
           /// break;
        }
        if(opc==3){
            imprimi_fila(f);
        }
        if(opc==4){
            exit(0);
        }
    }
}
