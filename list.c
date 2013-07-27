#include	"list.h"

void		lcreate(list **list)
{
  *list = malloc(sizeof(*list));
  (*list)->ptr = NULL;
  (*list)->init = NULL;
  (*list)->end = NULL;
  (*list)->size = 0;
}

void		ldestroy(list *list)
{
  link		*tmp;
  link		*tmp2;

  tmp = list->init;
  while (tmp)
    {
      tmp2 = tmp->next;
      free(tmp->content);
      free(tmp);
      tmp = tmp2;
    }
  free(list);
}

size_t		lsize(list *list)
{
  return list->size;
}
