/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rpn_calc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 16:52:11 by npanday        #+#    #+#                */
/*   Updated: 2019/05/20 17:41:10 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	skip(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

static int	rpn_calc(char *str, char op)
{
	static int	i;
	static char	error;
	char		ops[] = "+-*/%";
	int			j;

	if (op == 0)
	{
		i = skip(str);
		error = 0;
	}
	while (str[i] == ' ' && i > 0)
		i--;
	
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("Error\n"));
	rpn_calc(argv[1], 0);
}
