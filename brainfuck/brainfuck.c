/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 10:17:46 by exam              #+#    #+#             */
/*   Updated: 2016/04/12 11:32:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bf.h"

void		ft_putfuck(char c)
{
	write(1, &c, 1);
}

char		*brain_foreplay(void)
{
	char *fuck;
	int it;

	fuck = malloc(sizeof(char) * 2048);
	it = 0;
	while (it < 2048)
	{
		fuck[it] = 0;
		it++;
	}
	return (fuck);
}

int			go_to(int strpos, char *str, char bf_val)
{
	int i;
	int nb;

	nb = 1;
	i = strpos;
	if (str[strpos] == '[' && bf_val == 0)
	{
		while (str[i] != ']' || nb != 0)
		{
			if (str[i + 1] == '[')
				nb++;
			if (str[i + 1] == ']')
				nb--;
			i++;
		}
	}
	else if (str[strpos] == ']' && bf_val != 0)
	{
		while (str[i] != '[' || nb != 0)
		{
			if (str[i - 1] == ']')
				nb++;
			if (str[i - 1] == '[')
				nb--;
			i--;
		}
	}
	return (i);
}

void		brainfuck(char *bf_tab, char *str, int i, int j)
{
	while (str[j] != '\0' && j < 4097)
	{
		if (str[j] == '>')
			i++;
		else if (str[j] == '<')
			i--;
		else if (str[j] == '+')
			bf_tab[i] += 1;
		else if (str[j] == '-')
			bf_tab[i] -= 1;
		else if (str[j] == '.')
			ft_putfuck(bf_tab[i]);
		else if (str[j] == '[' || str[j] == ']')
			j = go_to(j, str, bf_tab[i]);
		j++;
	}
}

int			main(int ac, char **av)
{
	char	*fuck;
	int		it;
	int		that;

	it = 0;
	that = 0;
	if (ac == 2)
	{
		fuck = brain_foreplay();
		brainfuck(fuck, av[1], it, that);
		free(fuck);
	}
	else
		ft_putfuck('\n');
	return (0);
}
