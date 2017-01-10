/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 10:02:09 by exam              #+#    #+#             */
/*   Updated: 2016/01/19 11:11:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_get_mult(int nbr)
{
	int i;
	long int mult;

	i = 0;
	mult = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		mult = mult * 10;
	}
	return(mult / 10);
}

int		ft_alloc_size(int nbr, int isn, int i)
{
	i = i + isn;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return(i);
}

char	*ft_itoa(int nbr)
{
	char *str;
	int i;
	int len;
	int isn;
	int mult;

	str = NULL;
	i = 0;
	isn = 0;
	if (nbr == 0)
		return("0");
	else if (nbr == -2147483648)
		return("-2147483648");
	else if (nbr < 0)
	{
		isn = 1;
		nbr = nbr * -1;
	}
	len = ft_alloc_size(nbr, isn, i);
	mult = ft_get_mult(nbr);
	str = malloc(sizeof(char) * len + 1);
	if (isn)
	{
		str[0] = '-';
		i++;
	}
	while (i < len)
	{
		str[i] = '0' + (nbr / mult);
		nbr = nbr % mult;
		i++;
		mult = mult / 10;
	}
	str[i] = '\0';
	return(str);
	free(str);
}
