/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_spec_cs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:10:25 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/16 19:01:26 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_control_prefix_padding_left(t_opts *opt, unsigned char spec)
{
	if ((opt->fm & FLG_S) && (!opt->nb.m && !opt->nb.p) && opt->width-- >= 0)
	{
		copy_in_buff(opt, " ", 1);
		opt->fm ^= FLG_S;
	}
	((opt->fm & FLG_Z) && (opt->nb.m || opt->nb.p)) ? signed_number(opt) : 0;
	if ((opt->fm & FLG_H) && opt->b_nb[opt->start] != 48 && g_px[spec])
	{
		(!(opt->fm & FLG_M)) ? opt->width -= 2 : 0;
		if ((opt->fm & FLG_Z))
		{
			copy_in_buff(opt, g_p[spec], 2);
			opt->fm ^= FLG_H;
		}
	}
	else if (g_px[spec] && spec == 'p' && !(opt->fm & FLG_M))
	{
		opt->width -= 2;
		if ((opt->fm & FLG_Z))
		{
			copy_in_buff(opt, g_p[spec], 2);
			opt->fm ^= FLG_H;
		}
	}
}

static	void	ft_control_prefix_precision(t_opts *opt, unsigned char spec)
{
	if ((opt->fm & FLG_S) && (!opt->nb.m && !opt->nb.p) && opt->prec >= 0)
	{
		copy_in_buff(opt, " ", 1);
		opt->fm ^= FLG_S;
		--opt->width;
	}
	((opt->prec >= 0) && (opt->nb.m || opt->nb.p)) ? signed_number(opt) : 0;
	if ((opt->fm & FLG_H) && opt->b_nb[opt->start] != 48 && g_px[spec])
	{
		opt->width -= 2;
		if ((opt->prec >= 0))
		{
			copy_in_buff(opt, g_p[spec], 2);
			opt->fm ^= FLG_H;
		}
	}
	else if (g_px[spec] && spec == 'p')
	{
		(!(opt->fm & FLG_M)) ? opt->width -= 2 : 0;
		if ((opt->prec >= 0))
		{
			copy_in_buff(opt, g_p[spec], 2);
			opt->fm ^= FLG_H;
		}
	}
}

void			ft_control_c(t_opts *opt)
{
	int			octet;

	octet = 1;
	if (opt->b_nb[opt->start] == 48 && opt->prec >= 0)
		opt->size_nb = 0;
	opt->width = opt->width - octet;
	opt->width = (opt->width < 0) ? 0 : opt->width;
	if (opt->prec >= 0)
	{
		opt->prec = opt->prec - 1;
		opt->prec = (opt->prec < 0) ? 0 : opt->prec;
		opt->width -= opt->prec;
	}
	copy_in_buff(opt, opt->tmp, opt->size_tmp);
	ft_control_prefix_padding_left(opt, opt->len_spec[2]);
	control_padding_left(opt);
	ft_control_prefix_precision(opt, opt->len_spec[2]);
	control_precision(opt);
	copy_in_buff(opt, &(opt->nb.uni_nb.uintnb), octet);
	control_padding_right(opt);
}

void			ft_control_s(t_opts *opt)
{
	if (opt->prec >= 0 && opt->prec <= (int)opt->size_nb)
		opt->size_nb = opt->prec;
	else
		opt->prec = opt->size_nb;
	opt->width = opt->width - opt->size_nb;
	opt->width = (opt->width < 0) ? 0 : opt->width;
	if (opt->prec >= 0)
	{
		opt->prec = opt->prec - opt->size_nb;
		opt->prec = (opt->prec < 0) ? 0 : opt->prec;
		opt->width -= opt->prec;
	}
	copy_in_buff(opt, opt->tmp, opt->size_tmp);
	ft_control_prefix_padding_left(opt, opt->len_spec[2]);
	control_padding_left(opt);
	ft_control_prefix_precision(opt, opt->len_spec[2]);
	control_precision(opt);
	if (opt->s)
		copy_in_buff(opt, opt->s, opt->size_nb);
	else
		copy_in_buff(opt, "(null)", opt->size_nb);
	control_padding_right(opt);
}
