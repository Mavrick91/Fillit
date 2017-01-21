#include "libft.h"

char *ft_strdup(const char *src)
{
	char *dest;
	size_t nb;

	nb = ft_strlen(src);
	if (!(dest = malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
