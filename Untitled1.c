#include <stdio.h>
#include <string.h>

int main()
{
    int test;

    scanf("%d", &test);

    while(test--)
    {
        char s[60], t[60];

        scanf("%s %s", s, t);

        int tlen = strlen(t), slen = strlen(s);

        for(int i = 0; i < 60; i++)
        {
            if(i < slen)
                printf("%c", s[i]);

            if(i < tlen)
                printf("%c", t[i]);
        }


        printf("\n");
    }

    return 0;
}
