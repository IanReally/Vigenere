#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
    //check that there are two arguements provided by user, else print error
    if (argc != 2)
    {
        printf("User must provide key. Please use a single word containing only alphabetical characters. \n");
        return 1;
    }

    string key = (argv[1]);

    //create for loop to iterate over each letter in "key" and store the number of characters in "keylen"
    for (int i = 0, keylen = strlen(key); i < keylen; i++)
    {
        //if the letters in the string "key" are not alphabetical characters, print error
        if (!isalpha(key[i]))
        {
            printf("Please provide a single word containing only alphabetical characters. \n");
            return 1;
        }
    }

    //get plaintext from user, store in string "plntxt", then print "Ciphertext: " for later use.
    string plntxt = get_string("Enter Plaintext: ");
    printf("ciphertext: ");

    //create for loop to itereate over "plntxt" and store length of string as "txtlen"
    for (int j = 0, txtlen = strlen(plntxt); j < txtlen; j++)
    {

        int keylen = strlen(key);
        int i = (j % keylen);


        if (isalpha (plntxt[j]))
        {
            if (isupper(plntxt[j]) && isupper(key[i]))
            {
                printf("%c", ((((plntxt[j] - 65) + (key[i] - 65)) % 26) + 65));
            }

            else if (isupper(plntxt[j]) && islower(key[i]))
            {
                printf("%c", ((((plntxt[j] - 65) + (key[i] - 97)) % 26) + 65));
            }

            else if (islower(plntxt[j]) && isupper(key[i]))
            {
                printf("%c", ((((plntxt[j] - 97) + (key[i] - 65)) % 26) + 97));

            }
            else if (islower(plntxt[j]) && islower(key[i]))
            {
                printf("%c", ((((plntxt[j] - 97) + (key[i] - 97)) % 26) + 97));

            }
        }
        //print non-alphabetical characters as normal
        else
        {
            printf("%c", plntxt[j]);
        }

    }
    //print new line, end program
    printf("\n");
    return 0;
}
