// Equipe 3: Unidade de tratamento intensivo e Unidades de Exames de imagem

//************** Funções Gerais **********************//
//1) Criar cada uma das estruturas
//2) Fazer cada uma das estruturas vazia
//3) Teste se está vazia, para cada uma das estruturas
//4) Teste se está cheia, para cada uma das estruturas
//5) Inserir item em cada uma das estruturas
//6) Retirar item em cada uma das estruturas
//7) Listar todos os elementos de cada uma das estruturas
//8) Obter o conteúdo de um de terminado item de cada uma das estruturas

//************** Funções Específicas ******************//
// 18) Internar um paciente em uma unidade de tratamento intensivo
// 19) Lançar diária de paciente em uma unidade de tratamento intensivo
// 20) Dar alta de um paciente em uma unidade de tratamento intensivo
// 23) Agendar um exame para um paciente em uma unidade de exame de imagem
// 24) Registrar o resultado de um exame de imagem de um paciente

#include <stdio.h>
#include <stdlib.h>

int op=-1; //Variável de controle do menu de opções

typedef struct Paciente{
    char codigo[10];
    char nome[40];
    int *medico;  //ponteiro para código do médico
    char enfermidade[50];
    char tipoAtendimento[1]; //1-Pronto A., 2-Ambulatorial, 3-Internamento;
    char tipoAcomodacao[1]; //1-Leito Pronto, 2-Enfermaria, 3-Apartamento, 4-Semi-intensiva, 5-intensiva //ver como será a alta
    int *conta;
    char plano[8];
    int *prontuario;
};

struct Paciente *primeiro;
struct Paciente *proximo;
struct Paciente *ultimo;


typedef struct DiariaPaciente{
    char codigo[10];
    char nome[40];
    float valor;
    int *codigoPaciente;
};

typedef struct Uti{
    char codigo [1];
    char situacao [1]; //1 = livre, 2 = ocupado;
    int *p_paciente;
    int *p_leito;
}uti;

typedef struct UnidadeExamedeImagem{
    char codigo[2];
    char situacao_mes1[1]; //1=livre, 2=ocupado;
    char situacao_mes2[1]; //1=livre, 2=ocupado;
    char situacao_mes3[1]; //1=livre, 2=ocupado;
    int *agenda1;           //agenda do mês 1
    int *agenda2;           //agenda do mês 2
    int *agenda3;           //agenda do mês 3
}ueimagem;

typedef struct ExamedeImagem{
    char codigoexame[4];
    int *medico;        //código do médico
    int *paciente;      //código do paciente
    char resultado[500];
}eimagem;

typedef struct medico{
    char codigo[8];
    char nome[40];
    char especialidade[20];
    float r_consulta;
    float r_cirurgia;
    int *paciente;  //código do paciente

}medico;

void FlistaPacientesVazia(){
    struct Paciente *aux;
    aux = (struct Paciente *)malloc(sizeof(struct Paciente));
    primeiro = aux;
    ultimo = primeiro;

}

void InserePaciente(char cod, char n, char enf, char tAtendimento, char tAcomodacao, int c, char p){
    struct Paciente *aux;
    aux = (struct Paciente *)malloc(sizeof(struct Paciente));
    aux->codigo = cod;
    aux->nome = n;
    aux->enfermidade = enf;
    aux->tipoAtendimento = ttendimento;
    aux->tipoAcomodacao = tAcomodacao;
    aux->conta = c;
    aux->plano = p;
    ultimo->proximo = aux;
    ultimo = ultimo->prox;
    aux->proximo = NULL;
}

void menuloop(int op){ //função para menu de interação com o usuário
    while (op!=0 || op<=5){
        printf("-------------------- BEM VINDO AO MÓDULO 3 --------------------\n");
        printf("----------------------- AQUI VOCÊ PODE: -----------------------\n");
        printf("---------------------------------------------------------------\n");
        printf("----- (1) INTERNAR PACIENTE EM UTI;\n");
        printf("----- (2) LANÇAR DIÁRIA DE PACIENTE EM UTI;\n");
        printf("----- (3) DAR ALTA DE PACIENTE EM UTI;\n");
        printf("----- (4) AGENDAR EXAME EM UNIDADE DE EXAME DE IMAGEM;\n");
        printf("----- (5) REGISTRAR RESULTADO DO EXAME DE IMAGEM DE UM PACIENTE;\n");
        printf("----- (0) Digite 0 para sair da execução...\n");
        printf("---------------------------------------------------------------\n");
        printf("- Escolha a opção correspondente: ________ ");
        scanf("%d", &op);
        printf("---------------------------------------------------------------\n");
    }
}

void main(){
    menuloop(op);
}

