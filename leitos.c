#include <stdio.h>
#include <stdlib.h>
#include "leitos.h"

struct lista {
	int qtd;
	struct leitos dados[MAX];
}

//implementação das funções

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
	printf("3. Imprimir relatório.\n");
	printf("4. Criar lista da Semi-UTI.\n");
	printf("5. Liberar lista.\n");
	printf("6. Sair\n\n");
	printf("Selecione a opção desejada.\n");
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
			printf("Você optou por sair do programa.\n");
		break;
		default:
			printf("A operação não pode ser realizada.\n");
		break;
	}

system("pause");
return 0;	
}
