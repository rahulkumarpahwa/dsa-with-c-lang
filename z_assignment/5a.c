#include <stdio.h>
#include <ctype.h> // for isspace() method

void main()
{
    FILE *fp = NULL;
    fp = fopen("words.txt", "r");

    char ch;
    int in_word = 0, word_count = 0;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isspace(ch))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            word_count++;
            in_word = 1;
        }
    }

    printf("The Number of words in the file: %d", word_count);
}