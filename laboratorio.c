#include <stdio.h>
#include <stdlib.h>
#include "laboratorio.h"

#pragma region [ Funções gerais de exame ]

Exame* inicializa_Exame(char codigo[], Tipopaciente *paciente, char resultado[]) {
	Exame* exame = (Exame*)malloc(sizeof(Exame));
	int i;

	for (i = 0; i <= 4; i++) {
		exame->codigo[i] = codigo[i];
	}
	
	exame->paciente = paciente;

	for (i = 0; i <= 500; i++) {
		exame->resultado[i] = resultado[i];
	}
	
	return exame;
}

FilaExames* inicializa_filaExames() {
	//Cria a fila de exames
	FilaExames* fila = (FilaExames*)malloc(sizeof(FilaExames));
	return fila;
}

void encerra_filaExames(FilaExames* fila) {
	//Faz fila ficar vazia
	fila->inicio = fila->fim = NULL;
}

int filaExamesIsEmpty(FilaExames* fila) {
	//Verifica se a fila está vazia
	return(fila->inicio == NULL);
}

int filaExamesIsFull(FilaExames* fila) {
	//Verifica se fila está cheia
	return(fila->fim != NULL);
}

void insere_exame(Exame* exame, FilaExames *fila) {
	CelulaExame* aux;
	aux = (CelulaExame*)malloc(sizeof(CelulaExame));
	aux->exame = *exame;
	aux->prox = NULL;

	if (fila->fim != NULL) {
		fila->fim->prox = aux;
	}
	else
	{
		fila->inicio = aux;
	}

	fila->fim = aux;
}

void retira_exame(Exame *exame, FilaExames *fila) {
	CelulaExame* c;

	if (filaExamesIsEmpty(fila)) {
		printf("Fila de exames esta vazia\n");
		return;
	}

	c = fila->inicio;;
	fila->inicio = c->prox;

	if (fila->inicio == NULL) fila->fim = NULL;

	*exame = c->exame;
	free(c);
}

void imprime_filaExames(FilaExames* fila) {
	CelulaExame* aux = fila->inicio;
	printf("Lista de exames:\n");

	while (aux != NULL)
	{
		printf("Codigo do exame: %c\n", aux->exame.codigo);
		printf("Nome do paciente: %c\n", aux->exame.paciente->nome);
		printf("Resultado do exame: %c\n", aux->exame.resultado);

		aux = aux->prox;
	}
}

#pragma endregion

#pragma region [ Funções gerais de laboratório ]

Laboratorio* inicializa_laboratorio(char codigo, Exame *tipo1,
	Exame *tipo2, Exame *tipo3, Exame *tipo4, Exame *tipo5, Exame *tipo6) {

	Laboratorio* laboratorio = (Laboratorio*)malloc(sizeof(Laboratorio));

	laboratorio->codigo = codigo;
	laboratorio->exameTipo1 = tipo1;
	laboratorio->exameTipo2 = tipo2;
	laboratorio->exameTipo3 = tipo3;
	laboratorio->exameTipo4 = tipo4;
	laboratorio->exameTipo5 = tipo5;
	laboratorio->exameTipo6 = tipo6;

	return laboratorio;
}

ListaLaboratorios* inicializa_listaLaboratorios() {
	ListaLaboratorios* lista = (ListaLaboratorios*)malloc(sizeof(ListaLaboratorios));

	lista->ultimo = NULL;
	lista->primeiro = NULL;

	return lista;
}

//Falta implementar função para zerar listaLaboratorios

int listaLaboratoriosIsEmpty(ListaLaboratorios* lista) {
	return (lista->primeiro == NULL);
}

int listaLaboratoriosIsFull(ListaLaboratorios* lista) {
	return (lista->ultimo != NULL);
}

void insere_laboratorio(Laboratorio* laboratorio, ListaLaboratorios* lista) {
	CelulaLaboratorio* novo = (CelulaLaboratorio*)malloc(sizeof(CelulaLaboratorio));

	if (listaLaboratoriosIsEmpty(lista)) {
		lista->primeiro = lista->ultimo = novo;
	}
	else
	{
		lista->ultimo->prox = novo;
		lista->ultimo = lista->ultimo->prox;
	}

	lista->ultimo->laboratorio = *laboratorio;
	lista->ultimo->prox = NULL;
}

void retira_laboratorio(ListaLaboratorios *lista, char v) {
	CelulaLaboratorio* ant = NULL;
	CelulaLaboratorio* p = lista->primeiro;

	while (p != NULL && p->laboratorio.codigo != v) {
		ant = p;
		p = p->prox;
	}

	if (p == NULL) return;

	if (p == lista->primeiro && p == lista->ultimo) {
		lista->primeiro = lista->ultimo = NULL;
		free(p);
		return;
	}

	if (p == lista->ultimo) {
		lista->ultimo = ant;
		ant->prox = NULL;
		free(p);
		return;
	}

	if (p == lista->primeiro) {
		lista->primeiro = p->prox;
	}
	else
	{
		ant->prox = p->prox;
		free(p);
	}
}

void imprime_listaLaboratorios(ListaLaboratorios* lista) {
	CelulaLaboratorio* aux = lista->primeiro;

	while (aux != NULL)
	{
		printf("Codigo do laboratorio: %c\n", aux->laboratorio.codigo);
		printf("Codigo do exame 1: %c\n", aux->laboratorio.exameTipo1->codigo);
		printf("Codigo do exame 2: %c\n", aux->laboratorio.exameTipo2->codigo);		
		printf("Codigo do exame 3: %c\n", aux->laboratorio.exameTipo3->codigo);		
		printf("Codigo do exame 4: %c\n", aux->laboratorio.exameTipo4->codigo);
		printf("Codigo do exame 5: %c\n", aux->laboratorio.exameTipo5->codigo);
		printf("Codigo do exame 6: %c\n\n", aux->laboratorio.exameTipo6->codigo);
		
		aux = aux->prox;
	}
}

#pragma endregion

void receberMaterialExame(Tipopaciente* paciente, Tipomaterial* material, Laboratorio* laboratorio, Exame* exame) {
	//Registrar a entrada de material para exames de laboratório de um paciente
}

void registrarResultadoExame(Tipopaciente* paciente, char resultado[]) {
	//Registrar o resultado dos exames de laboratório de um paciente
}

