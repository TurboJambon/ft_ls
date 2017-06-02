/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:58:20 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/02 12:04:31 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <stdio.h>
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
# define BLUB  			"\x1B[34;46m"
# define BLUY  			"\x1B[34;43m"
# define BLAY  			"\x1B[30;43m"
# define BLAG  			"\x1B[30;42m"
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
# define LSGM			0x400

# define OPTL			(flags & LSL)
# define OPTA			(flags & LSA)
# define OPTR			(flags & LSR)
# define OPTT			(flags & LST)
# define OPTU			(flags & LSU)
# define OPTF			(flags & LSF)
# define OPTG			(flags & LSG)
# define OPTD			(flags & LSD)
# define OPTP			(flags & LSP)
# define OPTRM			(flags & LSRM)
# define OPTGM			(flags & LSGM)

# define LS_NAME		dirent->d_name
# define LS_TYPE		dirent->d_type
# define LS_MODE		stat.st_mode
# define LS_NLINK		stat.st_nlink
# define LS_UID			stat.st_uid
# define LS_GID			stat.st_gid
# define LS_SIZE		stat.st_size
# define LS_MTIME		stat.st_mtime
# define LS_ATIME		stat.st_atime
# define LS_BLOCKS		stat.st_blocks
# define SPOUPS			opendir->spoups
# define COUCOUILLE		opendir->coucouille
# define W				opendir->w
# define P				opendir->p

typedef struct s_my_stats		t_my_stats;
typedef struct s_opendir		t_opendir;
typedef struct s_folder_infos	t_folder_infos;
typedef struct stat				t_stat;
typedef struct dirent			t_dirent;
typedef unsigned int			t_uint;
typedef unsigned long int		t_ulint;
typedef unsigned short int		t_uhint;
typedef unsigned char			t_uchar;

struct			s_opendir
{
	t_dirent	*dirent;
	DIR			*dir;
	t_my_stats	*spoups;
	char		**coucouille;
	int			w;
	int			p;
	int			maxw;
	int			maxp;
};

struct			s_my_stats
{
	t_stat				stat;
	char				*name;
	char				*path;
	char				*gid;
	char				*uid;
	dev_t				rdev;
	dev_t				dev;
};

int				ft_ls_folder(char **av, t_uint flags, int ac);
int				ft_ls_file(t_my_stats *my_stats, t_uint flags, int ac);
void			ft_affarg(char **av, int ac);
void			ft_swaptab(char **s1, char **s2);
void			ft_swapstat(t_stat *s1, t_stat *s2);
void			ft_swapmystats(t_my_stats *s1, t_my_stats *s2);
int				is_folder(char *name);
int				ft_dirlen(DIR *dir, int a, char *file);
void			sort_params(char **av, int ac, t_uint flags);

void			sort_str(t_my_stats *stats, int size);
void			sort_str_t(t_my_stats *stats, int size);
void			sort_str_r(t_my_stats *stats, int size);
void			sort_str_rt(t_my_stats *stats, int size);
void			sort_str_ru(t_my_stats *stats, int size);
void			sort_str_u(t_my_stats *stats, int size);
void			sort_folder_u(char **av, t_stat *infos, int size);
void			sort_folder_t(char **av, t_stat *infos, int size);
void			sort_folder_ru(char **av, t_stat *infos, int size);
void			sort_folder_rt(char **av, t_stat *infos, int size);
void			sort_folder(char **av, int size);
void			sort_folder_r(char **av, int size);

void			ft_fill_name(char **av, t_my_stats *my_stats,
				int *ac, t_uint flags);
void			ft_putstr_buf(char *str);
void			ft_putendl_buf(char *str);
void			ft_putstr_buf_fd(char *str, int fd);
void			ft_putchar_buf(char c);
void			ft_putchar_buf_fd(char c, int fd);
void			ft_putcharendl_buf_fd(char c, int fd);
void			ft_putnbr_buf(int n);
void			ft_putendl_buf_fd(char *str, int fd);

int				ft_buf(int fd, void *str, int size);
void			ft_free(t_my_stats *stats, int ac, t_uint flags);
void			ft_free_stat(char **av, int ac);
char			**put_dot();
int				ft_nblen(int nb);
char			*ft_strjoin_ls(char *s1, char *s2);
void			ft_free_spe(t_my_stats *stats, int ac);
void			get_flags(char *av, t_uint *flags);
void			ft_put_link(t_my_stats stats, t_uint flags);
void			printtype(mode_t mode);
void			ft_mode(mode_t n);
void			ft_putdate(time_t date);
void			ft_put_name(t_my_stats stat, mode_t mode, t_uint flags);
void			ft_putdev(dev_t rdev, int *blanks);
void			ft_putstrblanks_buf(char *str, int blanks);
void			ft_putnbrblanks_buf(int nbr, int blanks);
void			printacl(char *file);
void			ft_put_error(char *str);
t_stat			*fill_folder_infos(char **av, int ac);
blkcnt_t		ft_stat(t_my_stats *my_stats, t_uint flags, int ac);
void			ft_blanks(t_my_stats *stats, int ac, int *blanks);

void			ft_put_ls_files(t_my_stats *stats, int ac, t_uint flags,
				blkcnt_t blocks);
void			ft_opendir(char **av, int ac, t_uint flags);
void			main_ac_zero(t_uint flags);
int				ft_av_to_stats(char **av, t_uint flags, int start);
void			ft_forbidden(char *str);
void			ft_norme_screw(char **avbis, t_uint flags, int start, int ac);
void			ft_opendir_optrm(t_opendir *opendir, t_uint flags);

#endif
