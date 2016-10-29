/* www.GeeksBR.com */

/* Implementa��o de �rvore bin�ria */

#include <stdio.h>
#include <stdlib.h>
#include "quarto.c"

/* Cada n� armazena tr�s informa��es:
   nesse caso um n�mero (num),
   ponteiro para sub�rvore � direita (sad)
   e ponteiro para sub�rvore � esquerda (sae).*/
typedef struct tree
{
  Tipopaciente *pontpaciente;
  struct tree* sad;
  struct tree* sae;
} Tree;

/* A estrutura da �rvore � representada por um ponteiro
   para o n� raiz. Com esse ponteiro, temos acesso aos
   demais n�s. */

/* Fun��o que cria uma �rvore */
Tree* createTree()
{
  /* Uma �rvore � representada pelo endere�o do n� raiz,
     essa fun��o cria uma �rvore com nenhum elemento,
     ou seja, cria uma �rvore vazia, por isso retorna NULL. */
  return NULL;
}

/* Fun��o que verifica se uma �rvore � vazia */
int treeIsEmpty(Tree* t)
{
  /* Retorna 1 se a �rvore for vazia e 0 caso contr�rio */
  return t == NULL;

}

/* Fun��o que mostra a informa��o da �rvore */
void showTree(Tree* t)
{
  /* Essa fun��o imprime os elementos de forma recursiva */

  printf("<"); /* nota��o para organizar na hora de mostrar os elementos */
  if(!treeIsEmpty(t)) /* se a �rvore n�o for vazia... */
  {

    printf("%s ", &t->pontpaciente.codigo); /* mostra a raiz */
    showTree(t->sae); /* mostra a sae (sub�rvore � esquerda) */
    showTree(t->sad); /* mostra a sad (sub�rvore � direita) */
  }
  printf(">"); /* nota��o para organizar na hora de mostrar os elementos */
}

/* Fun��o que insere um dado na �rvore */
void insertTree(Tree* t, Tipopaciente* ppac)
{
  /* Essa fun��o insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    t = (Tree*)malloc(sizeof(Tree)); /* Aloca mem�ria para a estrutura */
    t->sae = NULL; /* Sub�rvore � esquerda � NULL */
    t->sad = NULL; /* Sub�rvore � direita � NULL */
    t->Paciente = Pac; /* Armazena a informa��o */
  } else {

    int num;
    char cod [10];
    cod = Pac->codigo;

      if(Pac->codigo < (*t)->pontpaciente.codigo) /* Se o n�mero for menor ent�o vai pra esquerda */
    {
      /* Percorre pela sub�rvore � esquerda */
      insertTree(&(*t)->sae, Pac);
    }
    if(var1 > (*t)->var2) /* Se o n�mero for maior ent�o vai pra direita */
    {
      /* Percorre pela sub�rvore � direita */
      insertTree(&(*t)->sad, Pac);
    }
  }
}

/* Fun��o que verifica se um elemento pertence ou n�o � �rvore */
int isInTree(Tree* t, int num) {

  if(treeIsEmpty(t)) { /* Se a �rvore estiver vazia, ent�o retorna 0 */
    return 0;
  }

  /* O operador l�gico || interrompe a busca quando o elemento for encontrado */
  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}

int main()
{
  Tree* t = createTree(); /* cria uma �rvore */

  insertTree(&t, 12); /* insere o elemento 12 na �rvore */
  insertTree(&t, 15); /* insere o elemento 15 na �rvore */
  insertTree(&t, 10); /* insere o elemento 10 na �rvore */
  insertTree(&t, 13); /* insere o elemento 13 na �rvore */

  showTree(t); /* Mostra os elementos da �rvore em pr�-ordem */

  if(treeIsEmpty(t)) /* Verifica se a �rvore est� vazia */
  {
    printf("\n\nArvore vazia!!\n");
  } else {
    printf("\n\nArvore NAO vazia!!\n");
  }

  if(isInTree(t, 15)) { /* Verifica se o n�mero 15 pertence a �rvore */
    printf("\nO numero 15 pertence a arvore!\n");
  } else {
     printf("\nO numero 15 NAO pertence a arvore!\n");
  }

  if(isInTree(t, 22)) { /* Verifica se o n�mero 22 pertence a �rvore */
    printf("\nO numero 22 pertence a arvore!\n\n");
  } else {
     printf("\nO numero 22 NAO pertence a arvore!\n\n");
  }

  free(t); /* Libera a mem�ria alocada pela estrutura �rvore */

  return 0;
}
