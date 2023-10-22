/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:52:11 by noelgarc          #+#    #+#             */
/*   Updated: 2023/01/12 16:13:29 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *S)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((S[i] >= 9 && S[i] <= 13) || S[i] == 32)
	{
		i++;
	}
	if (S[i] == '+' || S[i] == '-')
	{
		if (S[i] == '-')
			sign = -1;
		i++;
	}
	while (S[i] >= '0' && S[i] <= '9')
	{
		num = num * 10 + S[i] - 48;
		i++;
	}
	return (sign * num);
}
