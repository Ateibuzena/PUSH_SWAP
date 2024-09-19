#include "/home/azubieta/sgoinfre/azubieta/push_swap_intra/pushlibft.h"

char	*ft_join(char const *s1, char const *s2)
{
	char		*join;
	t_size		i;
	t_size		n;

	n = 0;
	i = 0;
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!join)
		return (NULL);
	if (!s1 && !s2)
	{
		free(join);
		return (NULL);
	}
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	join[i] = ' ';
	i++;
	while (n < ft_strlen(s2))
	{
		join[i] = s2[n];
		i++;
		n++;
	}
	join[i] = '\0';
	return (join);
}