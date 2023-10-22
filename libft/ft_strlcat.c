/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:17:31 by noelgarc          #+#    #+#             */
/*   Updated: 2022/12/21 14:45:02 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	t;
	size_t	i;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	t = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && t < size - 1)
	{
		dest[t] = src[i];
		t++;
		i++;
	}
	dest[t] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
