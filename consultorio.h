#define MAX 50

struct consultorio {
	char code[2]; // c�digo
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
	char status; // Definido como "situa��o da hora", entendido como status da agenda pelo dia/hora.
	*medico
	*paciente
	
	
};


struct medico {
	char codigo[8]; // Campo destinado para armanezar o c�digo CREMEB do m�dico.
	char nome[40]; // Campo para colocar o nome do m�dico.
	char especialidade [20];
	float remuneracao-consulta;
	float remuneracao-cirurgia;
	*paciente
};

typedef struct lista Lista;

//prot�tipo das fun��es
Lista* criaLista();
void destroiLista(Lista* li);
int listaCheia(Lista* li);
int listaVazia(Lista* li);
int adicionaConsultorio(Lista* li, struct consultorio a);
int liberaConsultorio(Lista* li);
void imprimeConsultorios(Lista* li);
void imprimeDiaria(Lista* li);
void agendarConsulta(Lista* li);
