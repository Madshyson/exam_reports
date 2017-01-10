/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 10:02:24 by exam              #+#    #+#             */
/*   Updated: 2016/03/22 10:44:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			isprime(int nbr)
{
	int i;

	i = 2;
	while (i <= nbr / 2)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int			next_prime(int nbr)
{
	nbr++;

	while(!isprime(nbr))
		nbr++;
	return (nbr);
}

int			small_prime(int nbr)
{
	int i;

	i = 2;
	while (i > 1)
	{
		if (isprime(i) && nbr % i == 0)
			return (i);
		i = next_prime(i);
	}
	return (1);
}

void		fprime(int nbr)
{
	while (!isprime(nbr))
	{
		printf("%d*", small_prime(nbr));
		nbr = nbr / small_prime(nbr);
	}
	if (nbr != 1)
		printf("%d", nbr);
}

int			main(int ac, char **av)
{
	if (ac == 2)
	{
		if (atoi(av[1]) == 1)
		{
			printf("1\n");
			return (0);
		}
		else if (atoi(av[1]) <= 0)
		{
			printf("\n");
			return (0);
		}
		fprime(atoi(av[1]));
	}
	printf("\n");
	return (0);
}
