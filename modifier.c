#include	"list.h"
#include	"main.h"

void		lpush_front(list **list, void *add, size_t mem)
{
  link		*new;

  (*list)->ptr = (*list)->init;
  if ((new = malloc(sizeof(*new))))
    {
      if ((new->content = malloc(mem)))
	{
	  memcpy(new->content, add, mem);
	  new->next = (*list)->ptr;
	  new->prev = NULL;
	  if ((*list)->ptr)
	    (*list)->ptr->prev = new;
	  (*list)->ptr = new;
	  if (!(*list)->end)
	    (*list)->end = new;
	  (*list)->init = new;
	}
      (*list)->size++;
    }
}

void		lpush_back(list **list, void *add, size_t mem)
{
  link		*new;

  (*list)->ptr = (*list)->end;
  if ((new = malloc(sizeof(*new))))
    {
      if ((new->content = malloc(mem)))
	{
	  memcpy(new->content, add, mem);
	  new->prev = (*list)->ptr;
	  new->next = NULL;
	  if ((*list)->ptr)
	    (*list)->ptr->next = new;
	  if (!(*list)->init)
	    (*list)->init = new;
	  (*list)->end = new;
	}
      (*list)->size++;
    }
}

void		lpop_front(list **list)
{
  if (!(*list)->init)
    return;
  if ((*list)->init->next)
    {
      (*list)->ptr = (*list)->init;
      (*list)->init = (*list)->ptr->next;
      if ((*list)->ptr->next)
	(*list)->ptr->next->prev = NULL;
      free((*list)->ptr->content);
      free((*list)->ptr);
    }
  else
    {
      free((*list)->init->content);
      free((*list)->init);
      (*list)->size--;
      (*list)->ptr = NULL;
      (*list)->init = NULL;
      (*list)->end = NULL;
    }
  (*list)->size--;
}

void		lpop_back(list **list)
{
  if (!(*list)->end)
    return;
  if ((*list)->end->prev)
    {
      (*list)->ptr = (*list)->end;
      (*list)->end = (*list)->ptr->prev;
      if ((*list)->ptr->prev)
	(*list)->ptr->prev->next = NULL;
      free((*list)->ptr->content);
      free((*list)->ptr);
    }
  else
    {
      free((*list)->end->content);
      free((*list)->end);
      (*list)->size--;
      (*list)->ptr = NULL;
      (*list)->init = NULL;
      (*list)->end = NULL;
    }
  (*list)->size--;
}
