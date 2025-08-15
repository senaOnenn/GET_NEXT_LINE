#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("single.txt", O_RDONLY);
    char *line[100];
    int count = 0;

    if (fd < 0)
    {
        perror("Dosya açılamadı");
        return (1);
    }
    while((line[count] = get_next_line(fd)) != NULL)
        count++;
    close (fd);

    while (count > 0)
    {
        count --;
        printf("%s", line[count]);
        free(line[count]);
    }
    return (0);
}
