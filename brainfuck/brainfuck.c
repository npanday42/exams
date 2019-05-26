/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brainfuck.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/19 15:12:09 by exam          #+#    #+#                 */
/*   Updated: 2018/10/19 17:58:12 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

int		brainfuck(char *str, char *ptr, char end)
{
	int		i;
	int		ret;
	int		loops;
	char	op;
	char	curr;

	i = 0;
	if (end == ']')
		i++;
	while (str[i] != end)
	{
		op = str[i];
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
		else if (op == '[')
		{
			if (*ptr == 0)
			{
				loops = 1;
				while (loops > 0)
				{
					curr = str[++i];
					if (curr == '[')
						loops++;
					else if (curr == ']')
						loops--;
				}
			}
			else
			{
				while (*ptr != 0)
					ret = brainfuck(str + i, ptr, ']');
				i += ret;
			}
		}
		i++;
	}
	return (i);
}