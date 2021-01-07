#include<stdio.h>
#include<stdlib.h>

/** Implemente as funções de busca, inserção e remoção de arvores binárias  de busca (apresentadas anteriormente), criando também as arvores vistas em aula **/
struct arv{
    int info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* arv_cria (char c, Arv* SubArvoreEsqueda, Arv* SubArvoreDireita){
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = SubArvoreEsqueda;
    p->dir = SubArvoreDireita;
    return p;
}

int arv_vazia(Arv* a){
    return NULL;
}

Arv* abb_busca(Arv* r, int v){
    if(r==NULL){
        return NULL;
    }
    else if(r->info>v){
        return abb_busca(r->esq,v);
    }
    else if(r->info<v){
        return abb_busca(r->dir,v);
    }
    else{
        return r;
    }
}

Arv* abb_insere(Arv* a,int v){
    if(a==NULL){
        a=(Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if(v < a->info){
        a->esq = abb_insere(a->esq,v);
    }

    else{
        v > a->info;
        a->dir = abb_insere(a->dir,v);
        return a;
    }
}
Arv* abb_retira(Arv* r,int v){
    if(r==NULL){
        return NULL;
    }
    else if(r->info > v){
        r->esq = abb_insere(r-esq,v);
    }
    else if(r->info < v){
        r->dir = abb_retira(r->dir,v);
    }
    else{ /// achou o nó  a remover
        /// nó sem filhos
        if(r->esq == NULL && r->dir==NULL){
            free(r);
            r=NULL;
        }
    }
    else if(r->esq==NULL){
        Arv* t = r;
        r=r->dir;
        free(t);
    }
    ///só tem filho a esquerda
    else if(r->dir==NULL){
        Arv* t = r;
        r = r->esq;
        free(t);
    }
    /// nó tem os dois filhos
}
void arv_preordem (Arv* a){
    if(!arv_vazia(a)){
        imprimi(a);
        arv_preordem(a->esq);
        arv_preordem(a->dir);
    }
}

main(){
    int v;
    arv_cria();
    abb_insere();
}
