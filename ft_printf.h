

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	int				result;
	struct s_list	*next;
}	t_list;
/*typedef struct s_param
{
	char	   
} t_param*/


#endif 
