/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:02:27 by exam              #+#    #+#             */
/*   Updated: 2016/01/26 11:02:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	*ft_getword(char *s, int swd)
{
	int i;
	int j;
	char *word;

	word = NULL;
	i = swd;
	j = 0;
	while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		i++;
	word = malloc(sizeof(char) * (i - swd) + 1);
	i = swd;
	while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
	{
		word[j] = s[i];
		i++;
		j++;
	}
	word[j] = s[swd -1];
	j++;
	word[j] = '\0';
	return(word);
}

char	*revwstr(char *s)
{
	int i;
	int j;
	int wdstart;
	char *ret;
	char *wd;

	i = 0;
	j = 0;
	ret = NULL;
	while (s[i] != '\0')
		i++;
	ret = malloc((sizeof(char) * i) + 1);
	while (i > 0)
	{
		while(s[i - 1] != ' ' && s[i - 1] != '\t' && i != 0)
			i--;
		wdstart = i;
		wd = ft_getword(s, wdstart);
		i = 0;
		while (wd[i] != '\0')
		{
			ret[j] = wd[i];
			i++;
			j++;
		}
		i = wdstart - 1;
	}
	ret[j] = '\0';
	return(ret);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_putstr(revwstr(av[1]));
	ft_putchar('\n');
	return(0);
}
