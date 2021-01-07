#include<stdio.h>
#include<stdlib.h>

/** Implemente as fun��es b�sicas de opera��o de filas vistas anteriormente, adicionando tamb�m uma fun��o de impress�o
 (do in�cio para o final da fila).
 � Simule uma sequ�ncia de inser��es e remo��es proposta, verificando a adequa��o atrav�s de chamadas � fun��o de impress�o criada.
Estruturas  **/

int tam=0;
int pos=0;
void cria_fila();
void insere_fila();
void imprimi_fila();
void delete(void);
void *remove_fila();

main(){
    int opc;
    float valor;
    cria_fila();
    for(;;){
        printf("1)INSERIR\n2)REMOVER\n3)LISTAR\n4)SAIR \n");
        scanf("%i",&opc);
        if(opc==1){
            insere_fila();
            system("cls");
           /// break;
        }
        if(opc==2){
            remove_fila();
            system("cls");
            ///break;
        }
        if(opc==3){
            imprimi_fila();
            ///break;
        }
        if(opc==4){
            exit(0);
        }
    }
}
void cria_fila(){
    int *f=(int*)malloc(sizeof(int)*tam);
}
void insere_fila(int *f){
    int valor,i;
    printf("Digite um numero para inserir na fila na pos %i: \n",tam+1);
    scanf("%f",&valor);
    for(i=0; i<tam ; i++){
        scanf("%i",&f[i]);
    }
    tam++;
///    *vet = (int*)realloc(vet,sizeof(int)*(*t));
    f = (int*)realloc(f,sizeof(int)*(tam));
}
void delete(void){
    int *p;
    if((p=remove_fila())==NULL)
        return;
}
void *remove_fila(int *f){
    if(f==NULL){
        printf("A fila est� vazia! \n");
    }
    else{
        tam--;
        f=(int*)realloc(f,sizeof(int)*(tam));
    }
}
void imprimi_fila(int *f){
    int i;
    for(i=0; i<tam; i++){
        printf("%i ",f[i]);
    }
}
