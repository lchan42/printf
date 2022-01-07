#include "ft_printf.h"

int	main(void)
{
	char	name[] = "Geralt";
	char	birth_place[] = "Riv";
	int	age = 420;
	double	crit_rate = 77.4;
	double	crit_damage = 224.7895;

	printf("displayed space  5d: %10d\n", age);
	printf("displayed space+#5d: %+10d\n", age); //space is ignored if + is here ? 
	printf("displayed 05d: %05d\n", age);
	printf("name = %.1s\n", name); //precision number with a string : the dot gives the lengh to print;
	printf("age = %.10d\n", age); // missimg decimal point. dot seems to be treated as ZERO
	printf("age = %.p\n", &age);
	printf("age = %.10p ", &age); printf(" Dot is ignored with addresse\n");
	printf("age = %x ", age); printf("\n");
	printf("age = %.10x ", age); printf("Dot works like ZERO with hexa\n");
	printf("age = %-.10x ", age); printf("even with - the . that works like zero is not overwritten\n");
	printf("age = %-010x ", age); printf("however with -010x the minus is ignored\n");
	printf("age = %#.10x ", age); printf("ALTERNATE_FORME has to be writen first otherwize it does not work\n");
	printf("conclusion : the Dot change directly the forme of the result. the Hashtag only rights an ox before it");	
	printf("age = %10d", age); printf("10d tells that I want in minumun 10 byts\n");
	printf("age = %# 10d", age); printf("the didgit before the specifier tells the information\n");
	printf("age = %010d", age); printf("the didgit before the specifier tells the informatiom\n");
	printf("age = %"); printf("the didgit before the specifier tells the informatiom\n");

	printf("age = %-# +.04d", age); printf("we cant have an unlimited numbers of different  specifier\n");
}
/*****************************
FLAGS THAT HAS TO BE BEFORE
+ always display sign
' ' display space if no sign (positive). Is ignored when + is present.
# has undefined behaviour if placed with int. 

. can be use alone or with precision number. Alone = nothing after the . With a precision number = give numbers
%10 means i want 10 char in minimun. It is a miminum. it will still be printed out if the printf return is larger than that. 
- left justify,
0 replace space with 0s.



*/
