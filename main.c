#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <conio.h> ativar para windows
#include "diaria.h"
#include "consulta.h"
#include "procedimento.h"
#include "medicamento.h"
#include "funcoes.h"
#include "menu.h"

#define MAX 20







void main(){

  iniciaAgendaConsultorio(ListaAgendasPA);
  iniciaListaConsultorioPA(ListaConsultorioPA, ListaAgendasPA);
  iniciaLeitosPA(ListaLeitosPA);
  iniciaProntoAtendimento(ProntoAtendimento);
  Lpacientenova = crialistapaciente();
  menuPA();
}
