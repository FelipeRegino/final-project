#include <stdio.h>
#define MAX 1000

struct farmacia {
	char codigo;
	char local;
	struct farmacia *prim; 
	struct farmacia *prox;
	char* ListaMedicamentos;
};
typedef struct farmacia Farmacia;


struct medicamento {
	char codigo;
	int qtd;
	float id;
	char nome;
	char tipo;
	char lote;
	char validade;
};

typedef struct medicamento Medicamento;
typedef int Posicao;

struct listaMedicamentos{
	Medicamento medicamento[MAX];
	Posicao Primeiro, Ultimo;
};

typedef struct listaMedicamentos ListaMedicamentos;

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

ListaMedicamentos* incializaListaM(){
	ListaMedicamentos* lista = (ListaMedicamentos*)malloc(sizeof(ListaMedicamentos));
	return lista;
}

void limpa_lista(ListaMedicamentos* Lista){
	Lista->Primeiro = 0;
	Lista->Ultimo = Lista->Primeiro;	
}

int Vazia(ListaMedicamentos* Lista){
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

int main(){
	return 0;
}
