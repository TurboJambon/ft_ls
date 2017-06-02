/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writebuf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:56:55 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/02 14:58:03 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_putendl_buf_fd(char *str, int fd)
{
	size_t	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	ft_buf(fd, str, len);
	ft_buf(fd, "\n", 1);
}

static int			ft_if(int fd, int size, t_uchar **buf, int *p)
{
	if (!*buf)
	{
		if (!(*buf = (t_uchar *)malloc(sizeof(**buf) * 100000)))
			ft_malloc_error();
	}
	if (size == -1)
	{
		write(fd, *buf, *p);
		*p = 0;
		return (0);
	}
	if (*p + size > 100000)
	{
		write(fd, *buf, *p);
		*p = 0;
	}
	return (1);
}

static void			ft_bufcpy(t_uchar *buf, int *p, void *str, int size)
{
	t_ulint	*tmp1;
	t_ulint	*tmp2;
	t_uchar	*tmp3;
	int		i;

	tmp1 = (t_ulint *)buf;
	tmp2 = (t_ulint *)str;
	tmp3 = (t_uchar *)str;
	i = 0;
	while (size >= 8)
	{
		tmp1[i] = tmp2[i];
		i++;
		size -= 8;
		*p += 8;
	}
	i *= 8;
	while (size > 0)
	{
		buf[i] = tmp3[i];
		i++;
		size--;
		(*p)++;
	}
}

int					ft_buf(int fd, void *str, int size)
{
	static t_uchar	*buf = NULL;
	static int		p = 0;
	static int		savefd = -1;

	if (savefd == -1)
		savefd = fd;
	if (savefd != fd)
	{
		write(savefd, buf, p);
		p = 0;
		savefd = fd;
	}
	if (!ft_if(fd, size, &buf, &p))
		return (p);
	if (size > 100000)
	{
		write(fd, str, size);
		return (size);
	}
	ft_bufcpy(buf + p, &p, str, size);
	return (0);
}
