#include "../includes/cub3d.h"

static int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	cub_atoi(char *str)
{
	int	count;
	int	result;

	count = 0;
	result = 0;
	if (str[count] == '-')
		ft_error("not an rgb value: ", str);
	else if (str[count] == '+')
		count++;
	while (str[count] != '\0' && str[count] != ' ')
	{
		if (!ft_isdigit(str[count]))
			ft_error("not an rgb value: ", str);
		result = result * 10 + (str[count] - '0');
		count++;
	}
	if (result < 0 || result > 255)
		ft_error("not an rgb value: ", str);
	return (result);
}

char	**cut_newlines(char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] == '\n')
				file[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (file);
}

int	size_2d(char **s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i][0] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*cpy;
	size_t	size;
	size_t	count;

	size = ft_strlen(str);
	count = 0;
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (cpy == 0)
	{
		return (0);
	}
	while (count < size)
	{
		cpy[count] = str[count];
		count++;
	}
	cpy[count] = '\0';
	return (cpy);
}
