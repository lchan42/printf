/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:45:07 by lchan             #+#    #+#             */
/*   Updated: 2022/01/14 15:47:39 by lchan            ###   ########.fr       */
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

int    ft_strchr_booleen(const char *s, int c)
{
        int  i;

        i = 0;
        while (s[i])
        {
                if (s[i] == (unsigned char) c)
                        return (1);
                i++;
        }
        return (0);
}

void	struct_init(t_specifier *specifier_struct)
{
	specifier_struct->specifier = 0;
	specifier_struct->flag_value = 0;
	specifier_struct->digit_width = 0;
	specifier_struct->digit_precision = 0;
	specifier_struct->content = NULL;
}

char	*printf_strjoin_frees2(char const *s1, char const *s2)
{
	char	*joined;
	size_t	index;
	int		i;

	index = 0;
	if (s1 && s2)
		joined = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !joined)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		joined[index] = s1[i];
		index++;
	}
	i = -1;
	while (s2[++i])
	{
		joined[index] = s2[i];
		index++;
	}
	joined[index] = '\0';
	free((void *)s2);
	return (joined);
}

char	*printf_strjoin_free(char const *s1, char const *s2)
{
	char	*joined;
	size_t	index;
	int		i;

	index = 0;
	if (s1 && s2)
		joined = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !joined)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		joined[index] = s1[i];
		index++;
	}
	i = -1;
	while (s2[++i])
	{
		joined[index] = s2[i];
		index++;
	}
	joined[index] = '\0';
	free((void *)s1);
	free((void *)s2);
	return (joined);
}

/*****************************************************************
*********chained list fonctions***********************************
* ************************************************************************** */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;	
	return (lst);
}

static t_list	*ft_lstnew(void *content, int count)
{
	t_list	*tmp;
	
	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	if (!tmp->content)
		count = 1;
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
		if (!alst->content)
			write(1, "\0", 1);
		else
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
	while (tmp)
	{
		free(tmp->content);
		tmp = tmp->next;
		free(alst);
		alst = tmp;
	}
}
/*
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
*/
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

char    *ft_strndup(const char *s1, int len)
{
        char    *dup;

        dup = (char *)malloc((len + 1) * sizeof(char));
        if (!dup)
                return (0);
        dup[len] = '\0';
        while (len--)
                dup[len] = s1[len];
        return (dup);
}

/********************************************************************
 ********adding BONUS FLAG to content *******************************
 ********************************************************************/
/* ************************************************************************** */
void	ft_add_space_or_plus(char **t_specifier_content, int flag_value)
{
	if (flag_value & PLUS_SIGN)
		*t_specifier_content = printf_strjoin_frees2("+", *t_specifier_content);
	else if	(flag_value & SPACE)
		*t_specifier_content = printf_strjoin_frees2(" ", *t_specifier_content);
}

/********************************************************************
 **********************adding padding *******************************
 ********************************************************************/
/* ************************************************************************** */

void	ft_add_padding_onright(int content_len, t_specifier *specifier_struct)
{

	int		i;
	char	padding;
	char	*padded_content;

	i = -1;
	if (specifier_struct->flag_value & ZERO)
		padding = '0';
	else
		padding = ' ';
	padded_content = (char *)malloc(specifier_struct->digit_width + 1);
	while (specifier_struct->content[++i])
		padded_content[i] = specifier_struct->content[i];
	while (i < specifier_struct->digit_width)
		padded_content[i++] = padding;
	padded_content[specifier_struct->digit_width] = '\0';
	free(specifier_struct->content);
	specifier_struct->content = padded_content;
}

void	ft_add_padding_onleft(int content_len, t_specifier *specifier_struct)
{	
	int		i;
	int		j;
	char	padding;
	char	*padded_content;

	i = -1;
	j = 0;
	if (specifier_struct->flag_value & ZERO)
		padding = '0';
	else
		padding = ' ';
	padded_content = (char *)malloc(specifier_struct->digit_width + 1);
	while (++i < specifier_struct->digit_width - content_len)
		padded_content[i] = padding;
	if (specifier_struct->specifier == 'c')
		while ( i < specifier_struct->digit_width - 1 && j < content_len)
			padded_content[i++] = specifier_struct->content[j++];
	else
		while ( i < specifier_struct->digit_width && j < content_len)
			padded_content[i++] = specifier_struct->content[j++];
	padded_content[i] = '\0';
	free(specifier_struct->content);
	specifier_struct->content = padded_content;
}

void	ft_add_padding(t_specifier *specifier_struct)
{
	int		content_len;
	char	padding;
	if (specifier_struct->content)
		content_len = ft_strlen(specifier_struct->content);
	else
		content_len = 1;
	if (specifier_struct->digit_width <= content_len)
		return;
	if (specifier_struct->flag_value & LEFT_ADJUSTMENT)
		ft_add_padding_onright(content_len, specifier_struct);
	else
		ft_add_padding_onleft(content_len, specifier_struct);
}

/******************************adding precision*********************************/
void	ft_precision_case_null(t_specifier *specifier_struct)
{
//	printf("content = %s\n", specifier_struct->content);
//	printf("content len = %zu\n", ft_strlen(specifier_struct->content));
	if (specifier_struct->flag_value & ALTERNATE_FORME
		&& ft_strlen(specifier_struct->content) == 1)
	{
//		printf("I am a Null alternate forme x\n");
		free(specifier_struct->content);
		specifier_struct->content = ft_strdup("");
	}
	else if (specifier_struct->specifier != 's' 
		&& !(specifier_struct->flag_value & ALTERNATE_FORME)
		&& specifier_struct->content[0] == '0')
	{
//		printf("I am null non alternate forme \n");
		free(specifier_struct->content);
		specifier_struct->content = ft_strdup("");
	}
	else if (specifier_struct->specifier != 's' 
		&& ft_strchr_booleen(" +", specifier_struct->content[0])
		&& specifier_struct->content[1] == '0')
	{
//		printf("I am signed null content\n");
		specifier_struct->content[1] = '\0';
	}
}


void	ft_precision_case_signed(t_specifier *specifier_struct, int content_len)
{
	char	*index;
	int		i;
	int		new_content_len;
	char	*new_content;

	index = specifier_struct->content;
	i = 0;
	new_content_len = specifier_struct->digit_precision + 1;
	new_content = (char*)malloc((new_content_len + 1) * sizeof(char));//WARNING malloc is here. be freed in strjoin_free tho
	if (!new_content)
		return ;
	new_content[0] = specifier_struct->content[0];
	while (++i < new_content_len - content_len + 1)
		new_content[i] = '0';
	while(*(++index))
		new_content[i++] = *index;
	new_content[new_content_len] = '\0';
	free(specifier_struct->content);
	specifier_struct->content = new_content;
}

void	ft_precision_case_0x(t_specifier *specifier_struct, int content_len)
{
	char	*index;
	int		i;
	int		new_content_len;
	char	*new_content;

	index = specifier_struct->content;
	i = 1;
	new_content_len = specifier_struct->digit_precision + 2;
	new_content = (char*)malloc((new_content_len + 1) * sizeof(char));//WARNING malloc is here. be freed in strjoin_free tho
	if (!new_content)
		return ;
	new_content[0] = specifier_struct->content[0];
	new_content[1] = specifier_struct->content[1];
	while (++i < new_content_len - content_len + 2)
		new_content[i] = '0';
	index++;
	while(*(++index))
		new_content[i++] = *index;
	new_content[new_content_len] = '\0';
	free(specifier_struct->content);
	specifier_struct->content = new_content;
}


void	ft_precision_case_unsigned(t_specifier*specifier_struct, int content_len)
{	
	char	*add_content;

	content_len = specifier_struct->digit_precision - content_len;
	add_content = (char*)malloc((content_len + 1) * sizeof(char));//WARNING malloc is here. be freed in strjoin_free tho
	if (!add_content)
		return ;
	add_content[content_len] = '\0';
	while (content_len--)
		add_content[content_len] = '0';
	specifier_struct->content = printf_strjoin_free(add_content, specifier_struct->content);

}
void	ft_add_precision(t_specifier *specifier_struct)
{
	int		content_len;

	if (specifier_struct->digit_precision == 0)
		ft_precision_case_null(specifier_struct);
	content_len = ft_strlen(specifier_struct->content);
	if ((specifier_struct->specifier == 's' 
		|| content_len > specifier_struct->digit_precision))
		return ;
	if (ft_strchr_booleen("-+ ", specifier_struct->content[0]))
		ft_precision_case_signed(specifier_struct, content_len);
	else if (specifier_struct->content[0] == '0' 
			&& (ft_strchr_booleen("xX", specifier_struct->content[1])))
		ft_precision_case_0x(specifier_struct, content_len);
	else
		ft_precision_case_unsigned(specifier_struct, content_len);
}
/*****************************************************************
 ** print functions (has to be deleted afterwards)****************
 * ************************************************************************** */

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

void	del_print_content_address(t_list **strchain, char **specifier_struct_content)
{
	t_list *tmp;

	tmp = *strchain;
	while (tmp->next)
		tmp = tmp->next;
	printf("t_list strchain->content = %p\n", tmp->content);
	printf("s_specifier->content     = %p\n", *specifier_struct_content);
}

/********************************************************************
 ********adding content to chain list *******************************
 * ************************************************************************** */
void	ft_add_str_content(char *str, t_list **strchain)
{
	int		count;
	t_list	*new_chain;

	count = 0;
	while (str[count] && str[count] != '%')
		count++;	
	new_chain = ft_lstnew(ft_strndup(str, count), count);	
	ft_lstadd_back(strchain, new_chain);
}

void	ft_add_specifier_content(t_list **strchain, t_specifier *specifier_struct)
{
	int		content_len;
	t_list	*new_chain;

	content_len = 0;
	if (!specifier_struct->content && specifier_struct->specifier != 'c')
		return ;
	if (specifier_struct->flag_value & PRECISION)
		ft_add_precision(specifier_struct);
	if (specifier_struct->digit_width)
		ft_add_padding(specifier_struct);
	while (specifier_struct->content && specifier_struct->content[content_len])
		content_len++;
	//lets deal with fucking case c
	if (specifier_struct->specifier == 'c' && specifier_struct->digit_width > 0)
		new_chain = ft_lstnew(specifier_struct->content, specifier_struct->digit_width);
	else
		new_chain = ft_lstnew(specifier_struct->content, content_len);
	ft_lstadd_back(strchain, new_chain);
//	del_print_content_address(strchain, &specifier_struct->content);//have to delete this line
}

/********************************************************************
 ********specifier_tree**********************************************
* ************************************************************************** */
void	ft_case_c(int argument, char **t_specifier_content)
{
	char	c;

	if (!argument)
		*t_specifier_content = NULL;
	else
	{
		c = (char) argument;
		*t_specifier_content = ft_strndup(&c, 1); //this malloc is not freed
	}
}

void	ft_case_s(char *argument, t_specifier *specifier_struct)
{
	int	len;

	if (argument)
		len = ft_strlen(argument);
	else
		len = ft_strlen("(null)");
	if (specifier_struct->flag_value & PRECISION 
			&& specifier_struct->digit_precision < len)
		len = specifier_struct->digit_precision;
	if (!argument)
		specifier_struct->content = ft_strndup("(null)", len);
	else
		specifier_struct->content = ft_strndup(argument, len); //this malloc is not freed
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
	int		added_bytes;

	added_bytes = 0;
	if (!argument)
		len++;
	if (specifier == 'p')
		added_bytes = 2;
	content = (char *) malloc((len + added_bytes + 1) * sizeof(char));
	if (!content)
		return (NULL);
	content[len + added_bytes] = '\0';
	while (--len + added_bytes >= added_bytes)
	{
		content[len + added_bytes] = HEXABASE[argument % 16];
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

void	ft_case_p(unsigned long long int argument, char **t_specifier_content)
{
	int	len;

	len = ft_convertbase_size(argument, 16);
//	printf("unsigned long long int version = %llu\n", argument);
//	printf("argument size for malloc = %d\n", len);
	*t_specifier_content = ft_printf_itoa_hexa(len, argument, 'p');//this malloc is not freed
}


void	ft_case_d(int argument, char **t_specifier_content, int	flag_value)
{
	int			len;
	long int	nb;

	nb = argument;
	if (nb > 0)
		len = ft_convertbase_size(nb, 10);
	else
	{
		nb = - nb;
		len = ft_convertbase_size(nb, 10);
		len++;
	}
	*t_specifier_content = (char *) malloc((len + 1 ) * sizeof(char));//this malloc is not freed
	if (!*t_specifier_content)
		return ;
	(*t_specifier_content)[len] = '\0';
	while (--len >= 0)
	{
		(*t_specifier_content)[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (argument < 0)
		(*t_specifier_content)[0] = '-';
	if (argument >= 0) 
		ft_add_space_or_plus(t_specifier_content, flag_value);
}

void	ft_case_u(unsigned int argument, char **t_specifier_content)
{
	int			len;

	len = ft_convertbase_size(argument, 10);
	if (!argument)
		len = 1;
	*t_specifier_content = (char *) malloc((len + 1 ) * sizeof(char));//this malloc is not freed
	if (!*t_specifier_content)
		return ;
	(*t_specifier_content)[len] = '\0';
	while (--len >= 0)
	{
		(*t_specifier_content)[len] = argument % 10 + '0';
		argument /= 10;
	}
}

void	ft_case_x(unsigned int argument, t_specifier *t_specifier)
{
	int len;

	len = ft_convertbase_size(argument, 16);
	if (argument && (t_specifier->flag_value & ALTERNATE_FORME))
		t_specifier->content = ft_printf_itoa_hexa(len, argument, 'p'); //this malloc is not freed
	else
		t_specifier->content = ft_printf_itoa_hexa(len, argument, 'x'); //this malloc is not freed
}

void	ft_case_X(unsigned argument, t_specifier *t_specifier)
{
	int len;
	int	i;

	i = 0;
	len = ft_convertbase_size(argument, 16);
	if (argument && (t_specifier->flag_value & ALTERNATE_FORME))
		t_specifier->content = ft_printf_itoa_hexa(len, argument, 'p'); //this malloc is not freed
	else
		t_specifier->content = ft_printf_itoa_hexa(len, argument, 'x'); //this malloc is not freed
	while ((t_specifier->content)[i])
	{
		if ((t_specifier->content)[i] >= 97 && (t_specifier->content)[i] <= 122)
			(t_specifier->content)[i] -= 32;
		i++;
	}
}

void	ft_case_percent(char **t_specifier_content)
{	
	*t_specifier_content = ft_strdup("%");//this malloc is not freed
}

void	specifier_tree(char specifier, va_list arg_list, t_specifier *specifier_struct)
{
	if (specifier == 'c')
		ft_case_c(va_arg(arg_list, int), &specifier_struct->content);
	else if (specifier == 's')
		ft_case_s(va_arg(arg_list, char *), specifier_struct);
	else if (specifier == 'p')
		ft_case_p((unsigned long long int)va_arg(arg_list, void *),
			   	&specifier_struct->content);
	else if (specifier == 'd')
		ft_case_d(va_arg(arg_list, int), &specifier_struct->content,
			   	specifier_struct->flag_value);
	else if (specifier == 'i')
		ft_case_d(va_arg(arg_list, int), &specifier_struct->content,
			   	specifier_struct->flag_value);
	else if (specifier == 'u')
		ft_case_u(va_arg(arg_list, unsigned int), &specifier_struct->content);
	else if (specifier == 'x')
		ft_case_x(va_arg(arg_list, unsigned int), specifier_struct);
	else if (specifier == 'X')
		ft_case_X(va_arg(arg_list, unsigned int), specifier_struct);
	else if (specifier == '%')//no va_arg in this case??
		ft_case_percent(&specifier_struct->content);
}

/*****************************************************************
 * *******position du curseur*************************************
* ************************************************************************** */

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

/*********************************
 ************ parsing*************
 * ***************************************************************/

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
/*
void	parsing_bonus_digit_overwrites(t_specifier *specifier_struct)
{
//	printf("\nflag_value before overwrite = %d\n", *flag_value);//have to delete this line
	if (specifier_struct->specifier != 's'
			&& specifier_struct->digit_width < specifier_struct->digit_precision)
			specifier_struct->digit_width = 0;
}
*/

void	parsing_bonus_flag_overwrites(int *flag_value, char specifier)
{
//	printf("\nflag_value before overwrite = %d\n", *flag_value);//have to delete this line
	if (*flag_value & SPACE && *flag_value & PLUS_SIGN)
		*flag_value -= SPACE;
	if (*flag_value & ZERO && *flag_value & LEFT_ADJUSTMENT)
		*flag_value -= ZERO;
	if ((*flag_value & ALTERNATE_FORME) 
			&& (specifier != 'x')  && (specifier != 'X'))
		*flag_value -= ALTERNATE_FORME;
	if (*flag_value & PLUS_SIGN && specifier == 'p')
		*flag_value -= PLUS_SIGN;
	if ((*flag_value & PRECISION) 
			&& (specifier == 'c' || specifier == 'p'))
		*flag_value -= PRECISION;
	if (*flag_value & PRECISION  && *flag_value & ZERO
			&& ft_strchr_booleen("diouxX", specifier))
		*flag_value -= ZERO;
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
//	del_print_initial_flags_identity(str);//have to delete this line
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
//	parsing_bonus_digit_overwrites(specifier_struct);
}

int	parsing(char *str, t_list **strchain, va_list arg_list)
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
	specifier_tree(specifier_struct.specifier, arg_list, &specifier_struct);
//	del_print_t_specifier(&specifier_struct);
	ft_add_specifier_content(strchain, &specifier_struct);
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
			parsing(str, &strchain, arg_list);
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
