
#include "libft.h"

// static int	to_trim(const char *set, char c);
static char	*new_str(const char *s1, int start, int end, int size);

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	size_t	set_len;
	size_t	size;

	i = 0;
	j = ft_strlen(s1) - 1;
	set_len = ft_strlen(set);
	// printf("len of set=%zu\n", set_len);
	if (j <= 0)
		return (ft_strdup(""));
	if (set_len == 0)
		return (ft_strdup(s1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	// printf("from head i=%d\n", i);
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	size = abs(j - i) + 2;
	if (j == (int)ft_strlen(s1) - 1 || i == 0)
		size++;
	// printf("from tail j=%d\nstring llen  = %zu \n", j,ft_strlen(s1));
	return (new_str(s1, i, j, size));
}

static char	*new_str(const char *s1, int head, int tail, int size)
{
	char	*str;
	int		i;

	if (tail < head)
		return (ft_strdup(""));
	// printf("head=%d, tail=%d\n", head, tail);
	str = malloc(size);
	// printf("len %d\n", (abs(tail - head)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while ((head + i) <= tail)
	{
		str[i] = s1[head + i];
		i++;
	}
	str[tail + 1] = '\0';
	return (str);
}
