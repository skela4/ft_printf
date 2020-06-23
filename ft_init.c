/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:09:22 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/17 09:55:32 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_array(t_opts *opt)
{
	int			i;

	i = 0;
	while (i < 4096)
	{
		opt->g_buff_zero[i] = '0';
		opt->g_buff_space[i] = ' ';
		i++;
	}
}

void			init_flag_mask(t_opts *opt, int pos, int size)
{
	opt->fm = 0;
	opt->width = 0;
	opt->prec = -1;
	opt->size_nb = 0;
	opt->nb.m = 0;
	opt->nb.p = 0;
	opt->size = size;
	opt->string_pos = pos;
	opt->s = NULL;
	ft_memset(&opt->len_spec, 0, NBYTE_LENGTH_SPECIFIER);
}
