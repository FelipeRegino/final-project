#define MAX 50

struct consultorio {
	char code[2]; // código
	char situacaoAgenda1;
	char situacaoAgenda2;
	char situacaoAgenda3;
	*agenda1;
	*agenda2;
	*agenda3;
};

struct agendaConsultorio {
	char dia[2];
	char hora[4];
	char status; // Definido como "situação da hora", entendido como status da agenda pelo dia/hora.
	*medico
	*paciente
	
	
};


struct medico {
	char codigo[8]; // Campo destinado para armanezar o código CREMEB do médico.
	char nome[40]; // Campo para colocar o nome do médico.
	char especialidade [20];
	float remuneracao-consulta;
	float remuneracao-cirurgia;
	*paciente
};

typedef struct lista Lista;

//protótipo das funções
Lista* criaLista();
void destroiLista(Lista* li);
int listaCheia(Lista* li);
int listaVazia(Lista* li);
int adicionaConsultorio(Lista* li, struct consultorio a);
int liberaConsultorio(Lista* li);
void imprimeConsultorios(Lista* li);
void imprimeDiaria(Lista* li);
void agendarConsulta(Lista* li);
