/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:09:22 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/16 19:33:24 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_arg_d(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& (opt->len_spec[2] == 'd' || opt->len_spec[2] == 'i'))
		opt->nb.uni_nb.intnb = (intmax_t)va_arg(*ap, int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'h'
	&& (opt->len_spec[2] == 'd' || opt->len_spec[2] == 'i'))
		opt->nb.uni_nb.intnb = (short int)va_arg(*ap, int);
	else if (opt->len_spec[0] == 'h' && opt->len_spec[1] == 'h'
	&& (opt->len_spec[2] == 'd' || opt->len_spec[2] == 'i'))
		opt->nb.uni_nb.intnb = (signed char)va_arg(*ap, int);
	else if (opt->len_spec[0] == 'l' && opt->len_spec[1] == 'l'
	&& (opt->len_spec[2] == 'd' || opt->len_spec[2] == 'i'))
		opt->nb.uni_nb.intnb = (intmax_t)va_arg(*ap, long long int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'z'
	&& (opt->len_spec[2] == 'd' || opt->len_spec[2] == 'i'))
		opt->nb.uni_nb.intnb = (intmax_t)va_arg(*ap, size_t);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'l'
	&& (opt->len_spec[2] == 'd' || opt->len_spec[2] == 'i'))
		opt->nb.uni_nb.intnb = (intmax_t)va_arg(*ap, long int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& (opt->len_spec[2] == 'D' || opt->len_spec[2] == 'I'))
		opt->nb.uni_nb.intnb = (intmax_t)va_arg(*ap, long int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'j'
	&& (opt->len_spec[2] == 'd' || opt->len_spec[2] == 'i'))
		opt->nb.uni_nb.intnb = (intmax_t)va_arg(*ap, intmax_t);
}

void	get_arg_o(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& opt->len_spec[2] == 'o')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'h'
	&& opt->len_spec[2] == 'o')
		opt->nb.uni_nb.uintnb = (unsigned short int)va_arg(*ap, unsigned int);
	else if (opt->len_spec[0] == 'h' && opt->len_spec[1] == 'h'
	&& opt->len_spec[2] == 'o')
		opt->nb.uni_nb.uintnb = (unsigned char)va_arg(*ap, unsigned int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'l'
	&& opt->len_spec[2] == 'o')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (opt->len_spec[0] == 'l' && opt->len_spec[1] == 'l'
	&& opt->len_spec[2] == 'o')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned long long int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'z'
	&& opt->len_spec[2] == 'o')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, size_t);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& opt->len_spec[2] == 'O')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'j'
	&& opt->len_spec[2] == 'o')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, uintmax_t);
}

void	get_arg_u(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& opt->len_spec[2] == 'u')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'h'
	&& opt->len_spec[2] == 'u')
		opt->nb.uni_nb.uintnb = (unsigned short int)va_arg(*ap, unsigned int);
	else if (opt->len_spec[0] == 'h' && opt->len_spec[1] == 'h'
	&& opt->len_spec[2] == 'u')
		opt->nb.uni_nb.uintnb = (unsigned char)va_arg(*ap, unsigned int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'l'
	&& opt->len_spec[2] == 'u')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (opt->len_spec[0] == 'l' && opt->len_spec[1] == 'l'
	&& opt->len_spec[2] == 'u')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned long long int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'z'
	&& opt->len_spec[2] == 'u')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, size_t);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& opt->len_spec[2] == 'U')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (opt->len_spec[0] == 0 && opt->len_spec[1] == 'j'
	&& opt->len_spec[2] == 'u')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, uintmax_t);
}

void	get_arg_c(t_opts *opt, va_list *ap)
{
	if (opt->len_spec[0] == 0 && opt->len_spec[1] == 0
	&& opt->len_spec[2] == 'c')
		opt->nb.uni_nb.uintnb = (uintmax_t)va_arg(*ap, void *);
}
