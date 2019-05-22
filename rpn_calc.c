/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rpn_calc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 16:52:11 by npanday        #+#    #+#                */
/*   Updated: 2019/05/22 13:39:38 by npanday       ########   odam.nl         */
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

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	rpn_calc(char *str);

static int	process(char *str)
{
	char	c = str[i];
	int		b;
	int		a;

	i--;
	b = rpn_calc(str);
	a = rpn_calc(str);
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	if (c == '/')
		return (a / b);
	if (c == '%')
		return (a % b);
	return (0);
}

static int	rpn_calc(char *str)
{
	char	num = 0;

	if (str[i] != 0 && str[i] != ' ')
		error = 1;
	while (i > 0 && !error)
	{
		i--;
		if (num && str[i] == ' ')
			return (atoi(str + i + 1));
		else if (ft_isdigit(str[i]))
			num = 1;
		else if (is_op(str[i]))
			return (process(str));
		else if (str[i] != ' ')
			error = 1;
	}
	if (i == 0 && !ft_isdigit(str[i]))
		error = 1;
	if (error)
		return (1);
	return (atoi(str + i));
}

int			main(int argc, char **argv)
{
	int	ret;

	if (argc != 2)
		return (printf("Error\n"));
	while (argv[1][i])
		i++;
	ret = rpn_calc(argv[1]);
	if (error || i != 0)
		return (printf("Error\n"));
	return (printf("%d\n", ret));
}
