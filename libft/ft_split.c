/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:52:39 by noelgarc          #+#    #+#             */
/*   Updated: 2023/01/13 12:54:21 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_loop(char *str, char c, char **copy_to)
{
	int		n;
	char	*str_start;

	n = 0;
	while (str && *str != '\0')
	{
		if (*str == c)
			str++;
		else
		{
			str_start = str;
			str = ft_strchr(str, c);
			if (copy_to)
			{
				copy_to[n] = ft_substr(str_start, 0, str - str_start);
				if (!copy_to[n])
					return (-1);
			}
			n++;
		}
	}
	return (n);
}

void	free_mem(char **t, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (t[i])
			free(t[i]);
		i++;
	}
	free(t);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		n;

	n = split_loop((char *) s, c, NULL);
	result = ft_calloc(n + 1, sizeof(char **));
	if (!result)
		return (NULL);
	result[n] = NULL;
	if (split_loop((char *) s, c, result) < 0)
	{
		free_mem(result, n);
		return (NULL);
	}
	return (result);
}
