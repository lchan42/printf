#include "ft_printf.h"

int	main(void)
{
	char	name[] = "Geralt";
	char	birth_place[] = "Riv";
	int	age = 420;
	double	crit_rate = 77.4;
	double	crit_damage = 224.7895;

	printf("age = %10d\n", age);
	printf("Birth place = %-15s that is the birth place\n", birth_place);
	printf("crit rate = %5.f\n", crit_rate);
	printf("crit rate = %5.f\n", crit_rate);
	printf("crit damage  = %5f (full number)\n", crit_damage);
	printf("crit damage  = %5.f (. precision)\n", crit_damage);
	printf("crit damage  = %5.1f (.1 precision)\n", crit_damage);
	printf("crit damage  = %5.2f (.2 precision)\n", crit_damage);
	printf("crit damage  = %5.3f (.3 precision)\n", crit_damage);
	printf("crit damage  = %#5.3f (.3 precision)\n", crit_damage); // # by it self does nothing/
	printf("crit damage  = %#o5.3f (#o5.3f)\n", age);
	printf("crit damage  = %5.3f (.3 precision)\n", crit_damage);
}
/*****************************
. can be use alone of with precision number. Alone = nothing after the . With a precision number = give numbers
%10 means i want 10 char in minimun. It is a miminum. it will still be printed out if the printf return is larger than that. 
- left justify,
+ always display sign
space display space if no space
0 replace space with 0s.
*/
