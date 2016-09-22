# Estrutura de Dados - MATD04 - 2016.1
# Repositorio do projeto final

**UFBA – IM – DCC**
**Matd04 – Estrutura de Dados**
**Trabalho  –  setembro/2016**
**Professor: Walter Rocha Palma**


## EMENTA

**Definir e implementar estrutura de dados e operações, usando linguagem C,  para controlar as operações de um hospital, conforme especificações a seguir:**

Um determinado hospital possui uma estrutura física composta dos seguintes elementos:

> 1. 300 quartos com um leito cada, acomodados do quarto ao nono andar, com um posto de enfermagem em cada andar e 50 quartos por andar
> 2. 5 enfermarias com 20 leitos cada, acomodadas no terceiro andar, com um posto de enfermagem
> 3. 1 unidade de tratamento semi-intensivo acomodada no décimo andar, com 50 leitos e 1 posto de enfermagem e controle
> 4. 1 unidade de tratamento intensivo acomodada no décimo andar, com 50 leitos e 1 posto de enfermagem e controle
> 5. 50 consultórios médicos, para atendimento ambulatorial, com uma recepção, localizados no segundo andar
> 6. 10 unidades de exame de imagem com uma recepção, localizada no primeiro andar
> 7. 1 laboratório de exames clínicos com uma recepção, localizada no primeiro andar
> 8. 1 Farmácia central localizada no andar térreo
> 9. 10  farmácias satélites localizadas do primeiro ao décimo andar 
> 10. Uma unidade de pronto atendimento localizada no andar térreo com uma recepção, 20 consultórios e uma enfermaria com 30 leitos de observação e um posto de enfermagem


## ESTRUTURA


A estrutura dos quartos tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número do quarto | CHAR | 3 |
| Situação | CHAR | 1 ( 1- livre, 2-ocupado) |
| Paciente | PONTEIRO |  |
| Médico | PONTEIRO |  |
 

A estrutura das enfermarias tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número da enfermaria | CHAR | 1 |
| Situação | CHAR | 1 ( 1- livre, 2-ocupado) |
| Leitos | PONTEIRO |  |


A estrutura dos leitos das enfermarias tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número do leito | CHAR | 2 |
| Situação | CHAR | 1 ( 1- livre, 2-ocupado) |
| Paciente | PONTEIRO |  |
| Médico | PONTEIRO |  |


A estrutura da unidade de tratamento semi-intensivo tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número da unidade | CHAR | 1 |
| Situação | CHAR | 1 ( 1- livre, 2-ocupado) |
| Leitos | PONTEIRO |  |


A estrutura dos leitos da unidade de tratamento semi-intensivo  tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número do leito | CHAR | 2 |
| Situação | CHAR | 1 ( 1- livre, 2-ocupado) |
| Paciente | PONTEIRO |  |
| Médico | PONTEIRO |  |


A estrutura da unidade de tratamento intensivo tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número da unidade | CHAR | 1 |
| Situação | CHAR | 1 ( 1- livre, 2-ocupado) |
| Leitos | PONTEIRO |  |


A estrutura dos leitos da unidade de tratamento intensivo tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número do leito | CHAR | 2 |
| Situação | CHAR | 1 ( 1- livre, 2-ocupado) |
| Paciente | PONTEIRO |  |
| Médico | PONTEIRO |  |


A estrutura dos consultórios tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número do consultório | CHAR | 2 |
| Situação agenda do mês 1 | CHAR | 1 ( 1- livre, 2-ocupado) |
| Agenda 1 | PONTEIRO |  |
| Situação agenda do mês 2 | CHAR | 1 ( 1- livre, 2-ocupado) |
| Agenda do mês 2 | PONTEIRO |  |
| Situação agenda do mês 3 | CHAR | 1 ( 1- livre, 2-ocupado) |
| Agenda do mês 3 | PONTEIRO |  |


A estrutura da agenda dos consultórios tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Dia do mês | CHAR | 2 |
| Hora do dia | CHAR | 4 |
| Situação da hora | CHAR | 1 ( 1- livre, 2-ocupado) |
| Médico | PONTEIRO |  |
| Paciente | PONTEIRO |  |

 
A estrutura das unidades de exames de imagem tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número da unidade | CHAR | 2 |
| Situação agenda do mês 1 | CHAR | 1 ( 1- livre, 2-ocupado) |
| Agenda 1 | PONTEIRO |  |
| Situação agenda do mês 2 | CHAR | 1 ( 1- livre, 2-ocupado) |
| Agenda do mês 2 | PONTEIRO |  |
| Situação agenda do mês 3 | CHAR | 1 ( 1- livre, 2-ocupado) |
| Agenda do mês 3 | PONTEIRO |  |


A estrutura da agenda das unidades de imagem tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Dia do mês | CHAR | 2 |
| Hora do dia | CHAR | 4 |
| Situação da hora | CHAR | 1 ( 1- livre, 2-ocupado) |
| Médico | PONTEIRO |  |
| Paciente | PONTEIRO |  |

 
A estrutura dos exames de imagem tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código do exame | CHAR | 4 |
| Médico | PONTEIRO |  |
| Paciente | PONTEIRO |  |
| Resultado | CHAR | 500 |

 
A estrutura do laboratório de exames clínicos tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número da unidade | CHAR | 1 |
| Exame tipo 1 | PONTEIRO |  |
| Exame tipo 2 | PONTEIRO |  |
| Exame tipo 3 | PONTEIRO |  |
| Exame tipo 4 | PONTEIRO |  |
| Exame tipo 5 | PONTEIRO |  |
| Exame tipo 6 | PONTEIRO |  |


A estrutura dos exames tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código do exame | CHAR | 4 |
| Médico | PONTEIRO |  |
| Paciente | PONTEIRO |  |
| Resultado | CHAR | 500 |


A estrutura da farmácia central e das farmácias satélites tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número da farmácia | CHAR | 2 |
| Local – andar da farmácia |  CHAR | 2 |
| Medicamentos | PONTEIRO |  |


A estrutura dos medicamentos os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – código do medicamento | CHAR | 10 |
| QTD – quantidade em estoque | INTEIRO |  |
| Valor unitário | FLOAT |  |
| Nome – nome do medicamento | CHAR | 30 |
| Tipo | CHAR | 1 ( 1- marca, 2-similar,3-genérico |
| Lote | CHAR | 4 |
| Validade | CHAR | 8 |


A estrutura da unidade de pronto atendimento tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – código da unidade | CHAR | 1 |
| Consultório | PONTEIRO |  |
| Leitos | PONTEIRO |  |


A estrutura dos consultórios da unidade de pronto atendimento tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – número do consultório | CHAR | 2 |
| Situação agenda do dia | CHAR | 1 ( 1- livre, 2-ocupado) |
| Agenda do dia | PONTEIRO |  |


A estrutura da agenda dos consultórios de pronto atendimento tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Dia do mês | CHAR | 2 |
| Hora do dia | CHAR | 4 |
| Situação da hora | CHAR | 1 ( 1- livre, 2-ocupado) |
| Médico | PONTEIRO |  |
| Paciente | PONTEIRO |  |


A estrutura dos leitos da unidade de pronto atendimento tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |


A estrutura dos médicos tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |


A estrutura dos pacientes tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
| Código – código do paciente | CHAR | 10 |
| Nome | CHAR | 40 |
| Médico | PONTEIRO |  |
| Enfermidade | CHAR | 50 |
| Tipo atendimento | CHAR | 1 (1-Pronto A., 2-Ambulatorial, 3-internamento) |
| Tipo de acomodação | CHAR | 1 (1- Leito Pronto A, 2-Enfermaria, 3-Apartamento, 4-Semi-intensiva, 5-Intensiva |
| Conta | PONTEIRO |  |
| Código do Plano | CHAR | 8 |
| Prontuário | PONTEIRO |  |


A estrutura das contas dos pacientes tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |


As estruturas de procedimento, consulta, medicamento e diárias tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |


A estrutura de Prontuário dos pacientes tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |


A estrutura de Doenças tem os seguintes campos:

| Campo | Tipo | Tamanho |
| --- | --- | --- |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |


> Caso o aluno considere necessário ele pode criar outras estruturas complementares, devendo documentá-las, a exemplos das aqui apresentadas.

> As Estruturas destinadas a dados que tenham quantidades de itens pré-determinadas devem ser armazenadas em Listas Lineares com alocação sequencial e estática, com o índice do primeiro elemento armazenado em uma variável de nome PRIMEIRO e uma variável de nome FIM com o índice do último elemento alocado. As demais em Listas Lineares com alocação não sequencial e dinâmica ( encadeada ). O tipo de lista utilizada, simple, circular, dupalmente encadeada, pilha, fila ou árvore, fica a critério do aluno. 

## EQUIPES

As tarefas elencadas neste trabalho, referentes às estruturas e suas operações, devem ser executadas pelas equipes, conforme a seguinte divisão:

### Funções Gerais:

	1) Criar cada uma das estruturas
	2) Fazer cada uma das estruturas vazia
	3) Teste se está vazia, para cada uma das estruturas
	4) Teste se está cheia, para cada uma das estruturas
	5) Inserir item em cada uma das estruturas
	6) Retirar item em cada uma das estruturas
	7) Listar todos os elementos de cada uma das estruturas
	8) Obter o conteúdo de um de terminado item de cada uma das estruturas

> O programa principal deve providenciar a inicialização das estruturas e interagir com o usuário, apresentando um menu das operações que ele deseja fazer.
Deve ter uma opção no menu para encerrar as operações. 

> O programa principal deve ser comum a todos os grupos.

### Equipe 1: Quartos e enfermarias

	43) Paciente [NEW]
	9) Internar um paciente em um quarto
	10) Lançar diária de um paciente de um quarto
	11) Dar alta de um paciente de um quarto
	12) Internar um paciente em uma enfermaria
	13) Lançar diária de um paciente de uma enfermaria
	14) Dar alta de um paciente de uma enfermaria

### Equipe 2: Unidades de Tramento semi-intensivo e Consultórios

	44) Médico [NEW]
	15) Internar um paciente em uma unidade de tratamento semi intensivo
	16) Lançar diária de paciente em uma unidade de tratamento semi intensivo
	17) Dar alta de um paciente em uma unidade de tratamento semi intensivo
	21) Agendar uma consulta para um paciente em um consultório para um médico
	22) Registrar o resultado da consulta de uma paciente

### Equipe 3: Unidade de tratamento intensivo e Unidades de Exames de imagem

	18) Internar um paciente em uma unidade de tratamento intensivo 
	19) Lançar diária de paciente em uma unidade de tratamento intensivo
	20) Dar alta de um paciente em uma unidade de tratamento intensivo
	23) Agendar um exame para um paciente em uma unidade de exame de imagem
	24) Registrar o resultado de um exame de imagem de um paciente 

### Equipe 4: Laboratório, Farmácia Central e Farmácia satélite

	25) Registrar a entrada de material para exames de laboratório de um paciente
	26) Registrar o resultado dos exames de laboratório de um paciente
	27) Registrar entrada de medicamento na Farmácia Central
	28) Registrar transferência de medicamento da farmácia central para farmácia Satélite
	29) Confirmar recepção de medicamento na Farmácia Satélite
	30) Lançar medicamento para uma paciente

### Equipe 5: Umidade de pronto Atendimento e Faturamento

	31) Recepcionar paciente no Pronto Atendimento
	32) Agendar paciente do pronto atendimento para um consultório
	33) Encaminhar paciente do pronto atendimento para um consultório
	34) Registrar consulta de um paciente no consultório do Pronto Atendimento e seu resultado
	35) Internar um paciente em leito da unidade do Pronto Atendimento
	36) Lançar diária para um paciente em leito da unidade do Pronto Atendimento
	37) Dar alta a um paciente em leito da unidade do Pronto Atendimento

	38) Fechar a conta de um paciente
	39) Emitir despesas de uma paciente
	40) Emitir fatura de um paciente
	41) Enviar faturas de pacientes para um determinado convênio
	42) Emitir relatório de faturamento mensal


## MAÕS À MASSA

### Prototipagem das Funções:

> Arquivo "x.h":
...
...

> Arquivo "x.h":
...
...


