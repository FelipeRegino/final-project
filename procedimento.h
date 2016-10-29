/////////ESTRUTURA////////////
struct procedimento {
  char codigo_item[10];
  char nome[40];
  float valor;
};
typedef struct procedimento TipoProcedimento;
////////LISTA DAS ESTRUTURAS///////////
struct listaprocedimento {
   TipoProcedimento  procedimento;
   struct listaprocedimento *proximo;
};
typedef struct listaprocedimento ListaProcedimento;

//++++++++++++++FUNÇÕES++++++++++++++++++++//
/////////CRIAR ITEM /////////
TipoProcedimento *criaprocedimento (){

    TipoProcedimento *novo;
    novo = (TipoProcedimento *)malloc(sizeof(TipoProcedimento));
    return novo;

}


//////////////CRIAR LISTA//////////////
ListaProcedimento *crialistaprocedimento (){

    ListaProcedimento *novo;
    novo = (ListaProcedimento *)malloc(sizeof(ListaProcedimento));
    novo->proximo = NULL;
    return novo;

}




///////////VERIFICAR LISTA VAZIA/////////////////
int VerificaListaVaziaProcedimento (ListaProcedimento *listaprocedimento){

    if (listaprocedimento->proximo == NULL){
        return 1;
    }
    return 0;
}



//////////////CADASTRO DE PACIENTE////////////////
TipoConsulta *CadastrarProcedimento (ListaProcedimento *listaprocedimento){

//system("cls");

    printf(" ================ TELA DE CADASTRO DE PROCEDIMENTOS ================ \n \n");

    char temp;

    ListaProcedimento *aux;
    aux = crialistaprocedimento();

    printf("   Digite o codigo do procedimento ");
    scanf("%s",aux->procedimento.codigo_item);
    printf("   Digite o nome do procedimento  ");
    scanf("%s",aux->procedimento.nome);
    printf("\nDigite o valor:");
    scanf("%s",&aux->procedimento.valor);


    ListaProcedimento *oldhead = listaprocedimento->proximo;
    listaprocedimento->proximo = aux;
    aux->proximo = oldhead;
    printf("\n Procedimento cadastrado com sucesso! \n");

}


////////////////////IMPRIMIR LISTA////////////////////////
void ImprimeListaProcedimento(ListaProcedimento *listaprocedimento){


    if (VerificaListaVaziaProcedimento(listaprocedimento) == 1){

        printf("Sem procedimentos cadastrados \n");

    }
    else{

        ListaProcedimento *temp = listaprocedimento;//->proximo;

        while (temp != NULL){

            printf(" NOME : %s \n",&temp->procedimento.nome);
            printf(" CODIGO : %s \n",&temp->procedimento.codigo_item);
            printf("VALOR : %f \n",&temp->procedimento.valor);
            temp = temp->proximo;

        }

    }

}
