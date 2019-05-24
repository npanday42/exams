/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rpn_calc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 16:52:11 by npanday        #+#    #+#                */
/*   Updated: 2019/05/24 21:54:42 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	i;

static char	error = 0;

static int	rpn_calc(char *str);

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	process(char *str, char c)
{
	int		b = rpn_calc(str);
	int		a = rpn_calc(str);

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
	error = 1;
	return (1);
}

static int	rpn_calc(char *str)
{
	char	num = 0;

	if (str[i] != 0 && str[i] != ' ')
		error = 1;
	while (i > 0 && !error)
	{
		i--;
		if (ft_isdigit(str[i]))
			num = 1;
		else if (str[i] == ' ')
			if (num)
				return (atoi(str + i + 1));
		else
			return (process(str, str[i--]));
	}
	return (error ? 1 : atoi(str + i));
}

int			main(int argc, char **argv)
{
	int	ret;

	if (argc != 2)
		return (printf("Error\n"));
	i = 0;
	while (argv[1][i])
		i++;
	ret = rpn_calc(argv[1]);
	if (error || i != 0)
		return (printf("Error\n"));
	return (printf("%d\n", ret));
}
