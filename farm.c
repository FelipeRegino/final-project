#include <stdio.h>
#include <stdlib.h>
#include "farm.h"

Farmacia* cria_farm_central(char c, char l){
	Farmacia *f=(Farmacia *) malloc(sizeof(Farmacia));
	f->codigo = c;
	f->local = l;
	f->ListaMedicamentos = NULL;
	f->prim = NULL;
	f->prox = NULL;
	return f;
}

void insere_farm_satelite(Farmacia* fc, Farmacia* fs){
	fs->prox = fc->prim;
	fc->prim = fs;
}

void libera_farm(Farmacia* f){
	Farmacia* p = f->prim;
	while(p!=NULL){
		Farmacia* t = p->prox;
		libera_farm(p);
		p=t;
	}
	free(f);
}

ListaMedicamentos* incializaListaM(Farmacia* f){
	ListaMedicamentos* lista = (ListaMedicamentos*)malloc(sizeof(ListaMedicamentos));
	f->ListaMedicamentos = lista;
	return lista;
}

void limpaListaMedicamentos(ListaMedicamentos* Lista){
	Lista->Primeiro = 0;
	Lista->Ultimo = Lista->Primeiro;
}

int listaMedicamentosVazia(ListaMedicamentos* Lista){
	return(Lista->Primeiro == Lista->Ultimo);
}

Medicamento* inicializaMedicamento(){
	Medicamento* med = (Medicamento*)malloc(sizeof(Medicamento));
	return med;
}

void ModificaMedicamento(Medicamento* med, char c, int q, float i, char n, char t, char l, char v){
	med->codigo = c;
	med->qtd = q;
	med->id = i;
	med->nome = n;
	med->tipo = t;
	med->lote = l;
	med->validade = v;
}

void ImprimeMedicamento(Medicamento* m){
	printf("Nome: %d\n", m->nome);
	printf("Codigo: %d\n", m->codigo);
	printf("Quantidade: %i\n", m->qtd);
	printf("Identificacao: %f\n", m->id);
	printf("Tipo: %d\n", m->tipo);
	printf("Lote: %d\n", m->lote);
	printf("Validade: %d\n", m->validade);
}

void ImprimeTodosMedicamentos(ListaMedicamentos* Lista){
	int aux;
	for(aux = Lista->Primeiro; aux<Lista->Ultimo; aux++){
		printf("Nome: %d\n", Lista->medicamento[aux].nome);
		printf("Codigo: %d\n", Lista->medicamento[aux].codigo);
		printf("Quantidade: %i\n", Lista->medicamento[aux].qtd);
		printf("Identificacao: %f\n", Lista->medicamento[aux].id);
		printf("Tipo: %d\n", Lista->medicamento[aux].tipo);
		printf("Lote: %d\n", Lista->medicamento[aux].lote);
		printf("Validade: %d\n", Lista->medicamento[aux].validade);
		printf("--------------------------------------");
	}
}

void insere_medicamento(Medicamento* m, ListaMedicamentos* Lista, char c, int q, float i, char n, char t, char l, char v){
	if(Lista->Ultimo>=MAX){
		printf("Lista cheia\n");
	}
	else{
		m->codigo = c;
		m->qtd = q;
		m->id = i;
		m->nome = n;
		m->tipo = t;
		m->lote = l;
		m->validade = v;
		Lista->medicamento[Lista->Ultimo] = *m;
		Lista->Ultimo++;
	}
}

Medicamento* retiraMedicamento(Posicao p, ListaMedicamentos* Lista){
	int aux; Medicamento* medicamento;
	medicamento = (Medicamento*)malloc(sizeof(Medicamento));

	if(Vazia(Lista) || p>=Lista->Ultimo){
		printf("Posição não exite\n");
		return NULL;
	}

	*medicamento = Lista->medicamento[p];
	Lista->Ultimo--;
	for(aux = p; aux<Lista->Ultimo; aux++){
		Lista->medicamento[aux] = Lista->medicamento[aux+1];
	}
	return medicamento;
}

void trasfereMedicamento(Farmacia* fc, Farmacia* fs, Posicao p){
	Medicamento* m = retiraMedicamento(p,fc->ListaMedicamentos);
	ListaMedicamentos* l = fs->ListaMedicamentos;
	l->medicamento[l->Ultimo] = *m;
	l->Ultimo++;
}

Registros* inicializaRegistros(){
	Registros* lista = (Registros*)malloc(sizeof(Registros));
	return lista;
}

void LimpaRegistros(Registros* registros){
	registros->Primeiro = 0;
	registros->Ultimo = registros->Primeiro;
}

void registraEntrada(Entrada* entrada, Registros* registros, char f, char m, char d){
	if(registros->Ultimo>=MAX){
		printf("Lista cheia\n");
	}
	else{
		entrada->farmacia = f;
		entrada->medicamento = m;
		entrada->data = d;
		registros->entrada[registros->Ultimo] = *entrada;
		registros->Ultimo++;
	}
}

void registraTransferencia(Transferencia* transferencia, Registros* registros, char m, char f){
	if(registros->Ultimo>=MAX){
		printf("Lista cheia\n");
	}
	else{
		transferencia->farmaciareceptora = f;
		transferencia->medicamento = m;
		transferencia->status = "Pendente";
		registros->transferencia[registros->Ultimo] = *transferencia;
		registros->Ultimo++;
	}
}

void registraRecebimento(Transferencia* transferencia){
	transferencia->status = "recebido";
}

void ImprimeTodosRegistros(Registros* registros){
	int aux;
	printf("Entradas de medicamentos: ");
	for(aux = registros->entrada; aux<registros->Ultimo; aux++){
		printf("Medicamento: %d\n", registros->entrada[aux].medicamento);
		printf("Data: %d\n", registros->entrada[aux].data);
	}
	
	printf("Transferencias: ");
	for(aux = registros->transferencia; aux<registros->Ultimo; aux++){
		printf("Medicamento: %d\n", registros->transferencia[aux].medicamento);
		printf("Enviado para: %d\n", registros->transferencia[aux].farmaciareceptora);
		printf("Status: %d\n", registros->transferencia[aux].status);
	}
}

int main(){
	return 0;
}
