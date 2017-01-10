/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:18:40 by exam              #+#    #+#             */
/*   Updated: 2015/12/15 10:38:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_bwsearch(char *str, int pos, char c)
{
	pos--;
	while (pos >= 0)
	{
		if(str[pos] == c)
			return (0);
		pos--;
	}
		return (1);
}

void	ft_inter(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str1[i] != '\0')
	{
		while (str2[j] != '\0')
		{
			if (str1[i] == str2[j] && ft_bwsearch(str1, i, str1[i]) &&
				ft_bwsearch(str2, j, str2[j]))
				ft_putchar(str1[i]);
			j++;
		}
		j = 0;
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
