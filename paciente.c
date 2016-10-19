#include<stdio.h>
#include<stdlib.h>
#include <string.h>

/* ESTRUTURA DE DADOS DO PACIENTE FALTA OS NOMES DOS PONTEIROS DAS LISTA DE : CONSULTA,PROCEDIMENTOS,MEDICAMENTOS E  */

typedef struct Paciente{

	char nome [30];
	char codigo[10] ;
	/* Lconsulta  "nome do ponteiro da lista de consulta" */
	/* Lprocedimento "nome do ponteiro da lista de procedimentos" */
	/* Lmedicamento "nome do ponteiro da lista de medicamentos" */
	/* Ldiaria "nome do ponteiro da lista de medicamentos" */

};
typedef struct Paciente Tipopaciente;


typedef struct listapaciente {

   Tipopaciente  paciente;
   Tipopaciente *proximo;

};
typedef struct listapaciente Lpaciente;


Tipopaciente *criapaciente (){

Tipopaciente *novo;
novo = (Tipopaciente *)malloc(sizeof(Tipopaciente));
return novo;

}

Lpaciente *crialistapaciente (){

Lpaciente *novo;
novo = (Lpaciente *)malloc(sizeof(Lpaciente));
novo->proximo = NULL;
return novo;

}

int VerificaListaVaziaPaciente (Lpaciente *listadepaciente){

if (listadepaciente->proximo == NULL){

 return 1;
}
 return 0;
}



Tipopaciente *CadastrarCliente (Lpaciente * listapaciente){


Lpaciente *aux;
aux = crialistapaciente();


printf("   digite o nome do paciente  ");
scanf("%s",aux->paciente.nome);
printf("   digite o nome codigo do paciente  ");
scanf("%s",aux->paciente.codigo);


Lpaciente *oldhead = listapaciente->proximo;
listapaciente->proximo = aux;
aux->proximo = oldhead;


}





void ImprimeListaPacientes(Lpaciente *listadepaciente){


if (VerificaListaVaziaPaciente(listadepaciente) == 1){

   printf("Sem Pacientes Cadastrados \n");

}
  else
{

  Lpaciente *temp = listadepaciente->proximo;

  while (temp != NULL){




  printf(" NOME : %s \n",&temp->paciente.nome);
  printf(" CODIGO : %s \n",&temp->paciente.codigo);





  temp = temp->proximo;




  }

}

}



/* Essa função retorna o ponteiro de um paciente na lista de pacientes onde podem ser coletadas qualquer informação do paciente
   para usar essa função crie um variável Lpaciente *NomeDaVariavelTipoPonteiro = SelecionaPaciente;

   Ex:

  ==================================================================================

   Tipopaciente *DadosDoPaciente = SelecionaPaciente (Tipopaciente * listadepacientes) ;

   Quarto->Paciente  = DadosDoPaciente;

   ==================================================================================

   Para imprimir os dados do Paciente na Tela:

   ImprimeDadosPaciente (DadosDoPaciente);

   ==================================================================================
*/

Tipopaciente *SelecionaPaciente (Lpaciente * listapaciente)
{

if ( VerificaListaVaziaPaciente(listapaciente) == 1 ) {

 printf("A lista se encontra vazia \n");

}

else {

char cod [10];
int ret ;
printf("Qual o codigo do paciente ? ");
scanf("%s",cod);
ret = strcmp(cod, listapaciente->paciente.codigo);


while ( ret != 0 ){


listapaciente= listapaciente->proximo;
ret = strcmp(cod, listapaciente->paciente.codigo);

 if ( ret!=0 && listapaciente->proximo == NULL ){

    printf("CÓDIGO NÃO ENCONTRADO");

 }


}


Tipopaciente *PacienteSelecionado;
PacienteSelecionado = criapaciente();
*PacienteSelecionado = listapaciente->paciente ;


return PacienteSelecionado;

}



}



 void PesquisaPaciente (Lpaciente * listapaciente) //Retorna o Ponteiro do TipoCliente em uma lista de LPaciente
{

Tipopaciente *pac;
pac = criapaciente();
pac = SelecionaPaciente(listapaciente);
printf(" NOME : %s \n",&pac->nome);
printf(" CODIGO : %s \n",&pac->codigo);


}





typedef struct Medico {

	char nome [30];
	char especialidade [20];
	int CREMEB [8] ;
	float remuneracao ;
	float remuneracaocirurgia;
	Lpaciente *pacientes;

}; typedef struct Medico Tipomedico;


typedef struct listamedico {

  Tipomedico  medico;
  Tipomedico *proximo;

}; typedef struct listamedico Lmedico;



int VerificaListaVaziaMedico (){}

void imprimetodosmedicos(){}

Tipopaciente *retornapaciente(){}
Tipopaciente *retornamedico(){}



int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("1. Cadastrar paciente \n");
	printf("2. Imprimir Todos Paciente\n");
    printf("3. Pesquisar Paciente\n");
    printf("4. Relatório de Pacientes \n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}



void opcao(Lpaciente *lista, int op)
{


	switch(op){
		case 1:
			CadastrarCliente(lista);
			break;
		case 2:
			ImprimeListaPacientes(lista);
			break;
        case 3:
			SelecionaPaciente(lista);
			break;
        case 4:
			PesquisaPaciente(lista);
			break;

		default:
			printf("Comando invalido\n\n");
	}
}





main (){


    int i = 0;

 Lpaciente *listadepacientes;
 listadepacientes = crialistapaciente();



	int opt;

	do{
		opt=menu();
		opcao( listadepacientes,opt);
	}while(opt);

	free( listadepacientes);
	return 0;



}
