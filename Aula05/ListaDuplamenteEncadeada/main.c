#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

//Defini��o do tipo lista
struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

typedef struct elemento* Lista; /// PONTEIRO DE PONTEIRO PARA A STRUCT ELEMENTO

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL) /// SE A ALOCA��O FOR FEITA COM SUCESSO
        *li = NULL; /// RETORNA O PONTEIRO APONTANDO PARA NULL
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){ /// S� VAI LIBERAR A LISTA CASO HOUVER ELEMENTOS
        Elem* no; /// N� AUXILIAR
        while((*li) != NULL){ /// ENQUANTO A CABE�A DA LISTA OU SEJA O PONTEIRO DE PONTEIRO N�O FOR NULL N�O CAI FORA DO WHILE
            no = *li; /// N� RECEBE O CONTEUDO ANTERIOR DA LISTA
            *li = (*li)->prox; /// O PONTEIRO LISTA AVAN�A E RECEBE O CONTE�DO DA PR�XIMA POSI��O
            free(no); /// LIBERA O N�
        }
        free(li); /// LIBERA A LISTA POIS O *li aponta para NULL neste momento
    }
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al; /// n� recebe os dados do aluno
    no->prox = NULL; /// o pr�ximo aponta para NULL
    if((*li) == NULL){//lista vazia: insere in�cio
        no->ant = NULL; /// O N� RECEBE NULL
        *li = no; /// O PONTEIRO DE PONTEIRO APONTA PARA O N�
    }else{ /// CASO N�O ESTIVER VAZIA
        Elem *aux; /// PONTEIRO AUXILIAR
        aux = *li; ///
        while(aux->prox != NULL){ /// ENQUANTO A PR�XIMA POSI��O FOR DIFERENTE DE NULL
            aux = aux->prox; /// PONTEIRO AUX VAI ANDANDO E APONTANDO PARA O PR�XIMO
        }
        aux->prox = no; /// ASSIM QUE O PR�XIMO FOR NULL O AUX APONTA PARA O NOVO ELEMENTO
        no->ant = aux; /// E O N� APONTA PARA O ANTERIOR NO CASO O ULTIMO ANTES DELE
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem)); /// � ALOCADO UM ESPA�O PARA UM NOVO ELEMENTO
    if(no == NULL) /// SE DEU ERRADO A ALOCA��O RETORNA 0
        return 0;
    no->dados = al; /// PEGA OS DADOS
    no->prox = (*li); /// O QUE ERA O PR�XIMO APONTA PARA O ANTERIOR
    no->ant = NULL; /// O ANTERIOR APONTA PARA NULL
    if(*li != NULL)//lista n�o vazia: apontar para o anterior!
        (*li)->ant = no; /// O ANTERIOR QUE ERA NULL RECEBE O CONTE�DO
    *li = no; /// O PONTEIRO DE PONTEIRO APONTA PARA NO QUE AGORA � O PRIMEIRO ELEMENTO DA LISTA
    return 1; /// RETORNA 1 POIS DEU CERTO A INSER��O
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ante, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in�cio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){//TERMINAR
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if(no->prox != NULL)//n�o � o �ltimo?
        no->prox->ant = no->ant;

    free(no);
    return 1;
}


int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)//remover o primeiro e �nico
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL) /// SE FOR IGUAL A NULL, N�O EXISTE NENHUMA LISTA
        return 0; /// ENT�O RETORNA 0
    int cont = 0;
    Elem* no = *li; /// N� RECEBE O PRIMEIRO ELEMENTO DA LISTA
    while(no != NULL){ /// ENQUANTO N� N�O FOR IGUAL A NULL
        cont++; /// O CONT VAI PERCORRENDO A LISTA AT� QUE O N� SEJA IGUAL A NULL
        no = no->prox;
    }
    return cont; /// RETORNA O CONT POIS ELE TEM O TAMANHO FINAL DESTA LISTA
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

int main(){
    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));


    //remove_lista(li,3);
    for(i=0; i < 4; i++){
        remove_lista_final(li);
        imprime_lista(li);
        printf("\nTamanho: %d\n\n\n\n",tamanho_lista(li));
    }

    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    libera_lista(li);
    system("pause");
    return 0;
}

