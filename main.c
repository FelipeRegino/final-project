#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// -----------------------------------------------
void inicializa(){}

// -----------------------------------------------
void menu(){
	printf("\n******************\nHOSPITAL GERAL\n******************\n");
	int opcao=1;
	while(opcao!=0){
		printf("\n--------------------------------- MENU ---------------------------------\n");

		//-------------------------------------
		printf("\n-> Médico, Paciente, Conta do Paciente, Prontuário, Doença:\n\n");

		printf("1- Cadastrar Médico\n");
		printf("2- Remover Médico\n");
		printf("3- Pesquisar Médico\n");
		printf("4- Relatório de Médicos\n");
		printf("\n");

		printf("5- Cadastrar Paciente\n");
		printf("6- Remover Paciente\n");
		printf("7- Pesquisar Paciente\n");
		printf("8- Relatório de Pacientes\n");
		printf("\n");

		printf("9- Cadastrar Conta de Paciente\n");
		printf("10- Remover Conta de Paciente\n");
		printf("11- Pesquisar Conta de Paciente\n");
		printf("12- Relatório de Contas de Pacientes\n");
		printf("\n");

		printf("13- Cadastrar Prontuário\n");
		printf("14- Remover Prontuário\n");
		printf("15- Pesquisar Prontuário\n");
		printf("16- Relatório Prontuários\n");
		printf("\n");

		printf("17- Cadastrar Doença\n");
		printf("18- Remover Doença\n");
		printf("19- Pesquisar Doença\n");
		printf("20- Relatório de Doenças\n");

		//-------------------------------------
		printf("\n-> Quarto e Enfermaria:\n\n");

		printf("21- Internar paciente em um quarto\n");
		printf("22- Lançar diária de paciente de um quarto\n");
		printf("23- Dar alta a paciente de um quarto\n");
		printf("\n");
		printf("24- Internar paciente em uma enfermaria\n");
		printf("25- Lançar diária a paciente de uma enfermaria\n");
		printf("26- Dar alta a paciente de uma enfermaria\n");

		//-------------------------------------
		printf("\n-> Unidade de Tratamento Semi-intensivo e Consultório:\n\n");
		printf("99- abcdefg\n");
		printf("99- abcdefg\n");

		//-------------------------------------
		printf("\n-> Unidade de Tratamento Intensivo e Unidade de Exames de Imagem:\n\n");
		printf("99- abcdefg\n");
		printf("99- abcdefg\n");

		//-------------------------------------
		printf("\n-> Laboratório, Farmácia Central e Farmácia Satélite:\n\n");
		printf("99- abcdefg\n");
		printf("99- abcdefg\n");

		//-------------------------------------
		printf("\n-> Unidade de Pronto Atendimento e Faturamento:\n\n");
		printf("99- abcdefg\n");
		printf("99- abcdefg\n");

		//-------------------------------------

		printf("\n\n-> Informe a opção desejada (tecle 0 para sair): ");
		scanf("%d",&opcao);
		switch(opcao){
		//-------------------------------------
			case 0:
				printf("-------------------------------------------------------------------------\n\n= Você escolheu sair do sistema..!\n\n");
				break;
		//-------------------------------------
			case 21:
				break;
		//-------------------------------------
			case 22:
				break;
		//-------------------------------------
			case 23:
				break;
		//-------------------------------------
			case 24:
				break;
		//-------------------------------------
			case 25:
				break;
		//-------------------------------------
			case 26:
				break;
		//-------------------------------------
			case 99:
				break;
		//-------------------------------------
			default:
				printf("-------------------------------------------------------------------------\n\n= Opção inválida..!\n\n");
				opcao=0;
				break;
		//-------------------------------------
		}
	}
}

// -----------------------------------------------
int main(){
	
	inicializa();
	menu();

	getchar();
	return EXIT_SUCCESS;
}
// -----------------------------------------------

