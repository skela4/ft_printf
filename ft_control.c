/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:33:32 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/16 18:49:57 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		copy_in_buff(t_opts *opt, void *s, size_t size)
{
	if (opt->string_pos + size < MAX_BUFF)
	{
		ft_memcpy(&opt->string[opt->string_pos], s, size);
		opt->string_pos += size;
	}
	else
	{
		opt->size += write(1, &opt->string[0], opt->string_pos);
		opt->string_pos = 0;
		if (size < MAX_BUFF)
		{
			ft_memcpy(&opt->string[opt->string_pos], s, size);
			opt->string_pos += size;
		}
		else
		{
			opt->size += write(1, s, size);
		}
	}
}

void		control_padding_left(t_opts *opt)
{
	int		res;
	char	*buff;

	res = 0;
	if (!(opt->fm & FLG_Z))
		buff = (char *)&(opt->g_buff_space);
	else
		buff = (char *)&(opt->g_buff_zero);
	if (!(opt->fm & FLG_M))
	{
		while (opt->width > 0)
		{
			res = opt->width - MAX_BUFF_SIZE;
			if (res < 0)
			{
				copy_in_buff(opt, buff, opt->width);
				opt->width = 0;
			}
			else
			{
				opt->width = res;
				copy_in_buff(opt, buff, MAX_BUFF_SIZE);
			}
		}
	}
}

void		control_precision(t_opts *opt)
{
	int		res;
	char	*buff;

	res = 0;
	buff = (char *)&(opt->g_buff_zero[0]);
	while (opt->prec > 0)
	{
		res = opt->prec - MAX_BUFF_SIZE;
		if (res < 0)
		{
			copy_in_buff(opt, buff, opt->prec);
			opt->prec = 0;
		}
		else
		{
			opt->prec = res;
			copy_in_buff(opt, buff, MAX_BUFF_SIZE);
		}
	}
}

void		control_padding_right(t_opts *opt)
{
	int		res;

	res = 0;
	if ((opt->fm & FLG_M))
	{
		while (opt->width > 0)
		{
			res = opt->width - MAX_BUFF_SIZE;
			if (res < 0)
			{
				copy_in_buff(opt, opt->g_buff_space, opt->width);
				opt->width = 0;
			}
			else
			{
				opt->width = res;
				copy_in_buff(opt, opt->g_buff_space, MAX_BUFF_SIZE);
			}
		}
	}
}
