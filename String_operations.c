#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void word_count(char s[]);
void capitalize(char s[]);
void replace(char *, char *, char *);
void main()
{
    char s1[30], s2[30], s3[30];
    printf("\nString Operations using built-in functions\n\n");
    printf("Enter the string : ");
    gets(s1);
    word_count(s1);
    capitalize(s1);
    printf("\nEnter the substring:");
    fflush(stdin);
    gets(s2);
    printf("Enter the string to replace the substring:");
    fflush(stdin);
    gets(s3);
    replace(s1, s2, s3);
    //getch();
}
void word_count(char s[])
{
    int i = 0;
    int wc = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
        {
            wc++;
        }
        i++;
    }
    printf("\nTotal number of words in the string is : %d\n", wc+1);
}
void capitalize(char s[])
{
    int i = 0;
    char new[20];
    new[i] = toupper(s[0]);
    i++;
    while (s[i] != '\0')
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?' ||  s[i] == '\n')
        {
            new[i] = s[i];
            new[i+1] = toupper(s[i+1]);
            i += 2;
        }
        else
        {
            new[i] = s[i];
            i++;
        }
    }
    printf("\nAfter capitalizing: %s\n", new);
}
void replace(char *s1, char *s2, char *s3)
{
    char *p;
    char buf[20];
    p = strstr(s1, s2);
    if (p)
    {
        strncpy(buf, s1, p - s1);
        buf[p - s1] = 0;
        sprintf(buf + (p - s1), "%s%s", s3, p + strlen(s2));
        s1[0] = 0;
        strcpy(s1, buf);
        printf("\n%s", s1);
    }
    else
        printf("String not found\n");
}