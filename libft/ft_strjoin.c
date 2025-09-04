/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:20:02 by apchelni          #+#    #+#             */
/*   Updated: 2024/09/19 23:20:23 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_length(char const *s)
{
	size_t	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length])
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (count_length(s1) == 0 && count_length(s2) == 0)
	{
		result_str = ft_calloc(1, sizeof(char));
		if (!result_str)
			return (0);
		return (result_str);
	}
	result_str = ft_calloc((count_length(s1) + count_length(s2) + 1),
			sizeof(char));
	if (!result_str)
		return (0);
	while (++i < count_length(s1))
		result_str[i] = s1[i];
	while (++j < count_length(s2))
		result_str[i++] = s2[j];
	return (result_str);
}
/* 
#include <stdio.h>
int main ()
{
	printf("%s", ft_strjoin("", ""));
} */