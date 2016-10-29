/*Arquivo referente ao menu do programa. O menu é referente apenas a UNIDADE
PRONTO ATENDIMENTO - UPA*/

void titulomenu(char opcao[]){
  system("cls");
  printf("\n##################################################################\n#");
  printf("                                                                #\n" );
  printf("                      %s                      ",opcao );
  printf("\n#                                                                #");
  printf("\n##################################################################\n" );
}

void  menuPA(){
  int op;
  while (op != 13) {
    system("cls");
    printf("\n##################################################################\n#");
    printf("                                                                #\n" );
    printf("#             UNIDADE DE PRONTO ATENDIMENTO - UPA                #" );
    printf("\n#                                                                #");
    printf("\n##################################################################\n" );
    printf("# 1 - Recepcionar Paciente;       7 - Dar alta;                  #\n");
    printf("# 2 - Agendar paciente;           8 - Fechar conta;              #\n");
    printf("# 3 - Encaminhar paciente;        9 - Emitir despesas;           #\n");
    printf("# 4 - Registrar resultado;        10 - Emitir fatura;            #\n");
    printf("# 5 - Internar paciente;          11 - Emitir fatura de convenio;#\n");
    printf("# 6 - Lançar diaria;              12 - Emitir fatura mensal;     #\n");
    printf("#                                                                #\n");
    printf("#           13 - SAIR DA UNIDADE DE PRONTO ATENDIMENTO           #\n");
    printf("##################################################################\nOpçao:");
    scanf("%d", &op );

    switch (op) {

        case 1:
          system("cls");
          printf("");
          int opm1, teste;
          while (opm1 != 4) {
            char op1[] = "RECEPÇÃO DE CLIENTES";
            titulomenu(op1);
            printf("# 1 - Cadastrar novo paciente;   3 - Imprimir lista de pacientes;#\n");
            printf("# 2 - Buscar paciente;           4 - Voltar;                     #\n");
            printf("##################################################################\nOpçao:");
            scanf("%d", &opm1);
            switch (opm1) {

              case 1:
                printf("");
                Tipopaciente* novo = CadastrarCliente(Lpacientenova);
                //adicionar chamada de funcao para encaminhar e/ou agendar paciente
                break;

              case 2:
                printf("");
                PesquisaPaciente(Lpacientenova);
                break;

              case 3:
                printf("");
                ImprimeListaPacientes(Lpacientenova);
                scanf("%d", &teste);
                break;

              case 4:

                break;

              default:
                printf("Opção inválida!");
                break;
          }
          }
          break;

        case 2:
          printf("");
          char op2[] = "AGENDAR PACIENTES";
          titulomenu(op2);
          //agendarConsultorioPA(ListaConsultorioPA, paciente);
          break;

        case 3:
          printf("");
          char op3[] = "ENCAMINHAMENTO DE PACIENTES";
          titulomenu(op3);
          if ( VerificaListaVaziaPaciente(Lpacientenova) == 1 ) {
            printf("A lista se encontra vazia! \n");
            Tipopaciente* novo = CadastrarCliente(Lpacientenova);
            encaminharpacientePA(novo, ListaConsultorioPA);
          }else {
            Tipopaciente* novo = SelecionaPaciente(Lpacientenova);
            encaminharpacientePA(novo, ListaConsultorioPA);
          }

          break;

        case 4:
          printf("");

          char op4[] = "REGISTRAR RESULTADO";
          titulomenu(op4);
          //funcao para selecionar paciente
          //registrarresultado(ppaciente); //registrar resultado no prontuario do paciente
          break;

        case 5:
          printf("");

          char op5[] = "INTERNAR PACIENTE";
          if ( VerificaListaVaziaPaciente(Lpacientenova) == 1 ) {
            printf("A lista se encontra vazia! \n");
            Tipopaciente* novo2 = CadastrarCliente(Lpacientenova);
            internarpacienteleito(novo2, ListaLeitosPA);
          }else {
            Tipopaciente* novo2 = SelecionaPaciente(Lpacientenova);
            internarpacienteleito(novo2, ListaLeitosPA);
          }
          titulomenu(op5);
          break;

        case 6:
          printf("");

          char op6[] = "LANÇAR DIÁRIA DE PACIENTE";

          titulomenu(op6);
          if ( VerificaListaVaziaPaciente(Lpacientenova) == 1 ) {
            printf("A lista se encontra vazia! \n");
            Tipopaciente* novo3 = CadastrarCliente(Lpacientenova);
            ListaDiaria* lisdiaria = novo3->conta.diaria;
            CadastrarDiaria (novo3->conta.diaria);
          }else {
            Tipopaciente* novo3 = SelecionaPaciente(Lpacientenova);
            CadastrarDiaria(novo3->conta.diaria);
          }

        case 7:
          printf("");
          char op7[] = "DAR ALTA PARA PACIENTE";
          titulomenu(op7);
          //muda o status do prontuario.doença do paciente
          //chama função para remover paciente
          break;

        case 8:
          printf("");
          char op8[] = "FECHAR CONTA DE PACIENTE";
          titulomenu(op8);
          //fecharconta(paciente);
          break;

        case 9:
          printf("");
          char op9[] = "EMISSÃO DE DESPESAS DE PACIENTE";
          //chama funcao para selecionar paciente;
          //entra na conta do paciente
          //chamama as funções:
          //ImprimeListaDiaria(ListaDiaria *listadiaria)
          //ImprimeListaConsulta(ListaConsulta *listaconsulta)
          //ImprimeListaProcedimento(ListaProcedimento *listaprocedimento)
          //ImprimeListaMedicamento(ListaMedicamento *listamedicamento)
          titulomenu(op9);
          break;

        case 10:
          printf("");
          char op10 [] = "EMISSÃO DE FATURA DE PACIENTE";
          titulomenu(op10);
          //chama a função para selecionar o paciente coletando e comando o campo valor
          //varre lista de diarias do paciente coletando e comando o campo valor
          //varre lista de procedimentos do paciente coletando e comando o campo valor
          //varre lista de medicamentos do paciente coletando e comando o campo valor
          //varre lista de consultas do paciente coletando e comando o campo valor
          //faz o somatorio dos valores encontrados e emite.
          break;

        case 11:
          printf("");
          char op11[] = "EMISSÃO DE FATURA DE CONVENIO";
          titulomenu(op11);
          //usuario entra com o codigo do convenio
          //varre a lista de pacientes comparando o campo conveio com o codigo inserido
          //ao encontrar paciente do convenio, chama funcao de emissoa de fatura e guarda o valor em uma variavel auxiliar.
          //repete isso com todos os pacientes do convenio enquanto realiza somatorio das variaveis auxiliares.
          //imprime o valor total da fatura do conveio
          break;

        case 12:
          printf("");
          char op12[] = "EMISSÃO DE FATURA MENSAL";
          titulomenu(op12);
          //varre a lista dos pacientes que utilizaram serviços do hospital no mes
          //a cada paciente, é chamada a funcao de emissao de fatura e o valor é salvo
          //realiza somatorio de cada valor e apresenta o somatorio final.
          break;

        case 13:
          printf("Saindo da UPA...");
          break;

        default:
          printf("Opção inválida!");
          break;
      }
    }
}
