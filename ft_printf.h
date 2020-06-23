/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:39:46 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/17 09:33:47 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

# define FLG_M 1
# define FLG_P 2
# define FLG_S 4
# define FLG_H 8
# define FLG_Z 16
# define NBYTE_LENGTH_SPECIFIER 4
# define BUFF_SIZE 6
# define MAX_BUFF 4096
# define MAX_BUFF_SIZE 4096

typedef union		u_nb
{
	intmax_t		intnb;
	uintmax_t		uintnb;
}					t_nb;

typedef struct		s_number
{
	t_nb			uni_nb;
	int				p;
	int				m;
	int				base;
	int				hashed;
	int				charc;
}					t_number;

typedef struct		s_opts
{
	t_number		nb;
	unsigned char	len_spec[NBYTE_LENGTH_SPECIFIER];
	char			padding[BUFF_SIZE];
	char			b_nb[MAX_BUFF];
	char			string[MAX_BUFF];
	char			g_buff_zero[4096];
	char			g_buff_space[4096];
	size_t			string_pos;
	char			*tmp;
	char			*s;
	size_t			size_nb;
	uint8_t			fm;
	int				width;
	int				prec;
	int				size;
	int				size_tmp;
	int				start;

}					t_opts;

static const char	g_dec[] = "0123456789";
static const char	g_hex[] = "0123456789abcdef";
static const char	g_upcase_hex[] = "0123456789ABCDEF";

static const int	g_flags[128] = {
	[(unsigned char)'-'] = FLG_M,
	[(unsigned char)'+'] = FLG_P,
	[(unsigned char)' '] = FLG_S,
	[(unsigned char)'#'] = FLG_H,
	[(unsigned char)'0'] = FLG_Z,
};

static const int	g_valid_num[128] = {
	[(unsigned char)'0'] = 1,
	[(unsigned char)'1'] = 1,
	[(unsigned char)'2'] = 1,
	[(unsigned char)'3'] = 1,
	[(unsigned char)'4'] = 1,
	[(unsigned char)'5'] = 1,
	[(unsigned char)'6'] = 1,
	[(unsigned char)'7'] = 1,
	[(unsigned char)'8'] = 1,
	[(unsigned char)'9'] = 1,
};

static int			g_length[128] =
{
	['h'] = 1,
	['l'] = 2,
	['z'] = 3,
	['j'] = 4,
};

static char			g_px[128] = {
	['x'] = 1,
	['X'] = 1,
	['p'] = 1,
};

static char g_p[128][2] = {
	['x'] = "0x",
	['X'] = "0X",
	['p'] = "0x",
};

/*
 ** ft_arg_sxp.c
*/

void				get_arg_s(t_opts *opt, va_list *ap);
void				get_arg_x(t_opts *opt, va_list *ap);
void				get_arg_p(t_opts *opt, va_list *ap);

/*
 ** ft_arg.c
*/

void				get_arg_d(t_opts *opt, va_list *ap);
void				get_arg_o(t_opts *opt, va_list *ap);
void				get_arg_u(t_opts *opt, va_list *ap);
void				get_arg_c(t_opts *opt, va_list *ap);

/*
 ** ft_control_spec_cs.c
*/

void				ft_control_c(t_opts *opt);
void				ft_control_s(t_opts *opt);

/*
 ** ft_control_spec_dou.c
*/

void				ft_control_d(t_opts *opt);
void				ft_control_o(t_opts *opt);
void				ft_control_u(t_opts *opt);

/*
 ** ft_control_spec_xp.c
*/

void				ft_control_x(t_opts *opt);
void				ft_control_p(t_opts *opt);

/*
 ** ft_control.c
*/

void				copy_in_buff(t_opts *opt, void *s, size_t size);
void				control_padding_left(t_opts *opt);
void				control_precision(t_opts *opt);
void				control_padding_right(t_opts *opt);

/*
 ** ft_csxp_spec.c
*/

void				ft_x(t_opts *opt, va_list *ap);
void				ft_c(t_opts *opt, va_list *ap);
void				ft_s(t_opts *opt, va_list *ap);
void				ft_p(t_opts *opt, va_list *ap);

/*
 ** ft_diou_spec.c
*/

void				ft_d(t_opts *opt, va_list *ap);
void				ft_o(t_opts *opt, va_list *ap);
void				ft_u(t_opts *opt, va_list *ap);

/*
 ** ft_flags.c
*/

void				search_length(unsigned char **fmt, t_opts *opt);
void				search_prec(unsigned char **fmt, t_opts *opt, va_list *ap);
void				search_width(unsigned char **fmt, t_opts *opt, va_list *ap);
void				search_flags(unsigned char **fmt, t_opts *opt);

/*
 ** ft_init.c
*/

void				init_array(t_opts *opt);
void				init_flag_mask(t_opts *opt, int pos, int size);

/*
 ** ft_libft_function.c
*/

size_t				ft_strlen(char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *h, char *n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);

/*
 ** ft_numbers.c
*/

void				signed_number(t_opts *opt);
void				create_number(t_opts *opt, int base, unsigned char spec);
void				create_unumber(t_opts *opt, int base, unsigned char spec);

int					ft_printf(const char *restrict format, ...);

typedef void		(*t_fp_arg)(t_opts *opt, va_list *ap);
typedef void		(*t_fp_spec)(t_opts *opt, va_list *ap);
typedef void		(*t_fp_control)(t_opts *opt);

typedef struct		s_printf_arg
{
	t_fp_arg		fp_arg;
}					t_printf_arg;

typedef struct		s_printf_spec
{
	t_fp_spec		fp_spec;
	t_fp_control	fp_control;
}					t_printf_spec;

static const t_printf_arg g_array_function[128][128][128] =
{
	[0][0]['d'].fp_arg = get_arg_d,
	[0][0]['i'].fp_arg = get_arg_d,
	[0][0]['o'].fp_arg = get_arg_o,
	[0][0]['u'].fp_arg = get_arg_u,
	[0][0]['x'].fp_arg = get_arg_x,
	[0][0]['X'].fp_arg = get_arg_x,
	[0][0]['c'].fp_arg = get_arg_c,
	[0][0]['s'].fp_arg = get_arg_s,
	[0][0]['p'].fp_arg = get_arg_p,
};

static const t_printf_spec g_spec[128] =
{
	['%'].fp_spec = ft_c,
	['%'].fp_control = ft_control_c,
	['d'].fp_spec = ft_d,
	['d'].fp_control = ft_control_d,
	['D'].fp_spec = ft_d,
	['D'].fp_control = ft_control_d,
	['i'].fp_spec = ft_d,
	['i'].fp_control = ft_control_d,
	['o'].fp_spec = ft_o,
	['o'].fp_control = ft_control_o,
	['O'].fp_spec = ft_o,
	['O'].fp_control = ft_control_o,
	['u'].fp_spec = ft_u,
	['u'].fp_control = ft_control_u,
	['U'].fp_spec = ft_u,
	['U'].fp_control = ft_control_u,
	['x'].fp_spec = ft_x,
	['x'].fp_control = ft_control_x,
	['X'].fp_spec = ft_x,
	['X'].fp_control = ft_control_x,
	['c'].fp_spec = ft_c,
	['c'].fp_control = ft_control_c,
	['s'].fp_spec = ft_s,
	['s'].fp_control = ft_control_s,
	['p'].fp_spec = ft_p,
	['p'].fp_control = ft_control_p
};

#endif
