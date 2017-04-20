#include"header.h"
char *strcpy1(char *str1, char *str2, int i, int j)
{
    int k = 0;
    while (i <= j) {
	*(str2 + k) = *(str1 + i);
	i++;
	k++;
    }

    *(str2 + k) = '\0';
    return (str2);

}

