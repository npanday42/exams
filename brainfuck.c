/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brainfuck.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/19 15:20:24 by exam           #+#    #+#                */
/*   Updated: 2019/06/01 20:49:43 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	brainfuck(char *str, char *ptr, char end);

static int	loop(char *str, char *ptr, int i)
{
	int		ret = 0;
	int		loops = 1;

	if (*ptr == 0)
		while (loops > 0)
		{
			ret++;
			if (str[i + ret] == '[')
				loops++;
			else if (str[i + ret] == ']')
				loops--;
		}
	else while (*ptr != 0)
		ret = brainfuck(str + i, ptr, ']');
	return (ret);
}

static void	process(char **ptr, char op)
{
	if (op == '>')
		(*ptr)++;
	else if (op == '<')
		(*ptr)--;
	else if (op == '+')
		(**ptr)++;
	else if (op == '-')
		(**ptr)--;
	else if (op == '.')
		write(1, *ptr, 1);
}

static int	brainfuck(char *str, char *ptr, char end)
{
	int		i;

	i = (end == ']');
	while (str[i] != end)
	{
		if (str[i] == '[')
			i += loop(str, ptr, i);
		else
			process(&ptr, str[i]);
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	char	arr[2048] = {0};
	char	*ptr;

	ptr = arr;
	if (argc == 2)
		brainfuck(argv[1], ptr, '\0');
	return (0);
}
