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

typedef struct Paciente{
    char codigo[10];
    char nome[40];
    int* medico;
    char enfermidade[50];
    char tipoAtendimento[1]; //1-Pronto A., 2-Ambulatorial, 3-Internamento;
    char tipoAcomodacao[1]; //1-Leito Pronto, 2-Enfermaria, 3-Apartamento, 4-Semi-intensiva, 5-intensiva //ver como será a alta
    int* conta;
    char plano[8];
    int* prontuario;
};

typedef struct DiariaPaciente{
    char codigo[10];
    char nome[40];
    float valor;
    int* codigoPaciente;
};

typedef struct Uti{
    char codigo [1];
    char situacao [1]; //1 = livre, 2 = ocupado;
    int* p_paciente;
    int* p_leito;
};

typedef struct UnidadeExamedeImagem{
    char codigo[2];
    char situacao_mes1[1]; //1=livre, 2=ocupado;
    char situacao_mes2[1]; //1=livre, 2=ocupado;
    char situacao_mes3[1]; //1=livre, 2=ocupado;
    int* Agenda1;
    int* Agenda2;
    int* Agenda3;
};

typedef struct ExamedeImagem{
    char codigoexame[4];
    int* medico;
    int* paciente;
    char resultado[500];
};


