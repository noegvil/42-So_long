/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:44:09 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/22 22:06:24 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief	Initialises the values of a t_data structure.
 * 
 * @return	A pointer to the structue (t_data *).
 */

t_data	*init_game(void)
{
	t_data	*game;

	game = (t_data *)malloc(sizeof(t_data));
	game->map_list = NULL;
	game->matrix = NULL;
	game->dup_matrix = NULL;
	game->list_size = 0;
	game->rows = 0;
	game->cols = 0;
	game->count_p = 0;
	game->count_e = 0;
	game->count_c = 0;
	game->p_row = 0;
	game->p_col = 0;
	game->new_p_row = 0;
	game->new_p_col = 0;
	game->moves = 0;
	return (game);
}

/**
 * @brief	Displays an error message for the standard error output.
 * 
 * @param str	The error message.
 */

void	is_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

/**
 * @brief	Check if the argument that represents the path of a file
 * is valid for the program.
 * 
 * @param st	The path of a file.
 */

void	check_argv(char *str)
{
	if (ft_strncmp(str, "maps/", 5) != 0)
		is_error("Error: map file must be inside maps/ directory\n");
	if (ft_strncmp(&str[(ft_strlen(str) - 4)], ".ber", 4) != 0)
		is_error("Error: file extension must be <.ber> \n");
}

/**
 * @brief	Frees the elements that has been dinamically allocated.
 * 
 * @param game	Pointer to a structure containing information about the map.
 */

void	final_free(t_data *game)
{
	if (game)
	{
		if (game->map_list)
			free_list(game->map_list);
		if (game->matrix)
			free_matrix(game->matrix);
		if (game->dup_matrix)
			free_matrix(game->dup_matrix);
		free (game);
	}
}

/**
 * @brief	Gives the len of a string that can be ended by '\n'.
 * 
 * @param s	The string.
 * @return int	The len of the string.
 */

int	row_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}
