
/////////ESTRUTURA////////////
struct consulta {
  char codigo_item[10];
  char nome[40];
  float valor;
};
typedef struct consulta TipoConsulta;

////////LISTA DAS ESTRUTURAS///////////
struct listaconsulta {
   TipoConsulta  consulta;
   struct listaconsulta *proximo;
};
typedef struct listaconsulta ListaConsulta;
//++++++++++++++FUNÇÕES++++++++++++++++++++//
/////////CRIAR ITEM /////////
TipoConsulta *criaconsulta (){

    TipoConsulta *novo;
    novo = (TipoConsulta *)malloc(sizeof(TipoConsulta));
    return novo;

}


//////////////CRIAR LISTA//////////////
ListaConsulta *crialistaconsulta (){

    ListaConsulta *novo;
    novo = (ListaConsulta *)malloc(sizeof(ListaConsulta));
    novo->proximo = NULL;
    return novo;

}




///////////VERIFICAR LISTA VAZIA/////////////////
int VerificaListaVaziaConsulta (ListaConsulta *listaconsulta){

    if (listaconsulta->proximo == NULL){
        return 1;
    }
    return 0;
}



//////////////CADASTRO DE PACIENTE////////////////
TipoConsulta *CadastrarConsulta (ListaConsulta *listaconsulta){

//system("cls");

    printf(" ================ TELA DE CADASTRO DE CONSULTAS ================ \n \n");

    char temp;

    ListaConsulta *aux;
    aux = crialistaconsulta();

    printf("Digite o codigo da consulta: ");
    scanf("%s",aux->consulta.codigo_item);
    printf("Digite o nome do paciente:  ");
    scanf("%s",aux->consulta.nome);
    printf("\nDigite o valor:");
    scanf("%s",&aux->consulta.valor);

    ListaConsulta *oldhead = listaconsulta->proximo;
    listaconsulta->proximo = aux;
    aux->proximo = oldhead;
    printf("\n Consulta cadastrada com sucesso! \n");

}


////////////////////IMPRIMIR LISTA////////////////////////
void ImprimeListaConsulta(ListaConsulta *listaconsulta){


    if (VerificaListaVaziaConsulta(listaconsulta) == 1){

        printf("Sem consultas cadastradas \n");

    }
    else{

        ListaConsulta *temp = listaconsulta;//->proximo;

        while (temp != NULL){

            printf(" NOME : %s \n",&temp->consulta.nome);
            printf(" CODIGO : %s \n",&temp->consulta.codigo_item);
            printf("VALOR : %f \n",&temp->consulta.valor);
            temp = temp->proximo;

        }

    }

}
