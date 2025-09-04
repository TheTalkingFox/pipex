/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:07:48 by apchelni          #+#    #+#             */
/*   Updated: 2024/09/03 18:07:50 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
	{
		length++;
	}
	return (length);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	const char *s;
	s = "-";
	printf("Org.:%zu\n", strlen(s));
	printf("New.:%d\n", ft_strlen(s));
}*/
//SIZE_T TO DO