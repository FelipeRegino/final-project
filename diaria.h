/*Neste arquivo constam a estrutura do item Diaria e a estrutura de filas
do mesmo. Também constam as funções de inicialização e manipulação*/

/////////ESTRUTURA////////////
struct valores {
  char codigo_item[10];
  char nome[40];
  float valor;
};
typedef struct valores TipoDiaria;
////////LISTA DAS ESTRUTURAS///////////
struct ldiaria {
   TipoDiaria  diaria;
   struct ldiaria *proximo;
};
typedef struct ldiaria ListaDiaria;
//++++++++++++++FUNÇÕES++++++++++++++++++++//
/////////CRIAR ITEM /////////
TipoDiaria *criadiaria (){

TipoDiaria *novo;
novo = (TipoDiaria *)malloc(sizeof(TipoDiaria));
return novo;

}

//////////////CRIAR LISTA//////////////
ListaDiaria *crialistadiaria (){

ListaDiaria *novo;
novo = (ListaDiaria *)malloc(sizeof(ListaDiaria));
novo->proximo = NULL;
return novo;

}


///////////VERIFICAR LISTA VAZIA/////////////////
int VerificaListaVaziaDiaria (ListaDiaria *listadiaria){

if (listadiaria->proximo == NULL){

 return 1;
}
 return 0;
}


//////////////CADASTRO DE DIARIA////////////////
TipoDiaria *CadastrarDiaria (ListaDiaria * listadiaria){


printf(" ================ TELA DE CADASTRO DE DIARIAS ================ \n \n");

char temp;

ListaDiaria *aux;
aux = crialistadiaria();

printf("\nDigite o codigo da diaria:");
scanf("%s",aux->diaria.codigo_item);
printf("\nDigite o nome:");
scanf("%s",aux->diaria.nome);
printf("\nDigite o valor:");
scanf("%s",&aux->diaria.valor);


ListaDiaria *oldhead = listadiaria->proximo;
listadiaria->proximo = aux;
aux->proximo = oldhead;
printf("\n Diaria lançada com sucesso \n");

}
////////////////////IMPRIMIR LISTA////////////////////////
void ImprimeListaDiaria(ListaDiaria *listadiaria){


if (VerificaListaVaziaDiaria(listadiaria) == 1){

   printf("Sem Diarias cadastradas \n");

}
  else
{

  ListaDiaria *temp = listadiaria;//->proximo;

  while (temp != NULL){

  printf("CODIGO : %s \n",&temp->diaria.codigo_item);
  printf("NOME : %s \n",&temp->diaria.nome);
  printf("VALOR : %f \n",&temp->diaria.valor);
  temp = temp->proximo;

  }

}

}
