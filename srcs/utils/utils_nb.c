#include "../../includes/push_swap.h"

int	ft_is_word_fulldigit(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}
