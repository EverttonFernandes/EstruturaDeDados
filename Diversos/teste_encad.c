/*
void InserirNoMeio(){
    int valorAInserir;
    printf("Informe o valor do nó a ser inserido: \n");
    scanf("%i",&valorAInserir);
    /// no *novo = (no*) malloc(sizeof(no)); /// a mesma coisa que usar o new
    no *novo = new no;
    int posicaoAtual = 1;
    no *noAtual = primeiroNo;
    while (noAtual != NULL && posicaoAtual <= valorAInserir) {
    if (posicaoAtual == valorAInserir) { /// se chegou na posição a ser excluída
        if (noAtual->anterior == NULL) { /// se não há anterior, é a primeira posição
            InserirNoInicio();
        }
        else {
            if (noAtual->proximo == NULL) { /// se não há próximo, é a última posicao
                InserirNoFim();
            }
            else {
                noAtual->anterior->proximo = noAtual->proximo;
                noAtual->proximo->anterior = noAtual->anterior;
                printf("\n\nO elemento de valor %i foi adicionado na posição %i.", noAtual->conteudo, posicaoAtual);
                getch();
                }
            }
        }
        posicaoAtual++;
        noAtual = noAtual->proximo;
    }
}*/

printf("(1) Inserir elemento no início da lista\n");
        printf("(2) Inserir elemento no fim da lista\n");
        printf("(3) Inserir elemento no meio da lista\n");
        printf("(4) Remover elemento do início da lista\n");
        printf("(5) Remover elemento do final da lista\n");
        printf("(6) Remover elemento de determinada posição\n");
        printf("(7) Remover elemento pelo conteúdo\n");
        printf("(8) Sair do Programa\n");
        printf("\nDigite a opção desejada: ");
        opcao = getch();
        switch(opcao){
            case '1':
                InserirNoInicio();
                break;

            case '2':
                InserirNoFim();
                break;

           /// case '3':
            ///    InserirNoMeio();
            ///    break;

            case '4':
                RemoverDoInicio();
                break;

            case '5':
                RemoverDoFim();
                break;

            case '6':
                RemoverDaPosicao();
                break;

            case '7':
                RemoverConteudo();
                break;
        }
    } while (opcao != '8');
