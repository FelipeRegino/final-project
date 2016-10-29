#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "laboratorio.h"
#include "farm.h"
//#include "paciente.h"

void menuPrincipal() {
	printf("\n******************\nHOSPITAL GERAL\n******************\n");
	int opcao = 1;
	while (opcao != 0) {
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
		printf("8- Relat�rio de Pacientes\n");
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
		scanf("%d", &opcao);
		switch (opcao) {
			//-------------------------------------
		case 0:
			printf("-------------------------------------------------------------------------\n\n= Voc� escolheu sair do sistema..!\n\n");
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
		case 37:
			/*Registrar a entrada de material para exames de laborat�rio de um paciente*/
			break;
			//-------------------------------------
		case 38:
			/*Registrar o resultado dos exames de laborat�rio de um paciente*/
			break;
			//-------------------------------------
		case 39:
			/*Registrar entrada de medicamento na Farm�cia Central*/
			break;
			//-------------------------------------
		case 40:
			/*Registrar transfer�ncia de medicamento da farm�cia central para farm�cia Sat�lite*/
			break;
			//-------------------------------------
		case 41:
			/*Confirmar recep��o de medicamento na Farm�cia Sat�lite*/
			break;
			//-------------------------------------
		case 42:
			/*Lan�ar medicamento para uma paciente*/
			break;
			//-------------------------------------
		case 99:
			break;
			//-------------------------------------
		default:
			printf("-------------------------------------------------------------------------\n\n= Op��o inv�lida..!\n\n");
			opcao = 0;
			break;
			//-------------------------------------
		}
	}
};

// -----------------------------------------------
int main() {
	/*
	menu();

	getchar();
	return EXIT_SUCCESS;
	*/

	Lpaciente* listaPacientes = NULL;
	FilaExames* fila = NULL;
	int opt = 1;

	while (opt != 0) {
		system("cls");
		printf("Escolha a opcao\n");
		printf("0. Sair\n");
		printf("1. Importar pacientes\n");
		printf("2. Inserir exame\n");
		printf("3. Imprimir exames\n");
		printf("\nOpcao: ");

		scanf("%d", &opt);

		if (opt != 0) {
			switch (opt)
			{
			case 1: {
				char nome[20];
				char codigo[10];
				if (listaPacientes == NULL) listaPacientes = crialistapaciente();

				char url[] = "pacientes.txt";
				FILE *arq;
				arq = fopen(url, "r+");

				if (arq == NULL) {
					printf("N�o foi possivel abrir o arquivo!\n");
				}
				else {
					while ((fscanf(arq, "%s %s\n", nome, codigo)) != EOF) {
						Tipopaciente* paciente = criapaciente();
						int i;

						strcpy(paciente->nome, nome);
						strcpy(paciente->codigo, codigo);
					}

					fclose(arq);
					listaPacientes->paciente = paciente;
					system("cls");
					printf("Pacientes importados com sucesso!\n");
					getch();
				}

				break;
			}
			case 2: {
				char codigo[4];
				char resultado[500];
				if (listaPacientes == NULL) listaPacientes = crialistapaciente();
				if (fila == NULL) fila = inicializa_filaExames();

				system("cls");
				printf("Codigo do exame (4 digitos): ");
				scanf("%s", codigo);
				printf("\n");

				Tipopaciente* paciente = criapaciente;
				paciente = CadastrarCliente(listaPacientes);

				printf("Resultado do exame: ");
				scanf("%s", resultado);
				printf("\n");

				Exame* exame = inicializa_Exame(codigo, paciente, resultado);

				insere_exame(exame, fila);

				break;
			}
			case 3:
				system("cls");
				imprime_filaExames(fila);
				getch();
				system("cls");
				break;
			default:
				system("cls");
			}
			case 4: {
				Farmacia*  F1 = NULL;
				if (F1 == NULL) F1 = cria_farmacia_central("F", "Terreo");
			}
				break;
			}
		}
	}

	/*
	char codigoFarmacia;
	char localFarmacia;
	Farmacia* farmaciaCentral;
	Farmacia* farmaciaSatelite;

	printf("Codigo da farmacia central: ");
	scanf("%c", &codigoFarmacia);

	printf("Local da farmacia central: ");
	scanf(" %c", &localFarmacia);
	printf("\n");

	farmaciaCentral = cria_farm_central(codigoFarmacia, localFarmacia);

	printf("Codigo da farmacia satelite: ");
	scanf(" %c", &codigoFarmacia);

	printf("Local da farmacia satelite: ");
	scanf(" %c", &localFarmacia);
	printf("\n");

	farmaciaSatelite = cria_farm_satelite(codigoFarmacia, localFarmacia);

	insere_farm_satelite(farmaciaCentral, farmaciaSatelite);
	*/

	return 0;
}
// -----------------------------------------------
