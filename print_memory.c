/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_memory.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: npanday <npanday@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 17:05:36 by npanday        #+#    #+#                */
/*   Updated: 2019/06/09 17:05:38 by npanday       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define HEX "0123456789abcdef"

typedef unsigned char t_byte;

static int	isprint(char c)
{
	return (c >= 32 && c <= 126);
}

static void	print_chars(const void *addr, size_t size)
{
	const char	*str;
	size_t		i;

	str = addr;
	i = 0;
	while (i < size)
	{
		if (isprint(str[i]))
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

static void	print_hex(const void *addr, size_t size)
{
	const t_byte	*str;
	size_t			i;

	str = addr;
	i = 0;
	while (i < size)
	{
		write(1, &HEX[str[i] / 16], 1);
		write(1, &HEX[str[i] % 16], 1);
		if ((i + 1) % 2 == 0)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if ((i + 1) % 2 == 0)
			write(1, " ", 1);
		i++;
	}
}

static void	print_memory(const void *addr, size_t size)
{
	size_t	i;
	size_t	line_size;

	i = 0;
	while (i < size)
	{
		line_size = (size - i >= 16) ? 16 : size - i;
		print_hex(addr + i, line_size);
		print_chars(addr + i, line_size);
		write(1, "\n", 1);
		i += 16;
	}
}

int			main(void)
{
	int		tab[10] = {0, 23, 150, 255, 12, 16, 42, 103};

	print_memory(tab, sizeof(tab));
	return (1);
}
