#include <stdio.h>
#include <stdlib.h>
#include "leitos.h"

//implementa��o das fun��es

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
	printf("3. Imprimir relat�rio.\n");
	printf("4. Sair.\n\n");
	printf("Selecione a op��o desejada.\n");
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
			printf("Voc� optou por sair do programa.\n");
		break;
		default:
			printf("A opera��o n�o pode ser realizada.\n");
		break;
	}

system("pause");
return 0;	
}
