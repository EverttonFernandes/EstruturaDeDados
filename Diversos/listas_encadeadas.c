#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct no {
    int conteudo;
    struct no *proximo;
    struct no *anterior;
};

no *primeiroNo;
no *ultimoNo;

void InserirNoIncio() {
    int valor;
    printf("\n\nInforme o valor do n�: ");
    scanf("%i", &valor);
    no *novo = new no;
    novo->conteudo = valor;
    novo->anterior = NULL; ///como est� sendo inserido no in�cio, n�o h� n� anterior
    novo->proximo = primeiroNo; ///o antingo primeiro n� da lista ser� o pr�ximo
    if (primeiroNo == NULL) {
    ///se a lista estava vazia, esse n� tamb�m ser� o �ltimo
    ultimoNo = novo;
    } else {
    ///se a lista n�o estava vazia...
    primeiroNo->anterior = novo; ///o antigo primeiro n� agora aponta, no campo anterior, para este que est� sendo inserido
    }

    primeiroNo = novo;
}

void InserirNoFim() {
    int valor;
    printf("\n\nInforme o valor do n�'': ");
    scanf("%i", &valor);
    no *novo = new no;
    novo->conteudo = valor;
    novo->anterior = ultimoNo; /// o antingo ultimo n� da lista ser� o anterior a este que est� sendo inserido
    novo->proximo = NULL; /// como est� sendo inserido no final, n�o h� pr�ximo n�
    if (primeiroNo == NULL) {
    ///se a lista estava vazia, esse n� tamb�m ser� o primeiro
    primeiroNo = novo;
    } else {
    ///se a lista n�o estava vazia...
    ultimoNo->proximo = novo; ///o antigo �ltimo n� agora aponta, no campo pr�ximo, para este que est� sendo inserido
    }
    ultimoNo = novo; ///ajusta o ponteiro para o fim da lista
}

void RemoverDoInicio(){
    if (primeiroNo != NULL) { ///verifica se a lista n�o est� vazia
    int valor = primeiroNo->conteudo;
    if (primeiroNo == ultimoNo) { /// se h� apenas um elemento na lista
    primeiroNo = NULL;
    ultimoNo = NULL;
    } else {
    no *segundo = primeiroNo->proximo; //pega o segundo n�
    segundo->anterior = NULL; ///remove o link que o segundo tinha para o primeiro
    primeiroNo = segundo; ///promove o segundo n� a primeiro
    }
    printf("\n\nO elemente de valor %i foi removido do in�cio da lista!", valor);
    getch();
    }
}

void RemoverDoFim(){
    if (ultimoNo != NULL) { ///verifica se a lista n�o est� vazia
    int valor = ultimoNo->conteudo;
    if (primeiroNo == ultimoNo) { /// se h� apenas um elemento na lista
    primeiroNo = NULL;
    ultimoNo = NULL;
    } else {
    no *penultimo = ultimoNo->anterior; ///pega o pen�ltimo n�
    penultimo->proximo = NULL; ///remove o link que o pen�ltimo tinha para o �ltimo
    ultimoNo = penultimo; ///promove o pen�ltimo n� a �ltimo
    }
    printf("\n\nO elemente de valor %i foi removido do final da lista!", valor);
    getch();
    }
}

void RemoverDaPosicao() {

    int posicaoAExcluir;
    printf("\n\nInforme a posi��o do elemento a ser removido: ");
    scanf("%i", &posicaoAExcluir);
    int posicaoAtual = 1;
    no *noAtual = primeiroNo;
    while (noAtual != NULL && posicaoAtual <= posicaoAExcluir) {
    if (posicaoAtual == posicaoAExcluir) { /// se chegou na posi��o a ser exclu�da
        if (noAtual->anterior == NULL) { /// se n�o h� anterior, � a primeira posi��o
            RemoverDoInicio();
        }
        else {
            if (noAtual->proximo == NULL) { /// se n�o h� pr�ximo, � a �ltima posicao
                RemoverDoFim();
            }
            else {
                noAtual->anterior->proximo = noAtual->proximo;
                noAtual->proximo->anterior = noAtual->anterior;
                printf("\n\nO elemento de valor %i foi removido da posi��o %i.", noAtual->conteudo, posicaoAtual);
                getch();
                }
            }
        }
        posicaoAtual++;
        noAtual = noAtual->proximo;
    }
}


void RemoverConteudo() {

    int valorAExcluir;
    printf("\n\nInforme o valor a ser removido: ");
    scanf("%i", &valorAExcluir);
    int posicaoAtual = 1;
    no *noAtual = primeiroNo;
    while (noAtual != NULL) {
        if (noAtual->conteudo == valorAExcluir) { /// se o n� atual tem o valor a ser excl�ido
            if (noAtual->anterior == NULL) { /// se n�o h� anterior, � a primeira posi��o
                RemoverDoInicio();
            }
            else{
                if (noAtual->proximo == NULL) { /// se n�o h� pr�ximo, � a �ltima posicao
                    RemoverDoFim();
                }
                else {
                    no *noAnterior = noAtual->anterior;
                    no *proximoNo = noAtual->proximo;
                    noAnterior->proximo = proximoNo;
                    proximoNo->anterior = noAnterior;
                    printf("\n\nO elemento de valor %i foi removido da posi��o %i.", noAtual->conteudo, posicaoAtual);
                    getch();
                }
            }
        }
        noAtual = noAtual->proximo;
        posicaoAtual++;
    }
}
void ExibirLista() {
    if (primeiroNo == NULL) {
        printf("A lista est� vazia!");
    }
    else {
        no *noAtual = primeiroNo;
        while (noAtual != NULL) {
            printf("%i   ", noAtual->conteudo);
            noAtual = noAtual->proximo;
        }
    }
    printf("\n\n");
}

main() {
    primeiroNo = NULL;
    ultimoNo = NULL;
    char opcao;
    do {
        system("cls");
        ExibirLista();
        printf("(1) Inserir elemento no in�cio da lista\n");
        printf("(2) Inserir elemento no fim da lista\n");
        printf("(3) Remover elemento do in�cio da lista\n");
        printf("(4) Remover elemento do final da lista\n");
        printf("(5) Remover elemento de determinada posi��o\n");
        printf("(6) Remover elemento pelo conte�do\n");
        printf("(7) Sair do Programa\n");
        printf("\nDigite a op��o desejada: ");
        opcao = getch();
        switch(opcao){
            case '1':
            InserirNoIncio();
            break;
            case '2':
            InserirNoFim();
            break;
            case '3':
            RemoverDoInicio();
            break;
            case '4':
            RemoverDoFim();
            break;
            case '5':
            RemoverDaPosicao();
            break;
            case '6':
            RemoverConteudo();
            break;
        }
    } while (opcao != '7');
}
