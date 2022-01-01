

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list arg_list;

	i = 0;
	va_start(arg_list, str);
	while (str[i])
	{
		printf("%s", va_arg(arg_list, char *));
		i++;
	}
	va_end(arg_list);
	return (5);
}

int	main(void)
{
	char	*a = "hELLO";
	char	*b = "My Name is ";
	char	*c = "YOda ";

	ft_printf("abc", a, b, c);
}
