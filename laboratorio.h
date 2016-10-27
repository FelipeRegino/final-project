#pragma once
#include "paciente.h"

typedef int Posicao;

typedef struct Material {
	char codigo[10];
	char nome[40];
	float valor;
} Tipomaterial;

typedef struct exame {
	char codigo[4];
	/* Lmedico "nome do ponteiro da lista de medicamentos" */
	Tipopaciente* paciente;
	Tipomaterial* material;
	char resultado[500];
} Exame;

typedef struct celulaExame {
	Exame exame;
	struct CelulaExame* prox;
} CelulaExame;

typedef struct filaExames {
	CelulaExame* inicio;
	CelulaExame* fim;
} FilaExames;

typedef struct laboratorio {
	char codigo;
	Exame* exameTipo1;
	Exame* exameTipo2;
	Exame* exameTipo3;
	Exame* exameTipo4;
	Exame* exameTipo5;
	Exame* exameTipo6;
} Laboratorio;

typedef struct celulaLaboratorio {
	Laboratorio laboratorio;
	struct CelulaLaboratorio* prox;
} CelulaLaboratorio;

typedef struct listaLaboratorios {
	CelulaLaboratorio* primeiro;
	CelulaLaboratorio* ultimo;
} ListaLaboratorios;

#pragma region [ Funções gerais de exame ]

Exame* inicializa_Exame(char codigo[], Tipopaciente *paciente, char resultado[]);

FilaExames* inicializa_filaExames();

void encerra_filaExames(FilaExames* fila);

int filaExamesIsEmpty(FilaExames* fila);

int filaExamesIsFull(FilaExames* fila);

void insere_exame(Exame* exame, FilaExames *fila);

void retira_exame(Exame *exame, FilaExames *fila);

void imprime_filaExames(FilaExames* fila);

#pragma endregion

#pragma region [ Funções gerais de laboratório ]

Laboratorio* inicializa_laboratorio(char codigo, Exame *tipo1,
	Exame *tipo2, Exame *tipo3, Exame *tipo4, Exame *tipo5, Exame *tipo6);

ListaLaboratorios* inicializa_listaLaboratorios();

//Falta implementar função para zerar listaLaboratorios

int listaLaboratoriosIsEmpty(ListaLaboratorios* lista);

int listaLaboratoriosIsFull(ListaLaboratorios* lista);

void insere_laboratorio(Laboratorio* laboratorio, ListaLaboratorios* lista);

void retira_laboratorio(ListaLaboratorios *lista, char v);

void imprime_listaLaboratorios(ListaLaboratorios* lista);

#pragma endregion

void receberMaterialExame(Tipopaciente* paciente, Tipomaterial* material, Laboratorio* laboratorio, Exame* exame);

void registrarResultadoExame(Tipopaciente* paciente, char resultado[]);



