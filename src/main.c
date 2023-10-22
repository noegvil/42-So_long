/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:41:10 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/20 18:46:08 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @related			Basic MLX functions:
 * 
 * mlx_init:		 Initialize and run a new window instance
 * mlx_loop:		 Keep the window open as long as a shutdown is not requested
 * mlx_terminate:	 Destroy and clean up all images and mlx resources
 * mlx_close_window: Notifies MLX that it should stop rendering and exit the
 * 					 main loop
 */

/**
 * @name			ft_game
 * @brief			Manages the game including deleting images and
 * 					textures as well as using mlx_terminate to finish
 * 
 * @param game	Pointer to a structure containing information about the map
 */

void	ft_game(t_data	*game)
{
	window_config(game);
	print_map(game);
	mlx_key_hook(game->mlx, &which_event, game);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->character_img);
	mlx_delete_image(game->mlx, game->exit_img);
	mlx_delete_image(game->mlx, game->floor_img);
	mlx_delete_image(game->mlx, game->wall_img);
	mlx_delete_image(game->mlx, game->object_img);
	mlx_delete_texture(game->character_texture);
	mlx_delete_texture(game->exit_texture);
	mlx_delete_texture(game->floor_texture);
	mlx_delete_texture(game->wall_texture);
	mlx_delete_texture(game->object_texture);
	mlx_terminate(game->mlx);
	final_free(game);
}

int32_t	main(int argc, char **argv)
{
	t_data	*game;
	char	*error_message;

	if (argc != 2)
		is_error("Error: must have 2 arguments\n");
	else
		check_argv(argv[1]);
	game = init_game();
	game->map_list = read_map(argv[1]);
	if (!game->map_list)
	{
		final_free(game);
		is_error("Error: unable to read file\n");
	}
	error_message = check_map(game);
	if (error_message != NULL)
	{
		final_free(game);
		is_error(error_message);
	}
	else
		ft_game(game);
	return (0);
}
