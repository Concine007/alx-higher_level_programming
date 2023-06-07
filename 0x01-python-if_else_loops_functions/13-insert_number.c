#include "lists.h"

/**
 * insert_node - Ins er t s  a  n u mbe r   int o  a  so rt e d s in gly
 * @head: A p oi n t e r t h e   he a d   o f   th e   l i n ked   l i st.
 * @number: T h e  n u m b e r   t o   i n s er  t. 
 * Return: I f  t h e   f un c t i o n  f a i ls   -   N UL L.
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *node = *head, *new;

new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);
new->n = number;
if (node == NULL || node->n >= number)
{
new->next = node;
*head = new;
return (new);
}
while (node && node->next && node->next->n < number)
node = node->next;
new->next = node->next;
node->next = new;
return (new);
}
