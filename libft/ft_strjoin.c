/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:25:50 by noelgarc          #+#    #+#             */
/*   Updated: 2022/12/27 12:26:08 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s3;

	len_s1 = ft_strlen(s1);
	len_s3 = len_s1 + ft_strlen(s2) + 1;
	s3 = (char *)malloc((len_s3) * sizeof(char));
	if (!s3)
	{
		return (NULL);
	}
	ft_strlcpy((char *)s3, (char *)s1, len_s3);
	ft_strlcpy((char *)&s3[len_s1], (char *)s2, len_s3);
	return (s3);
}
