/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:58:24 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/13 16:44:56 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>

# define RED   			"\x1B[31m"
# define GRN   			"\x1B[32m"
# define YEL   			"\x1B[33m"
# define BLU   			"\x1B[34m"
# define MAG   			"\x1B[35m"
# define CYN   			"\x1B[1;96m"
# define WHT   			"\x1B[37m"
# define RESET 			"\x1B[0m"

# define LSL			0x01
# define LSA			0x02
# define LSR			0x04
# define LST			0x08
# define LSU			0x10
# define LSF			0x20
# define LSG			0x40
# define LSD			0x80
# define LSRM			0x100
# define LSP			0x200

# define OPTL			(flags & LSL)
# define OPTA			(flags & LSA)
# define OPTR			(flags & LSR)
# define OPTT			(flags & LST)
# define OPTU			(flags & LSU)
# define OPTF			(flags & LSF)
# define OPTG			(flags & LSG)
# define OPTD			(flags & LSD)
# define OPTRM			(flags & LSRM)

# define LS_NAME		dirent->d_name
# define LS_TYPE		dirent->d_type
# define LS_MODE		stat->mode
# define LS_NLINK		stat->nlink
# define LS_UNAME		stat->uname
# define LS_GRNAME		stat->grname
# define LS_SIZE		stat->size

typedef struct s_stats	t_my_stats;
typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef unsigned int	t_uint;

struct s_my_stats
{
	t_stat				*stat;
	t_dirent			*dirent;
	char				*path;
	char				*gid;
	char				*uid;
};

#endif
