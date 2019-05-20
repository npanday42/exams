/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brackets.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 16:56:32 by npanday        #+#    #+#                */
/*   Updated: 2019/05/20 16:56:34 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		brackets(char *str, char end)
{
	static int	i;
	int			j;
	char		*open = "([{";
	char		*close = ")]}";

	i = (end == 0) ? 0 : i + 1;
	while (str[i] != end)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i] == close[j])
				return (0);
			if (str[i] == open[j] && j < 3)
				if (!brackets(str, close[j]))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i = 1;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < argc)
	{
		if (brackets(argv[i], 0))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (1);
}
