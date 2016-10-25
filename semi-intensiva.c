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

int internaPaciente(Lista* li, struct leitos *a) {
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

int liberaPaciente(Lista* li) {
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

void imprimeRelatorio(Lista* li) {
	int i;
	if(li == NULL) {
		printf("Lista vazia.\n");
	}
	else {
		for(i=0; i<=MAX; i++) {
			printf("%c %c %d\n", struct lista.leitos dados);
		}
	}
}

int buscarItem(Lista* li, int leitos, struct leitos *a) {
	if(li == NULL) {
		return 0;
	}
	int k,i = 0;
	while(i<li->qtd && li->dados[i].*leitos != leitos) {
		i++;
	}
	if(i == li->qtd) { //item não encontrado
		return 0;
	}

	*a = li->dados[i];
	return 1;
}

void imprimeDiaria(Lista* li){
	if(li == NULL){
		printf ("Lista vazia.\n");
	}
	else {
		printf ("%c\n", struct leitos.status); // Sendo que o usuário seja algum trabalhor do hospital e atualize a ficha do paciente.
	}
}

int exibirMenu() {
	
	printf("\t UNIDADE DE TRATAMENTO SEMI-INTENSIVO\n\n");
	printf("1. Criar lista da SEMI-UTI.\n");
	printf("2. Liberar lista.\n");
	printf("3. Internar paciente.\n");
	printf("4. Liberar paciente.\n");
	printf("5. Imprimir relatório.\n");
	printf("6. Verificar se a SEMI-UTI está cheia.\n");
	printf("7. Verificar se a SEMI-UTI está vazia.\n");
	printf("8. Fazer busca na lista.\n");
	printf("9. Imprimir diária do paciente.\n");
	printf("10. Sair.\n\n");
	printf("Selecione a opção desejada.\n");
}

//programa principal
int main() {

Lista *li;
int menu;
menu = exibirMenu();

	switch (menu) {
		case 1:
		{
			li = criaLista();
		}	
		break;
		case 2:
		{
			destroiLista(li);
		}	
		break;
		case 3:
			int w = internaPaciente(li, &dados_leitos);
		break;
		case 4:
			int k = liberaPaciente(li);
		break;
		case 5:
			imprimeRelatorio(li);
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
		{
			int a = buscarItem(li, posicao, &dados_leitos);
		}	
		break;
		case 9:
			imprimeDiaria(Lista* li);
		break;
		case 10:
			printf("Você optou por sair do programa.\n");
		break;
		default:
			printf("A operação não pode ser realizada.\n");
		break;
	}

system("pause");
return 0;	
}
