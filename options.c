/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 17:05:44 by npanday        #+#    #+#                */
/*   Updated: 2019/06/09 17:09:34 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_options(unsigned int *options)
{
	int		i;
	char	c;

	i = 0;
	while (i < 32)
	{
		if (!(i % 8) && i)
			write(1, " ", 1);
		c = '0' + !!((1U << (31 - i)) & *options);
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

static int	options(char *str, unsigned int *opt)
{
	int			i;
	char		c;

	if (*str == 'h')
		return (0);
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 'a' && c <= 'z')
			*opt |= (1U << (c - 'a'));
		else
			return (-1);
		i++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	unsigned int	opt;
	int				ret;
	int				i;

	if (argc == 1)
		return (write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
	opt = 0;
	ret = 1;
	i = 1;
	while (i < argc)
	{
		if (*argv[i] == '-')
			ret = options(argv[i] + 1, &opt);
		if (ret == 0)
			return (write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36));
		else if (ret == -1)
			return (write(1, "Invalid Option\n", 15));
		i++;
	}
	print_options(&opt);
	return (1);
}
