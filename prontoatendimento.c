#include <stdlib.h>
#include <stdio.h>
#include "prontoatendimento.h"


/*Estrutura das agendas dos consultorios do pronto atendimento*/
struct agendaconsultorioPA { //consultorio pronto atendimento
  char dia[2];
  char horario[4];
  char situacao;
  //ponteiro para estrutura tipo Medico
  //ponteiro para estrutura tipo paciente
};
typedef struct agendaconsultorioPA TipoAgendaConsPA;


/*Estrutura dos consultorios do pronto atendimento*/
struct consultorioPA {
  char codigo[2];
  char sit_agenda;
  int teste;
  TipoAgendaConsPA *agenda;
};
typedef struct consultorioPA TipoConsPA;


/*Estrutura dos leitos do pronto atendimento*/
struct leitoPA {
  char codigo[2];
  char situacao;
  //ponteiro para paciente
  //ponteiro para Medico
};
typedef struct leitoPA TipoLeitoPA;


/*Estrutura do pronto atendimento*/
struct prontoatendimento {
  char codigo_unidade;
  TipoConsPA *consultorios[20];
  TipoLeitoPA *leitos[30];
};
typedef struct prontoatendimento TipoProntoAtendimento;


/*Funções*/

TipoConsPA* inicia_consultorioPA(){}

void recepcaoPA(){}

void agendarConsultorioPA(){}

void encaminharpacientePA(){}

void registrarresultado(){}

void internarpacienteleito(){}

void lancardiarialeitoPA(){}

void alta(){}

void fecharconta(){}

void emitirdespesas(){}

void emitirfatura(){}

void enviarfaturaconvenio(){}

void emitirfaturamensal(){}
