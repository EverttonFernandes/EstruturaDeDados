#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

/** Escreva um algoritmo que use uma pilha para verificar
se uma expressão está correta

   CORRETA: ( ( ) [ ( ) ] )
   INCORRETA: ( [ ) ]

**/
int t=0;
int pilha[50];
int cont_parenteses=0;
int cont_colchetes=0;

void criapilha (void) {
   t = 0;
}

void empilha (char c) {
   pilha[t++] = c;
}

char desempilha (void) {
   return pilha[--t];
}
main(){
    char vet[50];
    char caracter;

    criapilha();
    for(;;){
        while(pilha[t]!=13 || t<50){
            caracter=getche();
            ///system("cls");
            empilha(caracter);
            break;
            ///printf("tetse"); ENTROU

            if(pilha[t]=='(' || pilha[t]==')'){
                cont_parenteses++;

            }
            if(pilha[t]=='[' || pilha[t]==']'){
                cont_colchetes--;
            }
        }

        if(cont_parenteses==2 && cont_colchetes==2){
            printf("Quantidade correta! \n");
        }
    }
    printf("%i ",cont_parenteses);
        printf("%i ",cont_colchetes);
}

/**
    CORRETA: ( ( ) [ ( ) ] )
   INCORRETA: ( [ ) ]

 **/
