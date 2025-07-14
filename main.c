#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    char    buffer[BUFFER_SIZE];
    int fd = open("Text.txt", O_RDWR, 0644);

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));

    return (0);
}