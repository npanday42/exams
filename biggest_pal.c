#include <unistd.h>
#include <stdio.h>

int     biggest_pal(char *str, size_t len)
{
    size_t  max = 1;
    size_t  i;
    size_t  j;
    size_t  k;
    size_t  l;
    char    *pal = str;

    i = 0;
    while (str[i])
    {
        j = len - 1;
        while (j >= i && j > 0)
        {
            k = i;
            l = j;
            while (str[k] == str[l])
            {
                if (l <= k)
                {
                    if (j - i + 1 >= max)
                    {
                        max = j - i + 1;
                        pal = str + i;
                    }
                    break;
                }
                k++;
                l--;
            }
            j--;
        }
        i++;
    }
    return (write(1, pal, max));
}

int     main(int argc, char **argv)
{
    size_t len;

    if (argc == 2)
    {
        len = 0;
        while (argv[1][len])
            len++;
        biggest_pal(argv[1], len);
    }
    return (write(1, "\n", 1));
}