#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

#define MAX 5
/** ESTRUTURA DE DADOS - APRENDENDO FILAS **/

/** Protótipo das funções e variáveis globais **/
void qstore(char *q); /// Está função armazena um evento colocando no final da fila
void enter(void);
void review(void);
void delete(void);
char *qretrieve(void); /// Está função recupera um evento removendo o primeiro da fila
/**---------------------------------------------------------------------------------------**/
char *p[MAX];
int spos=0;
int rpos=0;
/**---------------------------------------------------------------------------------------**/
main(){
    setlocale(LC_ALL, "Portuguese");
    char s[80];
    register int t;
    for(t=0; t<MAX; t++)
        p[t]=NULL; /** Inicializa a matriz com nulos **/
    printf("\t\t\t\tMINI PROGRAMA DE UMA AGENDA DE EVENTOS \n");
    printf("     ######   \n");
    printf("   ###    ###\n");
    printf("  ###     ###\n");
    printf(" ############\n");
    printf("###       ###\n");
    for(;;){
        printf("I)INSERIR\nL)LISTAR\nR)REMOVER\nS)SAIR \n");
        gets(s);
        *s=toupper(*s);
        switch(*s){
        case 'I':
            enter();
            system("cls");
            break;
        case 'L':
            review();

            break;
        case 'R':
            delete();

            break;
        case 'S':
            exit(0);
        }
    }
}
/**------------------------------------------------------------------------------------------------------**/
void enter(void){ /** INSERE UM EVENTO NA FILA **/
    char s[256],*p;
    do{
        printf("Insira o evento %i°: \n",spos+1);
        gets(s);
        if(*s==0) /// nenhuma entrada
            break;
        p=malloc(strlen(s)+1);
        if(!p){
            printf("Sem memoria! \n");
            return;
        }
        strcpy(p,s);
        if(*s)
            qstore(p);
    }while(*s);
}
/**------------------------------------------------------------------------------------------------------**/
void review(void){/** VERIFICA O QUE CONSTA NA FILA **/
    register int t;
    for(t=rpos; t<spos; t++){
        printf("%i. %s\n",t+1,p[t]);
    }
}
/**------------------------------------------------------------------------------------------------------**/
void delete(void){ /** APAGA UM EVENTO DA FILA **/
    char *p;
    if((p=qretrieve())==NULL)
        return;
    printf("%s\n",p);
}
/**------------------------------------------------------------------------------------------------------**/
void qstore(char *q){ /** ARMAZENA UM EVENTO **/
    if(spos==MAX){
        printf("A lista está cheia \n");
    }
    p[spos]=q;
    spos++;
}
/**------------------------------------------------------------------------------------------------------**/
char *qretrieve(){ /** RECUPERA UM EVENTO **/
    if(rpos==spos){
        printf("A lista está vazia \n");
    }
    rpos++;
    return p[rpos-1];
}
/**------------------------------------------------------------------------------------------------------**/
