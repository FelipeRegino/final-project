typedef struct Paciente{

	char nome [30];
	char codigo[10] ;
    //*Médico
	char Enfermidade[50];
	char Tipoatendimento;
    char Tipodeacomodacao;
	//*Conta
	char CodigodoPlano;
	//*Prontuário
};
typedef struct Paciente Tipopaciente;


typedef struct listapaciente {

   Tipopaciente  paciente;
   Tipopaciente *proximo;

};
typedef struct listapaciente Lpaciente;



Tipopaciente *SelecionaPaciente (Lpaciente * listapaciente);
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

void PesquisaPaciente (Lpaciente * listapaciente); //Retorna o Ponteiro do TipoCliente em uma lista de LPaciente
void RemovePaciente (Lpaciente * listapaciente); //Remove o Ponteiro do TipoCliente em uma lista de LPaciente
void AlteraCadastroCliente (Lpaciente * listapaciente);
Tipopaciente *criapaciente ();
Lpaciente *crialistapaciente ();
int VerificaListaVaziaPaciente (Lpaciente *listadepaciente);
Tipopaciente *CadastrarCliente (Lpaciente * listapaciente);
void ImprimeListaPacientes(Lpaciente *listadepaciente);
