/* Esercizio 1

Caricamento dei valori in un vettore con tappo e stampa attraverso funzioni con passaggio dei dati per valore.

*/

#include <stdio.h>
#define DIM 11

/* Funzione che:
 * - riceve un vettore di interi;
 * - chiede all'utente di digitare un valore, fino ad un massimo di (DIM -1);
 * - inserisce tale valore nella prima cella libera del vettore;
 * - controlla che il valore non sia negativo; nel caso visualizza un opportuno messaggio e ripete la richiesta;
 * - chiede il valore successivo finche' l'utente non digita (DIM - 1) valori oppure il valore di fine sequenza "-1";
 * - carica il tappo "-1" nella prima cella libera del vettore;
 * - non restituisce nulla. */
void caricaVettore (int v[])
{
    int i;
    i = 0;
    
    printf ("Digita una serie di valori interi e positivi\n");
    do
    {
        do
        {
            printf ("Digita il valore in posizione %d, -1 per terminare: ", i);
            // &v[i] e' la locazione di memoria della prima cella libera del vettore: v[0] al primo clcio, v[1] al secondo, v[2] al terzo...
            scanf ("%d", &v[i]);
            
            // v[i] e' la cella del vettore dove e' stato memorizzato il valore appena acquisito
            if (v[i] < 0 && v[i] != -1)
                printf ("Solo valori positivi!\n");
        }
        // ripete il ciclo piu' interno (cioe' ripete la richiesta per la stessa cella del vettore: la variabile i non e' ancora stata incrementata)
        // finche' l'utente digita un valore negativo diverso da -1
        while (v[i] < 0 && v[i] != -1);
        
        i++;
    }
    // ripete il ciclo piu' esterno (cioe' passa a richiedere il valore per la cella successiva: la variabile i e' gia' stata incrementata)
    // finche' non e' stato digitato il valore in ultima posizione o finche' l'utente non digita il valore di fine sequenza "-1";
    // da DIM si sottrae 1 dato che c'e' bisogno di lasciare libera per il tappo "-1" almeno una cella del vettore
    // la cella dove e' stato memorizzato il valore appena acquisito ora e' v[i-1] dato che la variabile i e' gia' stata incrementata di 1
    while (i < (DIM - 1) && v[i -1] != -1);
    
    // al termine mette "-1" (cioe' il tappo) nella cella del vettore immediatamente successiva all'ultima caricata
    v[i] = -1;
}

/* Funzione che:
 * - riceve un vettore di interi;
 * - stampa i valori contenuti nel vettore;
 * - non restituisce nulla. */
void stampaVettore (int v[])
{
    int i;
    
    // v[i] e' la cella del vettore da stampare: v[0] al primo ciclo, v[1] al secondo, v[2] al terzo...
    for (i = 0; v[i] != -1; i++)
        printf ("Valore in posizione %d del vettore: %d\n", i, v[i]);
    
    printf ("\n");
}

/* Funzione main che:
 * - definisce un vettore di interi di dimensione pari ad una costante DIM;
 * - richiama la funzione per caricare i valori nel vettore passando il vettore;
 * - richiama la funzione per stampare i valori nel vettore passando il vettore. */
int main ()
{
    int vett[DIM];
    
    // "vett" equivale a "&vett[0]", cioe' all'indirizzo di memoria della prima casella del vettore: si passa comunque un puntatore;
    // la differenza tra passaggio per valore o per riferimento con un vettore dipende dalla funzione che riceve
    caricaVettore (vett);
    
    // "vett" equivale a "&vett[0]", cioe' all'indirizzo di memoria della prima casella del vettore: si passa comunque un puntatore;
    // la differenza tra passaggio per valore o per riferimento con un vettore dipende dalla funzione che riceve
    stampaVettore (vett);
    
    return 0;
}
