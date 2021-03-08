/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 06:52:01 by bjacob            #+#    #+#             */
/*   Updated: 2021/03/08 17:26:38 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define NB_INSTRUCTIONS 11

typedef struct		s_nbr
{
	struct s_nbr	*next;
	int				nb;
}					t_nbr;

typedef struct		s_inst
{
	struct s_inst	*next;
	char			inst[4];
}					t_inst;

typedef struct		s_swap
{
	t_list			*ptrs;
	t_nbr			*nbra;
	t_nbr			*nbrb;
	t_inst			*instruction;
	int				nb_int;
	int				*arr;
	int				tab_index_2[2];
	int				tab_index_5[5];
	// int				index;
	int				count_to_index;
	char			default_inst[11][4];
	void			(*fct_inst[11])(struct s_swap*);
	char			*line;
	int				print;
	int				print_rota;
	int				count_sort;
}					t_swap;

/*
****************************************************
**					  COMMONS					  **
****************************************************
*/

/*
** init.c
*/
int	init_swap(t_swap *swap, int argc, char **argv);

/*
** exit.c
*/
void	ft_exit_failure(t_swap *swap, int error);
void	ft_exit(t_swap *swap);

/*
** display.c
*/
void	print_rotate(char c, int nb_r, int size_nbr, t_swap *swap);
void	display_stack(t_swap *swap);

/*
** clear_objects.c
*/
void				*add_lst_to_free(t_swap *swap, void *ptr);
void				*malloc_lst(t_swap *swap, int size);
int					free_all_ptr(t_swap *swap);

/*
****************************************************
**					  SORT						  **
****************************************************
*/

/*
** sort_medium_and_high_numbers.c
*/
int		sort_medium_numbers(t_swap *swap);
int		sort_high_numbers(t_swap *swap);

/*
****************************************************
**					  INSTRUCTIONS				  **
****************************************************
*/

/*
** swap_push.c
*/
void	ft_sa(t_swap *swap);
void	ft_sb(t_swap *swap);
void	ft_ss(t_swap *swap);
void	ft_pa(t_swap *swap);
void	ft_pb(t_swap *swap);

/*
** rotate.c
*/
void	ft_ra(t_swap *swap);
void	ft_rb(t_swap *swap);
void	ft_rr(t_swap *swap);

/*
** reverse_rotate.c
*/
void	ft_rra(t_swap *swap);
void	ft_rrb(t_swap *swap);
void	ft_rrr(t_swap *swap);

/*
** instructions.c
*/
void	apply_instructions(t_swap *swap);

/*
****************************************************
**					  UTILS						  **
****************************************************
*/

/*
** utils_nb.c
*/
int	ft_is_word_fulldigit(char *str);

/*
** lst_nbr.c
*/
void	ft_addnbr_back(t_nbr **alst, t_nbr *new);
void	ft_addnbr_front(t_nbr **alst, t_nbr *new);
int		add_nbr(t_swap *swap, char *str);
void	free_nbr(t_nbr* nbr);

/*
** lst_nbr2.c
*/
int		nbr_size(t_nbr *nbr);
int	nbr_min(t_nbr *nbr);
int	nbr_max(t_nbr *nbr);
t_nbr	*ft_nbrlast(t_nbr *begin);
int	is_in_stack(t_swap *swap, int nb);


/*
** lst_inst.c
*/
int	add_inst(t_swap *swap, char *str);
void	free_inst(t_inst* inst);

/*
** utils_sort_check.c
*/
int	is_sorted(t_nbr* nbr);
int	is_sorted_reverse(t_nbr* nbr);
int	a_empty_and_b_sorted(t_swap *swap);
void	final_check(t_swap *swap);

/*
** utils_sort_modif.c
*/
void	align_to_top_a(t_swap *swap);
void	align_to_top_b(t_swap *swap);
void	insert_topa_in_b(t_swap *swap);

/*
** utils_sort_array.c
*/
int	create_swap_array(t_swap *swap);


/*
** utils_instructions.c
*/
int	is_instruction(char *str, t_swap *swap);

/*
** lst_utils.c
*/
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
