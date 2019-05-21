/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rpn_calc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 16:52:11 by npanday        #+#    #+#                */
/*   Updated: 2019/05/21 10:53:42 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	i = 0;

static char	error = 0;

static int	is_op(char c)
{
	if (c != '+')
		if (c != '-')
			if (c != '*')
				if (c != '/')
					if (c != '%')
						return (0);
	return (1);
}

static int	isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	rpn_calc(char *str, char op)
{
	char	num = 0;

	if (op != 0 && str[i] != ' ')
		error = 1;
	while (i > 0 && !error)
	{
		i--;
		if (str[i] == ' ')
			if (num)
				return (atoi(str + i + 1));
		else if (str[i] >= '0' && str[i] <= '9')
			num = 1;
		else if (is_op(str[i]))
			return (process());
		else
			error = 1;
	}
	if (i == 0 && )
}

int			main(int argc, char **argv)
{
	int	ret;

	while (argv[1][i])
		i++;
	if (argc != 2)
		return (printf("Error\n"));
	ret = rpn_calc(argv[1], 0);
}
