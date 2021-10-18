#include <stdio.h>
#include <string.h> /*strlen function included*/
#include <ctype.h>
#include <stdlib.h>
#define MAX_MSG 80

/*decrypt*/
void decrypt()
{
    char decrypt[MAX_MSG];
    int key;
    int succeed = 0;

    printf("Enter message to decrypt:");
    scanf("%[^\n]s", decrypt); /*get message from user, until newline*/

    if (strlen(decrypt) <= 80) /*length less than 80*/
    {
        while (succeed == 0)
        {
            printf("Enter rotation key:"); /*how much you want to push*/
            scanf("%d", &key);
            if (key >= 0 && key <= 26)
            {
                int i;
                for (i = 0; i < strlen(decrypt); i++)
                {
                    if (decrypt[i] >= 'A' && decrypt[i] <= 'Z') /*if character is alphabet-uppercase*/
                    {
                        decrypt[i] = ((decrypt[i] - 'A' - key) % 26) + 'A';
                    }
                    else if (decrypt[i] >= 'a' && decrypt[i] <= 'z') /*if character is alphabet-lowercase*/
                    {
                        decrypt[i] = ((decrypt[i] - 'a' - key) % 26) + 'a';
                    }
                } /*for end*/
                succeed = 1;
            }
            else
            {
                printf("Error - key must be in range 0 and 26. Try again.\n");
                succeed = 0;
            } /*if-else end*/
        } /*while end*/
    }
    else
    {
        printf("Invalid number of digits\n");
        exit(EXIT_FAILURE);
    } /*if-else end*/

    printf("Encrypting message (key = %d) : %s\n", key, decrypt);
    exit(EXIT_SUCCESS);
} /*decrypt end*/

int main()
{
    decrypt();

    return 0;
} /*main end*/