/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 08:50:56 by lgaume            #+#    #+#             */
/*   Updated: 2023/11/19 08:55:36 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (s--)
		ft_putchar_fd(*s, fd);
}
