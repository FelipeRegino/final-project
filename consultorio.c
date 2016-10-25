#include <stdio.h>
#include <stdlib.h>
#include "consultorio.h"

struct lista {
	int qtd;
	struct consultorio dados[MAX];
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

int listaCheia(Lista* li) {
	if(li == NULL) {
		return -1;	
	}
	return (li->qtd == MAX);
}

int listaVazia(Lista* li) {
	if(li == NULL) {
		return -1;	
	}
	return (li->qtd == 0);
}

int adicionaConsultorio(Lista* li, struct consultorio a) {
	if(li == NULL) {
		return 0;
	}
	else if(listaCheia(li)) {
		return 0;
	}
	else {
		li->dados[li->qtd] = a;
		li->qtd++;
		return 1;
	}
}

int liberaConsultorio(Lista* li) {
	if(li == NULL) {
		return 0;
	}
	else if(li->qtd == 0) {
		return 0;
	}
	else {
		li->qtd--;
		return 1;
	}

}

void imprimeConsultorios(Lista* li) { // Serve para que a lista de consult�rios seja exibida, mostrando todos os campos (m�dicos, consultorios)
	int i;
	if(li == NULL) {
		printf("Lista vazia.\n");
	}
	else {
		for(i=0; i<=MAX; i++) {
			printf("%c %c %d\n", struct lista.consultorio dados);
		}
	}
}


void imprimeDiaria(Lista* li){
	if(li == NULL){
		printf ("Lista vazia.\n");
	}
	else {
		printf ("%c\n", struct consultorio.status); // Para saber se os consultorios est�o dispon�veis (livres) ou n�o.
	}

int exibirMenu() {
	
	printf("\t CONSULT�RIOS\n\n");
	printf("1. Reservar Consult�rio.\n");
	printf("2. Liberar Consult�rio.\n");
	printf("3. Imprimir Lista de Consult�rios.\n");
	printf("4. Criar Lista de Consult�rio.\n");
	printf("5. Liberar Lista de Consult�rio.\n");
	printf("6. Verificar se o Consult�rio est� dispon�vel.\n");
	printf("7. Verificar se o Consult�rio est� vazio.\n");
	printf("8. Sair.\n\n");
	printf("Selecione a op��o desejada.\n");
}

//programa principal
int main() {

Lista *li;
int menu;
menu = exibirMenu();

	switch (menu) {
		case 1:
		{
			int w = internaPaciente(li, dados_leitos);
		}	
		break;
		case 2:
		{
			int k = liberaPaciente(li);
		}	
		break;
		case 3:
			imprimeRelatorio(li);
		break;
		case 4:
			li = criaLista();
		break;
		case 5:
			destroiLista(li);
		break;
		case 6:
		{
			int x = listaCheia(li);
		}
		break;
		case 7:
		{	
			int y = listaVazia(Lista* li);
		}
		break;
		case 8:
			printf("Voc� optou por sair do programa.\n");
		break;
		default:
			printf("A opera��o n�o pode ser realizada.\n");
		break;
	}

system("pause");
return 0;	
}
