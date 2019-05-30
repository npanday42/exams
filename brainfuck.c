/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brainfuck.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/19 15:20:24 by exam           #+#    #+#                */
/*   Updated: 2019/05/30 19:16:27 by npanday       ########   odam.nl         */
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
			i++;
			if (str[i] == '[')
				loops++;
			else if (str[i] == ']')
				loops--;
		}
	else while (*ptr != 0)
		ret = brainfuck(str + i, ptr, ']');
	return (ret);
}

static void	process(char *ptr, char op)
{
	if (op == '>')
		ptr++;
	else if (op == '<')
		ptr--;
	else if (op == '+')
		(*ptr)++;
	else if (op == '-')
		(*ptr)--;
	else if (op == '.')
		write(1, ptr, 1);
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
			process(ptr, str[i]);
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
