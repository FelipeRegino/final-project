/*Neste arquivo estão as estruturas de paciente, conta, prontuario consultorioPA
leitos e a UPA. Tambem contam as respectivas funções para inicialização e
manipulação*/

/*O codigo e funções dos pacientes foram desenvolvidos pelo GRUPO 01.
Copiei-os para cá devido a warnings que estavam gerando no codigo principal.
Realizei pequenas modificações no codigo da equipe.*/

struct conta {
  char codigo[10];
  ListaProcedimento* procedimento;
  ListaConsulta* consulta;
  ListaMedicamento* medicamento;
  ListaDiaria* diaria;

};
typedef struct conta TipoConta;


struct prontuario {
  char codigopaciente[10];
  TipoProcedimento* procedimento;
  TipoConsulta* consulta;
  TipoMedicamento* medicamento;
  //TipoExame* exame;
  //TipoDoenca* doenca;
};
typedef struct prontuario TipoProntuario;


struct Paciente{
	char nome [30];
	char codigo[10] ;
  //*Médico
	char Enfermidade[50];
	char Tipoatendimento [1];
  char Tipodeacomodacao [1];
	TipoConta conta;
	char CodigodoPlano [8];
	TipoProntuario* prontuario;
};
typedef struct Paciente Tipopaciente;


struct listapaciente {
   Tipopaciente  paciente;
   struct listapaciente *proximo;
};
typedef struct listapaciente Lpaciente;


/*Estrutura da agenda dos consultorios da UPA*/
struct agendaconsultorioPA {
  int dia;
  int horario;
  char situacao;
  Tipopaciente *paciente;
  //TipoMedico *medico;
};
typedef struct agendaconsultorioPA TipoAgendaConsPA;


/*Estrutura dos consultorios da UPA*/
struct consultorioPA {
  int codigo;
  int sit_agenda;
  TipoAgendaConsPA *agenda;
};
typedef struct consultorioPA TipoConsPA;


/*Estrutura dos leitos do pronto atendimento*/
struct leitoPA {
  int codigo;
  char situacao;
  Tipopaciente *paciente;
  //ponteiro para Medico
};
typedef struct leitoPA TipoLeitoPA;


/*Estrutura do pronto atendimento*/
struct prontoatendimento {
  char codigo_unidade;
  TipoConsPA **consultoriosPA;
  TipoLeitoPA **leitosPA;
};
typedef struct prontoatendimento TipoProntoAtendimento;

/*==========================declarações===============================*/
TipoConsPA* ListaConsultorioPA[20];
TipoLeitoPA* ListaLeitosPA[30];
TipoAgendaConsPA* ListaAgendasPA[20];
TipoProntoAtendimento* ProntoAtendimento;
Lpaciente* Lpacientenova;

////////////////////////////////////////////////////////////////////////////
Tipopaciente *criapaciente (){

Tipopaciente *novo;
novo = (Tipopaciente *)malloc(sizeof(Tipopaciente));
return novo;

}
////////////////////////////////////////////////////////////////////////////
Lpaciente *crialistapaciente (){

Lpaciente *novo;
novo = (Lpaciente *)malloc(sizeof(Lpaciente));
novo->proximo = NULL;
return novo;

}
/////////////////////////////////////////////////////////////////////////////
int VerificaListaVaziaPaciente (Lpaciente *listadepaciente){

if (listadepaciente->proximo == NULL){

 return 1;
}
 return 0;
}


///////////////////////////////////////////////////////////////////////////
Tipopaciente *CadastrarCliente (Lpaciente * listapaciente){


printf(" ================ TELA DE CADASTRO DE PACIENTES ================ \n \n");

char temp;

Lpaciente *aux;
aux = crialistapaciente();
aux->paciente.conta.diaria = crialistadiaria (); //inserir lista de diarias
aux->paciente.conta.consulta = crialistaconsulta (); //inserir lista de consulta
aux->paciente.conta.procedimento = crialistaprocedimento (); //inserir lista procedimentos
aux->paciente.conta.medicamento = crialistamedicamento (); //inserir lista medicamentos
printf("Digite o codigo do paciente: ");
scanf("%s",aux->paciente.codigo);
printf("Digite o nome do paciente:  ");
scanf("%s",aux->paciente.nome);
printf("Digite a Enfermidade do paciente:  ");
scanf("%s",aux->paciente.Enfermidade);
aux->paciente.Tipodeacomodacao[0] = 1;
printf("Qual o plano de saude:   ");
scanf("%s",aux->paciente.CodigodoPlano);
Lpaciente *oldhead = listapaciente->proximo;
listapaciente->proximo = aux;
aux->proximo = oldhead;
printf("\n Paciente cadastrado com sucesso! \n");

}


void ImprimeListaPacientes(Lpaciente *listadepaciente){


if (VerificaListaVaziaPaciente(listadepaciente) == 1){

   printf("Sem Pacientes Cadastrados \n");

}
  else
{

  Lpaciente *temp = listadepaciente;//->proximo;

  while (temp != NULL){

  printf(" NOME : %s \n",&temp->paciente.nome);
  printf(" CODIGO : %s \n",&temp->paciente.codigo);
  temp = temp->proximo;

  }

}

}




Tipopaciente *SelecionaPaciente (Lpaciente * listapaciente){
  if ( VerificaListaVaziaPaciente(listapaciente) == 1 ) {
    printf("A lista se encontra vazia \n");
  }
  else {
    char cod [10];
    int ret ;
    printf("Qual o codigo do paciente ? ");
    scanf("%s",cod);
    ret = strcmp(cod, listapaciente->paciente.codigo);
    while ( ret != 0 ){
      listapaciente= listapaciente->proximo;
      ret = strcmp(cod, listapaciente->paciente.codigo);
    if ( ret!=0 && listapaciente->proximo == NULL ){
      printf("CODIGO NAO ENCONTRADO");
      return NULL;
    }
  }
  Tipopaciente *PacienteSelecionado;
  PacienteSelecionado = criapaciente();
  *PacienteSelecionado = listapaciente->paciente ;
  return PacienteSelecionado;
  }
}


void PesquisaPaciente (Lpaciente * listapaciente) //Retorna o Ponteiro do TipoCliente em uma lista de LPaciente
  {
    printf(" ================ TELA DE PESQUISA DE PACIENTES ================ \n \n");
    Tipopaciente *pac;
    pac = criapaciente();
    pac = SelecionaPaciente(listapaciente);
    if ( pac == NULL){
    }else {

      printf(" NOME : %s \n",&pac->nome);
      printf(" CODIGO : %s \n",&pac->codigo);
    }
}


void encaminharpacientePA(Tipopaciente* paciente, TipoConsPA **consultorio /*TipoMedico medico*/){
  int i;
    for (i=0; i<20; i++){
      if (consultorio[i]->sit_agenda == 1){
        consultorio[i]->sit_agenda = 2;
        printf("Encaminhando paciente para o consultorio %d", consultorio[i]->codigo);
      //printf("\nDigite o dia da consulta:");
      //scanf("%d", &consultorio[i]->agenda->dia);
      //printf("\nDigite o horário da consulta (formato 24H):");
      //scanf("%d", &consultorio[i]->agenda->horario);
        consultorio[i]->agenda->situacao = 2;
        consultorio[i]->agenda->paciente = paciente;
      //paciente->medico = medico;
      //medico->paciente = paciente;
      //chamar funcao para adicionar consulta ao prontuario do paciente
        return;
      }
  }
  printf("Nao há consultorios disponiveis!" );
  //chamar funcao para agendar paciente
  return;

}











////////////////////Função incompleta para registrar resultado/////////////
void registrarresultado(Tipopaciente* paciente ){
  //paciente->prontuario->codigo = paciente->codigo;
  //paciente->prontuario->procedimento->
  //paciente->prontuario->consulta->
  //paciente->prontuario->medicamento->
  //paciente->prontuario->exames->
  //paciente->prontuario->doenca->
  //chama alguma funcao da equipe de laboratorio
}

void internarpacienteleito(Tipopaciente* paciente, TipoLeitoPA **leito /*TipoMedico* medico*/){
  int i;
  for(i=0; i<20; i++)
  {
    if (leito[i]->situacao == 1) {
      leito[i]->situacao = 2;
      leito[i]->paciente = paciente;
      paciente->Tipodeacomodacao[0] = 1;
      //leito[i]->medico = medico;
    }
  }

}


/////////////////////////////////////////////////////////////////
/*AS funções abaixo inicializam algumas estruturas do programa.*/

void iniciaAgendaConsultorio(TipoAgendaConsPA** agendaPA){
  int i;
  for( i=0; i<20; i++){
      agendaPA[i] = (TipoAgendaConsPA*)malloc(sizeof(TipoAgendaConsPA));
  }
}


void iniciaListaConsultorioPA(TipoConsPA** listaConsPA, TipoAgendaConsPA** agendaPA){
  FILE *arq;
  char url[]="consultorios.txt";
  int codigo, i  ;
  arq = fopen(url, "r");
//  TipoConsPA* ListaConsultorio[MAX];
  for( i=0; i<20; i++){
      listaConsPA[i] = (TipoConsPA*)malloc(sizeof(TipoConsPA));
      listaConsPA[i]->agenda = agendaPA[i];
      listaConsPA[i]->sit_agenda = 1;
  }
  i = 0;
  if (arq == NULL){
    printf("Arquivo nao pode ser aberto!");
  }
  while ((fscanf(arq, "%d\n", &codigo))!= EOF) {
    listaConsPA[i]->codigo = codigo;
    i++;
  }
}


void iniciaLeitosPA(TipoLeitoPA** ListaLeitosPA){
  FILE *arq;
  char url[]="leitos.txt";
  int codigo, i  ;
  arq = fopen(url, "r");
  for( i=0; i<30; i++){
      //listaConsPA[i] = NULL;
      ListaLeitosPA[i] = (TipoLeitoPA*)malloc(sizeof(TipoLeitoPA));
      ListaLeitosPA[i]->situacao = 1;
  }
  i = 0;
  if (arq == NULL){
    printf("Arquivo nao pode ser aberto!");
  }
  while ((fscanf(arq, "%d\n", &codigo))!= EOF) {
    ListaLeitosPA[i]->codigo = codigo;
    i++;
  }
}

void iniciaProntoAtendimento(TipoProntoAtendimento* pa){
  pa = (TipoProntoAtendimento*)malloc(sizeof(TipoProntoAtendimento));
  pa->consultoriosPA = ListaConsultorioPA;
  pa->leitosPA = ListaLeitosPA;
  pa->codigo_unidade = 0;
  ProntoAtendimento = pa;
}
