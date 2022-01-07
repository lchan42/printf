/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:45:07 by lchan             #+#    #+#             */
/*   Updated: 2022/01/05 20:23:04 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

/*************************************
*********utiles*******
**************************************/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int     ft_isdigit(int c)
{
        if (c >= '0' && c <= '9')
                return (1);
        return (0);
}

int     ft_isnonull_digit(int c)
{
        if (c >= '1' && c <= '9')
                return (1);
        return (0);
}

char    *ft_strchr(const char *s, int c)
{
        size_t  i;

        i = 0;
        while (s[i])
        {
                if (s[i] == (unsigned char) c)
                        return ((char *) &s[i]);
                i++;
        }
        if (c == '\0')
                return ((char *) &s[i]);
        return (NULL);
}

void	struct_init(t_specifier *specifier_struct)
{
	specifier_struct->specifier = 0;
	specifier_struct->flag_value = 0;
	specifier_struct->digit_width = 0;
	specifier_struct->digit_precision = 0;
	specifier_struct->content = NULL;
}

/*****************************************************************
*********chained list fonctions***********************************
******************************************************************/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;	
	return (lst);
}

t_list	*ft_lstnew(void *content, int count)
{
	t_list	*tmp;
	
	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->result = count;
	tmp->next = NULL;
	return (tmp);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;	
		else
			ft_lstlast(*alst)->next = new;	
	}
}

int	ft_print_list_result(t_list *alst)
{
	int	result;

	result = 0;
	while (alst)
	{
		write(1, alst->content, alst->result);
		result = result + alst->result; 
		alst = alst->next;
	}
	return (result);
}

void	free_list(t_list *alst)
{
	t_list *tmp;

	tmp = alst;
	while (alst)
	{
		free(alst->content);
		alst = alst->next;
	}
	free(tmp);
}


char	*ft_strndup(const char *s1, int	count)
{
	char	*dup;
	char	*result;

	dup = (char *)malloc((count + 1) * sizeof(char));
	if (!dup)
		return (0);
	result = dup;
	while (count-- > 0)
	{
		*dup = *s1;
		s1++;
		dup++;
	}
	*dup = '\0';	
	return (result);
}

void	ft_add_str_content(char *str, t_list **strchain)
{
	int		count;
	t_list	*new_chain;

	count = 0;
	while (str[count]  && str[count] != '%')
		count++;	
	new_chain = ft_lstnew(ft_strndup(str, count), count);	
	ft_lstadd_back(strchain, new_chain);
}

/********************************************************************
 ********specifier_tree**********************************************
 ********************************************************************/

void	specifier_tree(char c, int va_arg)
{
	if (c == 'c')
		printf("\nI found a c\n");
	else if (c == 's')
		printf("\nI found a s\n");
	else if (c == 'p')
		printf("\nI found a p\n");
	else if (c == 'd')
		printf("\nI found a d\n");
	else if (c == 'i')
		printf("\nI found a i\n");
	else if (c == 'u')
		printf("\nI found a u\n");
	else if (c == 'x')
		printf("\nI found a x\n");
	else if (c == 'X')
		printf("\nI found a X\n");
	else if (c == '%')
		printf("\nI found a percentage\n");
}

/*****************************************************************
 * *******position du curseur*************************************
 * ***************************************************************/
int	jump_specifier (char *str)
{
	int	jump_len;

	jump_len = 2;
	while (*(++str))
	{
		if (ft_strchr("cspdiuxX%", *str))
			return(jump_len);
		else
			jump_len++;
	}
	return (0);
}

/*****************************************************************
 ** print functions that has to be deleted afterwards*************
 * ***************************************************************/

void	del_print_initial_flags_identity(char *str)
{
	int	len;
	char *tmp;

	len = 0;
	tmp = str;
	while (++tmp)
	{
		if (ft_strchr(SPECIFIERS, *(tmp)))
			break ;
		len++;
	}
	write(1, "initial str flags = ", 20);
	write(1, str + 1, len);
}

void	del_print_flags_identity(int flag_value)
{
	printf("      founed flag :");
	if (flag_value & ALTERNATE_FORME)
		printf("'#' ");
	if (flag_value & SPACE)
		printf("' ' ");
	if (flag_value & PLUS_SIGN)
		printf("'+' ");
	if (flag_value & LEFT_ADJUSTMENT)
		printf("'-' ");
	if (flag_value & ZERO)
		printf("'0' ");
	if (flag_value & PRECISION)
		printf("'.' ");
	printf("\n");
}
void	del_print_t_specifier(t_specifier *specifier_struct)//this function has to be delete afterwards
{
	printf("***********SPECIFIER PARSED INFORMATION ************\n");
	printf("value of specifier_struct.specifier = %c\n", specifier_struct->specifier);
	printf("value of specifier_struct.flag_value = %d\n", specifier_struct->flag_value);
	if (specifier_struct->flag_value > 0)
		del_print_flags_identity(specifier_struct->flag_value);
	printf("value of specifier_struct.precision_digits = %d\n", specifier_struct->precision_digits);
	printf("value of specifier_struct.content = %s\n", specifier_struct->content);	
	printf("****************************************************\n\n");
}

/*********************************
 ************ parsing*************
 *********************************/

void	parsing_bonus_digit(char *str, t_specifier *specifier_struct)
{
	
}
void	parsing_bonus_flag_overwrites(int *flag_value, char specifier)
{
	printf("\nflag_value before overwrite = %d\n", *flag_value);
	if (*flag_value & SPACE && *flag_value & PLUS_SIGN)
		*flag_value -= SPACE;
	if (*flag_value & ZERO && *flag_value & LEFT_ADJUSTMENT)
		*flag_value -= ZERO;
	if ((*flag_value & ALTERNATE_FORME) 
			&& (specifier != 'x' || specifier != 'X'))
		*flag_value -= ALTERNATE_FORME;
}

void	parsing_bonus_flag_value(char flag, int *flag_value)
{
	if (flag == '#')
		*flag_value |= ALTERNATE_FORME;
	else if (flag == ' ')
		*flag_value |= SPACE;
	else if (flag == '+')
		*flag_value |= PLUS_SIGN;
	else if (flag == '-')
		*flag_value |= LEFT_ADJUSTMENT;
	else if (flag == '0')
		*flag_value |= ZERO;
	else if (flag == '.')
		*flag_value |= PRECISION;
}

void	parsing_bonus(char *str, int len, t_specifier *specifier_struct)
{
	del_print_initial_flags_identity(str);
	while (*(++str) != specifier_struct->specifier)
	{
		if (ft_strchr(FLAGS, *str))
			parsing_bonus_flag_value(*str, &specifier_struct->flag_value);
		else if (ft_isnonull_digit(*str)
			parsing_bonus_digit(str - 1, &specifier_struct);
	}
	parsing_bonus_flag_overwrites(&specifier_struct->flag_value, 
		specifier_struct->specifier);
}

int	parsing(char *str, int va_arg)
{
	int			len;
	t_specifier	specifier_struct;

	len = 0;
	struct_init(&specifier_struct);
	while (str[++len])
	{
		if (ft_strchr("cspdiuxX%", str[len]))
		{
			specifier_struct.specifier = str[len];
			if (len > 1)
				parsing_bonus(str, len, &specifier_struct);
			break ;
		}
	}
	specifier_tree(str[len], va_arg);
	del_print_t_specifier(&specifier_struct);
	return (0);
}

int	ft_printf(char *str, ...)
{
	va_list	arg_list;
	t_list	*strchain;
	int		result;

	va_start(arg_list, str);
	strchain = NULL;
	result = 0;
	while (*str)
	{
		if (*str == '%')
		{
			parsing(str, va_arg(arg_list, int));
			str += jump_specifier(str);
		}
		else
		{
			ft_add_str_content(str, &strchain);	
			while (*str && *str != '%')
				str++;
		}
	}
	va_end(arg_list);
	result = ft_print_list_result(strchain);
	free_list(strchain);
	return (result);
}

int	main(void)
{
	char	test[] = "ceci est un petit test";
	int	result;
	int	real_result;
	
	result = ft_printf("ceci %- +   #.sest un %#cpetit % stest", test);
	printf("\nresult final no segfault = %d\n", result);
	real_result = printf("%s", test);
	printf("\nreal printf result = %d\n", real_result);
}
