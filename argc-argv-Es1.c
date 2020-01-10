/* Programma che:
 * - acquisisce le parole digitate dall'utente come parametri da riga di comando;
 * - stampa il numero di parole inserite, incluso il nome dell'eseguibile;
 * - stampa ciascuna parola, indicando in quale indice di argv e' presente e la sua lunghezza. */

#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[])
{
    int i, wordlenght;
    
    printf ("Numero di parole digitate: %d\n", argc);
    
    for (i = 0; i < argc; i++)
    {
        wordlenght = strlen(argv[i]);
             
        printf ("argv[%d] = %s, lunghezza: %d\n", i, argv[i], wordlenght);
    }
    
    return 0;
}
