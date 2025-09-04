/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:23:27 by apchelni          #+#    #+#             */
/*   Updated: 2024/09/12 23:23:30 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	i;
	char	*dest;

	length = 0;
	i = 0;
	if (!*s)
	{
		dest = ft_calloc(1, sizeof(char));
		return (dest);
	}
	while (s[length])
		length++;
	dest = ft_calloc(length + 1, sizeof(char));
	if (dest == 0)
		return (0);
	while (length--)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>
int	main()
{
	char src[] = "";
	char *dest = strdup(src);

	printf("%s\n", dest);
	char src2[] = "";
	char *dest2 = ft_strdup(src2);

	printf("%s", dest2);
} */