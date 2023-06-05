#include "lists.h"

/**
 * check_cycle - c he cks  i f a link e d li st con t ain s a cy cl e
 * @list: lin ke d  lis t  to  che ck
 * Return: 1 i f th e  lis t h as  a cy cl e , 0  i f  it   do e s n 't
 */
int check_cycle(listint_t *list)
{
listint_t *s = list;
listint_t *f = list;

if (!list)
return (0);
while (s && f && f->next)
{
s = s->next;
f = f->next->next;
if (s == f)
return (1);
}
return (0);
}
