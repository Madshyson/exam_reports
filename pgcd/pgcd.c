/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:45:03 by exam              #+#    #+#             */
/*   Updated: 2015/12/15 11:30:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_checkdiv(int nb, int divres, int div)
{
	if ((divres * div) == nb)
		return (1);
	return (0);
}

int		ft_findpgcd(int nb1, int nb2, int pgcd)
{
	while (pgcd > 1)
	{
		if (ft_checkdiv(nb1, (nb1 / pgcd), pgcd) && ft_checkdiv(nb2, (nb2 / pgcd), pgcd))
			return (pgcd);
		pgcd--;
	}
	return (pgcd);
}

int		ft_pgcd(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (ft_findpgcd(nb1, nb2, nb2));
	else if (nb2 > nb1)
		return (ft_findpgcd(nb1, nb2, nb1));
	else if (nb1 == nb2 && nb1 != 0 && nb2 != 0)
		return (nb1);
	else
		return (-1);
}

int		main(int argc, char **argv)
{
	int nb1;
	int nb2;
	int pgcd;
	if (argc == 3)
	{
		nb1 = atoi(argv[1]);
		nb2 = atoi(argv[2]);
		pgcd = ft_pgcd(nb1, nb2);
		if (pgcd == -1)
		{
			printf("\n");
			return (0);
		}
		printf("%d", pgcd); 
	}
	printf("\n");
	return (0);
}
