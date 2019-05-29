#include <unistd.h>
#define HEX "0123456789abcdef"

typedef unsigned char t_byte;

static void	print_chars(const void *addr, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)addr;
	i = 0;
	while (i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

static void	print_hex(const void *addr, size_t size)
{
	t_byte	*str;
	size_t	i;

	str = (t_byte *)addr;
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
	char	chars[] = "Hello, World!";

	print_memory(tab, sizeof(tab));
	write(1, "\n", 1);
	print_memory(chars, sizeof(chars) - 1);
	return (1);
}
