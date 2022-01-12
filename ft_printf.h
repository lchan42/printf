/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:46:49 by lchan             #+#    #+#             */
/*   Updated: 2022/01/12 22:55:56 by lchan            ###   ########.fr       */
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
#define HEXABASE "0123456789abcdef"

typedef struct s_list
{
	void			*content;
	int				result;
	struct s_list	*next;
}	t_list;

typedef struct s_specifier
{
	char	specifier;
	int		flag_value;
	int		digit_width;
	int		digit_precision; // real printf can manage numbers that are over int;
	char	*content;
}	t_specifier;

enum e_flags
{
	ALTERNATE_FORME = 1,//only works with x, X put 0x
	SPACE = 2,	// is overwritten by PLUS_SIGN
				// has undefined behaviour with c, s, p, u, x, X
				// ---> works with d, i , %(does nothing with %)
	PLUS_SIGN = 4, 	// overrights SPACE // = undefined behavior with p
					//has undefined behaviour with c, s, p, u, x, X
					//works with d, i, 
	LEFT_ADJUSTMENT = 8, //overrights ZERO // not here for string
	ZERO = 16,//IS OVERWRITTEN BY LEFT_ADJUDSTMENT
	PRECISION = 32, // case string :gives the number of byte to print. 
					//else if number or hexa the dot is treated as ZERO
					//seens that no flag can appear after precisions. 
					// if %10.15d => 10 < .15 le 10 saute.
					// WARNING a leading 0 is a flag but embedded zero is part of a filed.
					//has undefined behaviour with c, p
					//works with s, d, i, u, x, X. 
					//				If digit specifier, writes 0 if result < digit_precision.
					//				With s, [.] works as a 'print no more than'. if .30 > strlen(str) prints normal str
					//				If %s prints [(null)] %.3s will print [(nul],
};

//chained list
size_t  ft_strlen(const char *s);
t_list  *ft_lstlast(t_list *lst);
static t_list  *ft_lstnew(void *content, int count);
void    ft_lstadd_back(t_list **alst, t_list *new);
int     ft_print_list_result(t_list *alst);
void    free_list(t_list *alst);

//utiles
char    *ft_strndup(const char *s1, int count);
void    ft_add_str_content(char *str, t_list **strchain);
char    *ft_strchr(const char *s, int c);
int     ft_printf(char *str, ...);

#endif 
