/* Programma che:
 * - acquisisce le parole digitate dall'utente come parametri da riga di comando;
 * - stampa il numero di parole inserite, escludendo il nome dell'eseguibile;
 * - stampa ciascuna parola, indicando in quale indice di argv e' presente e la sua lunghezza. */

#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[])
{
    int i, wordnumber, wordlenght;
    wordnumber = argc - 1;
    
    printf ("Numero di parole digitate: %d\n", wordnumber);
    
    for (i = 1; i <= wordnumber; i++)
    {
        wordlenght = strlen(argv[i]);
             
        printf ("argv[%d] = %s, lunghezza: %d\n", i, argv[i], wordlenght);
    }
    
    return 0;
}
