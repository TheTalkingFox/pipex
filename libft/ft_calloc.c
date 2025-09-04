/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:07:14 by apchelni          #+#    #+#             */
/*   Updated: 2024/09/11 23:07:16 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	full_size;
	void	*p;
	char	*byte_p;
	size_t	i;

	full_size = nmemb * size;
	if (size == 0 || (nmemb != 0 && full_size / nmemb != size))
		return (malloc(0));
	p = malloc(full_size);
	if (p == 0)
		return (0);
	byte_p = (char *)p;
	i = 0;
	while (i < full_size)
	{
		byte_p[i] = 0;
		i++;
	}
	return (p);
}
/* 
#include <stdio.h>
#include <string.h>
int	main()
{
	int* arr = (int *)ft_calloc(-1, sizeof(int));
	if (arr == NULL) {
	      printf("Null pointer \n");
	   } else {
	      printf("Address = %p\n", (void*)arr);
	   }
	free(arr);
	int *pointer = (int *)calloc(-1, sizeof(int));
	   if (pointer == NULL) {
	      printf("Null pointer \n");
	   } else {
	      printf("Address = %p", (void*)pointer);
	   }
	   free(pointer);
	   return 0;
} */
