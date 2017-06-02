/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:01:13 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/01 13:28:59 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_av_to_stats(char **av, t_uint flags, int start)
{
	t_my_stats	*my_stats;

	if (!(my_stats = malloc(sizeof(*my_stats) * start)))
		exit(0);
	ft_fill_name(av, my_stats, &start, flags);
	ft_ls_file(my_stats, flags, start);
	ft_free_spe(my_stats, start);
	return (0);
}

void			param_sorter(char **av, char **avbis, int ac, t_uint flags)
{
	int			tmp;
	static int	i = 0;
	static int	start = 0;
	int			end;

	end = ac - 1;
	while (i < ac)
	{
		tmp = is_folder(av[i]);
		if (tmp == 0)
			avbis[start++] = av[i];
		else
		{
			if (tmp == 1)
				avbis[end] = av[i];
			else
			{
				ft_forbidden(av[i]);
				avbis[end] = ft_strdup("\0");
			}
			end--;
		}
		i++;
	}
	ft_norme_screw(avbis, flags, start, ac);
}

void			sort_params(char **av, int ac, t_uint flags)
{
	char		**avbis;

	if (!(avbis = (char **)malloc(sizeof(*avbis) * ac)))
		return ;
	param_sorter(av, avbis, ac, flags);
	free(avbis);
}

int				check_folder(char *name, t_uint flags)
{
	if (is_folder(name))
	{
		ft_ls_folder(&name, flags, 1);
		return (0);
	}
	ft_av_to_stats(&name, flags, 1);
	free(name);
	return (0);
}

int				main(int ac, char **av)
{
	static t_uint	flags = 0;
	static int		i = 1;
	char			**dot;

	while (i < ac && av[i][0] == '-' && av[i][1] != '\0')
	{
		get_flags(av[i] + 1, &flags);
		i++;
	}
	av += i;
	ac -= i;
	if (ac == 0)
	{
		sort_params((dot = put_dot()), 1, flags);
		free(dot[0]);
		free(dot);
	}
	else
		sort_params(av, ac, flags);
	ft_buf(1, NULL, -1);
	return (0);
}
