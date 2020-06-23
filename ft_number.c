/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:11:02 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/16 19:47:26 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	inline	int	remain(uintmax_t n, int base)
{
	return (n % base);
}

void				signed_number(t_opts *opt)
{
	if (opt->nb.p)
	{
		copy_in_buff(opt, "+", 1);
		opt->nb.p = 0;
		if (opt->fm & FLG_S)
			opt->fm ^= FLG_S;
	}
	else if (opt->nb.m)
	{
		copy_in_buff(opt, "-", 1);
		opt->nb.m = 0;
		if (opt->fm & FLG_S)
			opt->fm ^= FLG_S;
	}
}

void				create_number(t_opts *opt, int base, unsigned char spec)
{
	uintmax_t	n;
	uintmax_t	nb;
	int			i;

	n = opt->nb.uni_nb.intnb;
	i = MAX_BUFF - 1;
	while ((nb = n / base))
	{
		if (spec == 'x')
			opt->b_nb[i] = g_hex[remain(n, base)];
		else if (spec == 'X')
			opt->b_nb[i] = g_upcase_hex[remain(n, base)];
		else
			opt->b_nb[i] = g_dec[remain(n, base)];
		n = nb;
		--i;
	}
	if (spec == 'x')
		opt->b_nb[i] = g_hex[remain(n, base)];
	else if (spec == 'X')
		opt->b_nb[i] = g_upcase_hex[remain(n, base)];
	else
		opt->b_nb[i] = g_dec[remain(n, base)];
	opt->start = i;
	opt->size_nb = MAX_BUFF - opt->start;
}

void				create_unumber(t_opts *opt, int base, unsigned char spec)
{
	uintmax_t	n;
	uintmax_t	nb;
	int			i;

	n = opt->nb.uni_nb.intnb;
	i = MAX_BUFF - 1;
	while ((nb = n / base))
	{
		if (base == 16 && (spec == 'x' || spec == 'p'))
			opt->b_nb[i] = g_hex[remain(n, base)];
		else if (base == 16 && spec == 'X')
			opt->b_nb[i] = g_upcase_hex[remain(n, base)];
		else
			opt->b_nb[i] = g_dec[remain(n, base)];
		n = nb;
		--i;
	}
	if (base == 16 && (spec == 'x' || spec == 'p'))
		opt->b_nb[i] = g_hex[remain(n, base)];
	else if (base == 16 && spec == 'X')
		opt->b_nb[i] = g_upcase_hex[remain(n, base)];
	else
		opt->b_nb[i] = g_dec[remain(n, base)];
	opt->start = i;
	opt->size_nb = MAX_BUFF - opt->start;
}
