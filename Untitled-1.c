#include <stdio.h>
#include <string.h>

int main()
{
    int mx = 1e7 + 5;

    char s[mx];

    scanf("%s", s);

    int a[26];

    memset(a, 0, sizeof(a));

    for(int i = 0; i < strlen(s); i++)
        a[s[i] - 'a']++;

    for(int i = 0; i < 26; i++)
    {
        if(a[i])
            printf("%c : %d\n", i + 'a', a[i]);
    }


    return 0;
}
