/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:09:22 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/17 09:33:04 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	inline	int	multen(int a, int b)
{
	return ((a << 3) + (b << 1));
}

void				search_length(unsigned char **fmt, t_opts *opt)
{
	int			i;

	i = 1;
	ft_memset(&opt->len_spec, 0, NBYTE_LENGTH_SPECIFIER);
	while (**fmt && g_length[**fmt])
	{
		if (i < 0 || **fmt > opt->len_spec[1])
		{
			i = 1;
			ft_memset(&opt->len_spec, 0, NBYTE_LENGTH_SPECIFIER);
		}
		if (**fmt >= opt->len_spec[1] && i >= 0)
		{
			opt->len_spec[i] = **fmt;
			--i;
		}
		++(*fmt);
	}
}

void				search_prec(unsigned char **fmt, t_opts *opt, va_list *ap)
{
	++(*fmt);
	opt->prec = 0;
	if (**fmt && **fmt == '*')
	{
		opt->prec = va_arg(*ap, int);
		++(*fmt);
	}
	else
	{
		while (**fmt && g_valid_num[**fmt])
		{
			opt->prec = (multen(opt->prec, opt->prec)) + (**fmt - '0');
			++(*fmt);
		}
	}
}

void				search_width(unsigned char **fmt, t_opts *opt, va_list *ap)
{
	opt->width = 0;
	if (**fmt && **fmt == '*')
	{
		opt->width = va_arg(*ap, int);
		if (opt->width < 0)
		{
			opt->fm ^= FLG_M;
			opt->width *= -1;
		}
		++(*fmt);
	}
	else
	{
		while (**fmt && g_valid_num[**fmt])
		{
			opt->width = (multen(opt->width, opt->width)) + (**fmt - '0');
			++(*fmt);
		}
	}
}

void				search_flags(unsigned char **fmt, t_opts *opt)
{
	while (**fmt && g_flags[**fmt])
	{
		opt->fm |= g_flags[**fmt];
		++(*fmt);
	}
}
