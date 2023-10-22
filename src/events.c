/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:09:34 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/04 02:02:24 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief			Checks the win condition when the player reach 'E'.
 * 
 * @param game		Pointer to a structure containing information about the map.
 */

void	win_condition(t_data	*game)
{
	game->moves++;
	ft_putstr_fd("total moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" \n", 1);
	if (game->count_c == 0)
		ft_putstr_fd("Congratulations!\n", 1);
	else
		ft_putstr_fd("KO!\n", 1);
	mlx_close_window(game->mlx);
}

/**
 * @brief			Update necessary data to continue the game and then 
 * 					print the map again.
 * 
 * @param game		Pointer to a structure containing information about the map.
 * @param player	One of the two characters that will be exchanged
 * @param floor 	The other of the two characters that will be exchanged
 */

void	update_data(t_data	*game, char player, char floor)
{
	game->matrix[game->new_p_row][game->new_p_col] = player;
	game->matrix[game->p_row][game->p_col] = floor;
	game->p_row = game->new_p_row;
	game->p_col = game->new_p_col;
	game->moves++;
	ft_putstr_fd("total moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" \n", 1);
	print_map(game);
}

/**
 * @brief			Selects the path to be followed by the program based on the
 * 					content of the new coordinates.
 * 
 * @param game		Pointer to a structure containing information about the map.
 */

void	which_path(t_data	*game)
{
	if (game->matrix[game->new_p_row][game->new_p_col] == '1')
		return ;
	if (game->matrix[game->new_p_row][game->new_p_col] == '0')
		update_data(game, 'P', '0');
	if (game->matrix[game->new_p_row][game->new_p_col] == 'C')
	{
		update_data(game, 'P', '0');
		game->count_c--;
	}
	if (game->matrix[game->new_p_row][game->new_p_col] == 'E')
		win_condition(game);
}

/**
 * @brief			Callback function used to handle keypresses.
 * 
 * @param keydata 	The callback data, contains info on key, action,...
 * @param param		Used to connect to the original t_data *game structure.
 */

void	which_event(mlx_key_data_t keydata, void *param)
{
	t_data	*game;

	game = param;
	game->new_p_row = game->p_row;
	game->new_p_col = game->p_col;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->new_p_col--;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->new_p_col++;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->new_p_row++;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->new_p_row--;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	which_path (game);
}
