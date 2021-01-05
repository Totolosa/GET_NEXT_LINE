#include "get_next_line.h"

int     main()
{
    char    *rs;
    int     fd;
    int     vr;
    fd = open("texte.txt", O_RDONLY);
    while ((vr = get_next_line(fd, &rs)))
    {
        printf("[%d][%s]\n", vr, rs);
        if (rs != 0)
            free(rs);
    }
    printf("[%d][%s]\n", vr, rs);
    return (0);
}