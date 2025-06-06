/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevonuk <mevonuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:52:46 by mevonuk           #+#    #+#             */
/*   Updated: 2023/11/07 15:05:46 by mevonuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if the int is lower (2) or uppercase (1) letter
int	ft_isalpha(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (2);
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}
