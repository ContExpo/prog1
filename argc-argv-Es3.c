/* Programma che:
 * - acquisisce le parole digitate dall'utente come parametri da riga di comando;
 * - stampa il numero di parole inserite
 * - stampa ciascuna parola, indicando in quale indice di argv e' presente e la sua lunghezza;
 * - copia le parole in una matrice definita in base al numero delle parole digitate e alla lunghezza della parola piu' lunga;
 * - stampa la matrice;
 * - riordina i valori in ordine lessicograficamente crescente;
 * - stampa la matrice;
 * - riordina i valori in ordine lessicograficamente decrescente;
 * - stampa la matrice.  */

#include <stdio.h>
#include <string.h>

/* Funzione che:
 * - riceve in input il numero di parole acquisite da linea di comando (argc) e il puntatore all'array dove sono memorizzate (argv[]);
 * - trova la lunghezza massima tra le parole inserite;
 * - restituisce tale valore. */
int lunghmax (int argc, char* argv[])
{
    int i, max = 0;
    
    for (i = 0; i < argc; i++)
        if (strlen(argv[i]) > max)
            max = strlen(argv[i]);
            
    return max;
}

/* Funzione che:
 * - riceve in input il numero di parole acquisite da linea di comando (argc), il puntatore all'array dove sono memorizzate (argv[]), la lunghezza massima tra le parole inserite e una matrice;
 * - carica le parole acquisite da linea di comando nella matrice;
 *. - non restituisce nulla. */
void caricamatrice (int argc, char* argv[], int lunghmax, char matrice[][lunghmax])
{
    int i;
    
    for (i = 0; i < argc; i++)
        strcpy (matrice[i], argv[i]);
}

/* Funzione che:
 * - riceve in input il numero di parole acquisite da linea di comando (argc), la lunghezza massima tra le parole inserite e la matrice nella quale sono memorizzate;
 * - stampa la matrice;
 *. - non restituisce nulla. */
void stampamatrice (int argc, int lunghmax, char matrice[][lunghmax])
{
    int i;
    
    for (i = 0; i < argc; i++)
        printf ("Parola in posizione %d della matrice: %s\n", i, matrice[i]);
}

/* Funzione che:
 * - riceve in input il numero di parole acquisite da linea di comando (argc), la lunghezza massima tra le parole inserite e la matrice nella quale sono memorizzate;
 * - riordina la matrice in ordine lessicograficamente crescente;
 *. - non restituisce nulla. */
void riordinocrescente (int argc, int lunghmax, char matrice[][lunghmax])
{
    int i, j;
    char temp[lunghmax];
    
    for (i = 0; i < argc-1; i++)
        for (j = i + 1; j < argc; j++)
            if ( (strcmp (matrice[i], matrice[j]) ) > 0 )
            {
                strcpy (temp, matrice[i]);
                strcpy (matrice[i], matrice[j]);
                strcpy (matrice[j], temp);
            }
}

/* Funzione che:
 * - riceve in input il numero di parole acquisite da linea di comando (argc), la lunghezza massima tra le parole inserite e la matrice nella quale sono memorizzate;
 * - riordina la matrice in ordine lessicograficamente decrescente;
 *. - non restituisce nulla. */
void riordinodecrescente (int argc, int lunghmax, char matrice[][lunghmax])
{
    int i, j;
    char temp[lunghmax];
    
    for (i = 0; i < argc-1; i++)
        for (j = i + 1; j < argc; j++)
            if ( (strcmp (matrice[i], matrice[j]) ) < 0 )
            {
                strcpy (temp, matrice[i]);
                strcpy (matrice[i], matrice[j]);
                strcpy (matrice[j], temp);
            }
}

/* Funzione main che:
 * - riceve una serie di parole da linea di comando;
 * - stampa il numero di parole digitate (incluso il nome dell'eseguibile);
 * - stampa la posizione di ciascuna parola in argv e la sua lunghezza;
 * - richiama la funzione per il calcolo della lunghezza massima tra le parole inserite e ne stampa il valore;
 * - dichiara una matrice di m righe e n colonne, dove:
 *    - m = numero delle parole inserite;
 *    - n = lunghezza della parola più lunga aumentata di uno per lasciare spazio al carattere di fine stringa '\0';
 * - richiama la funzione per caricare nella matrice le parole digitate;
 * - richiama la funzione per stampare la matrice;
 * - richiama la funzione per riordinare le parole in ordine lessicograficamente crescente;
 * - richiama la funzione per stampare la matrice;
 * - richiama la funzione per riordinare le parole in ordine lessicograficamente decrescente;
 * - richiama la funzione per stampare la matrice. */
int main (int argc, char* argv[])
{
    int i, wordlenght, maxlenght;
    
    printf ("Numero di parole digitate: %d\n", argc);
    
    for (i = 0; i < argc; i++)
    {
        wordlenght = strlen(argv[i]);
             
        printf ("argv[%d] = %s, lunghezza: %d\n", i, argv[i], wordlenght);
    }
    
    maxlenght = lunghmax (argc, argv);
    
    printf ("\nLa parola di lunghezza massima misura %d caratteri\n", maxlenght);
    
    //aumento maxlenght di uno per far spazio al carattere di fine stringa
    maxlenght++;
    // Dichiarazione di una matrice con argc righe (numero parole) e maxlenght colonne (lunghezza delle parole)
    char matrice[argc][maxlenght];
    
    caricamatrice (argc, argv, maxlenght, matrice);
    printf ("\nMatrice in ordine di inserimento:\n");
    
    stampamatrice (argc, maxlenght, matrice);
    
    riordinocrescente (argc, maxlenght, matrice);
    printf ("\nMatrice riordinata in ordine crescente:\n");
    stampamatrice (argc, maxlenght, matrice);
    
    riordinodecrescente (argc, maxlenght, matrice);
    printf ("\nMatrice riordinata in ordine decrescente:\n");
    stampamatrice (argc, maxlenght, matrice);
    
    return 0;
}
