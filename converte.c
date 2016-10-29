#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char cpf[11];
//String de tamanho 12, ou seja de 0 a 11
// última posição reservado para \0

    int conv; //Destino do valor a ser convertido
    int i=0;
//Tamanho da string digitada será guardada nessa variável


    printf("Digite seu CPF\n");
    gets (cpf);  //Valor digitado será armazenado

    conv=atoi(cpf); //Convertemos CPF para inteiro,
                           //e seu valor vai para conv

   printf("CPF em inteiro: %i\n",conv);

system("pause");
}
