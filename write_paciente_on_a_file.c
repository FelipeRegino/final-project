/* Fiz esse exemplo de codigo para escrever os dados de um paciente em um arquivo texto e para importar
os dados de um arquivo texto para uma estrutura tipo paciente. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char nome[20], plano[20], escrita[20];
int codigo;

struct paciente {
	char nome[20];
	int codigo;
	char plano[20];
};
typedef struct paciente Paciente;

void leitura(){
  char url[]="pacientes.txt";
  FILE *arq;
  arq = fopen(url, "r+");

  if (arq == NULL) printf("Não foi possivel abrir o arquivo!\n");
  else
    /*Exemplo: passando os dados para uma estrutura */
    while ((fscanf(arq, "%s %d %s\n", nome, &codigo, plano))!= EOF ){
        Paciente* p = (Paciente* )malloc(sizeof(Paciente));
		    strcpy(p->nome, nome);
        p->codigo = codigo;
        strcpy(p->plano, plano);
        printf("%s %d %s\n",p->nome, p->codigo, p->plano );
    }
    fclose(arq);
}

void escrever(){
  char url[]="arqv.txt", op;
  FILE *arq = fopen(url, "r+");
  if (arq == NULL){
    printf("Não foi possivel abrir o arquivo!\n");
  }
  else
  fseek (arq, 0, SEEK_END);
  //while (fscanf(arq,)!= EOF) {
    /* code */
  /*Exemplo de escrita */
  while (1) {
    printf("\nDeseja entrar com dados? y/n: ");
    scanf("%c", &op);

    switch (op) {
      case 'y':
        printf("\nEscreva o nome do paciente: ");
        scanf("\n%s", nome );
        printf("Escreva o codigo do paciente: ");
        scanf("\n%d", &codigo );
        printf("Escreva o plano paciente: ");
        scanf("\n%s", plano );
        fprintf(arq, "%s %d %s\n", nome, codigo, plano );
        break;
      case 'n':
        printf("Fechando arquivo!\n");
        fclose(arq);
        exit(0);
        break;
      default:
        printf("opcao invalida\n");
        break;
    }
    }
}

void main(){
  leitura();
  escrever();
}

/* O codigo irá abir o arquivo pceientes.txt onde cada paciente ocupa uma linha do arquivo, onde o codigo ira buscar pela ocorrencia
de uma string um int e outra string */
