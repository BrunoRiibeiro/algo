#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct Node {
	Item data;
	struct Node *next;
}Node;
typedef struct Head {
	Node *begin, *end;
}Head;

int create_stack(Head *h) {
	h->begin = NULL;
	h->end = NULL;
	return 1;
}

int push(Head *h, Item e) {
	Node *new_node = malloc(sizeof(Item));
	if (new_node == NULL) return 0;
	new_node->data = e;
	new_node->next = h->begin;
	h->begin = new_node;
	return 1;
}

void pull(Head *h) {
	h->begin = h->begin->next;
}

int sum_stack(Head *h) {
	int sum = 0;
	Node *aux = h->begin;
	while (aux) {
		sum += aux->data;
		aux = aux->next;
	}
	return sum;
}

int main() {
	int n;
	Head h;
	create_stack(&h);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0)
			pull(&h);
		else
			push(&h, x);
	}
	printf("%d\n", sum_stack(&h));
	return 0;
}

/* Raciocínio:
 *
 * Primeiramente, por não saber o número exato de ordens corretas, criei uma estrutura de nó. Devido a ter sempre que retirar o
 * último elemento adicionado, organizei esses nós por meio de uma estrutura de pilha (FiLo - first in, last out).
 * Desta maneira, foi só criar um laço (for) para rodar as (n) leituras dadas no exercício, e verificar primeiro se o número (x)
 * dito pelo chefe foi '0', caso positivo, por meio da função (pull), desempilho o último elemento, caso contrário, por meio da
 * função (push), empilho o número (x) dito pelo chefe.
 * Por fim, imprimo na soma dos elementos restantes da pilha, por meio da função (sum_stack), a qual por um simples laço (while),
 * vai incrementando o acumulador (sum) a cada nó que percorre.
 */
