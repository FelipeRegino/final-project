#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char cpf[11];
//String de tamanho 12, ou seja de 0 a 11
// �ltima posi��o reservado para \0

    int conv; //Destino do valor a ser convertido
    int i=0;
//Tamanho da string digitada ser� guardada nessa vari�vel


    printf("Digite seu CPF\n");
    gets (cpf);  //Valor digitado ser� armazenado

    conv=atoi(cpf); //Convertemos CPF para inteiro,
                           //e seu valor vai para conv

   printf("CPF em inteiro: %i\n",conv);

system("pause");
}
