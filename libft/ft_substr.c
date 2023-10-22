/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:04:47 by noelgarc          #+#    #+#             */
/*   Updated: 2023/01/13 12:06:00 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*str;
	size_t	len_to;
	size_t	len_s;

	len_to = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	else if (len_s - start < len)
		len_to = len_s - start + 1;
	else
		len_to = len + 1;
	str = (char *)malloc((len_to) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy (str, (char *)&s[start], len_to);
	return (str);
}
