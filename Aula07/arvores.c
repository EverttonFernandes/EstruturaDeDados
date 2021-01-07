#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;

///Cria uma arvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

///cria uma arvore com a informado do no raiz c, e
///com sub arvore esquerda e sub arvore direita d
Arv* arv_cria (int c, Arv* sae, Arv* sad){
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

///retorna true se a arvore estiver vazia e false caso contrario
int arv_vazia (Arv* a){
    return a==NULL;
}

///busca valor em arvore binaria
Arv* arv_busca (Arv* a, int v){
	if(a == NULL)
        return NULL;
	else if(a->info > v)
        return arv_busca(a->esq, v);
	else if(a->info < v)
        return arv_busca(a->dir, v);
	else
        return a;
}

///insere o de elemento em arvore binaria
Arv* arv_insere (Arv* a, int v){
	if(a == NULL){ /// SE FOR A PRIMEIRA VEZ ELE INSERE O VALOR COMO RAIZ
		a = (Arv*)malloc(sizeof(Arv));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if(v < a->info){ /// CASO JÁ TENHA ALGUM VALOR INSERIDO, ELE VERIFICA SE É MENOR, CASO FOR MENOR ELE VIRA O NÓ FILHO DA ESQUERDA
		a->esq =  arv_insere(a->esq,v);
	}
	else{ /// v > a->info /// /// CASO JÁ TENHA ALGUM VALOR INSERIDO, ELE VERIFICA SE É MENOR, CASO FOR MENOR ELE VIRA O NÓ FILHO DA DIREITA
		a->dir =  arv_insere(a->dir,v);
	}
	return a; /// RETORNA A ARVORE
}

///remove o de elemento em arvore binaria
Arv* arv_retira (Arv* a, int v){
	if(a == NULL)
		return NULL;
	else if (a->info > v)
		a->esq =  arv_retira(a->esq,v); /// SE O ELEMENTO INFORMADO FOR MENOR QUE RETIRA DA ESQUERDA
	else if (a->info < v)
		a->dir =  arv_insere(a->dir,v); ///SE O ELEMENTO INFORMADO FOR MAIOR QUE RETIRA DA DIREITA
	else{
		///nó sem filhos
		if(a->esq == NULL && a->dir == NULL){ /// SE OS NÓS DA DIREITA E ESQUERDA FOREM NULOS, RETIRA O NÓ RAIZ INSERIDO
			free(a);
			a = NULL;
		}
		///nó só tem filhos a direita
		else if(a->esq == NULL){
			Arv* t= a;
			a = a->dir;
			free(t);
		}
		///nó só tem filhos a esquerda
		else if(a->dir == NULL){
			Arv* t= a;
			a = a->esq;
			free(t);
		}
		///nó tem os dois filhos
		else{
			Arv* f= a->esq;
			while(f->dir != NULL){
				f = f->dir;
			}
			///troca as informações de lugar
			a->info = f->info;
			f->info = v;
			a->esq = arv_retira(a->esq, v);
		}
	}
	return a;
}

///libera o espa?o de mem?ria ocupado pela ?rvore a
Arv* arv_libera (Arv* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq); /** libera sae **/
        arv_libera(a->dir); /** libera sad **/
        free(a); /** libera raiz **/
    }
    return NULL;
}

///indica a ocorr?ncia (1) ou n?o (0) do caracter c
int arv_pertence (Arv* a, int c){
    if (arv_vazia(a))
        return 0; /** arvore vazia: nao encontrou **/
    else
        return a->info==c || arv_pertence(a->esq,c) || arv_pertence(a->dir,c);
}


///imprime as informa??es dos n?s da ?rvore
///ordem de percurso pr?-ordem
void arv_preordem (Arv* a)
{
    if (!arv_vazia(a))
    {
        printf("%d ", a->info); /** mostra raiz **/
        arv_preordem(a->esq);  /** mostra sae **/
        arv_preordem(a->dir); /** mostra sad **/
    }
}

///ordem de percurso inordem
void arv_inordem (Arv* a)
{
    if (!arv_vazia(a))
    {
        arv_inordem (a->esq);   /** mostra sae **/
        printf("%d ", a->info); /** mostra raiz **/
        arv_inordem (a->dir);   /** mostra sad **/
    }
}

///ordem de percurso p?s-ordem
void arv_posordem (Arv* a)
{
    if (!arv_vazia(a))
    {
        arv_posordem (a->esq);  /** mostra sae **/
        arv_posordem (a->dir);  /** mostra sad **/
        printf("%d ", a->info); /** mostra raiz **/
    }
}

int main() {

    ///Criar a ?rvore < a < b < > < d < > < > > > < c < e < > < > >
    ///               < f < > < > > > >
    /**
    // sub-?rvore 'd'
    Arv* a1= arv_cria('d',arv_criavazia(),arv_criavazia());
    // sub-?rvore 'b'
    Arv* a2= arv_cria('b',arv_criavazia(),a1);
    // sub-?rvore 'e'
    Arv* a3= arv_cria('e',arv_criavazia(),arv_criavazia());
    // sub-?rvore 'f'
    Arv* a4= arv_cria('f',arv_criavazia(),arv_criavazia());
    // sub-?rvore 'c'
    Arv* a5= arv_cria('c',a3,a4);
    // ?rvore 'a'
    Arv* a = arv_cria('a',a2,a5 );
    **/

    ///Criar a ?rvore < a < b < > < d < > < > > > < c < e < > < > >
    ///               < f < > < > > > >
    ///Arv* a = arv_cria('a',arv_cria('b',arv_criavazia(),arv_cria('d', arv_criavazia(), arv_criavazia())),arv_cria('c', arv_cria('e', arv_criavazia(), arv_criavazia()),arv_cria('f', arv_criavazia(), arv_criavazia())));


    ///Criar a ?rvore  <6         <2          <1  <><>                            >          <4         <3     <><>                         >       <>       >>          <8    <><>                          >>
    Arv* a = arv_cria(6, arv_cria(2, arv_cria(1, arv_criavazia(), arv_criavazia()), arv_cria(4,arv_cria(3, arv_criavazia(), arv_criavazia()),arv_criavazia())), arv_cria(8, arv_criavazia(), arv_criavazia()));

    ///Acrescenta n?s x, y e z
    /**a->esq->esq = arv_cria('x',
                  arv_cria('y',
                  arv_criavazia(),
                  arv_criavazia()),
                  arv_cria('z',
                  arv_criavazia(),
                  arv_criavazia()));

    //libera nos
    a->dir->esq = arv_libera(a->dir->esq);**/

    printf("Pre-ordem: ");
    arv_preordem(a);
    printf("\nIn-ordem: ");
    arv_inordem (a);
    printf("\nPos-ordem: ");
    arv_posordem (a);

	if(arv_pertence(a, 10) == 0){
        printf("\nValor Nao encontrado!");
    }else{
        printf("\nValor encontrado!");
    }

	arv_insere(a, 10);
	arv_retira(a, 6);

	printf("\nIn-ordem: ");
    arv_inordem (a);

    return 0;
}
