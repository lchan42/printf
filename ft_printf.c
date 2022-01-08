/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:45:07 by lchan             #+#    #+#             */
/*   Updated: 2022/01/08 16:21:38 by lchan            ###   ########.fr       */
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

char    *ft_strdup(const char *s1)
{
        size_t  len;
        char    *dup;

        len = ft_strlen(s1);
        dup = (char *)malloc((len + 1) * sizeof(char));
        if (!dup)
                return (0);
        while (*s1 != '\0')
        {
                *dup = *s1;
                s1++;
                dup++;
        }
        *dup = '\0';
        return (dup - len);
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

void	ft_case_c(int argument, char **t_specifier_content)
{
	char	c;

	c = (char) argument;
	*t_specifier_content = ft_strndup(&c, 1); //this malloc is not freed
}

void	ft_case_s(char* argument, char **t_specifier_content)
{
	*t_specifier_content = ft_strdup(argument); //this malloc is not freed
}

int	ft_convertbase_size(unsigned long long int argument, int base)
{
	int	len;
	
	len = 0;
	while (argument)
	{
		argument /= base;
		len ++;
	}
	return (len);
}

char	*ft_printf_itoa_hexa(int len, unsigned long long int argument, char specifier)
{
	char	*content;
	int		i;

	if (!argument)
		len++;
	if (specifier == 'p')
		len += 2;
	content = malloc((len + 1) * sizeof(char));
	if (!content)
		return (NULL);
	content[len] = '\0';
	while (--len > 1)
	{
		content[len] = HEXABASE[argument % 16];
		argument /= 16;
//		printf("argument = %llu /HEXABASE[%llu] = %c\n", argument, argument % 16, HEXABASE[argument % 16]);
	}
	if (specifier == 'p')
	{
		content[1] = 'x';
		content[0] = '0';
	}
//	printf("content in hexa = %s\n", content);
	return (content);
}
/*
char	*ft_itoa(int argument)
{
	int		tmp;
	int		len;
	char	*itoa;

	tmp = argument;
	len = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	itoa = malloc((len + 1) * sizeof(char));
	while 
}

void	ft_putnbr(int n)
{
	long int nb;

	nb = n;
	if (nb < n)
		nb = -nb
	if (nb > 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb >= 16)
		ft_putnbr_fd(nb / 16);
	nb = nb % 16 + '0';
	write (1, &nb, 1);
}*/

void	ft_case_p(unsigned long long int argument, char **t_specifier_content)
{
	int	len;
	int	i;

	len = ft_convertbase_size(argument, 16);
	i = 0;
	printf("unsigned long long int version = %llu\n", argument);
	printf("argument size for malloc = %d\n", len);
	*t_specifier_content = ft_printf_itoa_hexa(len, argument, 'p'); //this malloc is not freed
}


void	specifier_tree(char c, va_list arg_list, char **t_specifier_content)
{
	if (c == 'c')
		ft_case_c(va_arg(arg_list, int), t_specifier_content);
	else if (c == 's')
		ft_case_s(va_arg(arg_list, char *), t_specifier_content);
	else if (c == 'p')
		ft_case_p((unsigned long long int)va_arg(arg_list, void *), t_specifier_content);
	else if (c == 'd')
		printf("\nI found a d\n"); //int
	else if (c == 'i')
		printf("\nI found a i\n"); //int
	else if (c == 'u')
		printf("\nI found a u\n"); //unsigned int
	else if (c == 'x')
		printf("\nI found a x\n"); //int
	else if (c == 'X')
		printf("\nI found a X\n"); //int
	else if (c == '%')//no va_arg in this case
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
 ** print functions (has to be deleted afterwards)****************
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
	printf("   -->founed flag list :");
	if (flag_value & ALTERNATE_FORME)
		printf("[#]");
	if (flag_value & SPACE)
		printf("[ ]");
	if (flag_value & PLUS_SIGN)
		printf("[+]");
	if (flag_value & LEFT_ADJUSTMENT)
		printf("[-]");
	if (flag_value & ZERO)
		printf("[0]");
	if (flag_value & PRECISION)
		printf("[.]");
	printf("\n");
}
void	del_print_t_specifier(t_specifier *specifier_struct)//this function has to be delete afterwards
{
	printf("***********SPECIFIER PARSED INFORMATION ************\n");
	printf("value of specifier_struct.specifier = %c\n", specifier_struct->specifier);
	printf("value of specifier_struct.flag_value = %d\n", specifier_struct->flag_value);
	if (specifier_struct->flag_value > 0)
		del_print_flags_identity(specifier_struct->flag_value);
	printf("value of specifier_struct.digit_width = %d\n", specifier_struct->digit_width);
	printf("value of specifier_struct.digit_precision = %d\n", specifier_struct->digit_precision);
	printf("value of specifier_struct.content = %s\n", specifier_struct->content);	
	printf("****************************************************\n\n");
}

/*********************************
 ************ parsing*************
 *********************************/

char	*parsing_bonus_digit(char *str, t_specifier *specifier_struct)
{
	int		result;
	char	flag;

	result = 0;
	flag = *str;
	while (ft_isdigit(*(++str)))
		result = result * 10 + (*str - '0') % 10;
	if (flag  == '.')
		specifier_struct->digit_precision = result;
	else
		specifier_struct->digit_width = result;
	return (str - 1);
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
	if (*flag_value & PLUS_SIGN && specifier == 'p')
		*flag_value -= PLUS_SIGN;
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
		if (*str == '.' && ft_isdigit(*(str + 1)))	
			str = parsing_bonus_digit(str, specifier_struct);
		else if (ft_isnonull_digit(*str))
			str = parsing_bonus_digit(str - 1, specifier_struct);
	}
	parsing_bonus_flag_overwrites(&specifier_struct->flag_value, 
		specifier_struct->specifier);
}

int	parsing(char *str, va_list arg_list)
{
	int			len;
	t_specifier	specifier_struct;

	len = 0;
	struct_init(&specifier_struct);
	while (str[++len])
	{
		if (ft_strchr(SPECIFIERS, str[len]))
		{
			specifier_struct.specifier = str[len];
			if (len > 1)
				parsing_bonus(str, len, &specifier_struct);
			break ;
		}
	}
	specifier_tree(specifier_struct.specifier, arg_list, &specifier_struct.content);
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
			parsing(str, arg_list);
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
	char	test[] = "[test dans un test]";
	int 	nb = 1;
	char	*null = NULL;
	int		result;
	int		real_result;
	
	result = ft_printf("ceci %#10.15cest un %#+000000000000150.000000160ppetit % 956ptest", 'a', &nb, null);
	printf("\nresult final no segfault = %d\n", result);
	real_result = printf("ceci %sest un %ppetit %ptest %x", test, &nb, null, -2147483648);
	printf("\nreal printf result = %d\n", real_result);
}
