/*Neste arquivo constam a estrutura do item Medicamento e a estrutura de filas
do mesmo. Também constam as funções de inicialização e manipulação*/

/////////ESTRUTURA////////////
struct medicamento {
  char codigo_item[10];
  char nome[40];
  float valor;
};
typedef struct medicamento TipoMedicamento;
////////LISTA DAS ESTRUTURAS///////////
struct listamedicamento {
   TipoMedicamento medicamento;
   struct listamedicamento *proximo;
};
typedef struct listamedicamento ListaMedicamento;

//++++++++++++++FUNÇÕES++++++++++++++++++++//
/////////CRIAR ITEM /////////
TipoMedicamento *criamedicamento (){

    TipoMedicamento *novo;
    novo = (TipoMedicamento *)malloc(sizeof(TipoMedicamento));
    return novo;

}


//////////////CRIAR LISTA//////////////
ListaMedicamento *crialistamedicamento (){

    ListaMedicamento *novo;
    novo = (ListaMedicamento *)malloc(sizeof(ListaMedicamento));
    novo->proximo = NULL;
    return novo;

}




///////////VERIFICAR LISTA VAZIA/////////////////
int VerificaListaVaziaMedicamento (ListaMedicamento *listamedicamento){

    if (listamedicamento->proximo == NULL){
        return 1;
    }
    return 0;
}



//////////////CADASTRO DE PACIENTE////////////////
TipoConsulta *CadastrarMedicamento (ListaMedicamento *listamedicamento){

//system("cls");

    printf(" ================ TELA DE CADASTRO DE MEDICAMENTOS ================ \n \n");

    char temp;

    ListaMedicamento *aux;
    aux = crialistamedicamento();

    printf("Digite o codigo do medicamento ");
    scanf("%s",aux->medicamento.codigo_item);
    printf("Digite o nome do medicamento  ");
    scanf("%s",aux->medicamento.nome);
    printf("\nDigite o valor:");
    scanf("%s",&aux->medicamento.valor);


    ListaMedicamento *oldhead = listamedicamento->proximo;
    listamedicamento->proximo = aux;
    aux->proximo = oldhead;
    printf("\n Medicamento cadastrado com sucesso! \n");

}


////////////////////IMPRIMIR LISTA////////////////////////
void ImprimeListaMedicamento(ListaMedicamento *listamedicamento){


    if (VerificaListaVaziaMedicamento(listamedicamento) == 1){

        printf("Sem medicamentos cadastrados \n");

    }
    else{

        ListaMedicamento *temp = listamedicamento;//->proximo;

        while (temp != NULL){

            printf("NOME : %s \n",&temp->medicamento.nome);
            printf("CODIGO : %s \n",&temp->medicamento.codigo_item);
            printf("VALOR : %f \n",&temp->medicamento.valor);
            temp = temp->proximo;

        }

    }

}
