/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:56:36 by David             #+#    #+#             */
/*   Updated: 2017/06/02 15:10:14 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			fill_tab(t_uint **tab)
{
	if (!(*tab = (t_uint*)malloc(sizeof(**tab) * 127)))
		ft_malloc_error();
	ft_bzero(*tab, 127 * 4);
	(*tab)['l'] = LSL;
	(*tab)['a'] = LSA;
	(*tab)['r'] = LSR;
	(*tab)['t'] = LST;
	(*tab)['u'] = LSU;
	(*tab)['f'] = LSF;
	(*tab)['d'] = LSD;
	(*tab)['R'] = LSRM;
	(*tab)['G'] = LSGM;
	(*tab)['p'] = LSP;
}

void			get_flags(char *av, t_uint *flags)
{
	static t_uint	*tab = NULL;

	if (!tab)
		fill_tab(&tab);
	while (*av)
	{
		if (tab[(int)*av])
			*flags |= tab[(int)*av];
		else
		{
			ft_putstr_fd("ls: illegal option -- ", 2);
			ft_putchar_fd(*av, 2);
			ft_putendl_fd("\nusage: ls [-GRadflprtu] [file ...]", 2);
			exit(0);
		}
		av++;
	}
}

char			*get_name(char *path)
{
	char	*name;

	name = ft_strrchr(path, '/');
	if (name == NULL)
		return (path);
	else
		return (name + 1);
}

void			ft_malloc_error(void)
{
	ft_putstr_fd("Malloc error\n", 2);
	exit(0);
}
