#include "get_next_line.h"



int howmany_of_n_func(char *str)
{
	int i = 0;
	int j = 1;
	while(str[i] != '\0')
	{
		if(str[i] == '\n')
			j++;
		i++;
	}
	return j;
}

int* locations__n_func(int *l__n, char *str)
{
	int i = 0;
	int num = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			l__n[num] = i;
			num++;
			i++;
		}
	i++;
	}
	return l__n;
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		dex;

	ptr = (char *)malloc((ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	else
	{
		dex = 0;
		while (s1[dex] != '\0')
		{
			ptr[dex] = s1[dex];
			dex++;
		}
		ptr[dex] = '\0';
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		dex;
	size_t		dexx;
	char		*ptr;

	if (!s1 || !s2)
		return (NULL);
	dex = 0;
	dexx = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (dex < ft_strlen(s1))
	{
		ptr[dex] = s1[dex];
		dex++;
	}
	while (dexx < ft_strlen(s2))
		ptr[dex++] = s2[dexx++];
	ptr[dex] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	dex;

	dex = 0;
	while (s[dex] != '\0')
	{
		dex++;
	}
	return (dex);
}
