#include "../cub3d.h"

static void	free_split(char **arr, t_data *data, char exit)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	if (exit)
		clean(data, "invalid RGB values\n", 1, -1);
}

static int	check_overflow(int current, int digit)
{
	if (current > (INT_MAX - digit) / 10)
		return (1);
	return (0);
}

static int	string_to_integer(const char *str, int *error)
{
	int	result;
	int	digit;

	*error = 0;
	result = 0;
	while (*str && ft_isdigit(*str))
	{
		digit = *str - '0';
		if (check_overflow(result, digit))
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + digit;
		str++;
	}
	if (*str != '\0')
		*error = 1;
	return (result);
}

int	add_rgb(const char *str, int *rgb, t_data *data)
{
	char	**colors;
	int		i;
	int		error;

	while (*str == ' ')
		str++;
	colors = ft_split(str, ','); // line 56
	if (!colors)
		clean(data, "malloc failure inside ft_split", 1, -1);
	i = 0;
	while (colors[i])
		++i;
	if (i != 3)
		free_split(colors, data, 1);
	while (i--)
	{
		rgb[i] = string_to_integer(colors[i], &error);
		if (error || rgb[i] > 255)
			free_split(colors, data, 1);
	}
	free_split(colors, data, 0);
	return (0);
}
