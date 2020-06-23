/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diou_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:09:22 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/16 19:05:19 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_d(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[2] == 'd' || opt->len_spec[2] == 'i'
	|| opt->len_spec[2] == 'D')
		g_array_function[0][0]['d'].fp_arg(opt, ap);
	if (opt->nb.uni_nb.intnb < 0)
	{
		opt->nb.m = 1;
		opt->width -= 1;
		opt->nb.uni_nb.intnb = opt->nb.uni_nb.intnb * -1;
	}
	else if (opt->nb.uni_nb.intnb >= 0 && (opt->fm & FLG_P))
	{
		opt->nb.p = 1;
		opt->width -= 1;
	}
	create_number(opt, 10, 'd');
	g_spec['d'].fp_control(opt);
}

void	ft_o(t_opts *opt, va_list *ap)
{
	g_array_function[0][0]['o'].fp_arg(opt, ap);
	opt->nb.base = 8;
	opt->nb.charc = 'o';
	create_unumber(opt, 8, 'o');
	g_spec['o'].fp_control(opt);
}

void	ft_u(t_opts *opt, va_list *ap)
{
	g_array_function[0][0]['u'].fp_arg(opt, ap);
	opt->nb.base = 10;
	opt->nb.charc = 'u';
	create_unumber(opt, 10, 'u');
	g_spec['u'].fp_control(opt);
}
