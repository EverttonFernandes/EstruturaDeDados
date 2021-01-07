#include<stdio.h>

/**  Implemente uma função recursiva que encontre o elemento apresentado na série de Fibonacci em uma dada posição. **/

int fibonacci(int n);
/// 1А   2А  3А  4А  5А  6А  7А  8А   9А   10А  11А  12А  13А  14А
/// 0    1   1   2   3   5   8   13   21   34   55   89   144  233
main(){
    int n;
    printf("Digite uma posicao: \n");
    scanf("%i",&n);

    int resultado = fibonacci(n);
    printf("%i ",resultado);
}

int fibonacci(int n){
    if(n==0 || n==1){ /// Se for 0 ou 1 retorna 0
        return 0;
    }
    if(n==2){
        return 1; /// se for 2 retorna 1
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2); /// se for 3 ou mais ele retorna a soma do ultimo com o penultimo
    }
}
