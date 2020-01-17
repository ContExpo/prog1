#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
///Splits str1 into two pieces pointed by str1 and str2 at first ' ' character found, replacing it with a '\0'
///NOTE: NOTHING WILL HAPPEN IS NOT DEFINED IF str1[0] is '\0' or '\n'
void split(char *str1, char **str2);
///Returns 1 if character is contained in str1
int containsChar (char *str1, char character);
///Returns 1 if all the characters contained in str2 are contained in str1
int contains (char *str1, char *str2);
///Replaces every occurrence in hayball of oldChar with newChar
void replace (char *hayball, char oldChar, char newChar);

void split(char *str1, char **str2)
{
    for (int i=0; str1[i]!='\0' && str1[i]!='\n'; i++)
    {
        if(str1[i]==' ')
        {
            str1[i]='\0';
            *str2=&str1[i+1];
        }
    }
}

void replace (char *hayball, char oldChar, char newChar)
{
    for (int i=0; hayball[i]!='\0'; i++)
    {
        if (hayball[i]==oldChar)
            hayball[i]=newChar;
    }
}

int containsChar (char *str1, char character)
{
    printf("\t %s contains %c?", str1, character);
    for (int i=0; str1[i]!='\0'; i++)
    {
        if (str1[i]==character)
        {
            printf("true\n");
            return true;
        }

    }
    printf("false\n");
    return false;
}

int contains (char *str1, char *str2)
{
    //printf("%s deve contenere %s", str1, str2);
    for (int i=0; str2[i]!='\0'; i++)
    {
        if (!containsChar(str1, str2[i]))
            return false;
    }
    return true;
}

int main()
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w+");
    if (ferror(input))
    {
        printf("Errore di apertura file di input");
        return -1;
    }
    if (ferror(output))
    {
        printf("Errore di apertura file di output");
        return -1;
    }
    char riga[101], *parola2;
    while (!feof(input))
    {
        fgets(riga, 101, input);
        if (riga[0]=='\n' || riga[0]=='\0') //Anche se è praticamente impossibile che ci sia un \0
        {
            printf("****RIGA VUOTA****\n");
            fprintf(output, "****RIGA VUOTA****\n");
        }
        else
        {
            split(riga, &parola2);
            replace(parola2, '\n', '\0');
            fprintf(output, "%s %s->", riga, parola2);

            printf("\n%s contains %s -->\n", riga, parola2);
            if (contains(riga, parola2))
            {
                printf("TRUE\n");
                fprintf(output, "TRUE\n");
            }
            else
            {
                fprintf(output, "FALSE\n");
                printf("FALSE\n");
            }
            //printf("Prima parola: %s, seconda parola: %s", riga, parola2);
        }
    }
    fclose(input);
    fclose(output);
}
