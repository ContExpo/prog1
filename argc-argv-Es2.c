/* Programma che:
 * - acquisisce le parole digitate dall'utente come parametri da riga di comnado;
 * - stampa il numero di parole inserite, incluso il nome dell'eseguibile;
 * - stampa ciascuna parola, indicando in quale indice di argv e' presente e la sua lunghezza;
.*.  la lunghezza di ciascuna parola viene calcolata usando l'artimetica dei puntatori e non la funzione strlen */

#include <stdio.h>

int main (int argc, char* argv[])
{
    int i, j, wordlenght;
    printf ("Numero di parole digitate: %d\n", argc);
    
    // ciclo esterno che scorre tutte le parole inserite
    for (i = 0; i < argc; i++)
    {
        wordlenght = 0;
        
        // ciclo interno che scorre ciascuna parola carattere per carattere e incrementa wordlenght di 1 finche' non trova il carattere di fine stringa '\0'
        for (j = 0; *(argv[i] + j) != '\0'; j++)
            wordlenght++;
        
        printf ("argv[%d] = %s, lunghezza: %d\n", i, argv[i], wordlenght);
    }
}
