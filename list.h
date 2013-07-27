#ifndef		__LIST_H__
# define	__LIST_H__

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

typedef struct	link
{
  void		*content;
  struct link	*next;
  struct link	*prev;
}		link;

typedef struct	list
{
  link		*init;
  link		*ptr;
  link		*end;
  size_t	size;
}		list;

/* LIST.C */

void		lcreate(list**);
void		ldestroy(list*);
size_t		lsize(list*);

/* ITERATOR.C */

void		literator(list*, void(*)(void*));
void		lreverse_iterator(list*, void(*)(void*));

void		lshow(list*);
void		lrshow(list*);

/* MODIFIER.C */

void		lpush_front(list**, void*, size_t);
void		lpush_back(list**, void*, size_t);

void		lpop_front(list**);
void		lpop_back(list**);

#endif		/* __LIST_H__ */
