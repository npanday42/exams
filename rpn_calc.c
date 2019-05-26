/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rpn_calc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 16:52:11 by npanday        #+#    #+#                */
/*   Updated: 2019/05/26 22:38:27 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	i;

static char	error;

static char *str;

static int	rpn_calc(void);

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	process(char c)
{
	int		b = rpn_calc();
	int		a = rpn_calc();

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

static int	rpn_calc(void)
{
	char	num = 0;

	if (str[i] != 0 && str[i] != ' ')
		error = 1;
	while (i > 0 && !error)
	{
		i--;
		if (ft_isdigit(str[i]))
			num = 1;
		else if (i == 0)
			error = 1;
		else if (str[i] != ' ')
			return (process(str[i--]));
		else if (num)
			return (atoi(str + i + 1));
	}
	return (error ? 1 : atoi(str + i));
}

int			main(int argc, char **argv)
{
	int	ret;

	if (argc != 2)
		return (printf("Error\n"));
	str = argv[1];
	i = 0;
	while (str[i])
		i++;
	error = 0;
	ret = rpn_calc();
	if (error || i != 0)
		return (printf("Error\n"));
	return (printf("%d\n", ret));
}
