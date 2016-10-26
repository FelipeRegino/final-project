#include <stdio.h>
#define MAX 1000

typedef int Posicao;

typedef struct farmacia {
	char codigo;
	char local;
	struct farmacia *prim; 
	struct farmacia *prox;
	char* ListaMedicamentos;
} Farmacia;

typedef struct medicamento {
	char codigo;
	int qtd;
	float id;
	char nome;
	char tipo;
	char lote;
	char validade;
} Medicamento;

 struct listaMedicamentos{
	Medicamento medicamento[MAX];
	Posicao Primeiro, Ultimo;
} ListaMedicamentos;

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
