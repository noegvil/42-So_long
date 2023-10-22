/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:08:41 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/04 22:14:46 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief			Duplicates a matrix (char **) given.
 * 
 * @param matrix	The matrix that is going to be duplicated.
 * @param rows		Number of rows (non null) of the original matrix.
 * @return char**	A pointer to the new matrix.
 */

char	**dup_map(char **matrix, int rows)
{
	int		i;
	char	**dup_matrix;

	dup_matrix = (char **)malloc((rows + 1) * sizeof(char *));
	if (!dup_matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dup_matrix[i] = ft_strdup(matrix[i]);
		if (!dup_matrix[i])
		{
			free_matrix(dup_matrix);
			return (NULL);
		}
		i++;
	}
	dup_matrix[rows] = NULL;
	return (dup_matrix);
}

/**
 * @brief		Get the coordinates of a searched object (char).
 * 
 * @param game	Pointer to a structure containing information about the map.
 * @param c		The object (char) for which the coordinates are needed.
 */

void	get_coordinates(t_data *game, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->matrix[i][j] == c)
			{
				game->p_row = i;
				game->p_col = j;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief			Recursive algorithm that determines the area connected 
 * 					to a given cell in a multi-dimensional array
 * 
 * @param matrix	Multi-dimensional array where the path will be searched
 * @param x			Rows coordinates
 * @param y 		Columns coordinates
 */

void	flood_fill(char **matrix, int x, int y)
{
	if (matrix[x][y] == 'E')
	{
		matrix[x][y] = '1';
		return ;
	}
	if (matrix[x][y] != '1')
	{
		matrix[x][y] = '1';
		flood_fill(matrix, x - 1, y);
		flood_fill(matrix, x + 1, y);
		flood_fill(matrix, x, y - 1);
		flood_fill(matrix, x, y + 1);
	}
}

/**
 * @brief			Searchs the first occurrence of a char in a matrix.
 * 
 * @param matrix	The matrix to be inspected.
 * @param rows		Number of rows of the matrix.
 * @param c			The char to be searched.
 * @return int 		1 (if the char has been found), 0 (if not).
 */

int	find_chr(char	**matrix, int rows, char c)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (ft_strchr(matrix[i], c))
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief			Frees completely a multi-dimensional array (char **)
 * 
 * @param matrix	The char **array to be freed
 */

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix != NULL)
	{
		i = 0;
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}
