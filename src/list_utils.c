/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:16:12 by noelgarc          #+#    #+#             */
/*   Updated: 2023/10/20 14:45:51 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief			Create a new node object
 * 
 * @param line		String that will go into the node content
 * @return t_list* 	Pointer to the new node
 */

t_list	*create_node(char *line)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = line;
	new->next = NULL;
	return (new);
}

/**
 * @brief				Adds a node to the end of a given linked list
 * 
 * @param to_add		The node that will be added
 * @param begin_list	The list to which the node is to be added
 * @return t_list* 
 */

t_list	*add_back_list(t_list *to_add, t_list *begin_list)
{
	t_list	*end_node;

	if (begin_list == NULL)
		begin_list = to_add;
	else
	{
		end_node = ft_lstlast(begin_list);
		end_node->next = to_add;
	}
	return (begin_list);
}

/**
 * @brief			Creates a char **matrix from a linked list
 * 
 * @param list		Pointer to the list used
 * @param rows		Number of elements of the linked list (not null)
 * @return char** 	The matrix created or NULL if it fails
 */

char	**list_to_matrix(t_list	*list, int rows)
{
	t_list	*current;
	int		i;
	char	**matrix;

	current = list;
	if (rows < 3)
		return (NULL);
	matrix = (char **)malloc((rows + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (current != NULL && i < rows)
	{
		matrix[i] = ft_strdup(current->content);
		if (!matrix[i])
		{
			free_matrix(matrix);
			return (NULL);
		}
		current = current->next;
		i++;
	}
	matrix[rows] = NULL;
	return (matrix);
}

/**
 * @brief			Frees a linked list
 * 
 * @param list		Pointer to the linked list that will be free
 */

void	free_list(t_list *list)
{
	t_list	*temp;

	temp = list;
	if (list == NULL)
		return ;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp->content);
		free(temp);
	}
}
