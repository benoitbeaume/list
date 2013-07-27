#include	"list.h"
#include	"main.h"

void		affiche(void *test)
{
  printf("%s\n", test);
}

int		main(int ac, char **av)
{
  list		*list;

  (void)ac;
  lcreate(&list);
  while (++av && *av)
    lpush_back(&list, *av, sizeof(*av));
  literator(list, &affiche);
  printf("Argument(s) : %d\n", (int)lsize(list));
  ldestroy(list);
  return 0;
}
