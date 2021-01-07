#include<stdio.h>
#include<string.h>

#define n 30
char pilha[n];
int t=0;

void empilhar(char y){
    pilha[t++]=y;
}

char desempilhar(){
    return pilha[--t];
}

main(){
    char exp[30],desemp;
    int i;

    printf("\nInforme uma expressao: ");
    gets(exp);

    for(i=0;i<exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{' ){
            empilhar(exp[i]);
        }else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            desemp=desempilhar();
            if(exp[i]==')' && desemp!='('){
                printf("\nExpressão inválida!");
                break;
            }
            if(exp[i]==']' && desemp!='['){
                printf("\nExpressão inválida!");
                break;
            }
            if(exp[i]=='}' && desemp!='{'){
                printf("\nExpressão inválida!");
                break;
            }
        }
    }
    printf("\nPilha: %s",pilha);
    if(exp[i]=='\0' && t == 0){
        printf("\nExpressao valida!");
    }else{
        printf("\nExpressao invalida!");
    }
}
