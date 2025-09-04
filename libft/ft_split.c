/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:51:59 by apchelni          #+#    #+#             */
/*   Updated: 2024/09/25 16:53:24 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int	i;
	int	num;
	int	string;

	i = 0;
	num = 0;
	string = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !string)
		{
			string = 1;
			num++;
		}
		else if (s[i] == c)
			string = 0;
		i++;
	}
	return (num);
}

static char	*copy_str(char const *s, char *start)
{
	char	*str;
	int		length;
	int		i;

	length = s - start;
	i = 0;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	while (i < length)
	{
		str[i] = start[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**free_mem(char **res, int i)
{
	while (i-- > 0)
		free (res[i]);
	free (res);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	char	*start;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!res)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			res[i] = copy_str(s, start);
			if (!res[i])
				return (free_mem(res, i));
			i++;
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}
/* 
#include <stdio.h>
int	main()
{
	char *s = "aa";
	char del = 'a';
	char **res;
	int i;

	i = 0;
	res = ft_split(s, del);
	if (!*res)
		printf ("NULL");
	while (res[i] != 0)
	{
		printf("%s\n", res[i]);
		free (res[i]);
		i++;
	}
	free (res);
} */
