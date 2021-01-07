#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define tam 100 /// constante de tamanho 100

char pilha[tam],result[tam],l;
int t=0,cont=0;

	void criaPilha(){
		t = 0;
	}
	void empilha(char y){
		pilha[t++] = y; /// a cada caracter recebido como parametro ele vai empilhando
	}
	char desempilha(){
		return pilha[--t]; /// desempilha e vai jogando o ultimo caracter do vetor pilha na primeira posição do vetor result e assim sucessivamente
	}
main(){
	int i;
	printf("Digite uma frase:\n");
	for(; ;){
		l=getche();
		if(l==32 || l==13){ /// se caso o usuario apertar espaço a primeira palavra é empilhada e depois desempilhada para o outro vetor, se caso
                /// o usuario apertar ENTER apenas uma palavra é empilhada e depois desempilhada para o outro vetor
			while(t>=0){
				result[cont] = desempilha(); /// o ultimo da pilha é o primeiro a ser inserido no vetor e assim sucessivamente
				cont++; /// vai para a proxima posição, recebe o penultimo caracter da pilha e assim por diante
			}
			if(l==13)
				break;
			criaPilha();
		}else
			empilha(l);
	}
	printf("\nResultado: ");
	for(i=0;i<=cont;i++){
		printf("%c",result[i]); /// mostra na tela o vetor result com cada palavra desempilhada na tela
	}
}
