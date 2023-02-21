#include <stdio.h>

typedef struct Item {
	int dd;
	char n;
}Item;

int main() {
	Item in[52];	
	int c[13], e[13], u[13], p[13];
	for (int i = 0; i < 13; i++) {
		c[i] = 0; e[i] = 0; u[i] = 0; p[i] = 0;
	}
	for (int i = 0; scanf("%2d %c", &in[i].dd, &in[i].n) != EOF; i++) {
		if (in[i].n == 'C')
			c[in[i].dd-1] = 1;
		else if (in[i].n == 'E')
			e[in[i].dd-1] = 1;
		else if (in[i].n == 'U')
			u[in[i].dd-1] = 1;
		else if (in[i].n == 'P')
			p[in[i].dd-1] = 1;
	}
	int cf = 0, ef = 0, uf = 0, pf = 0;
	for (int i = 0; i < 13; i++) {
		if (c[i] == 0)
			cf++;
		if (e[i] == 0)
			ef++;
		if (u[i] == 0)
			uf++;
		if (p[i] == 0)
			pf++;
	}
	printf("%d\n%d\n%d\n%d\n", cf, ef, uf, pf);
	return 0;
}

/* Raciocínio:
 *
 * Primeiramente defino um tipo "Item" que carrega as informações das cartas (naipe e número). Com isso, instancio um array
 * do tipo Item (in) de 52 posições (número máximo dado pelo exercício) para ler as informações de entrada, crio também quatro
 * vetores de 13 posições, todas iniciadas em valor 0, os quais servirão de gabarito para cada naipe. Deste modo, por meio de um
 * laço (for) verifico o naipe da carta lida e inserida no array in, para cada carta mudo o valor na posição (dd) para 1 na respectiva
 * posição (dd) no vetor correspondente ao naipe.
 * Por fim, por meio de um laço (for) faço a varredura de todos os vetores booleanos com o auxilio de um contador para cada um deles,
 * contando o número de posições do vetor que ainda estão com o valor 0 (ou seja, falta uma carta com aquele valor).
 */