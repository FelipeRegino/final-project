#include <stdio.h>
#include <stdlib.h>
#include "leitos.h"

//implementação das funções

void internaPaciente() {

}

void liberaPaciente() {

}

void imprimeRelatorio() {

}

void exibirMenu() {
	int menu;
	
	printf("\t UNIDADE DE TRATAMENTO SEMI-INTENSIVO\n\n");
	printf("1. Internar paciente.\n");
	printf("2. Liberar paciente.\n");
	printf("3. Imprimir relatório.\n");
	printf("4. Sair.\n\n");
	printf("Selecione a opção desejada.\n");
}

//main program
int main() {

menu = exibirMenu();

	switch (menu) {
		case 1:
			internaPaciente();
		break;
		case 2:
			liberaPaciente();
		break;
		case 3:
			imprimeRelatorio();
		break;
		case 4:
			printf("Você optou por sair do programa.\n");
		break;
		default:
			printf("A operação não pode ser realizada.\n");
		break;
	}

system("pause");
return 0;	
}
