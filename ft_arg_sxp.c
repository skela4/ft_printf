/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_sxp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:09:22 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/16 19:31:16 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_arg_s(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& opt->len_spec[2] == 's')
		opt->s = (char *)va_arg(*ap, char *);
}

void	get_arg_x(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& (opt->len_spec[2] == 'x' || opt->len_spec[2] == 'X'))
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'h'
	&& (opt->len_spec[2] == 'x' || opt->len_spec[2] == 'X'))
		opt->nb.uni_nb.uintnb = (unsigned short int)va_arg(*ap, unsigned int);
	else if (opt->len_spec[0] == 'h' && opt->len_spec[1] == 'h'
	&& (opt->len_spec[2] == 'x' || opt->len_spec[2] == 'X'))
		opt->nb.uni_nb.uintnb = (unsigned char)va_arg(*ap, unsigned int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'l'
	&& (opt->len_spec[2] == 'x' || opt->len_spec[2] == 'X'))
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (opt->len_spec[0] == 'l' && opt->len_spec[1] == 'l'
	&& (opt->len_spec[2] == 'x' || opt->len_spec[2] == 'X'))
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned long long int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'z'
	&& (opt->len_spec[2] == 'x' || opt->len_spec[2] == 'X'))
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, size_t);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'j'
	&& (opt->len_spec[2] == 'x' || opt->len_spec[2] == 'X'))
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, uintmax_t);
}

void	get_arg_p(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& opt->len_spec[2] == 'p')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, void *);
}
