#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "quarto.c"


// -----------------------------------------------
void inicializa(){




}

// -----------------------------------------------
void menu(){
	printf("\n******************\nHOSPITAL GERAL\n******************\n");
	int opcao=1;



		/* CRIA��O DA LISTA DE PACIENTES  */


		Lpaciente *LISTADEPACIENTES;
        LISTADEPACIENTES = crialistapaciente();






	while(opcao!=0){
		printf("\n--------------------------------- MENU ---------------------------------\n");

		//-------------------------------------
		printf("\n-> M�dico, Paciente, Conta do Paciente, Prontu�rio, Doen�a:\n\n");


		printf("5- Cadastrar Paciente\n");
		printf("6- Remover Paciente\n");
		printf("7- Pesquisar Paciente\n");
		printf("8- Relat�rio Pacientes\n");
		printf("\n");

		//-------------------------------------
		printf("\n-> Quarto e Enfermaria:\n\n");

		printf("21- Internar paciente em um quarto\n");
		printf("22- Lan�ar di�ria de paciente de um quarto\n");
		printf("23- Dar alta a paciente de um quarto\n");
		printf("\n");
		printf("24- Internar paciente em uma enfermaria\n");
		printf("25- Lan�ar di�ria a paciente de uma enfermaria\n");
		printf("26- Dar alta a paciente de uma enfermaria\n");

		//-------------------------------------

		printf("\n\n-> Informe a op��o desejada (tecle 0 para sair): ");
		scanf("%d",&opcao);
		switch(opcao){
		//-------------------------------------
			case 0:
				printf("-------------------------------------------------------------------------\n\n= Voc� escolheu sair do sistema..!\n\n");
				break;
        //-------------------------------------
			case 5:
			    CadastrarCliente(LISTADEPACIENTES);
				break;
		 //-------------------------------------
			case 6:
			    RemovePaciente (LISTADEPACIENTES);
				break;
		 //-------------------------------------
			case 7:
			    PesquisaPaciente(LISTADEPACIENTES);
				break;
				 //-------------------------------------
			case 8:
			    AlteraCadastroCliente(LISTADEPACIENTES);
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
				printf("-------------------------------------------------------------------------\n\n= Op��o inv�lida..!\n\n");
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
