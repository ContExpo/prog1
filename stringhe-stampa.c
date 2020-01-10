#include <stdio.h>

int main ()
{
    int i;
    char stringa[] = "Ciao";
    
    // Stampa la stringa con %s
    printf ("%s\n", stringa);
    
    // Stampa la stringa con ciclo
    for (i = 0; stringa[i] != '\0'; i++)
        printf ("%c", stringa[i]);
    
    printf ("\n");
    
    return 0;
}
