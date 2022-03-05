/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:43:07 by hjosua            #+#    #+#             */
/*   Updated: 2022/01/02 22:03:41 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# elif BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_list
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	long			value;
	int				index;
	struct s_list	*next;
	int				order;
}					t_list;

size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_word_len(char const *s, char c);
int		ft_num_of_prt(char const *s, char c);
void	ft_memory_clean(char **res, int i);
char	**ft_full_array(char const *s, char c, char **res, int num_of_word);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(long content, int index);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
long	ft_check_int(const char *string);
int		ft_check_doubles(t_list *stack, int inx_last_elem);
void	ft_swap_a(t_list **stack_a);
void	ft_swap_b(t_list **stack_b);
void	ft_swap_a_b(t_list **stack_a, t_list **stack_b);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a(t_list **stack_a);
void	ft_rotate_a_for_rr(t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
void	ft_rotate_b_for_rr(t_list **stack_b);
void	ft_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_a(t_list **stack_a);
void	ft_reverse_rotate_a_for_rrr(t_list **stack_a);
void	ft_reverse_rotate_b(t_list **stack_b);
void	ft_reverse_rotate_b_for_rrr(t_list **stack_b);
void	ft_reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
int		ft_check_sort(t_list *stack_a);
t_list	*ft_parser_string(int argv, char **argc);
void	ft_create_stack(int argv, char **argc, t_list **stack_a);
void	ft_sort_stack_of_3_elem(t_list **stack_a);
void	ft_iterate_list(t_list *stack_a);
void	ft_arrange_stack_elements(t_list *stack);
int		ft_max_index_in_stack(t_list *stack);
int		ft_find_nearest_index(t_list *stack_a, int curr_index);
void	ft_num_of_operations_in_stack_a(t_list *stack_b, t_list *stack_a);
void	ft_count_num_of_operat_for_each_elem(t_list *stack_b, t_list *stack_a);
void	ft_zeroing_num_of_operations(t_list *stack_b);
void	ft_rb_rrb_ra_rra_control(t_list **stack_a, t_list **stack_b, \
		t_list *copy_stack_b);
void	ft_distributions_of_operations(t_list **stack_a, t_list **stack_b, \
		t_list *copy_stack_b);
void	ft_proc_min_num_of_operations(int min_operations, t_list **stack_a, \
		t_list **stack_b);
void	ft_optional_pa(t_list **stack_a, t_list **stack_b);
void	ft_leave_3_elem_in_stack_a(t_list **stack_a, t_list **stack_b);
void	ft_twist(t_list **stack_a);
void	ft_sort_stack_a(t_list **stack_a, t_list **stack_b);

char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_find_line(char *rem);
char	*ft_buf_use(char *rem, int fd);
char	*ft_modific_rem(char *rem);
char	*get_next_line(int fd);
void	ft_swap_a_checker(t_list **stack_a);
void	ft_swap_b_checker(t_list **stack_b);
void	ft_swap_a_b_checker(t_list **stack_a, t_list **stack_b);
void	ft_push_a_checker(t_list **stack_a, t_list **stack_b);
void	ft_push_b_checker(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a_and_b_checker(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_a_and_b_checker(t_list **stack_a, t_list **stack_b);
int		ft_viewing_command(char *string, t_list **stack_a, t_list **stack_b);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
#endif
