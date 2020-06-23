/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahizi-e <aahizi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:09:22 by aahizi-e          #+#    #+#             */
/*   Updated: 2020/01/17 11:08:35 by aahizi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t				ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char				*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char				*ft_strstr(const char *h, char *n)
{
	size_t			n_size;
	int				res;

	res = 0;
	n_size = ft_strlen(n);
	if (!n_size)
		return ((char *)h);
	while (*h)
	{
		while (n_size--)
			if (*(unsigned char *)(h++) != *(unsigned char *)(n++))
				res = (*(unsigned char *)(h - 1) - *(unsigned char *)(n - 1));
		if (res == 0)
			return ((char *)h);
		++h;
	}
	return (NULL);
}

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *)b;
	if (len & 1)
	{
		s[0] = (unsigned char)c;
		++s;
	}
	len = len / 2;
	while (len)
	{
		s[0] = (unsigned char)c;
		s[1] = (unsigned char)c;
		s += 2;
		--len;
	}
	return (b);
}

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (n & 1)
	{
		d[0] = s[0];
		++d;
		++s;
	}
	n = n / 2;
	while (n)
	{
		d[0] = s[0];
		d[1] = s[1];
		d += 2;
		s += 2;
		--n;
	}
	return (dst);
}
