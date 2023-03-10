/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:19:02 by sutku             #+#    #+#             */
/*   Updated: 2023/02/06 12:12:21 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	find_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
