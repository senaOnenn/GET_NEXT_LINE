#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *saved;
    char *buff;
    int read_count;
    if(!saved)
        saved = ft_strdup("");
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    read_count = 1;
    while(!ft_strchr(saved, '\n') && read_count > 0)
    {
        read_count = read(fd, buff, BUFFER_SIZE);
        if (read_count == -1)
        {
            free(buff);
            free(saved);
            saved = NULL;
            return (NULL);
        }
        buff [read_count] = '\0';
        saved = ft_strjoin(saved, buff);
    }
    free(buff);
    return(NULL);
}