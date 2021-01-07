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
    printf("\n\nInforme o valor do nó: ");
    scanf("%i", &valor);
    no *novo = new no;
    novo->conteudo = valor;
    novo->anterior = NULL; ///como está sendo inserido no início, não há nó anterior
    novo->proximo = primeiroNo; ///o antingo primeiro nó da lista será o próximo
    if (primeiroNo == NULL) {
    ///se a lista estava vazia, esse nó também será o último
    ultimoNo = novo;
    } else {
    ///se a lista não estava vazia...
    primeiroNo->anterior = novo; ///o antigo primeiro nó agora aponta, no campo anterior, para este que está sendo inserido
    }

    primeiroNo = novo;
}

void InserirNoFim() {
    int valor;
    printf("\n\nInforme o valor do nó'': ");
    scanf("%i", &valor);
    no *novo = new no;
    novo->conteudo = valor;
    novo->anterior = ultimoNo; /// o antingo ultimo nó da lista será o anterior a este que está sendo inserido
    novo->proximo = NULL; /// como está sendo inserido no final, não há próximo nó
    if (primeiroNo == NULL) {
    ///se a lista estava vazia, esse nó também será o primeiro
    primeiroNo = novo;
    } else {
    ///se a lista não estava vazia...
    ultimoNo->proximo = novo; ///o antigo último nó agora aponta, no campo próximo, para este que está sendo inserido
    }
    ultimoNo = novo; ///ajusta o ponteiro para o fim da lista
}

void RemoverDoInicio(){
    if (primeiroNo != NULL) { ///verifica se a lista não está vazia
    int valor = primeiroNo->conteudo;
    if (primeiroNo == ultimoNo) { /// se há apenas um elemento na lista
    primeiroNo = NULL;
    ultimoNo = NULL;
    } else {
    no *segundo = primeiroNo->proximo; //pega o segundo nó
    segundo->anterior = NULL; ///remove o link que o segundo tinha para o primeiro
    primeiroNo = segundo; ///promove o segundo nó a primeiro
    }
    printf("\n\nO elemente de valor %i foi removido do início da lista!", valor);
    getch();
    }
}

void RemoverDoFim(){
    if (ultimoNo != NULL) { ///verifica se a lista não está vazia
    int valor = ultimoNo->conteudo;
    if (primeiroNo == ultimoNo) { /// se há apenas um elemento na lista
    primeiroNo = NULL;
    ultimoNo = NULL;
    } else {
    no *penultimo = ultimoNo->anterior; ///pega o penúltimo nó
    penultimo->proximo = NULL; ///remove o link que o penúltimo tinha para o último
    ultimoNo = penultimo; ///promove o penúltimo nó a último
    }
    printf("\n\nO elemente de valor %i foi removido do final da lista!", valor);
    getch();
    }
}

void RemoverDaPosicao() {

    int posicaoAExcluir;
    printf("\n\nInforme a posição do elemento a ser removido: ");
    scanf("%i", &posicaoAExcluir);
    int posicaoAtual = 1;
    no *noAtual = primeiroNo;
    while (noAtual != NULL && posicaoAtual <= posicaoAExcluir) {
    if (posicaoAtual == posicaoAExcluir) { /// se chegou na posição a ser excluída
        if (noAtual->anterior == NULL) { /// se não há anterior, é a primeira posição
            RemoverDoInicio();
        }
        else {
            if (noAtual->proximo == NULL) { /// se não há próximo, é a última posicao
                RemoverDoFim();
            }
            else {
                noAtual->anterior->proximo = noAtual->proximo;
                noAtual->proximo->anterior = noAtual->anterior;
                printf("\n\nO elemento de valor %i foi removido da posição %i.", noAtual->conteudo, posicaoAtual);
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
        if (noAtual->conteudo == valorAExcluir) { /// se o nó atual tem o valor a ser exclúido
            if (noAtual->anterior == NULL) { /// se não há anterior, é a primeira posição
                RemoverDoInicio();
            }
            else{
                if (noAtual->proximo == NULL) { /// se não há próximo, é a última posicao
                    RemoverDoFim();
                }
                else {
                    no *noAnterior = noAtual->anterior;
                    no *proximoNo = noAtual->proximo;
                    noAnterior->proximo = proximoNo;
                    proximoNo->anterior = noAnterior;
                    printf("\n\nO elemento de valor %i foi removido da posição %i.", noAtual->conteudo, posicaoAtual);
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
        printf("A lista está vazia!");
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
        printf("(1) Inserir elemento no início da lista\n");
        printf("(2) Inserir elemento no fim da lista\n");
        printf("(3) Remover elemento do início da lista\n");
        printf("(4) Remover elemento do final da lista\n");
        printf("(5) Remover elemento de determinada posição\n");
        printf("(6) Remover elemento pelo conteúdo\n");
        printf("(7) Sair do Programa\n");
        printf("\nDigite a opção desejada: ");
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
