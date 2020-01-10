#include <stdio.h>
#include <string.h>

int main ()
{
    int i, wordlenght;
    char stringa[] = "Ciao";
    
    // Conta lunghezza con strlen
    wordlenght = strlen (stringa);
    printf ("La parola %s e' lunga %d caratteri\n", stringa, wordlenght);
    
    // Conta lunghezza con ciclo
    wordlenght = 0;
    for (i = 0; stringa[i] != '\0'; i++)
        wordlenght++;
    printf ("La parola %s e' lunga %d caratteri\n", stringa, wordlenght);
    
    return 0;
}
