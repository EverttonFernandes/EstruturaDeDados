#include<stdio.h>
#include<stdlib.h>

#define 7
typedef struct{
    int chave;
    string valor;
} tipoObjeto;

tipoObjeto objetonulo;
objetonulo.chave = 0;

typedef struct insere *link;

struct insere{
    tipoObjeto obj;
    link proximo;
};
void insere(tipoObjeto obj){
    int h,v;
    v = obj.chave;
    h = hash(v,M);
    link novo = malloc(sizeof (insere));
    novo->obj = obj;
    novo->proximo = tab[h];
}
main(){

}
