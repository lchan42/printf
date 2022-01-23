/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:45:07 by lchan             #+#    #+#             */
/*   Updated: 2022/01/23 15:33:54 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

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
