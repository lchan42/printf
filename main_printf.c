/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:45:07 by lchan             #+#    #+#             */
/*   Updated: 2022/01/14 16:53:22 by lchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	test[] = "[test dans un test]";
	char	*str_null = NULL;
	char	char_null = (char)NULL;
	int 	int_min = -2147483648;
	int		int_null = 0;
	int		int_max = 2147483647;
	int		int_random = 42;
	int		int_random2 = -9;
	int		result;
	int		real_result;

	result = ft_printf("%%%%%d%%, %c, %s, %s, %p, %d, %i, %u, %x, %X, %%, %x, %X", 
			int_random, 'a', "[une phrase de test]", 
			str_null, str_null, int_min, int_max, int_random, int_max, int_max, int_min, -1);
	printf("\nmine, result = %d\n", result);
//	result = ft_printf("%s", str_null);
//	printf("\nmine, result = %d\n", result);
//	real_result = printf("%s", str_null);
//	printf("\nmine, real_result = %d\n", real_result);
	real_result = printf("%%%%%d%%, %c, %s, %s, %p, %d, %i, %u, %x, %X, %%, %x, %X",
		   	int_random, 'a', "[une phrase de test]", 
			str_null, str_null, int_min, int_max, int_random, int_max, int_max, int_min, -1);
	printf("\nreal, result = %d\n", real_result);
	printf("******************************test avec null***************************\n");
	printf("		case c :\n");
	write (1, "mine : ", 7);	result = ft_printf("%c", (char)NULL);		printf("\n");
	printf("real : ");			real_result = printf("%c", (char)NULL);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("		case s :\n");
	result = ft_printf("mine : %s\n", NULL);
	real_result = printf("real : %s\n", NULL);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("		case p :\n");
	result = ft_printf("mine : %p\n", NULL);
	real_result = printf("real : %p\n", NULL);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("		case d :\n");
	result = ft_printf("mine : %d\n", (int)NULL);
	real_result = printf("real : %d\n",(int)NULL);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("		case u :\n");
	result = ft_printf("mine : %u\n", (unsigned int)NULL);
	real_result = printf("real : %u\n",(unsigned int)NULL);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	ft_printf("		case x :\n");
	result = ft_printf("mine : %x\n", (unsigned int)NULL);
	real_result = printf("real : %x\n", (unsigned int)NULL);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("***************************testing flag [#]******************************\n");
	printf("----------------test with x\n");
	write (1, "mine : ", 7);	result = ft_printf("%#x", 0);		printf("\n");
	printf("real : ");			real_result = printf("%#x", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	write (1, "mine : ", 7);	result = ft_printf("%#x", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%#x", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	write (1, "mine : ", 7);	result = ft_printf("%#x", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%#x", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("--------------test with X\n");
	write (1, "mine : ", 7);	result = ft_printf("%#X", 0);		printf("\n");
	printf("real : ");			real_result = printf("%#X", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	write (1, "mine : ", 7);	result = ft_printf("%#X", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%#X", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	write (1, "mine : ", 7);	result = ft_printf("%#X", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%#X", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("***************************testing flag [ ]******************************\n");
	printf("----------------test with d = int_max\n");
	write (1, "mine : ", 7);	result = ft_printf("% d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("% d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0\n");
	write (1, "mine : ", 7);	result = ft_printf("% d", 0);		printf("\n");
	printf("real : ");			real_result = printf("% d", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with i = int_max\n");
	write (1, "mine : ", 7);	result = ft_printf("% i", int_max);		printf("\n");
	printf("real : ");			real_result = printf("% i", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with i = 0\n");
	write (1, "mine : ", 7);	result = ft_printf("% i", 0);		printf("\n");
	printf("real : ");			real_result = printf("% i", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with %%\n");
	write (1, "mine : ", 7);	result = ft_printf("% %");		printf("\n");
	printf("real : ");			real_result = printf("% %");
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("***************************testing flag [+]******************************\n");
	printf("----------------test with d\n");
	write (1, "mine : ", 7);	result = ft_printf("%+d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%+d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0\n");
	write (1, "mine : ", 7);	result = ft_printf("%+d", 0);		printf("\n");
	printf("real : ");			real_result = printf("%+d", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with i\n");
	write (1, "mine : ", 7);	result = ft_printf("%+i", int_min);		printf("\n");
	printf("real : ");			real_result = printf("%+i", int_min);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with i\n");
	write (1, "mine : ", 7);	result = ft_printf("%+i", 0);		printf("\n");
	printf("real : ");			real_result = printf("%+i", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with %%\n");
	write (1, "mine : ", 7);	result = ft_printf("%+%");		printf("\n");
	printf("real : ");			real_result = printf("%+%");
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("**********************testing flag [.] and [precision digit]************************\n");
	printf("*************************************test with s *******************************\n");
	printf("----------------test with s and [.1]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.1s", test);		printf("\n");
	printf("real : ");			real_result = printf("%.1s", test);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with s and [.9]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.9s", test);		printf("\n");
	printf("real : ");			real_result = printf("%.9s", test);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with s and [.15]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.15s", test);		printf("\n");
	printf("real : ");			real_result = printf("%.15s", test);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with s and [.50]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.50s", test);		printf("\n");
	printf("real : ");			real_result = printf("%.50s", test);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with s and [.500]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.500s", test);		printf("\n");
	printf("real : ");			real_result = printf("%.500s", test);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("*************************************test with d *******************************\n");
	printf("----------------test with d and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%.d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d and [.1]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.1d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%.1d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d and [.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.10d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%.10d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d and [.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.20d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%.20d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.d", 0);		printf("\n");
	printf("real : ");			real_result = printf("%.d", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [.1]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.1d", 0);		printf("\n");
	printf("real : ");			real_result = printf("%.1d", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.10d", 0);		printf("\n");
	printf("real : ");			real_result = printf("%.10d", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_min and [.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.20d", int_min);		printf("\n");
	printf("real : ");			real_result = printf("%.20d", int_min);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [ .]\n");
	write (1, "mine : ", 7);	result = ft_printf("% .d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("% .d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_min and [ .0]\n");
	write (1, "mine : ", 7);	result = ft_printf("% .0d", int_min);		printf("\n");
	printf("real : ");			real_result = printf("% .0d", int_min);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_min and [+.0]\n");
	write (1, "mine : ", 7);	result = ft_printf("%+.0d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%+.0d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [+.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("%+.20d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%+.20d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [ .20]\n");
	write (1, "mine : ", 7);	result = ft_printf("% .20d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("% .20d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [+.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("%+.20d", 0);		printf("\n");
	printf("real : ");			real_result = printf("%+.20d", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [ .20]\n");
	write (1, "mine : ", 7);	result = ft_printf("% .20d", 0);		printf("\n");
	printf("real : ");			real_result = printf("% .20d", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [+.]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%+.d]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%+.0d]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [ .]\n");
	write (1, "mine : ", 7);	result = ft_printf("[% .d]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[% .0d]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("*************************************test with i *******************************\n");
	printf("----------------test with i = 0 and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%.i]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%.i]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with i = 10 and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.i", 10);		printf("\n");
	printf("real : ");			real_result = printf("%.i",10);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with i = 10 and [.1]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.1i", 10);		printf("\n");
	printf("real : ");			real_result = printf("%.1i",10);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with i = 10 and [.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.10i", 10);		printf("\n");
	printf("real : ");			real_result = printf("%.10i",10);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("*************************************test with u *******************************\n");
	printf("----------------test with u = 0 and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%.u]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%.u]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with u = 0 and [.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.10u", 0);		printf("\n");
	printf("real : ");			real_result = printf("%.10u", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with u = int_random and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.u", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%.u", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with u = int max and [.15]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.15u", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%.15u", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with u = (unsigned long int)int_min and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.u", (unsigned int) int_min);		printf("\n");
	printf("real : ");			real_result = printf("%.u", (unsigned int) int_min);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with u = (unsigned long int)int_min and [.15]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.15u", (unsigned int) int_min);		printf("\n");
	printf("real : ");			real_result = printf("%.15u", (unsigned int) int_min);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("*************************************test with x *******************************\n");
	printf("----------------test with x = 0 and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%.x]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%.x]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = 0 and [.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.10x", 0);		printf("\n");
	printf("real : ");			real_result = printf("%.10x", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = 10 and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.x", 10);		printf("\n");
	printf("real : ");			real_result = printf("%.x", 10);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = 10 and [.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.10x", 10);		printf("\n");
	printf("real : ");			real_result = printf("%.10x", 10);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = int_max and [.]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.x", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%.x", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = int_max and [.15]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.15x", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%.15x", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = 0 and [.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%.10x", 0);		printf("\n");
	printf("real : ");			real_result = printf("%.10x", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("******************************test with x  and [#.]*******************************\n");
	printf("----------------test with x = 0 and [#.]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%#.x]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%#.x]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = 0 and [#.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%#.10x]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%#.10x]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = 10 and [#.]\n");
	write (1, "mine : ", 7);	result = ft_printf("%#.x", 10);		printf("\n");
	printf("real : ");			real_result = printf("%#.x", 10);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = 10 and [#.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%#.10x", 10);		printf("\n");
	printf("real : ");			real_result = printf("%#.10x", 10);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = int_max and [#.]\n");
	write (1, "mine : ", 7);	result = ft_printf("%#.x", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%#.x", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = int_max and [#.15]\n");
	write (1, "mine : ", 7);	result = ft_printf("%#.15x", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%#.15x", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with x = 0 and [#.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%#.10x]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%#.10x]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");


	printf("***************************testing flag [digit_width]******************************\n");
	printf("----------------test with c and [-15]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%-15c]", 'a');		printf("\n");
	printf("real : ");			real_result = printf("[%-15c]", 'a');
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with c = (char)NULL and [no flag]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%c]", (char)NULL);		printf("\n");
	printf("real : ");			real_result = printf("[%c]", (char)NULL);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with c = (char)NULL and [1]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%1c]", (char)NULL);		printf("\n");
	printf("real : ");			real_result = printf("[%1c]", (char)NULL);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with c = (char)NULL and [2]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%2c]", (char)NULL);		printf("\n");
	printf("real : ");			real_result = printf("[%2c]", (char)NULL);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with c = (char)NULL and [5]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%5c]", (char)NULL);		printf("\n");
	printf("real : ");			real_result = printf("[%5c]", (char)NULL);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");

	printf("----------------test with c = (char)NULL and [15]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%15c]", (char)NULL);		printf("\n");
	printf("real : ");			real_result = printf("[%15c]", (char)NULL);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with c = (char)256 and [15]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%15c]", (char)256);		printf("\n");
	printf("real : ");			real_result = printf("[%15c]", (char)256);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");


	printf("----------------test with s = test and [1]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%1s]", test);		printf("\n");
	printf("real : ");			real_result = printf("[%1s]", test);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with s = test and [1]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%1s]", str_null);		printf("\n");
	printf("real : ");			real_result = printf("[%1s]", str_null);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with s = test and [50]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%50s]", test);		printf("\n");
	printf("real : ");			real_result = printf("[%50s]", test);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with s = test and [50]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%50s]", str_null);		printf("\n");
	printf("real : ");			real_result = printf("[%50s]", str_null);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with s = test and [-1]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%-1s]", test);		printf("\n");
	printf("real : ");			real_result = printf("[%-1s]", test);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with s = test and [1]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%-1s]", str_null);		printf("\n");
	printf("real : ");			real_result = printf("[%-1s]", str_null);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with s = test and [50]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%-50s]", test);		printf("\n");
	printf("real : ");			real_result = printf("[%-50s]", test);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with s = test and [-50]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%-50s]", str_null);		printf("\n");
	printf("real : ");			real_result = printf("[%-50s]", str_null);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");



	printf("*************************************test with d *******************************\n");
	printf("----------------test with d and [15.]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%15.d]", int_random);		printf("\n");
	printf("real : ");			real_result = printf("[%15.d]", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d and [15.1]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%15.1d]", int_random);		printf("\n");
	printf("real : ");			real_result = printf("[%15.1d]", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d and [5.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%5.10d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%5.10d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d and [25.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("%25.20d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%25.20d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [010.]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%010.d]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%010.d]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [10.1]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%.1d]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%.1d]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [15.10]\n");
	write (1, "mine : ", 7);	result = ft_printf("%15.10d", 0);		printf("\n");
	printf("real : ");			real_result = printf("%15.10d", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_min and [10.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("%10.20d", int_min);		printf("\n");
	printf("real : ");			real_result = printf("%10.20d", int_min);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [ .]\n");
	write (1, "mine : ", 7);	result = ft_printf("% .d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("% .d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_min and [ 10.0]\n");
	write (1, "mine : ", 7);	result = ft_printf("% 10.0d", int_min);		printf("\n");
	printf("real : ");			real_result = printf("% 10.0d", int_min);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_min and [+10.0]\n");
	write (1, "mine : ", 7);	result = ft_printf("%+10.0d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%+10.0d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [+10.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("%+10.20d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%+10.20d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [ 025.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("% 025.20d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("% 025.20d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [ 25.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("% 25.20d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("% 25.20d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [025]\n");
	write (1, "mine : ", 7);	result = ft_printf("%025d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%025d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");



	printf("----------------test with d = int_max and [0]\n");
	write (1, "mine : ", 7);	result = ft_printf("%0d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%0d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [+10.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%+10.20d]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%+10.20d]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [ 025.20]\n");
	write (1, "mine : ", 7);	result = ft_printf("[% 025.20d]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[% 25.20d]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [+1.]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%+1.d]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[%+1.0d]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [ 1.]\n");
	write (1, "mine : ", 7);	result = ft_printf("[% 5.d]", 0);		printf("\n");
	printf("real : ");			real_result = printf("[% 5.0d]", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");

	printf("----------------test with s and dot to check how it works\n");
	write (1, "mine : ", 7);	result = ft_printf("%15.3s", str_null);		printf("\n");
	printf("real : ");			real_result = printf("%15.3s", str_null);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with s\n");
	write (1, "mine : ", 7);	result = ft_printf("%15s", test);		printf("\n");
	printf("real : ");			real_result = printf("%15s", test);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with d and int_random\n");
	write (1, "mine : ", 7);	result = ft_printf("%15d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%15d", int_random);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with d and int_null\n");
	write (1, "mine : ", 7);	result = ft_printf("%15d", int_null);		printf("\n");
	printf("real : ");			real_result = printf("%15d", int_null);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with d and int min\n");
	write (1, "mine : ", 7);	result = ft_printf("%15d", int_min);		printf("\n");
	printf("real : ");			real_result = printf("%15d", int_min);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with p\n");
	write (1, "mine : ", 7);	result = ft_printf("%15p", &str_null);		printf("\n");
	printf("real : ");			real_result = printf("%15p", &str_null);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");
	printf("----------------test with p\n");
	write (1, "mine : ", 7);	result = ft_printf("%.10x", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%.10x", int_max);
	printf("\nresult = %d / %d\n", result, real_result);			printf("\n");



	printf("----------------test with x = int_max and [       -d]\n");
	write (1, "mine : ", 7);	result = ft_printf("%       -d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%      -d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");

	printf("----------------test with s = test and [-25.5]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%-25.5s]", test);		printf("\n");
	printf("real : ");			real_result = printf("[%-25.5s]", test);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_random and [-25.20]\n"); printf("[.] should overwrite padding");
	write (1, "mine : ", 7);	result = ft_printf("%-25.20d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%-25.20d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_random and [-25]\n"); 
	write (1, "mine : ", 7);	result = ft_printf("%-25d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%-25d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_random and [-25]\n"); 
	write (1, "mine : ", 7);	result = ft_printf("%-25d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%-25d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [-25.200]\n");
	write (1, "mine : ", 7);	result = ft_printf("%-25.20d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%-25.20d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");

	printf("----------------test with s = test and [25.5]\n");
	write (1, "mine : ", 7);	result = ft_printf("[%25.5s]", test);		printf("\n");
	printf("real : ");			real_result = printf("[%25.5s]", test);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = 0 and [25.20]"); printf("[.] should overwrite padding \n");
	write (1, "mine : ", 7);	result = ft_printf("%25.20d", 0);		printf("\n");
	printf("real : ");			real_result = printf("%25.20d", 0);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_random and [25]\n"); 
	write (1, "mine : ", 7);	result = ft_printf("%25d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%25d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_random and [025]\n"); 
	write (1, "mine : ", 7);	result = ft_printf("%025d", int_random);		printf("\n");
	printf("real : ");			real_result = printf("%025d", int_random);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
	printf("----------------test with d = int_max and [025.200]\n");
	write (1, "mine : ", 7);	result = ft_printf("%025.20d", int_max);		printf("\n");
	printf("real : ");			real_result = printf("%025.20d", int_max);
	printf("\nresult = %d / %d\n", result, real_result); if(result != real_result) printf(" ERROR");	printf("\n");
}
