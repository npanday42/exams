/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/19 15:20:24 by exam          #+#    #+#                 */
/*   Updated: 2018/10/19 17:31:12 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

int		main(int argc, char **argv)
{
	char	*arr;
	char	*ptr;
	int		i;

	arr = (char *)malloc(2048);
	i = 0;
	while (arr[i])
	{
		arr[i] = 0;
		i++;
	}
	ptr = arr;
	if (argc == 2)
		brainfuck(argv[1], ptr, '\0');
	return (0);
}
