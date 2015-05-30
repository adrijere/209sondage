/*
** 209sondage.hpp for 209sondage in /home/mathon_j/rendu/209sondage
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri May 29 19:49:38 2015 Jérémy MATHON
** Last update Sat May 30 10:23:46 2015 Jérémy MATHON
*/

#ifndef __209SONDAGE_HPP_
# define __209SONDAGE_HPP_

#define	USAGE		"Wrong parameters. USAGE : ./209sondage [size of population] [size of sample] [percentage of favorable vote]\n"

#define	USAGE_VOTE	"Wrong parameters : percentage of favorable vote must be between 0 and 100. USAGE : ./209sondage [size of population] [size of sample] [percentage of favorable vote]\n"

#define	USAGE_NULL	"Wrong parameters : size of population and size of sample must be upper than 0. USAGE : ./209sondage [size of population] [size of sample] [percentage of favorable vote]\n"

#define	USAGE_POP	"Wrong parameters : size of population must be higher than size of sample. USAGE : ./209sondage [size of population] [size of sample] [percentage of favorable vote]\n"

#include	<iostream>
#include	<cmath>
#include	<cstdlib>
#include	<cstdio>

class	Sondage
{
public:
  int		_population;
  int		_echantillon;
  double	_vote;

  Sondage() {};
  ~Sondage() {};
};

void	main_loop(Sondage *);
int	init_var(Sondage *, char **);
void	print_result(Sondage *, double, double, double);
double	calc_intc95(double);
double	calc_intc99(double);
double	calc_variance(Sondage *);

#endif /* !__209SONDAGE_HPP_ */
