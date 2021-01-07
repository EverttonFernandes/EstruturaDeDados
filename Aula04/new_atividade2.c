#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/** Combinação de filas:
1) Implemente uma função que receba três filas,
f_res, f1 e f2, e transfira alternadamente os
elementos de f1 e f2 para f_res.
2) Ao final de função, as filas f1 e f2 devem estar
vazias.
3) A fila f_res pode ou não estar vazia
inicialmente
 **/
#define N 100
typedef struct fila Fila;
int i;

struct fila {
    int n, ini, fim;
    char vet[N];
};

Fila* cria_fila(void){
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->n = 0;
    f->ini = 0;
    f->fim = 0;
    return f;
}

void insere_filas(Fila* f){
    float v;

    printf("Digite um numero para inserir na fila: \n");
    scanf("%f",&v);

    if(f->n==N){
        printf("Fila cheia! \n");
        exit(1);
    }
        f->fim = (f->ini + f->n) % N;
        f->vet[f->fim] = v;
        f->n++;
}

float* retira_da_fila(Fila* f){
    if(fila_vazia(f)){
        printf("\nFila vazia.");
        exit(1);
    }
    f->ini = (f->ini + 1) % N;
    f->n--;
    return f->vet[f->ini-1];
}

int fila_vazia(Fila* f){
    return f->n <=0;
}

void remove_filas(Fila *f1,Fila *f2, Fila *f_res){
    float *remove;
    int tam1=0,tam2=0;
    while(tam1<=f1->fim || tam2<=f2->fim){
        if(((tam2+1!=tam2) || (tam2-1<=f2->fim)) && (tam1-1<f1->fim)){
            remove = retira_da_fila(f1);
            insere_filas(f_res,remove);
            tam1++;
        }
        else if((tam2+1==tam1) || tam1>f1->fim){
            remove = retira_da_fila(f2);
            insere_filas(f_res,remove);
            tam2++;
        }
    }
}

void imprimi_fila_res(Fila *f){
    /**if(f_res->f->n==0){
        printf("Fila vazia!\n");
        system("pause");
        system("cls");

    }**/
    for(i = f->ini; i < f->fim; i++){
        printf("Elemento: %.2f \n",f->vet[i]);
    }
}
main(){
    int opc;
    float valor;

    Fila* f1 = cria_fila();
    Fila* f2 = cria_fila();
    Fila* f_res = cria_fila();

    do{
        printf("1)INSERIR FILA 1\n2)2)INSERIR FILA 2\n3)REMOVER FILA 1 E FILA 2\n4)LISTAR FILA RES\n5)SAIR DO PROGRAMA \n");
        scanf("%i",&opc);
        if(opc==1){
            insere_filas(f1);
            system("cls");
           /// break;
        }
        if(opc==2){
            printf("Digite um numero para inserir na fila 1: \n");
            scanf("%f",&valor);
            insere_filas(f2,valor);
            system("cls");
           /// break;
        }
        if(opc==3){
            remove_filas(f1,f2,f_res);
            ///printf("Valor que foi removido: %.2f \n",numero);
            system("cls");
           /// break;
        }
        if(opc==4){
            imprimi_fila(f_res);
        }
    }while(opc!=5);
}
