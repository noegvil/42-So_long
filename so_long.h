/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:16:35 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/03 19:25:00 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
// #include "MLX42/include/MLX42/MLX42.h"

typedef struct s_data {
	t_list			*map_list;
	char			**matrix;
	char			**dup_matrix;
	int				list_size;
	int				rows;
	int				cols;
	int				count_p;
	int				count_e;
	int				count_c;
	int				p_row;
	int				p_col;
	int				new_p_row;
	int				new_p_col;
	int				moves;
	mlx_t			*mlx;
	mlx_texture_t	*character_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*object_texture;
	mlx_texture_t	*wall_texture;
	mlx_image_t		*character_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*object_img;
	int32_t			instance_index;
}				t_data;

/* utils */

t_data	*init_game(void);
void	is_error(char *str);
void	check_argv(char *str);
int		row_len(const char *s);
void	final_free(t_data *game);

/* list_utils */

t_list	*create_node(char *line);
t_list	*add_back_list(t_list *to_add, t_list *begin_list);
char	**list_to_matrix(t_list	*list, int rows);
void	free_list(t_list *list);

/* matrix_utils */

char	**dup_map(char **matrix, int rows);
void	get_coordinates(t_data *game, char c);
void	flood_fill(char **matrix, int x, int y);
int		find_chr(char	**matrix, int rows, char c);
void	free_matrix(char **matrix);

/* check */

int		check_matrix_structure(t_data	*game);
int		closed_map(char **matrix, int rows, int cols);
int		elements_inside_map(t_data	*game);
int		check_valid_path(t_data *game);
char	*check_map(t_data *game);

/* map_utils */

t_list	*read_map(char *str);
void	window_config(t_data *game);
void	print_map(t_data *game);

/* events */

void	win_condition(t_data	*game);
void	update_data(t_data	*game, char player, char floor);
void	which_path(t_data	*game);
void	which_event(mlx_key_data_t keydata, void	*param);

#endif