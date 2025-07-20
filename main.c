#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    char    *read;
    char    *read2;
    int fd = open("Text.txt", O_RDWR, 0644);
    int fd2 = open("Text2.txt", O_RDWR, 0644);
    
    read = get_next_line(fd);
    read2 = get_next_line(fd2);

    while(read || read2)
    {
        if (read)
        {
            printf("%s", read);
            free(read);
            read = get_next_line(fd);
        }
        if (read2)
        {
            printf("%s", read2);
            free(read2);
            read2 = get_next_line(fd2);
        }
    }

    return (0);
}