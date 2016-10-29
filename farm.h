#define MAX 1000

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

struct farmacia {
	char codigo;
	char local;
	struct farmacia *prim;
	struct farmacia *prox;
	ListaMedicamentos* ListaMedicamentos;
};
typedef struct farmacia Farmacia;

struct entrada{
	char medicamento;
	char farmacia;
	char data;
};
typedef struct entrada Entrada;
struct transferencia{
	char medicamento;
	char farmaciareceptora;
	char status;
};
typedef struct transferencia Transferencia;

struct registros{
	Entrada entrada[MAX];
	Transferencia transferencia[MAX];
	Posicao Primeiro, Ultimo;
};
typedef struct registros Registros;

struct buscaMedicamento{
	float id;
	Medicamento* medicamento;
	struct buscaMedicamento* esq;
	struct buscaMedicamento* dir;
};
typedef struct buscaMedicamento BuscaMedicamento;

Farmacia* cria_farm_central(char c, char l);

void insere_farm_satelite(Farmacia* fc, Farmacia* fs);

void libera_farm(Farmacia* f);

ListaMedicamentos* incializaListaM(Farmacia* f);

void limpaListaMedicamentos(ListaMedicamentos* Lista);

int listaMedicamentosVazia(ListaMedicamentos* Lista);

Medicamento* inicializaMedicamento();

void ModificaMedicamento(Medicamento* med, char c, int q, float i, char n, char t, char l, char v);

void ImprimeMedicamento(Medicamento* m);

void ImprimeTodosMedicamentos(ListaMedicamentos* Lista);

void insere_medicamento(Medicamento* m, ListaMedicamentos* Lista, char c, int q, float i, char n, char t, char l, char v);

Medicamento* retiraMedicamento(Posicao p, ListaMedicamentos* Lista);

void trasfereMedicamento(Farmacia* fc, Farmacia* fs, Posicao p);

void registraEntrada(Entrada* entrada, Registros* registros, char f, char m, char d);

void registraTransferencia(Transferencia* transferencia, Registros* registros, char m, char f);

void registraRecebimento(Transferencia* transferencia);

void registraRecebimento(Transferencia* transferencia);

void ImprimeTodosRegistros(Registros* registros);

BuscaMedicamento* criaAbm();

BuscaMedicamento* BuscaMed(BuscaMedicamento* b, float i);

BuscaMedicamento* insereCodBusca(BuscaMedicamento* b, Medicamento* med, float i);

BuscaMedicamento* retiraCodBusca(BuscaMedicamento* r, float v);
