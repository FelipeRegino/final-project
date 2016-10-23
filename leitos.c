#include <stdio.h>
#include <stdlib.h>
#include "leitos.h"

struct lista {
	int qtd;
	struct leitos dados[MAX];
}

//implementa��o das fun��es

Lista* criaLista() {
	Lista *li;
	li = (Lista*)malloc(sizeof(struct lista));
		if(li != NULL) {
			li->qtd = 0;
		}
	return li;
}

void destroiLista(Lista* li) {
	free(li);
}

void internaPaciente() {
	
}

void liberaPaciente() {

}

void imprimeRelatorio() {

}

int exibirMenu() {
	
	printf("\t UNIDADE DE TRATAMENTO SEMI-INTENSIVO\n\n");
	printf("1. Internar paciente.\n");
	printf("2. Liberar paciente.\n");
	printf("3. Imprimir relat�rio.\n");
	printf("4. Criar lista da Semi-UTI.\n");
	printf("5. Liberar lista.\n");
	printf("6. Sair\n\n");
	printf("Selecione a op��o desejada.\n");
}

//main program
int main() {

Lista *li;
int menu;
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
			li = criaLista();
		break;
		case 5:
			destroiLista(li);
		break;
		case 6:
			printf("Voc� optou por sair do programa.\n");
		break;
		default:
			printf("A opera��o n�o pode ser realizada.\n");
		break;
	}

system("pause");
return 0;	
}
