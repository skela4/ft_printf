/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csxp_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:09:22 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/16 19:05:19 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[2] == 'x' || opt->len_spec[2] == 'X')
	{
		g_array_function[0][0]['x'].fp_arg(opt, ap);
		opt->nb.base = 16;
		if (opt->len_spec[2] == 'x')
			create_unumber(opt, 16, 'x');
		else
			create_unumber(opt, 16, 'X');
		g_spec[opt->len_spec[2]].fp_control(opt);
	}
}

void	ft_c(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[2] == 'c' || opt->len_spec[2] == 'C'
		|| (opt->len_spec[1] == 'l' && opt->len_spec[2] == 'c'))
	{
		g_array_function[0][0]['c'].fp_arg(opt, ap);
		opt->nb.base = 10;
		create_unumber(opt, 10, 'c');
		g_spec['c'].fp_control(opt);
	}
	else
	{
		opt->nb.uni_nb.uintnb = opt->len_spec[2];
		create_unumber(opt, 10, 'c');
		g_spec['c'].fp_control(opt);
	}
}

void	ft_s(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[1] == 0 && opt->len_spec[2] == 's')
	{
		g_array_function[0][0]['s'].fp_arg(opt, ap);
		if (opt->s)
			opt->size_nb = ft_strlen(opt->s);
		else
			opt->size_nb = 6;
		g_spec['s'].fp_control(opt);
	}
}

void	ft_p(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[2] == 'p')
		if (!(opt->fm & FLG_H))
			opt->fm ^= FLG_H;
	g_array_function[0][0]['p'].fp_arg(opt, ap);
	opt->nb.base = 16;
	create_unumber(opt, 16, 'x');
	g_spec[opt->len_spec[2]].fp_control(opt);
}
