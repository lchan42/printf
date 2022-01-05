/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:46:49 by lchan             #+#    #+#             */
/*   Updated: 2022/01/05 18:36:36 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>


#define SPECIFIERS "cspdiuxX%"
#define FLAGS "# +-0."

typedef struct s_list
{
	void			*content;
	int				result;
	struct s_list	*next;
}	t_list;

typedef struct s_specifier
{
	char	specifier;
	int		flag_value;//declaration en char ici cara pas besoin de 4 bytes
	int		precision_digits;
	char	*content;
}	t_specifier;

enum e_flags
{
	ALTERNATE_FORME = 1,//only works with x, X put ox
	SPACE = 2,// is overwritten by PLUS_SIGN
	PLUS_SIGN = 4, // overrights SPACE
	LEFT_ADJUSTMENT = 8, //overrights ZERO
	ZERO = 16,//IS OVERWRITTEN BY LEFT_ADJUDSTMENT
	PRECISION = 32, // gives the lengh to print if is string, else if number or hexa the dot is treated as ZERO
	// if -10 < .15 le 10 saute. 
};

//chained list
size_t  ft_strlen(const char *s);
t_list  *ft_lstlast(t_list *lst);
t_list  *ft_lstnew(void *content, int count);
void    ft_lstadd_back(t_list **alst, t_list *new);
int     ft_print_list_result(t_list *alst);
void    free_list(t_list *alst);

//utiles
char    *ft_strndup(const char *s1, int count);
void    ft_add_str_content(char *str, t_list **strchain);
char    *ft_strchr(const char *s, int c);
void    specifier_tree(char c, int va_arg);
int     parsing(char *str, int va_arg);
int     ft_printf(char *str, ...);

#endif 
