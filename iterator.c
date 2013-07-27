#include	"list.h"

void		literator(list *list, void(*ptr)(void*))
{
  link		*tmp;

  tmp = list->init;
  while (tmp)
    {
      (*ptr)(tmp->content);
      tmp = tmp->next;
    }
}

void		lreverse_iterator(list *list, void(*ptr)(void*))
{
  link		*tmp;

  tmp = list->end;
  while (tmp)
    {
      (*ptr)(tmp->content);
      tmp = tmp->prev;
    }
}

void		lshow(list *list)
{
  link		*tmp;

  tmp = list->init;
  while (tmp)
    {
      printf("%s\n", tmp->content);
      tmp = tmp->next;
    }
}

void		lrshow(list *list)
{
  link		*tmp;

  tmp = list->end;
  while (tmp)
    {
      printf("%s\n", tmp->content);
      tmp = tmp->prev;
    }
}
