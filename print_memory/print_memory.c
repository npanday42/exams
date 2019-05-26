#include <unistd.h>

// void	print_memory(const void *addr, size_t size)
// {
// 	int		i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		write(STDOUT_FILENO, )
// 	}
// }

int		main(void)
{
	int		i;
	char	*c;

	i = 0;
	c = 30;
	while (i < 128)
	{
		write(1, c + i, 1);
		if ((i + 1) % 16 == 0)
			write(1, "\n", 1);
		else if (i < 255)
			write(1, "-", 1);
		i++;
	}
	return (0);
}