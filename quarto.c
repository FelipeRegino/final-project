#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "quarto.h"


// ***********************************************
// Inicializar lista de quartos
// ***********************************************

lista_quartos* inicializarQuartos(){
	lista_quartos* lista = (lista_quartos*)malloc(sizeof(lista_quartos));
	lista->primeiro = 0;
	lista->fim = 0;
	lista->tam=0;
	return lista;
}

// ***********************************************
// Verificar lista vazia
// ***********************************************

bool verificarQuartosListaVazia(lista_quartos* lquartos){
	if(lquartos->primeiro==lquartos->fim){
		return true;
	}else{
		return false;
	}
}

// ***********************************************
// Verificar lista cheia
// ***********************************************

bool verificarQuartosListaCheia(lista_quartos* lquartos){
	if(lquartos->tam==maxQuartos-1){
		return true;
	}else{
		return false;
	}
}

// ***********************************************
// Inserir quarto na lista
// ***********************************************

bool inserirQuarto(lista_quartos* lquartos, int andar){
	int pos=lquartos->fim;
	int cod=pos+1;

	sprintf(lquartos->quartos[pos].codigo, "%d", cod);
	sprintf(lquartos->quartos[pos].situacao, "%d", 1);	// 1-livre 2-ocupado

	LeitoQ* leitoQ = (LeitoQ*)malloc(sizeof(LeitoQ));
	lquartos->quartos[pos].leitoQ=leitoQ;
	sprintf(lquartos->quartos[pos].leitoQ->codigo, "%d", cod);

	sprintf(lquartos->quartos[pos].andar, "%d", andar);

	PostoEnfermagem* postoEnfermagem = (PostoEnfermagem*)malloc(sizeof(PostoEnfermagem));
	lquartos->quartos[pos].postoEnfermagem=postoEnfermagem;
	sprintf(lquartos->quartos[pos].postoEnfermagem->codigo, "%d", andar);

	lquartos->quartos[pos].paciente=criapaciente();
	lquartos->quartos[pos].medico=(Medico*)malloc(sizeof(Medico));

	lquartos->tam++;
	lquartos->fim++;	// incrementa variavel fim q indica o proximo vazio

	 //printf("pos: %d codigo: %s andar: %s postoEnfermagem: %s\n",pos,lquartos->quartos[pos].codigo,lquartos->quartos[pos].andar,lquartos->quartos[pos].postoEnfermagem->codigo);

	return true;
}

// ***********************************************
// Criar todos os quartos na lista
// ***********************************************

bool criarQuartos(lista_quartos* lquartos){

	if( verificarQuartosListaVazia(lquartos) ){	// verifica se a lista esta vazia
		int cont=0,aux=0,andar=4;

		while(cont<maxQuartos){					// controla insercao de quartos
			if( inserirQuarto(lquartos,andar) ){
				cont+=1;
				aux+=1;

				if(aux==maxQuartosAndar){		// controla insercao por andar
					andar+=1;
					aux=0;
				}
			}
		} // fim while

		printf("\nQuartos criados com sucesso!\n");
		return true;

	} else{
		printf("\nQuartos já existem, não é possível criar!\n");
		return false;
	}
}


// ***********************************************
// Buscar quarto
// ***********************************************

Quarto* buscarQuarto(lista_quartos* lquartos, char* codigo){
	int i;
	Quarto *q=NULL;

	for(i=0; i<=lquartos->tam; i++){
		if( strcmp(lquartos->quartos[i].codigo,codigo)==0 ){	// compara strings com strcmp
			q=&lquartos->quartos[i];
		}
	}

	if(q!=NULL){
		printf("\nponteiro do quarto: %p codigo do quarto: %s\n",q,q->codigo);
	} else{
		printf("\nQuarto não encontrado!\n");
	}

	return q;
}


// ***********************************************
// Remover quarto da lista (sem reordenacao)
// ***********************************************

bool removerQuarto(lista_quartos* lquartos, char* codigo){
	Quarto *q=NULL,qVazio;

	q=buscarQuarto(lquartos,codigo);

	if(q!=NULL){
		*q=qVazio;
		lquartos->tam--;
		printf("\nQuarto removido com sucesso!\n");
		return true;
	}else{
		printf("\nNão foi possível remover o Quarto!\n");
		return false;
	}
}


// ***********************************************
// Imprimir quarto
// ***********************************************

void imprimirQuarto(Quarto* q){

	char status[8];
	char pac[3];
	char pacN[40];
	char med[3];
	char medN[40];

	if(*q->situacao=='1'){	// livre
		strcpy(status,"Livre  ");
		strcpy(pac,"---");
		strcpy(pacN,"---");
		strcpy(med,"---");
		strcpy(medN,"---");
	}else{					// ocupado
		strcpy(status,"Ocupado");
		strcpy(pac,q->paciente->codigo);
		strcpy(pacN,q->paciente->nome);
		strcpy(med,q->medico->codigo);
		strcpy(medN,q->medico->nome);
	}

	printf("\n|Nº Quarto\t|Nº Andar\t|Nº Leito\t|Nº PE\t|Situação\t|Tipopaciente-C\t|Tipopaciente-N\t|Medico-C\t|Medico-N\t|\n");
	printf("|---------------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("|%s\t\t|%s\t\t|%s\t\t|%s\t|%s\t|%s\t\t|%s\t\t|%s\t\t|%s\t\t|\n",q->codigo,q->andar,q->leitoQ->codigo,q->postoEnfermagem->codigo,status,pac,pacN,med,medN);
	printf("\n");

/*
	printf("Nº Quarto: %s\n",q->codigo);
	printf("Nº Andar: %s\n",q->andar);
	printf("Nº Leito: %s\n",q->leitoQ->codigo);
	printf("Nº Posto de Enfermagem: %s\n",q->postoEnfermagem->codigo);

	if(*q->situacao=='1'){	// livre
		printf("\n-> Situação: Livre\n");
		printf("Tipopaciente -Cod: %s\n","-----");
		printf("Tipopaciente -Nome: %s\n","-----");
		printf("Tipopaciente -Cod: %s\n","-----");
		printf("Tipopaciente -Nome: %s\n\n","-----");
	}else{					// ocupado
		printf("-> Situação: Ocupado\n");
		printf("Tipopaciente -Cod: %s\n",q->paciente->codigo);
		printf("Tipopaciente -Nome: %s\n",q->paciente->nome);
		printf("Médico -Cod: %s\n",q->medico->codigo);
		printf("Médico -Nome: %s\n\n",q->medico->nome);
	}
*/
}


// ***********************************************
// Buscar e listar quarto
// ***********************************************

bool listarQuarto(lista_quartos* lquartos, char* codigo){
	Quarto *q=NULL;

	q=buscarQuarto(lquartos,codigo);

	if(q!=NULL){
		printf("\nQuarto\n--------");
		imprimirQuarto(q);
		return true;
	}else{
		printf("\nQuarto não encontrado!\n");
		return false;
	}
}


// ***********************************************
// Listar todos os quartos
// ***********************************************

bool listarQuartos(lista_quartos* lquartos){
	int i;

	if( !verificarQuartosListaVazia(lquartos) ){

		for(i=0;i<=lquartos->fim;i++){
			if( *lquartos->quartos[i].situacao!=NULL ){		// quarto ja foi inicializado
				imprimirQuarto( &lquartos->quartos[i] );
			}
		}

		return true;
	}else{
		printf("\nLista vazia!\n");
		return false;
	}
}


// ***********************************************
// 9- Internar paciente em quarto
// ***********************************************

bool internarPacienteQuarto(lista_quartos* lquartos, Tipopaciente* paciente, Medico* medico){
	int i;
	bool token=false;

	for(i=0;i<lquartos->fim;i++){	// percorre lista de quartos
		if(*lquartos->quartos[i].situacao=='1'){	// verifica se o quarto esta disponivel

			lquartos->quartos[i].paciente=paciente;
			lquartos->quartos[i].medico=medico;
			strcpy(lquartos->quartos[i].situacao,"2");

			printf("\nTipopaciente internado com sucesso! Quarto nº: %s\n",lquartos->quartos[i].codigo);
			return true;
			break;
		}
	}

	if(!token){
		printf("\nNão foi possivel internar paciente!\n");
		return false;
	}
}


// ***********************************************
// 11- Dar alta de paciente em quarto
// ***********************************************

bool darAltaPacienteQuarto(lista_quartos* lquartos, Tipopaciente* paciente){
	int i;
	bool token=false;

	for(i=0;i<lquartos->fim;i++){	// percorre lista de quartos
		if(lquartos->quartos[i].paciente==paciente){	// verifica se o quarto esta disponivel

			lquartos->quartos[i].paciente=NULL;
			lquartos->quartos[i].medico=NULL;
			strcpy(lquartos->quartos[i].situacao,"1");

			printf("\nTipopaciente recebeu alta com sucesso! Quarto nº: %s esta disponível!\n",lquartos->quartos[i].codigo);
			return true;
			break;
		}
	}

	if(!token){
		printf("\nTipopaciente não encontrado!\n");
		return false;
	}
}


// ***********************************************
// Inicializar arvore binária de quartos
// ***********************************************

tNo* inicializarArvoreBQuartos(){
	//tNo *arv = (tNo*)malloc(sizeof(tNo));
	tNo *arv = NULL;
	return arv;
}

// ***********************************************
// Inserir em arvore binária de quartos
// ***********************************************

bool inserirArvoreBQuartos(tNo* no, Quarto* q){

	if(no == NULL){
		no = (tNo *)malloc(sizeof(tNo));
		no->esq=NULL;
		no->dir=NULL;
		no->conteudo=q;
		printf("%s\n",q->codigo);
     }else{
		printf("%s\n",q->codigo);
		printf("%s\n",no->conteudo->codigo);

		if( strcmp(q->codigo,no->conteudo->codigo)<0 ){	// compara o codigo com o codigo do quarto q esta como conteudo do no
			inserirArvoreBQuartos(no->esq, q);
		}else if(strcmp(q->codigo,no->conteudo->codigo)>0){
			inserirArvoreBQuartos(no->dir, q);
		}
	}
}


// ***********************************************
// Gerar (preencher) arvore binária de quartos
// ***********************************************

bool gerarArvoreBQuartos(tNo* arvQuartos,lista_quartos* lquartos){
	int i;

	if( !verificarQuartosListaVazia(lquartos) ){

		for(i=0;i<=lquartos->fim;i++){		// percorre a arvore
			if( *lquartos->quartos[i].situacao!=NULL ){		// quarto ja foi inicializado
				printf("%p",arvQuartos);
				inserirArvoreBQuartos(arvQuartos,&lquartos->quartos[i]);
			}
		}

		return true;
	}else{
		printf("\nLista vazia! Não é possível criar arvore!\n");
		return false;
	}

}


// ***********************************************
//  Imprimir arvore binária de quartos
// ***********************************************

bool imprimirArvoreBQuartos(tNo* arvQuartos){

	if(arvQuartos!=NULL){
		imprimirArvoreBQuartos(arvQuartos->esq);

		// conteudo - ponteiro Quarto
		imprimirQuarto(arvQuartos->conteudo);

		imprimirArvoreBQuartos(arvQuartos->dir);

		return true;
	} else{
		return false;
	}
}


// ***********************************************
// ***********************************************
