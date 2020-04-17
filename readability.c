#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int i = 0;
    float letters = 0;
    float words = 1;
    float sentences = 0;

    // Prompt text input
    string s = get_string("Text: \n");

    // Stop while loop when end of string is reached
    while (s[i] != '\0')
    {
        for (i = 0; i < strlen(s); i++)
        {
            // Number of letters
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                letters++;
            }

            //Number of words
            if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
            {
                words++;
            }

            // Number of sentences
            if (s[i] == '.' || s[i] == '!' || s[i] == '?')
            {
                sentences++;
            }
        }
    }

    // Coleman-Liau index
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = round(0.0588 * L - 0.296 * S - 15.8);


    printf("%.f letter(s)\n", letters);
    printf("%.f words(s)\n", words);
    printf("%.f sentence(s)\n\n", sentences);

    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index > 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %.f", index);
    }

    printf("\n");
}