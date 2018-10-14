/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <lfedorko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:44:52 by lfedorko          #+#    #+#             */
/*   Updated: 2018/10/12 18:44:54 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;

	s = b;
	while (len > 0)
	{
		*s++ = c;
		len--;
	}
	return (b);
}

static int	ft_size(int c)
{
	int			count;

	count = 0;
	if (c == 0 || c < 0)
		count++;
	while (c != 0)
	{
		c /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			count;
	int			i;
	long		num;

	i = 0;
	num = n;
	count = ft_size(num);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}
	str[count] = '\0';
	count = count - 1;
	while (i <= count)
	{
		str[count] = (num % 10) + 48;
		num /= 10;
		count--;
	}
	return (str);
}

void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
