#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "paciente.c"


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

		printf("1- Cadastrar M�dico\n");
		printf("2- Remover M�dico\n");
		printf("3- Pesquisar M�dico\n");
		printf("4- Relat�rio de M�dicos\n");
		printf("\n");


		printf("5- Cadastrar Paciente\n");
		printf("6- Remover Paciente\n");
		printf("7- Pesquisar Paciente\n");
		printf("8- Relat�rio Pacientes\n");
		printf("\n");

		printf("9- Cadastrar Conta de Paciente\n");
		printf("10- Remover Conta de Paciente\n");
		printf("11- Pesquisar Conta de Paciente\n");
		printf("12- Relat�rio de Contas de Pacientes\n");
		printf("\n");

		printf("13- Cadastrar Prontu�rio\n");
		printf("14- Remover Prontu�rio\n");
		printf("15- Pesquisar Prontu�rio\n");
		printf("16- Relat�rio Prontu�rios\n");
		printf("\n");

		printf("17- Cadastrar Doen�a\n");
		printf("18- Remover Doen�a\n");
		printf("19- Pesquisar Doen�a\n");
		printf("20- Relat�rio de Doen�as\n");

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
		printf("\n-> Unidade de Tratamento Semi-intensivo e Consult�rio:\n\n");

		printf("27- Internar um paciente em uma unidade de tratamento semi intensivo\n");
		printf("28- Lan�ar di�ria de paciente em uma unidade de tratamento semi intensivo\n");
		printf("29- Dar alta de um paciente em uma unidade de tratamento semi intensivo\n");
		printf("30- Agendar uma consulta para um paciente em um consult�rio para um m�dico\n");
		printf("31- Registrar o resultado da consulta de uma paciente\n");

		//-------------------------------------
		printf("\n-> Unidade de Tratamento Intensivo e Unidade de Exames de Imagem:\n\n");

		printf("32- Internar um paciente em uma unidade de tratamento intensivo \n");
		printf("33- Lan�ar di�ria de paciente em uma unidade de tratamento intensivo \n");
		printf("34- Dar alta de um paciente em uma unidade de tratamento intensivo\n");
		printf("35- Agendar um exame para um paciente em uma unidade de exame de imagem\n");
		printf("36- Registrar o resultado de um exame de imagem de um paciente \n");



		//-------------------------------------
		printf("\n-> Laborat�rio, Farm�cia Central e Farm�cia Sat�lite:\n\n");

		printf("37- Registrar a entrada de material para exames de laborat�rio de um paciente\n");
		printf("38- Registrar o resultado dos exames de laborat�rio de um paciente\n");
		printf("39- Registrar entrada de medicamento na Farm�cia Central\n");
		printf("40- Registrar transfer�ncia de medicamento da farm�cia central para farm�cia Sat�lite\n");
		printf("41- Confirmar recep��o de medicamento na Farm�cia Sat�lite\n");
		printf("42- Lan�ar medicamento para uma paciente\n");

		//-------------------------------------
		printf("\n-> Unidade de Pronto Atendimento e Faturamento:\n\n");

		printf("43- Recepcionar paciente no Pronto Atendimento\n");
		printf("44- Agendar paciente do pronto atendimento para um consult�rio\n");
		printf("45- Encaminhar paciente do pronto atendimento para um consult�rio\n");
		printf("46- Registrar consulta de um paciente no consult�rio do Pronto Atendimento e seu resultado\n");
		printf("47- Internar um paciente em leito da unidade do Pronto Atendimento\n");
		printf("48- Lan�ar di�ria para um paciente em leito da unidade do Pronto Atendimento\n");
		printf("49- Dar alta a um paciente em leito da unidade do Pronto Atendimento\n");
		printf("50- Fechar a conta de um paciente\n");
		printf("51- Emitir despesas de uma paciente\n");
		printf("52- Emitir fatura de um paciente\n");
		printf("53- Enviar faturas de pacientes para um determinado conv�nio\n");
		printf("54- Emitir relat�rio de faturamento mensal\n");






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
