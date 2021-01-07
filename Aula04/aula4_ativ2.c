#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

struct fila {
    int n, ini, fim;
    char vet[N][N];
};

typedef struct fila Fila;
int i;

Fila* cria_fila(void){
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->n = 0;
    f->ini = 0;
    f->fim = 0;
    return f;
}

void insere_fila(Fila* f, char* v){
    if(f->n == N){
        printf("\nCapacidade da fila estourou");
        exit(1);
    }
    f->fim = (f->ini + f->n) % N;
    strcpy(f->vet[f->fim], v);
    f->n++;
}

char* retira_fila(Fila* f){
    //char v[100];
    if(fila_vazia(f)){
        printf("\nFila vazia.");
        exit(1);
    }
    f->ini = (f->ini + 1) % N;
    f->n--;
    return f->vet[f->ini-1];
}

void imprime_fila(Fila* f){
    for(i=f->ini;i<=f->fim;i++){
        printf("%s\n",f->vet[i]);
    }
}

int fila_vazia(Fila* f){
    return f->n <=0;
}

void esvazia(Fila* f1, Fila* f2, Fila* f_res){
    int x=0, y=0;
    char *retirado;
    do{
        if(((y+1 != x) || (y>f2->fim)) && (x-1<f1->fim)){
            retirado = retira_fila(f1);
            insere_fila(f_res, retirado);
            x++;
        }else if ((y+1 == x)|| x>f1->fim){
            retirado = retira_fila(f2);
            insere_fila(f_res, retirado);
            y++;
        }
    }while(x<=f1->fim || y<=f2->fim);
}

main(){
    int tamF1, tamF2;
    char nome[100];

    Fila* f1 = cria_fila();
    Fila* f2 = cria_fila();
    Fila* f_res = cria_fila();

    printf("Qual o tamanho da fila 1? ");
    scanf("%i",&tamF1);
    fflush(stdin);
    printf("Listar o nome das pessoas na fila 1:\n");
    for(i=0;i<tamF1;i++){
        printf("\t");
        gets(nome);
        insere_fila(f1,nome);
    }

    printf("\nQual o tamanho da fila 2? ");
    scanf("%i",&tamF2);
    fflush(stdin);
    printf("Listar o nome das pessoas na fila 2:\n");
    for(i=0;i<tamF2;i++){
        printf("\t");
        gets(nome);
        insere_fila(f2,nome);
    }

    printf("\n####### ANTES #######\nF1:\n");
    imprime_fila(f1);
    printf("\nF2:\n");
    imprime_fila(f2);
    printf("\nF_res:\n");
    imprime_fila(f_res);

    esvazia(f1, f2, f_res);

    printf("\n####### DEPOIS #######\nF1:\n");
    imprime_fila(f1);
    printf("\nF2:\n");
    imprime_fila(f2);
    printf("\nF_res:\n");
    imprime_fila(f_res);
}
