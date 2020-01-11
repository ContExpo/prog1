/*
Esercizio 4

Scrivere una funzione che preso in input un vettore con tappo, restuisca all’esterno
quanti sono i valori positivi, i valori negativi e i valori nulli.

NOTA: Io eseguo l'esercizio come richiesto, ma per definizione un vettore con tappo
           puo' contenere solo valori postivi o nulli, quindi il contatore per i valori negativi
           non ha molto senso.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 11

/* Funzione che:
 * - riceve in ingresso un vettore di interi;
 * - genera una numero casuale tra 0 e DIM -1, che sara' il numero dei valori che verranno inseriti nel vettore;
 * - assegna a ciascuna cella del vettore un numero casuale tra 0 e 100, fino al numero di valori prima generato;
 * - assegna "-1", ossia il valore tappo, alla cella successiva all'ultimo valore inserito;
 * - non restituisce nulla. */
void vettoreCasuale (int v[])
{
    int i, nv;
    // Genera un numero casuale tra 0 e DIM -1 e lo assegna a nv
    nv = ( rand() ) % DIM;
    
    for (i = 0; i < nv; i++)
        // Genera un numero casuale tra 0 e 100 e lo assegna a v[i]
        v[i] = ( rand() ) % 101;
    
    // Assegna -1 alla cella immediatamente successiva all'ultimo valore caricato
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

/* Funzione che:
 * - riceve in ingresso un vettore di interi e i puntatori a tre variabili di interi;
 * - visita il vettore e incrementa la variabile opportuna a seconda che il valore trovato sia positivo, negativo o nullo;
 * - non restituisce nulla. */
void contaPosNegNul (int v[], int* pos, int* neg, int* nul)
{
    int i;
    *pos = 0;
    *neg = 0;
    *nul = 0;
    
    for (i = 0; i < DIM-1 && v[i] != -1; i++)
        if (v[i] > 0)
            (*pos)++; // Incrementa di 1 il valore puntato da pos
        else
            if (v[i] < 0)
                (*neg)++; // Incrementa di 1 il valore puntato da pos
                else
                    (*nul)++; // Incrementa di 1 il valore puntato da nul
}

/* Funzione main che:
 * - dichiara un vettore di interi e tre variabili;
 * - ricalcola in base a data e ora il punto di partenza per la generazione di valori casuali (seed rand);
 * - richiama la funzione per generare un vettore casuale di interi e lo stampa tramite apposita funzione;
 * - richiama la funzione per contare quanti valori positivi, negativi o nulli ci sono nel vettore;
 *    le variabili relative ai tre contatori vengono passate per riferimento;
 * - stampa i valori dei tre contatori. */
int main ()
{
    int vett[DIM], valpos, valneg, valnul;
    
    srand (time(NULL));
    
    vettoreCasuale (vett);
    stampaVettore (vett);
    
    contaPosNegNul (vett, &valpos, &valneg, &valnul);
    
    printf ("Il vettore contiene %d valori positivi, %d valori negativi e %d valori nulli\n", valpos, valneg, valnul);
    
    return 0;
}
