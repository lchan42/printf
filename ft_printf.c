/*******************************************
HEADER
*********************************************/


#include"ft_printf.h"

/*************************************
*********chained list fonctions*******
**************************************/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
/*************************************
****end of chained list fonctions****
**************************************/



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
			printf("the work is ongoing, please find another sentence\n");
		else
			ft_add_str_content(str, &strchain);	
		while (*str && *str != '%')
			str++;
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

	result = ft_printf("ceci est un petit test", test);
	printf("result final no segfault = %d\n", result);
	real_result = printf("%s", test);
	printf("real printf result = %d\n", real_result);
}
