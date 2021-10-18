#include <stdio.h>
#include <string.h> /*strlen function included*/
#include <ctype.h>
#include <stdlib.h>

/*encrypt*/
void encrypt() /*returning string*/
{
    char encrypt[100]; /*message*/
    int key;
    int succeed = 0; /*for success or not*/

    printf("Enter message to encrypt:");
    scanf("%[^\n]s", encrypt); /*get message from user, until newline*/

    if (strlen(encrypt) <= 80) /*length less than 80*/
    {
        while (succeed == 0)
        {
            printf("Enter rotation key:"); /*how much you want to push*/
            scanf("%d", &key);
            if (key >= 0 && key <= 26)
            {
                int i;
                for (i = 0; i < strlen(encrypt); i++)
                {
                    if (encrypt[i] >= 'A' && encrypt[i] <= 'Z') /*if character is alphabet-uppercase*/
                    {
                        encrypt[i] = ((encrypt[i] - 'A' + key) % 26) + 'A';
                    }
                    else if (encrypt[i] >= 'a' && encrypt[i] <= 'z') /*if character is alphabet-lowercase*/
                    {
                        encrypt[i] = ((encrypt[i] - 'a' + key) % 26) + 'a';
                    }
                } /*for end*/
                succeed = 1;
            }
            else
            {
                printf("Error - key must be in range 0 and 26. Try again.\n");
                succeed = 0;
            } /*if-else end*/
        }     /*while end*/
    }
    else
    {
        printf("Invalid number of digits\n");
        exit(EXIT_FAILURE);
    } /*if-else end*/

    printf("Encrypting message (key = %d) : %s\n", key, encrypt);
    exit(EXIT_SUCCESS);
} /*encrypt end*/

int main()
{
    encrypt();

    return 0;
} /*main end*/