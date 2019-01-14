/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:15:02 by lezhang           #+#    #+#             */
/*   Updated: 2018/10/19 11:45:54 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <libft.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <color.h>
# define ERROR_MESSAGE		"ERROR\n"
# define ERROR_EMPTY_FILE	"Fichier vide\n"
# define ERROR_EMPTY_LINE	"Line vide\n"
# define ERROR_START_SPACE	"Ligne commence par une espace\n"
# define ERROR_ANTS			"Nombre de fourmie invalide\n"
# define ERROR_TUBE			"Tube invalide\n"
# define ERROR_SALLE		"Salle invalide\n"
# define ERROR_START_SALLE	"Start salle invalide\n"
# define ERROR_END_SALLE	"End salle invalide\n"
# define ERROR_MULTI_START	"Trop de start\n"
# define ERROR_MULTI_END	"Trop de end\n"
# define ERROR_NO_START		"Pas de start\n"
# define ERROR_NO_END		"Pas de end\n"
# define ERROR_SAME_NAME	"Les noms des salles ne doivent pas se repeter\n"
# define ERROR_TUBE_SALLE	"Le tube ne peut pas connecter la meme salle\n"
# define ERROR_SALLE_NULL	"La salle connecter n'existe pas\n"
# define ERROR_NO_TUBE		"Pas de tubes\n"
# define ERROR_NO_SALLE		"Pas de salles\n"
# define ERROR_LINE			"Ligne invalide\n"
# define ERROR_NO_PATH		"Pas de path\n"

# define ERROR_COLOR		"\033[31m"

typedef struct		s_salle
{
	char	*nom;
	int		x;
	int		y;
	int		nb_tube;
	int		fourmie_a;
	int		fourmie_b;
	int		used;
}					t_salle;

typedef struct		s_error
{
	int		error;
	int		empty_line;
	int		start_space;
	int		ants;
	int		tube;
	int		salle;
	int		start_salle;
	int		end_salle;
	int		same_name;
	int		tube_salle;
	int		salle_null;
	int		line;
	int		no_path;
}					t_error;

typedef struct		s_lem
{
	char		**file;
	char		*nom_start;
	char		*nom_end;
	int			start;
	int			end;
	int			nbf;
	int			nbs;
	int			nbt;
	int			stop_line;
	int			curr_salle;
	t_salle		*salles;
	char		**tube;
	t_error		error;
	int			option;
}					t_lem;

void				printlem(t_lem lem);

/*
**	stock_file.c
*/

void				stock_file(t_lem *lem);

/*
**	handle_info.c
*/

void				stock_info(t_lem *lem);

/*
**	verif_tool.c
*/

void				verif_salle(t_lem *lem);
void				verif_tube(t_lem *lem);

/*
**	verif_tool2.c
*/

int					get_option(int argc, char **argv);
int					is_comment(char *str);
void				count_salle_tube(t_lem *file);

/*
**	check_tool.c
*/

int					check_salle(char *str);
int					check_tube(char *str);
int					check_diese(char *str, t_lem *lem, int *i);
int					check_space(char *str);
void				get_salle(t_lem *lem, char *str, int pos);

/*
**	print_error.c
*/

int					parse_error(t_lem lem);
void				print_error(t_lem lem);

/*
**	algorithme.c
*/

void				find_multi_path(t_lem *lem);

/*
**	find_path.c
*/

char				*ft_find_path(t_lem *lem, char **path, char *tmp,
					char **dst);

/*
**	find_path_tool.c
*/

int					path_exist(char *str, char **path);
int					path_end(char *str, char **tmp, t_lem *lem);
int					get_str_path(t_lem *lem, char **dst, char **tmp,
					char **str);
int					path_repete(char *str);

/*
**	find_less.c
*/

char				**check_salle_find_less(t_lem *lem, char **dst, char *tmp,
					int (*j)[2]);

/*
**	choose_path.c
*/

void				choose_path(char **path, t_lem *lem);

/*
**	choose_path_tool.c
*/

int					nb_path(t_lem *lem);
int					get_path_length(char **path);

/*
**	print_fourmie.c
*/

void				print_fourmie(char **path, t_lem *lem);

/*
**	print_fourmie_tool.c
*/

void				avance_fourmie(char **tmp, t_lem *lem);

#endif
