#include "libft.h"

int	ft_is_only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}
