#include<stdio.h>
#include<stdlib.h>
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
#define M 100
#define O 100
typedef struct fila Fila1;
typedef struct fila Fila2;
typedef struct fila Fila_res;

struct fila1{
    int n1; /// numero de elementos da fila
    int ini1; /// posição do próximo elemento da fila
    float vet[N];
};
struct fila2{
    int n2; /// numero de elementos da fila
    int ini2; /// posição do próximo elemento da fila
    float vet2[M];
};
struct fila_res{
    int n3; /// numero de elementos da fila
    int ini3; /// posição do próximo elemento da fila
    float vet3[O];
};
/*Fila1 *fila_cria(void){
    Fila1 *f1 = (Fila1*) malloc(sizeof(Fila1));
    f1->n1=0; /// inicializa a fila como vazia
    f1->ini1=0; /// escolhe uma posição inicial
    return f1;
}*/
Fila2 *fila_cria(void){
    Fila2 *f2 = (Fila2*) malloc(sizeof(Fila2));
    f2->n2=0; /// inicializa a fila como vazia
    f2->ini2=0; /// escolhe uma posição inicial
    return f2;
}
Fila_res *fila_cria(void){
    Fila_res *f3 = (Fila_res*) malloc(sizeof(Fila_res));
    f3->n3=0; /// inicializa a fila como vazia
    f3->ini3=0; /// escolhe uma posição inicial
    return f3;
}
void insere_filas(Fila *f1, Fila *f2){
    int fim1;
    int fim2;
    float v1,v2;
    printf("Digite um numero para inserir na fila 1: \n");
    scanf("%f",&v1);
    printf("Digite um numero para inserir na fila 1: \n");
    scanf("%f",&v2);
    if(f1->n==N){
        printf("Fila 1 cheia! \n");
        exit(1);
    }
        fim1 = (f->ini1+f->n1)%N;
        f->vet1[fim1] = v1;
        f->n1++;

    if(f2->n==M){
        printf("Fila 2 cheia! \n");
        exit(1);
    }
        fim2 = (f->ini2+f->n2)%M;
        f->vet2[fim2] = v2;
        f->n2++;
}
void remove_filas(Fila *f1,Fila *f2, Fila f_res){
    float v1;
    float v2;
    if(f1->n==0 && f2->n2==0){
        printf("Filas vazias!\n");
        exit(1);
    }
    v1 = f1->vet1[f1->ini1];
    f1->ini1=(f1->ini1+1)%N;
    f1->n1--;

    v2 = f2->vet[f->ini];
    f2->ini2=(f2->ini2+1)%M;
    f->n2--;

    fim3 = (f_res->ini3+f_res->n3)%O;
    f_res->vet3[fim3] = v1;
    f->n3++;
    f_res->vet3[fim3] = v2;
    f->n3++;
}
void imprimi_fila_res(Fila *f_res){
    if(f_res->n3==0){
        printf("Fila vazia!\n");
        system("pause");
        system("cls");

    }
    int fim = (f_res->ini3+f_res->n3)%O;
    int inicio = f_res->ini3;
    int i;
    for(i = inicio; i < fim; i++){
        printf("Elemento: %.2f \n",f_res->vet3[i]);
    }
}
main(){
   int opc;
    ///float valor;
    Fila *f1 = fila_cria();

    for(;;){
        printf("1)INSERIR\n2)REMOVER\n3)LISTAR\n4)SAIR \n");
        scanf("%i",&opc);
        if(opc==1){
            insere_fila(f1,f2);
            system("cls");
           /// break;
        }
        if(opc==2){
            remove_fila(f1,f2);
            system("cls");
           /// break;
        }
        if(opc==3){
            imprimi_fila(f_res);
        }
        if(opc==4){
            exit(0);
        }
    }
}


}

/// FILA DUPLAMENTE ENCADEADA
