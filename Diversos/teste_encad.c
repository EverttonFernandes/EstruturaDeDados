/*
void InserirNoMeio(){
    int valorAInserir;
    printf("Informe o valor do n� a ser inserido: \n");
    scanf("%i",&valorAInserir);
    /// no *novo = (no*) malloc(sizeof(no)); /// a mesma coisa que usar o new
    no *novo = new no;
    int posicaoAtual = 1;
    no *noAtual = primeiroNo;
    while (noAtual != NULL && posicaoAtual <= valorAInserir) {
    if (posicaoAtual == valorAInserir) { /// se chegou na posi��o a ser exclu�da
        if (noAtual->anterior == NULL) { /// se n�o h� anterior, � a primeira posi��o
            InserirNoInicio();
        }
        else {
            if (noAtual->proximo == NULL) { /// se n�o h� pr�ximo, � a �ltima posicao
                InserirNoFim();
            }
            else {
                noAtual->anterior->proximo = noAtual->proximo;
                noAtual->proximo->anterior = noAtual->anterior;
                printf("\n\nO elemento de valor %i foi adicionado na posi��o %i.", noAtual->conteudo, posicaoAtual);
                getch();
                }
            }
        }
        posicaoAtual++;
        noAtual = noAtual->proximo;
    }
}*/

printf("(1) Inserir elemento no in�cio da lista\n");
        printf("(2) Inserir elemento no fim da lista\n");
        printf("(3) Inserir elemento no meio da lista\n");
        printf("(4) Remover elemento do in�cio da lista\n");
        printf("(5) Remover elemento do final da lista\n");
        printf("(6) Remover elemento de determinada posi��o\n");
        printf("(7) Remover elemento pelo conte�do\n");
        printf("(8) Sair do Programa\n");
        printf("\nDigite a op��o desejada: ");
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
