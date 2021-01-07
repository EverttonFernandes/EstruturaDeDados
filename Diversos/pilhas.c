#include<stdio.h>
#include<stdlib.h>
    ///                 PILHAS EM ESTRUTURA DE DADOS, (LAST IN, FIRST OUT)
#define TAM 10
int prateleira[TAM];
int topoPilha=0;
int *topo,*fimPilha;

void inserePilha(){
    int prato;
    printf("Insira um valor: \n");
    scanf("%i",&prato);
    if(topoPilha>=TAM){
        printf("A pilha/prateleira esta cheia! \n\n");
    }

    else{
        prateleira[TAM] = prato;
        topoPilha++;
    }


}
int removePilha(){
    topoPilha--;
    if(topoPilha<0){
        printf("A prateleira esta vazia! \n\n");
    }
    else{
        return prateleira[TAM];
    }
}
void consultaPilha(){
    int i;
    for(i=0; i<TAM ; i++){
        printf("%i ",prateleira[i]);
    }
}
main(){
    int p = (int*)malloc(TAM,sizeof(int)); /// memória da pilha
    if(!p){
        printf("Falha na alocacao de memoria! \n");
    }*/
    int opcao;
    printf("\t\t\tOLA, ESCOLHA UMA DAS OPCOES:\n");
    printf("1)INSERIR PRATO\n2)REMOVER PRATO\n3)CONSULTAR QUANTOS PRATOS TEM NA PRATELEIRA\n0)SAIR \n");
    scanf("%i",&opcao);
    for(;;){
        switch(opcao){
        case 1:
            inserePilha();
            break;
        case 2:
            removePilha();
            break;
        case 3:
            consultaPilha();
            break;
        case 0:
            printf("Programa encerrado! \n");
            exit(0);
        }
    }
    int ultimoDaPilha;
    ultimoDaPilha=removePilha();
    printf("Ultimo da pilha e: %i",ultimoDaPilha);
}
