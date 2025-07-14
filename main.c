#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void    ft_read(int fd)
{
        char    *read;
        read = get_next_line(fd);
        printf("%s", read);
        free(read);
}

int main(void)
{
    int fd = open("Text.txt", O_RDWR, 0644);

    ft_read(fd);
    ft_read(fd);
    ft_read(fd);

    return (0);
}