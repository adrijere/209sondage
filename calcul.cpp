/*
** calcul.cpp for calcul in /home/mathon_j/rendu/209sondage
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Sat May 30 10:15:37 2015 Jérémy MATHON
** Last update Sat May 30 10:22:04 2015 Jérémy MATHON
*/

#include	"209sondage.hpp"

void		print_result(Sondage *sondage, double intc95, double intc99, double variance)
{
  double	a, a1, b, b1;

  a = (sondage->_vote - intc95);
  if (a < 0)
    a = 0;
  a1 = (sondage->_vote + intc95);
  if (a1 > 100.0)
    a1 = 100;
  b = (sondage->_vote - intc99);
  if (b < 0)
    b = 0;
  b1 = (sondage->_vote + intc99);
  if (b1 > 100.0)
    b1 = 100;
  printf ("taille de la population :\t%d\n", sondage->_population);
  printf ("taille de l'echantillon :\t%d\n", sondage->_echantillon);
  printf ("resultat du sondage :\t\t%0.2f%%\n", sondage->_vote);
  printf ("variance estimee :\t\t%f\n", variance);
  printf ("intervalle de confiance a 95%% :\t[%0.2f%% ; %0.2f%%]\n", a, a1);
  printf ("intervalle de confiance a 99%% :\t[%0.2f%% ; %0.2f%%]\n", b, b1);
}

double		calc_intc95(double variance)
{
  return (((2 * 1.96) * sqrt(variance)) / 2 * 100);
}

double		calc_intc99(double variance)
{
  return (((2 * 2.58) * sqrt(variance)) / 2 * 100);
}

double		calc_variance(Sondage *sondage)
{
  double	var_b = 0, p = 0, pop, ech;
  double	res = 0;

  pop = sondage->_population;
  ech = sondage->_echantillon;

  p = sondage->_vote / 100;
  var_b = (p * (1 - p));

  res = ((var_b / ech) * ((pop - ech) / (pop - 1)));
  return (res);
}
