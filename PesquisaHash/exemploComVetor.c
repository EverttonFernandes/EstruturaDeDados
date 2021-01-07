#include<stdio.h>
#include<stdlib.h>

int hash(int valor, int tam){
    return (valor%tam);
}

main(){
    int vetor[7] = {0};
    int val, aux, i;

    for(i=0; i<5; i++){
        printf("");
        scanf("%d",&val);
        aux = hash(val,7);
        vetor[aux] = val;
    }

    for(i=0; i<7; i++){
        printf("vetor[%i] = %i",i,vetor[i]);
    }
}
