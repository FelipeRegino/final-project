#define MAX 50

struct leitos {
	char code[2];
	char medico[20];
	char status;
	*leitos;
};

typedef struct lista Lista;

//protótipo das funções
Lista* criaLista();
void destroiLista(Lista* li);
int listaCheia(Lista* li);
int listaVazia(Lista* li);
int internaPaciente(Lista* li, struct leitos a);
int liberaPaciente(Lista* li);
void imprimeRelatorio(Lista* li);
