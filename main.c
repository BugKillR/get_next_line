#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    char    *read;
    int fd = open("Text.txt", O_RDWR, 0644);

    read = NULL;
    while(read = get_next_line(fd))
    {
        printf("%s", read);
        free(read);
    }

    return (0);
}