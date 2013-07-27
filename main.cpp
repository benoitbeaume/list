#include	<iostream>
#include	<list>

using namespace	std;

int		main(int ac, char **av)
{
  list<string>	tmp;
  int		i;

  static_cast<void>(ac);
  while (++av && *av)
    {

      if (i == 1)
	{
	  i = -1;
	  tmp.push_front(*av);
	}
      else
	tmp.push_back(*av);
      i++;
   }
  for (list<string>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    cout << *it << endl;
  tmp.pop_front();
  tmp.pop_front();
  tmp.push_front("test");
  for (list<string>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    cout << *it << endl;
  return 0;
}
