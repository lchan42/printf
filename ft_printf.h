/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:46:49 by lchan             #+#    #+#             */
/*   Updated: 2022/01/03 19:40:00 by lchan            ###   ########.fr       */
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

/* j ai le droit ???????????
#define SPECIFIERS "cspdiuxX%"
#define FLAGS "# +-0."
*/
typedef struct s_list
{
	void			*content;
	int				result;
	struct s_list	*next;
}	t_list;
/*
enum e_flags
{
	HASHTAG = 1,
	SPACE = 2,
	SIGN = 4,
	LEFT_JUSTIFY = 8,
	ZERO = 16,
	DOT = 32,
};
*/

#endif 
