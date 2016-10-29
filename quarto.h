//-----------------------------------------------------------------------

// PRE-CADASTRO - teste de outras estruturas

//typedef struct tipo_paciente {char codigo[3];char nome[40];} Tipopaciente;
typedef struct tipo_medico {char codigo[3];char nome[40];} Medico;

//--------

// CADASTRO QUARTO, LEITO E POSTO ENFERMAGEM

typedef struct tipo_leitoQ {char codigo[3];} LeitoQ;
typedef struct tipo_PostoEnfermagem {char codigo[3];} PostoEnfermagem;


#define maxQuartos 300
#define maxQuartosAndar 50
#include "paciente.c"
typedef struct {
	char codigo[4]; // erro professor tinha dito tam3, mas o tamanho maximo é '300\0'
	char situacao[1]; // 1- livre, 2-ocupado
	struct Paciente *paciente;
	Medico *medico;
	LeitoQ *leitoQ;
	char andar[1];
	PostoEnfermagem *postoEnfermagem;
} Quarto;

typedef struct lista_quartos{
	int tam;
	int primeiro;
	int fim;
	Quarto quartos[maxQuartos];
} lista_quartos;

// tipo no
typedef struct no{
	Quarto* conteudo; /* conteúdo: ponteiro pro quarto */
	struct no* esq;
	struct no* dir;
} tNo;

//-----------------------------------------------------------------------

/*
** Cabeçalhos das funções implementadas no módulo quarto.c ,
** que servem para controlar as funcionalidades da estrutura quarto
*/

// ***********************************************
// Inicializar lista de quartos
// ***********************************************

lista_quartos* inicializarQuartos();

// ***********************************************
// Verificar lista de quartos vazia
// ***********************************************

bool verificarQuartosListaVazia(lista_quartos* lquartos);

// ***********************************************
// Verificar lista de quartos cheia
// ***********************************************

bool verificarQuartosListaCheia(lista_quartos* lquartos);

// ***********************************************
// Inserir quarto na lista
// ***********************************************

bool inserirQuarto(lista_quartos* quartos, int andar);

// ***********************************************
// Criar todos os quartos na lista
// ***********************************************

bool criarQuartos(lista_quartos* lquartos);

// ***********************************************
// Buscar quarto
// ***********************************************

Quarto* buscarQuarto(lista_quartos* lquartos, char* codigo);

// ***********************************************
// Remover quarto na lista (sem reordenacao)
// ***********************************************

bool removerQuarto(lista_quartos* lquartos, char* codigo);

// ***********************************************
// Imprimir quarto
// ***********************************************

void imprimirQuarto(Quarto* q);

// ***********************************************
// Buscar e listar quarto
// ***********************************************

bool listarQuarto(lista_quartos* lquartos, char* codigo);

// ***********************************************
// Listar todos os quartos
// ***********************************************

bool listarQuartos(lista_quartos* lquartos);

// ***********************************************
// 9- Internar em quarto
// ***********************************************

bool internarPacienteQuarto(lista_quartos* lquartos, Tipopaciente* paciente, Medico* medico);

// ***********************************************
// 11- Dar alta de paciente em quarto
// ***********************************************

bool darAltaPacienteQuarto(lista_quartos* lquartos, Tipopaciente* paciente);

// ***********************************************
// Inicializar arvore binária de quartos
// ***********************************************

tNo* inicializarArvoreBQuartos();

// ***********************************************
// Inserir em arvore binária de quartos
// ***********************************************

bool inserirArvoreBQuartos(tNo* arv, Quarto* q);

// ***********************************************
// Gerar arvore binária de quartos
// ***********************************************

bool gerarArvoreBQuartos(tNo* arv,lista_quartos* lquartos);

// ***********************************************
//  Imprimir arvore binária de quartos
// ***********************************************

bool imprimirArvoreBQuartos(tNo* arv);

// ***********************************************
// Carregar arquivo quarto.txt
// ***********************************************

bool carregarFileQuarto();

// ***********************************************
// Persistir arquivo quarto.txt
// ***********************************************

bool persistirFileQuarto();

// ***********************************************
// ***********************************************
