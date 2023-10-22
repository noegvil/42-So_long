/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:19:17 by noelgarc          #+#    #+#             */
/*   Updated: 2023/03/29 18:04:38 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**split_in_two(char *str, char c)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = init_splitted(ft_strlen(str));
	while (splitted && str[i])
	{
		splitted[0][i] = str[i];
		splitted[0][i + 1] = '\0';
		if (str[i] == c)
		{
			splitted[1] = ft_strdup(str + i + 1);
			if (splitted[1] == NULL)
				return (free_splitted(splitted));
			break ;
		}
		i++;
	}
	return (splitted);
}

char	**init_splitted(size_t len)
{
	char	**splitted;

	splitted = (char **) malloc(3 * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	splitted[0] = (char *) malloc((len + 1) * sizeof(char));
	if (splitted[0] == NULL)
		return (free_splitted(splitted));
	splitted[0][0] = '\0';
	splitted[1] = NULL;
	splitted[2] = NULL;
	return (splitted);
}

char	**free_splitted(char **splitted)
{
	int	i;

	i = 0;
	if (splitted != NULL)
	{
		while (splitted[i] != NULL)
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
	}
	return (NULL);
}
