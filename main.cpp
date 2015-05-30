/*
** main.cpp for main in /home/mathon_j/rendu/209sondage
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri May 29 19:49:26 2015 Jérémy MATHON
** Last update Sat May 30 10:22:08 2015 Jérémy MATHON
*/

#include	"209sondage.hpp"

void		main_loop(Sondage *sondage)
{
  double	intc95 = 0;
  double	intc99 = 0;
  double	var = 0.000464;

  var = calc_variance(sondage);
  intc95 = calc_intc95(var);
  intc99 = calc_intc99(var);
  print_result(sondage, intc95, intc99, var);
}

int		init_var(Sondage *sondage, char **av)
{
  sondage->_population = atoi(av[1]);
  sondage->_echantillon = atoi(av[2]);
  sondage->_vote = atof(av[3]);
  if (sondage->_vote > 100 || sondage->_vote < 0)
    return (1);
  if (sondage->_population < 0 || sondage->_echantillon < 0)
    return (2);
  if (sondage->_echantillon > sondage->_population)
    return (3);
  return (0);
}

int		main(int ac, char **av)
{
  Sondage	sondage;
  int		check;

  if (ac != 4)
    {
      std::cout << USAGE << std::endl;
      return (1);
    }
  if ((check = init_var(&sondage, av)) != 0)
    {
      if (check == 1)
	std::cout << USAGE_VOTE << std::endl;
      if (check == 2)
	std::cout << USAGE_NULL << std::endl;
      if (check == 3)
	std::cout << USAGE_POP << std::endl;
      return (1);
    }
  main_loop(&sondage);
  return (0);
}
