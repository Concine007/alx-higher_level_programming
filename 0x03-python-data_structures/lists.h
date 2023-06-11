#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - si n gl y   l in    k ed  l is  t
 * @n: in te ger
 * @next: poi nt s   to  t h e   n e xt   n o d e
 * Description: si ng l y  l i nk e d   li s t   n o de  st r u c t ur e
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);
int is_palindrome(listint_t **head);

#endif
