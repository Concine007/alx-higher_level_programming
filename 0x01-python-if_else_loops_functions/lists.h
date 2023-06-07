#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - sin  gl y  li nk ed l is t
 * @n: in t e g er
 * @next: po i n ts t o th e n ex t   no de
 *
 * Description: si ng l y li nk ed li st nod e st ruc t u re
 *
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);
listint_t *insert_node(listint_t **head, int number);

#endif
