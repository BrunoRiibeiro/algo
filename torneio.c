#include <stdio.h>

int main() {
	int v = 0;
	for (int i = 0; i < 6; i++) {
		char r;
		scanf(" %c", &r);
		if (r == 'V') v++;
	}
	switch (v) {
		case 5 ... 6:
			printf("%d\n", 1); break;
		case 3 ... 4:
			printf("%d\n", 2); break;
		case 1 ... 2:
			printf("%d\n", 3); break;
		default:
			printf("%d\n", -1); break;
	}
	return 0;
}

/* Raciocínio:
 *
 * Por se tratarem de um número de entradas pré-estabelecidas e constantes, criei um laço (for) rodar as 6 leituras necessárias
 * dos resultados das partidas, caso o resultado seja uma vitória (entrada = 'V') incremento a variável (v) em uma unidade.
 * Por fim, por meio de um (switch case) imprimo o grupo do atleta de acordo com o renge de vitórias por ele acumuladas em (v).
 */
