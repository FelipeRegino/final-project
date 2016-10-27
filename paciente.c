#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "paciente.h"



Tipopaciente *criapaciente (){

Tipopaciente *novo;
novo = (Tipopaciente *)malloc(sizeof(Tipopaciente));
return novo;

}

Lpaciente *crialistapaciente (){

Lpaciente *novo;
novo = (Lpaciente *)malloc(sizeof(Lpaciente));
novo->proximo = NULL;
return novo;

}




int VerificaListaVaziaPaciente (Lpaciente *listadepaciente){

if (listadepaciente->proximo == NULL){

 return 1;
}
 return 0;
}



Tipopaciente *CadastrarCliente (Lpaciente * listapaciente){

system("cls");

printf(" ================ TELA DE CADASTRO DE PACIENTES ================ \n \n");


Lpaciente *aux;
aux = crialistapaciente();
char letra;

printf("   Qual tipo de atendimento  1-Pronto A., 2-Ambulatorial, 3-internamento  ");
scanf("%c",&letra);
aux->paciente.Tipoatendimento = letra;




printf("   Digite o codigo do paciente ");
scanf("%s",aux->paciente.codigo);
printf("   Digite o nome do paciente  ");
scanf("%s",aux->paciente.nome);
printf("   Digite a Enfermidade do paciente  ");
scanf("%s",aux->paciente.Enfermidade);

printf("   Qual tipo de acomodacao 1- Leito Pronto A, 2-Enfermaria, 3-Apartamento, 4-Semi-intensiva, 5-Intensiva ");
scanf("%c",&aux->paciente.Tipodeacomodacao);
printf("   Qual o plano de saude  ");
scanf("%s",aux->paciente.CodigodoPlano);
Lpaciente *oldhead = listapaciente->proximo;
listapaciente->proximo = aux;
aux->proximo = oldhead;
printf("\n Paciente cadastrado com sucesso! \n");
getch();
system("cls");

}


void ImprimeListaPacientes(Lpaciente *listadepaciente){


if (VerificaListaVaziaPaciente(listadepaciente) == 1){

   printf("Sem Pacientes Cadastrados \n");

}
  else
{

  Lpaciente *temp = listadepaciente->proximo;

  while (temp != NULL){

  printf(" NOME : %s \n",&temp->paciente.nome);
  printf(" CODIGO : %s \n",&temp->paciente.codigo);
  temp = temp->proximo;

  }

}

}



/* Essa função retorna o ponteiro de um paciente na lista de pacientes onde podem ser coletadas qualquer informação do paciente
   para usar essa função crie um variável Lpaciente *NomeDaVariavelTipoPonteiro = SelecionaPaciente;
   Ex:
  ==================================================================================
   Tipopaciente *DadosDoPaciente = SelecionaPaciente (Tipopaciente * listadepacientes) ;
   Quarto->Paciente  = DadosDoPaciente;
   ==================================================================================
   Para imprimir os dados do Paciente na Tela:
   ImprimeDadosPaciente (DadosDoPaciente);
   ==================================================================================
*/

Tipopaciente *SelecionaPaciente (Lpaciente * listapaciente)
{

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
system("cls");
printf(" ================ TELA DE PESQUISA DE PACIENTES ================ \n \n");
Tipopaciente *pac;
pac = criapaciente();
pac = SelecionaPaciente(listapaciente);

if ( pac == NULL){



}else {

printf(" NOME : %s \n",&pac->nome);
printf(" CODIGO : %s \n",&pac->codigo);
getch();


}



}

void RemovePaciente (Lpaciente * listapaciente)
{

if ( VerificaListaVaziaPaciente(listapaciente) == 1 ) {

 printf("A lista se encontra vazia \n");

}

else {

char cod [10];
int ret ;
printf("Qual o codigo do paciente deseja remover ? ");
scanf("%s",cod);
ret = strcmp(cod, listapaciente->paciente.codigo);
Lpaciente *antes;
Lpaciente *pselecionado;
pselecionado = crialistapaciente();

while ( ret != 0 ){

antes = listapaciente;
listapaciente= listapaciente->proximo;
ret = strcmp(cod, listapaciente->paciente.codigo);


 if ( ret!=0 && listapaciente->proximo == NULL ){

    printf("CÓDIGO NÃO ENCONTRADO");

 }

}

if (listapaciente->proximo == NULL){

  antes->proximo = listapaciente->proximo;
  pselecionado = listapaciente ;
  free(listapaciente);
  listapaciente = antes;
}

}

}




void AlteraCadastroCliente (Lpaciente * listapaciente)
{

if ( VerificaListaVaziaPaciente(listapaciente) == 1 ) {

 printf("A lista se encontra vazia \n");

}

else {

char cod [10];
int ret ;
printf("Qual o codigo do paciente que deseja alterar o cadastro ");
scanf("%s",cod);
ret = strcmp(cod, listapaciente->paciente.codigo);
Lpaciente *antes;
Lpaciente *pselecionado;
pselecionado = crialistapaciente();

while ( ret != 0 ){

antes = listapaciente;
listapaciente= listapaciente->proximo;
ret = strcmp(cod, listapaciente->paciente.codigo);


 if ( ret!=0 && listapaciente->proximo == NULL ){

    printf("CÓDIGO NÃO ENCONTRADO");

 }


printf("Digite o novo nome do paciente ");
scanf("%s",listapaciente->paciente.nome);



}

}

}
