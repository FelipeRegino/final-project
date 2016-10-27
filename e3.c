// Equipe 3: Unidade de tratamento intensivo e Unidades de Exames de imagem

//************** Funções Gerais **********************//
//1) Criar cada uma das estruturas
//2) Fazer cada uma das estruturas vazia
//3) Teste se está vazia, para cada uma das estruturas
//4) Teste se está cheia, par   a cada uma das estruturas
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
#include <string.h>

int op=-1; //Variável de controle do menu de opções

typedef struct Paciente{
    char codigo[10];
    char nome[40];
    char *medico;  //ponteiro para código do médico
    char enfermidade[50];
    char tipoAtendimento[1]; //1-Pronto A., 2-Ambulatorial, 3-Internamento;
    char tipoAcomodacao[1]; //1-Leito Pronto, 2-Enfermaria, 3-Apartamento, 4-Semi-intensiva, 5-intensiva //ver como será a alta
    float *conta;
    char plano[8];
    int *prontuario;
};

typedef struct Paciente Tipopaciente;

typedef struct listapacientes {
   Tipopaciente  paciente;
   Tipopaciente *proximo;
   Tipopaciente *primeiro;
   Tipopaciente *ultimo;

};
typedef struct listapacientes Lpacientes;


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
};

typedef struct Uti tipoUTI;

typedef struct listaUtis {
   tipoUTI  uti;
   tipoUTI *proximo;
   tipoUTI *primeiro;
   tipoUTI *ultimo;

};
typedef struct listaUtis lUTI;

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
} exame;

typedef struct ExamedeImagem tipoExameImagem;

typedef struct listaExames {
   tipoExameImagem  exame;
   tipoExameImagem *proximo;
   tipoExameImagem *primeiro;
   tipoExameImagem *ultimo;

};
typedef struct listaExames lExameImagem;

typedef struct medico{
    char codigo[8];
    char nome[40];
    char especialidade[20];
    float r_consulta;
    float r_cirurgia;
    int *paciente;  //código do paciente

}medico;


Tipopaciente *criaPaciente (){ //cria um novo paciente
    Tipopaciente *novo;
    novo = (Tipopaciente *)malloc(sizeof(Tipopaciente));
    return novo;
}

tipoExameImagem *criaExameImagem (){ //cria um novo exame de imagem
    tipoExameImagem *novo;
    novo = (tipoExameImagem *)malloc(sizeof(tipoExameImagem));
    return novo;
}

tipoUTI *criaUTI (){ //cria uma nova uti
    tipoUTI *novo;
    novo = (tipoUTI *)malloc(sizeof(tipoUTI));
    return novo;
}

Lpacientes *criaListadePacientes (){              //cria lista de pacientes
    Lpacientes *novo;
    novo = (Lpacientes *)malloc(sizeof(Lpacientes));
    novo->proximo = NULL;
    return novo;
}

lExameImagem *criaListadeExamesImagem (){         //cria lista de exames de imagem
    lExameImagem *novo;
    novo = (lExameImagem *)malloc(sizeof(lExameImagem));
    novo->proximo = NULL;
    return novo;
}

lUTI *criaListadeUTI (){              //cria lista de UTI
    lUTI *novo;
    novo = (lUTI *)malloc(sizeof(lUTI));
    novo->proximo = NULL;
    return novo;
}

int semPacientes (Lpacientes *listapacientes){ //verifica se a lista de pacientes está vazia
    if (listapacientes->proximo == NULL){
        return 1;
    }
        return 0;
}

int semExamesdeImagem (lExameImagem *listaExames){ //verifica se a lista de exames de imagem está vazia
    if (listaExames->proximo == NULL){
        return 1;
    }
        return 0;
}

int semUTI (lUTI *listaUtis){ //verifica se a lista de UTIs está vazia
    if (listaUtis->proximo == NULL){
        return 1;
    }
        return 0;
}

void excluiPaciente (Lpacientes * listapacientes, int v){ //v é o código do paciente
     Lpacientes *ant = NULL;
     Lpacientes *p = listapacientes->primeiro;

     if (semPacientes(listapacientes) == 1 ) {
        printf(" -- Não há pacientes cadastrados. \n");
    } else
    if (semPacientes(listapacientes) == 0) {
     while(p != NULL && p->paciente.codigo!=v){
      ant = p;
      p = p->proximo;
        if (p == NULL)
        return;
        if (p == listapacientes->primeiro && p == listapacientes->ultimo){
        listapacientes->primeiro = listapacientes->ultimo = NULL;
        free (p);
        return;
        }
        }
    }
}

void excluiUTI (lUTI * listaUtis, int c){ //c é o código da UTI
     lUTI *ant = NULL;
     lUTI *p = listaUtis->primeiro;

     if (semUTI(listaUtis) == 1 ) {
        printf(" -- Não há UTI's cadastradas. \n");
    } else
    if (semUTI(listaUtis) == 0) {
     while(p != NULL && p->uti.codigo!=c){
      ant = p;
      p = p->proximo;
        if (p == NULL)
        return;
        if (p == listaUtis->primeiro && p == listaUtis->ultimo){
        listaUtis->primeiro = listaUtis->ultimo = NULL;
        free (p);
        return;
        }
        }
    }
}

void excluiExamedeImagem (lExameImagem * listaExames, int c){ //c é o código do exame de imagem
     lExameImagem *ant = NULL;
     lExameImagem *p = listaExames->primeiro;

     if (semExamesdeImagem(listaExames) == 1 ) {
        printf(" -- Não há exames de imagem disponíveis. \n");
    } else
    if (semExamesdeImagem(listaExames) == 0) {
     while(p != NULL && p->exame.codigoexame !=c){
      ant = p;
      p = p->proximo;
        if (p == NULL)
        return;
        if (p == listaExames->primeiro && p == listaExames->ultimo){
        listaExames->primeiro = listaExames->ultimo = NULL;
        free (p);
        return;
        }
        }
    }
}

void listaPacientesCadastrados(Lpacientes * listapacientes){

    Lpacientes *aux = listapacientes->primeiro;

        while (aux != NULL){
        printf("---------- INFORMAÇÕES DOS PACIENTES ----------");
        printf(" -- NOME: %s ",&aux->paciente.nome);
        printf(" -- CÓDIGO: %s ",&aux->paciente.codigo);
        printf(" -- ENFERMIDADE: %s ",&aux->paciente.enfermidade);
        printf(" -- TIPO DE ATENDIMENTO: %s ",&aux->paciente.tipoAtendimento);
        printf(" -- TIPO DE ACOMODAÇÃO: %s ",&aux->paciente.tipoAcomodacao);
        printf(" -- TIPO DE PLANO: %s ",&aux->paciente.plano);
        aux = aux->proximo;
        }
    }

void listaUTIcadastradas(lUTI * listaUtis){

    lUTI *aux = listaUtis->primeiro;

        while (aux != NULL){
        printf("---------- INFORMAÇÕES DAS UTIs ----------");
        printf(" -- CÓDIGO: %s ",&aux->uti.codigo);
        printf(" -- SITUAÇÃO: %s ",&aux->uti.situacao);
        aux = aux->proximo;
        }
    }

void listaExamesdeImagem(lExameImagem * listaExames){

    lExameImagem *aux = listaExames->primeiro;

        while (aux != NULL){
        printf("---------- INFORMAÇÕES DOS EXAMES DE IMAGEM ----------");
        printf(" -- CÓDIGO: %s ",&aux->exame.codigoexame);
        printf(" -- RESULTADO: %s ",&aux->exame.codigoexame);
        aux = aux->proximo;
        }
    }

Tipopaciente *inserePaciente(Lpacientes *listapacientes){

    int opp; //varivel de controle de operações com um paciente

    printf("----------------------------------------------------------------\n");
    printf("---------------- BEM VINDO AO CADASTRO DE PACIENTES ------------\n");
    printf("----------------- INFORME OS DADOS SOLICITADOS:  ---------------\n");
    Lpacientes *aux;
    aux = criaListadePacientes();
    printf(" ----- Nome do paciente: \n");
    scanf("%s",aux->paciente.nome);
    printf(" ----- Codigo do paciente: \n");
    scanf("%s",aux->paciente.codigo);
    printf(" ----- Enfermidade do paciente: \n");
    scanf("%s",aux->paciente.enfermidade);
    printf(" ----- Tipo de atendimento do paciente: \n");
    printf(" (1) Pronto Antendimento | (2) Ambulatorial | (3) Internamento \n");
    scanf("%s",aux->paciente.tipoAtendimento);
    printf(" ----- Tipo de acomodaçãp do paciente: \n");
    printf(" (1) Leito Pronto | (2) Enfermaria | (3) Apartamento | (4) Semi-intensiva | (5) intensiva \n");
    scanf("%s",aux->paciente.tipoAcomodacao);
    printf(" ----- Plano de saúde do paciente: \n");
    scanf("%s",aux->paciente.plano);

    Lpacientes *antigo = listapacientes->proximo;
    listapacientes->proximo = aux;
    aux->proximo = antigo;
    printf("----------------------------------------------------------------\n");
    printf("\n -- PACIENTE INSERIDO NO SISTEMA... -- \n");
    getchar();
    printf("----------------------------------------------------------------\n");
    printf("\n     -- MAIS OPÇÕES PARA PACIENTE: -- \n");
    printf("     (1) Listar pacientes cadastrados; \n");
    printf("     (2) Cadastrar novo paciente; \n");
    printf("     (3) Excluir cadastro de um paciente; \n");
    printf("     (4) Buscar um paciente; \n");
    scanf("%d", &opp);

    switch (opp){   //Gerencia as opções de gerenciamento dos pacientes
        case 1:
           // listaPacientesCadastrados(Lpacientes* listapacientes);
            break;
        case 2:
            //inserePaciente(Lpacientes* listapacientes);
            break;
        case 3:
            //excluiPaciente (Lpacientes * listapacientes);
            break;
        case 4:
            //buscaPaciente (Lpacientes * listapacientes);
          break;
    }
}

tipoUTI *insereUTI(lUTI *listaUtis){

    printf("----------------------------------------------------------------\n");
    printf("------------ BEM VINDO AO CADASTRO DE UTIs ---------\n");
    printf("------------ INFORME OS DADOS SOLICITADOS:  -----------\n");
    lUTI *aux;
    aux = criaListadeUTI();
    printf(" ----- Código da UTI: \n");
    scanf("%s",aux->uti.codigo);
    printf(" ----- Situação da UTI: \n");
    scanf("%s",aux->uti.situacao);

    lUTI *antigo = listaUtis->proximo;
    listaUtis->proximo = aux;
    aux->proximo = antigo;
}

tipoExameImagem *insereExamedeImagem(lExameImagem *listaExames){

    printf("----------------------------------------------------------------\n");
    printf("------------ BEM VINDO AO CADASTRO DE EXAMES DE IMAGEM ---------\n");
    printf("----------------- INFORME OS DADOS SOLICITADOS:  ---------------\n");
    lExameImagem *aux;
    aux = criaListadeExamesImagem();
    printf(" ----- Código do Exame: \n");
    scanf("%s",aux->exame.codigoexame);
    printf(" ----- Resultado do Exame: \n");
    scanf("%s",aux->exame.resultado);

    lExameImagem *antigo = listaExames->proximo;
    listaExames->proximo = aux;
    aux->proximo = antigo;
}

    void menuloop(int op){  //função para menu de interação com o usuário

    Lpacientes *listapacientes;
    listapacientes = criaListadePacientes();

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
        printf("- Escolha a opção correspondente:  ");
        scanf("%d", &op);
        printf("---------------------------------------------------------------\n");

        switch(op){
        case 1:
            inserePaciente(listapacientes);
            break;
        }
    }
}

void main(){

    menuloop(op);
}
