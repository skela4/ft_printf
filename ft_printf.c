/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:09:22 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/17 09:55:32 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		control_condition(t_opts *opt)
{
	if (((opt->fm & FLG_Z) && (opt->fm & FLG_M)) || (opt->prec >= 0
				&& (opt->fm & FLG_Z) && opt->len_spec[2] != 's')
			|| (opt->prec >= 0 && (opt->fm & FLG_Z)))
	{
		if (opt->len_spec[2] != 'c' && opt->len_spec[2] != '%')
			opt->fm ^= FLG_Z;
	}
	if ((opt->len_spec[2] == 'd' || opt->len_spec[2] == 'i')
			&& (opt->fm & FLG_H))
		opt->fm ^= FLG_H;
	if (((opt->fm & FLG_S) && (opt->fm & FLG_P)) || (opt->len_spec[2] == '%'
				&& (opt->fm & FLG_S)) || (opt->len_spec[2] == 'o'
				&& (opt->fm & FLG_S)) || (opt->len_spec[2] == 'u'
				&& (opt->fm & FLG_S)) || (opt->len_spec[2] == 'x'
				&& (opt->fm & FLG_S)) || ((opt->len_spec[2] == 'x'
					|| opt->len_spec[2] == 'X') && (opt->fm & FLG_S))
			|| (opt->len_spec[2] == 'c' && (opt->fm & FLG_S)))
		opt->fm ^= FLG_S;
	if ((opt->len_spec[2] == 'u' && (opt->fm & FLG_P))
	|| (opt->len_spec[2] == 'x' && (opt->fm & FLG_P))
	|| ((opt->len_spec[2] == 'x' || opt->len_spec[2] == 'X')
	&& (opt->fm & FLG_P)))
		opt->fm ^= FLG_P;
}

static	void	control_flags(t_opts *opt)
{
	control_condition(opt);
	if ((opt->len_spec[2] == '%' || opt->len_spec[2] == 'c') && opt->prec >= 0)
		opt->prec = -1;
}

static	void	get_flags(unsigned char **fmt, t_opts *opt, va_list *ap)
{
	opt->fm = 0;
	while (**fmt && (g_flags[**fmt] || g_valid_num[**fmt] || **fmt == '.'
				|| g_length[**fmt] || **fmt == '*'))
	{
		(g_flags[**fmt]) ? search_flags(fmt, opt) : 0;
		(g_valid_num[**fmt] || **fmt == '*') ? search_width(fmt, opt, ap) : 0;
		(**fmt == '.' || **fmt == '*') ? search_prec(fmt, opt, ap) : 0;
		(g_length[**fmt]) ? search_length(fmt, opt) : 0;
	}
	if (**fmt)
	{
		opt->len_spec[2] = **fmt;
		control_flags(opt);
		if (g_spec[**fmt].fp_spec && g_spec[opt->len_spec[2]].fp_spec)
			g_spec[opt->len_spec[2]].fp_spec(opt, ap);
		else
		{
			if (((opt->fm & FLG_S) && (opt->fm & FLG_P)) || (opt->fm & FLG_S))
				opt->fm ^= FLG_S;
			g_spec['c'].fp_spec(opt, ap);
		}
		*fmt += 1;
	}
	else
		copy_in_buff(opt, opt->tmp, opt->size_tmp);
}

int				ft_printf(const char *restrict format, ...)
{
	char		*fmt;
	t_opts		opt;
	va_list		ap;

	fmt = NULL;
	va_start(ap, format);
	opt.string_pos = 0;
	init_flag_mask(&opt, 0, 0);
	init_array(&opt);
	if (!format)
		return (0);
	while ((fmt = ft_strchr(format, '%')))
	{
		opt.size_tmp = fmt - format;
		opt.tmp = (char *)format;
		fmt += 1;
		get_flags((unsigned char**)&fmt, &opt, &ap);
		init_flag_mask(&opt, opt.string_pos, opt.size);
		format += (fmt - format);
	}
	va_end(ap);
	if (*format)
		copy_in_buff(&opt, (void *)format, ft_strlen((char *)format));
	opt.size += write(1, &opt.string[0], opt.string_pos);
	return (opt.size);
}
