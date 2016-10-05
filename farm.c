#include <stdio.h>

struct famarcia {
	char codigo[2];
	char local[2];
	char* medicamentos;
};

struct medicamentos {
	char codigo[10];
	int qtd;
	float id;
	char nome[30];
	char tipo[1];
	char lote[4];
	char validade[8];
};

int main(){
	return 0;
}
