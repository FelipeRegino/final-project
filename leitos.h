#define MAX 100

struct leitos {
	char paciente[30];
	char medico[30];
	char code[2];
	char status;
};

typedef struct lista Lista;

//protótipo das funções
Lista* criaLista();
void destroiLista(Lista* li);
void internaPaciente();
void liberaPaciente();
void imprimeRelatorio();
