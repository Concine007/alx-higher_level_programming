#include "lists.h"

listint_t *reverse_listint(listint_t **head);
int is_palindrome(listint_t **head);

/**
 * reverse_listint - Re v  ers e s  a   s in g l   y- li n ke d  lis ti nt_t
 * @head: A  poi n t e r  to t h e st  a rti n g n ode  of th e li st to
 * Return: A p   oi nte r   t o t he  h ead  o f  th e   r e v e rsed
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *node = *head, *next, *prev = NULL;

while (node)
{
next = node->next;
node->next = prev;
prev = node;
node = next;
}
*head = prev;
return (*head);
}

/**
 * is_palindrome - Ch eck s if  a sin gly  li nk edl ist i s a p ali ndr ome.
 * @head: A poin te r  to  t he  h ead   o f  t he li nke d li st.
 * Return: I f t he l ink ed l ist  i s  no t  a p al in dro m e - 0.
 */
int is_palindrome(listint_t **head)
{
listint_t *t, *r, *m;
size_t s = 0, x;

if (*head == NULL || (*head)->next == NULL)
return (1);
tmp = *head;
while (t)
{
s++;
t = t->next;
}
t = *head;
for (x = 0; x < (s / 2) - 1; x++)
t = t->next;
if ((s % 2) == 0 && t->n != t->next->n)
return (0);
t = t->next->next;
r = reverse_listint(&t);
m = r;
t = *head;
while (r)
{
if (t->n != r->n)
return (0);
t = t->next;
r = r->next;
}
reverse_listint(&m);
return (1);
}
