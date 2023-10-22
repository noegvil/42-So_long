/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:48:08 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/22 22:10:28 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @name	read_map
 * @brief	Reads a file and stores each line in a linked list
 * 
 * @param	str: Path to a file location
 * @return 	t_list*: The linked list that contents the original map lines
 */

t_list	*read_map(char *str)
{
	char	*line;
	int		fd;
	t_list	*begin_list;
	t_list	*to_add;

	begin_list = NULL;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		to_add = create_node(line);
		begin_list = add_back_list(to_add, begin_list);
		line = get_next_line(fd);
	}
	close(fd);
	return (begin_list);
}

/**
 * @name	window_config
 * @brief	- Initialize and run a new window instance with 'mlx_init'
 * 	-	Load a PNG file into a buffer with 'mlx_load_png'
 * 	-	Converts a given texture to an image with 'mlx_texture_to_image'
 * 
 * @param game	Pointer to a structure containing information about the map
 */

void	window_config(t_data *game)
{
	game->mlx = mlx_init(32 * game->cols, 32 * game->rows, "so_long", true);
	game->character_texture = mlx_load_png("./textures/character.png");
	game->exit_texture = mlx_load_png("./textures/exit.png");
	game->floor_texture = mlx_load_png("./textures/floor.png");
	game->object_texture = mlx_load_png("./textures/object.png");
	game->wall_texture = mlx_load_png("./textures/wall.png");
	game->character_img = mlx_texture_to_image(game->mlx,
			game->character_texture);
	game->exit_img = mlx_texture_to_image(game->mlx, game->exit_texture);
	game->floor_img = mlx_texture_to_image(game->mlx, game->floor_texture);
	game->wall_img = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->object_img = mlx_texture_to_image(game->mlx, game->object_texture);
}

/**
 * @name	set_instance_image
 * @brief	Depending on the element found (0, P, C, E), this function:
 * 	-	Sets the depth of the instance with 'mlx_set_instance_depth'
 * 	-	Draws a new instance of an image with 'mlx_image_to_window'
 * 
 * @param game	Pointer to a structure containing information about the map
 * @param i	Current row position
 * @param j	Current column position
 */

void	set_instance_image(t_data *game, int i, int j)
{
	game->instance_index = mlx_image_to_window(game->mlx,
			game->floor_img, j * 32, i * 32);
	if (game->matrix[i][j] == 'P')
	{
		mlx_set_instance_depth(&(game->floor_img->instances
			[game->instance_index]), 1);
		mlx_image_to_window(game->mlx, game->character_img, j * 32, i * 32);
	}
	else if (game->matrix[i][j] == 'C')
	{
		mlx_set_instance_depth(&(game->floor_img->instances
			[game->instance_index]), 1);
		mlx_image_to_window(game->mlx, game->object_img, j * 32, i * 32);
	}
	else if (game->matrix[i][j] == 'E')
	{
		mlx_set_instance_depth(&(game->floor_img->instances
			[game->instance_index]), 1);
		mlx_image_to_window(game->mlx, game->exit_img, j * 32, i * 32);
	}
}

/**
 * @name	print_map
 * @brief	Goes through each position of the map (game->matrix) and prints the
 * corresponding image of the element.
 * 
 * @param game	Pointer to a structure containing information about the map
 */

void	print_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->matrix[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall_img, j * 32, i * 32);
			else if (game->matrix[i][j] != '1')
				set_instance_image(game, i, j);
			j++;
		}
		i++;
	}
}
