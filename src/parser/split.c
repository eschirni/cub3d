#include "../includes/cub3d.h"

static	char	**free_strings(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		count++;
	}
	free(arr);
	return (0);
}

static	int	count_delims(char const *s, char c)
{
	int	count;
	int	del;

	count = 0;
	del = 0;
	if (s[count] == '\0')
		return (0);
	while (s[count] && s[count] == c)
		count++;
	while (s[count])
	{
		if (s[count] == c)
		{
			del++;
			while (s[count] && s[count] == c)
			{
				count++;
			}
			continue ;
		}
		count++;
	}
	if (s[count - 1] != c)
		del++;
	return (del);
}

static	int	count_chrs(char const *s, char c, int start)
{
	int	chrs;

	chrs = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		chrs++;
	}
	return (chrs);
}

static	char	**split_helper(char const *s, char **arr, char c, int strs)
{
	int	count;
	int	str_nbr;
	int	n;

	count = 0;
	str_nbr = 0;
	while (s[count] && str_nbr < strs)
	{
		n = 0;
		while (s[count] == c)
			count++;
		arr[str_nbr] = (char *)malloc(count_chrs(s, c, count) + 1);
		if (arr[str_nbr] == 0)
			return (free_strings(arr));
		while (s[count] && s[count] != c)
		{
			arr[str_nbr][n] = s[count];
			count++;
			n++;
		}
		arr[str_nbr][n] = '\0';
		str_nbr++;
	}
	arr[str_nbr] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		strs;

	if (s == 0)
		return (0);
	strs = count_delims(s, c);
	arr = (char **)malloc(sizeof(char *) * (strs + 1));
	if (arr == 0)
		return (0);
	return (split_helper(s, arr, c, strs));
}
