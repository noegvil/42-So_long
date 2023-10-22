/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:53:29 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/22 21:51:11 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief	Sets the game->cols and game->rows variables and 
 * 	check if the map is rectangular with at least 3 rows.
 * 
 * @param game	Pointer to a structure containing information about the map.
 * @return int	1 if the map is rectangular, 0 if not.
 */

int	check_matrix_structure(t_data	*game)
{
	int		i;

	game->rows = ft_lstsize(game->map_list);
	if (game->rows < 3)
		return (0);
	game->cols = row_len(game->matrix[0]);
	i = 0;
	while (i < game->rows && game->matrix[i][0] != '\0')
	{
		if (row_len(game->matrix[i]) != game->cols)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief 		Checks if a matrix is delimited by '1'.
 * 
 * @param matrix 	The matrix to be checked.
 * @param rows		Number of rows of the matrix to be checked.
 * @param cols 		Number of columns of the matrix to be checked.
 * @return int		1 (if the map is delimited by '1') or 0 (if not).
 */

int	closed_map(char **matrix, int rows, int cols)
{
	int	i;
	int	j;

	j = 0;
	while (j < cols)
	{
		if (matrix[0][j] != '1' || matrix[rows - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (i < rows)
	{
		if (matrix[i][0] != '1' || matrix[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief		Checks that there is only one exit (E), only one player (P),
 * 		at least one collectible (C) and
 * 		that the rest are floor (0) and walls (1)
 * 
 * @param game		Pointer to a structure containing information about the map.
 * @return int		1 (the elements are right) or 0 (if not).
 */

int	elements_inside_map(t_data	*game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->rows - 1)
	{
		j = 1;
		while (j < game->cols - 1)
		{
			if (game->matrix[i][j] == 'P')
				game->count_p++;
			else if (game->matrix[i][j] == 'E')
				game->count_e++;
			else if (game->matrix[i][j] == 'C')
				game->count_c++;
			else if (game->matrix[i][j] != '0' && game->matrix[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (game->count_p != 1 || game->count_e != 1 || game->count_c < 1)
		return (0);
	return (1);
}

/**
 * @brief 		Check that there is at least one valid path
 * 		where the player can find the exit with all collectibles.
 * 
 * @param game		Pointer to a structure containing information about the map.
 * @return int:		1 (there is a valid path) or 0 (if not).
 */

int	check_valid_path(t_data *game)
{
	game->dup_matrix = dup_map(game->matrix, game->rows);
	if (!game->dup_matrix)
		return (0);
	get_coordinates(game, 'P');
	flood_fill(game->dup_matrix, game->p_row, game->p_col);
	if (find_chr(game->dup_matrix, game->rows, 'E'))
		return (0);
	return (1);
}

/**
 * @brief		Calls the necessary functions in order to check 
 * 		if the map meets all the requirements.
 * 
 * @param game		Pointer to a structure containing information about the map.
 * @return char* 	- NULL if the map meets all the requirements.
 * 		- a string with the corresponding error message.
 */

char	*check_map(t_data *game)
{
	char	*error_message;

	error_message = NULL;
	game->list_size = ft_lstsize(game->map_list);
	game->matrix = list_to_matrix(game->map_list, game->list_size);
	if (game->matrix == NULL)
		error_message = "Error: problem creating map\n";
	if (check_matrix_structure(game) == 0)
		error_message = "Error: wrong map structure\n";
	else
	{
		if (closed_map(game->matrix, game->rows, game->cols) == 0)
			error_message = "Error: map not closed\n";
		else
		{
			if (elements_inside_map(game) == 0)
				error_message = "Error: wrong elements\n";
			else
			{
				if (check_valid_path(game) == 0)
					error_message = "Error: invalid road\n";
			}
		}
	}
	return (error_message);
}
