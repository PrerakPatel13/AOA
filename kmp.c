#include <stdio.h>
#include <string.h>

int *prefix_fun(char *p)
{
    static int pie[100], k = 0;
    pie[0] = 0;
    for (int i = 1; i < strlen(p); i++)
    {
        while (k > 0 && p[k] != p[i])
        {
            k = pie[k];
        }
        if (p[k] == p[i])
        { 
            k += 1;
        }
        pie[i] = k;
    }
    return pie;
}

void main()
{
    int tlen, plen, q = 0;
    int *pie;
    char text[200] = "xyzahxyfxyzd", pat[100] = "xyz";
    tlen = strlen(text);
    plen = strlen(pat);
    pie = prefix_fun(pat);
    for (int i = 0; i < tlen; i++)
    {
        while (q > 0 && pat[q] != text[i])
        {

            q = pie[q - 1];
        }
        if (pat[q] == text[i])
        {
            q += 1;
        }
        if (q == plen)
        {
            printf("pattern occurs at %d , pattern : ", i - plen + 1);
            for (int j = (i - plen + 1); j < i + 1; j++)
            {
                printf("%c", text[j]);
            }
            q = pie[q - 1];
            printf("\n");
        }
    }
}