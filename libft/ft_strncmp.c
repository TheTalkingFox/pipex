/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:25:43 by apchelni          #+#    #+#             */
/*   Updated: 2024/09/07 22:25:46 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	us1;
	unsigned char	us2;

	i = 0;
	while (i < n)
	{
		us1 = s1[i];
		us2 = s2[i];
		if (us1 != us2)
			return (us1 - us2);
		if (us1 == '\0')
			break ;
		i++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>
int	main()
{
	printf("%d", strncmp("test\200", "test\0", 6));
	printf("%d", ft_strncmp("test\200", "test\0", 6));
} */