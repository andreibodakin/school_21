/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:12:08 by zdawnsta          #+#    #+#             */
/*   Updated: 2020/11/30 15:17:41 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/param.h>
# include <sys/errno.h>
# include "../libft/libft.h"

# define ERR_NOT_NUM_ARG 1
# define ERR_MANY_ARGS 2
# define ERR_NO_COMMAND 3
# define ERR_CD_NO_FILE_OR_DIR 4
# define ERR_NO_FILE_OR_DIR 5
# define ERR_TOKEN 6
# define ERR_NOT_VALID_IND 7
# define ERR_REDIR 8

# define TEMP_CHAR 127
# define IN_RED "<"
# define OUT_RED ">"
# define DOB_OUT_RED ">>"

# define MAX_LEN 2048
# define NUM_SEC 128

typedef struct	s_env
{
	char		*home;
	char		*pwd;
	char		*oldpwd;
	char		**envv;
	char		**path;
	int			size;
	int			in;
	int			out;
	int			redir;
	int			excode;
}				t_env;

typedef struct	s_prs_com
{
	int			y;
	int			z;
	int			ry;
	int			rz;
	int			quotes;
	char		**com;
	char		**rdr;
	char		**res;
}				t_prs_com;

t_env			g_env;
char			*g_line;

void			envv_init(char **envv);
int				count_args(char **section);
int				in_envs(char *value);
void			error_message(char *value, int err_num, char *line);
void			values_free(char **values);
void			shell_close(int err_num);
void			correction(char **cmnds, char c);
void			rewrite_path(char *path);
void			sort_arr(char **new_arr, int size);
void			adding_env2(char **values, int i);
char			**add_env_var(char *value);
int				skip_space(char *line, int i);

int				check_line(char *line);
int				check_pipes(char *line, int i, char quotes);
int				check_semicolon(char *line, int i, char quotes);
int				check_redir(char **corr, int i);
int				in_redir_action(char **corr, int i);
int				out_redir_action(char **corr, int i, int mod);
void			signal_handler(int sig);

int				cmd_echo(char **argv);
int				cmd_pwd(void);
int				cmd_cd(char **path);
int				cmd_env();
int				cmd_unset(char **values);
int				cmd_exit(char **values);
int				cmd_export(char **values);
int				other_cmd(char **values);
int				end_cmd(char **corr);

char			*parse_shield(void);
void			start_pipes(char *section);
void			start_section(char *section);

char			**parse_sections(char *line);
void			space_skip(char *line, int *i);
char			*ft_part_strdup(const char *src, int size);
size_t			ft_part_strlcpy(char *dst, const char *src, size_t len);
int				char_cmp(char ch, char *stop);
int				ft_is_num_or_question(int c);

void			init_struct(t_prs_com *new, int *i, char *line);
void			ft_free_mem(char **com, char **rdr, char *line);
void			ft_copy_mem(char **com, char **rdr, t_prs_com *new);

void			parse_quotes(char *line, int *i, t_prs_com *new);
void			ft_dollar_strlcpy(t_prs_com *new, const char *src, size_t len);
int				find_pwds(char *var, t_prs_com *new);
void			find_env(char *line, int start, int *i, t_prs_com *new);
void			parse_dollar(char *line, int *i, t_prs_com *new);

int				ft_is_num_or_question(int c);
int				char_cmp(char ch, char *stop);
size_t			ft_part_strlcpy(char *dst, const char *src, size_t len);
char			*ft_part_strdup(const char *src, int size);
void			space_skip(char *line, int *i);
void			copy_file_name_utils(char *line, int *i, t_prs_com *new);
void			ft_copy_file_name(char *line, int *i, t_prs_com *new);
void			save_redirect(char *line, int *i, t_prs_com *new);

size_t			ft_dollar_cpy_rdr(t_prs_com *new, const char *src, size_t len);
int				find_pwds_rdr(char *var, t_prs_com *new);
void			find_env_rdr(char *line, int start, int *i, t_prs_com *new);
void			parse_dollar_file_name(char *line, int *i, t_prs_com *new);

#endif
