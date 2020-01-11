/*
Esercizio 6

Scrivere una funzione che preso in input un vettore con tappo, restituisca
in una variabile passata per riferimento che rappresenta il numero di volte
che il valore massimo nel vettore tappo si presenta.
Restituire -1 se il vettore con tappo è vuoto.
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
}

/* Funzione che:
 * - riceve in ingresso un vettore;
 * - assume come valore massimo quello presente nella prima cella del vettore;
 * - se il vettore non e' vuoto (ossia se il valore presente nella prima cella del vettore e' diverso da -1)
 *   scorre le altre celle per trovare il valore maggiore, fino ad arrivare al tappo;
 * - restituisce il valore maggiore (o -1 se il vettore e' vuoto). */
int calcoloValMax (int v[])
{
    int i, max;
    
    max = v[0];
    
    if (max != -1)
        for (i = 1; v[i] != -1; i++)
            if (max < v[i])
                max = v[i];
            
    return max;
}

/* Funzione che:
 * - riceve un vettore di interi con tappo, un valore e il puntatore ad una variabile;
 * - verifica che il vettore non sia vuoto; se e' vuoto mette -1 nella locazione di memoria puntata dal puntatore;
 * - conta le occorrenze del valore e ne pone il numero nella locazione di memoria puntata dal puntatore;
 * - non restituisce nulla.*/
void contaOccorrenze (int v[], int n, int* occ)
{
    int i;
    
    *occ = 0;
    
    if (v[0] == -1)
        *occ = -1;
    else
        for (i = 0; v[i] != -1; i++)
            if (v[i] == n)
                (*occ)++;
}

/* Funzione main che:
 * - dichiara un vettore di interi;
 * - ricalcola in base a data e ora il punto di partenza per la generazione di valori casuali (seed rand);
 * - richiama la funzione per generare un vettore casuali di interi e lo stampa tramite apposita funzione;
 * - richiama la funzione per trovare il valore massimo contenuto nel vettore;
 * - richiama la funzione per trovare quante volte ricorra un valore in un vettore
 *   passando alla funzione come valore da trovare il valore massimo precedentemente trovato;
 * - in base al valore restituito dalla funzione stampa il numero delle occorrenze del valore massimo
 *   o un messaggio che indica che il vettore e' vuoto. */
int main ()
{
    int vett[DIM], valmax, numocc;
    
    srand (time(NULL));
    
    vettoreCasuale (vett);
    printf ("Vettore:\n");
    stampaVettore (vett);
    
    valmax = calcoloValMax (vett);
    
    contaOccorrenze (vett, valmax, &numocc);
    
    if (numocc == -1)
        printf ("Il vettore e' vuoto\n");
    else
    {
        printf ("Il valore massimo contenuto nel vettore e' %d\n", valmax);
        
        if (numocc == 1)
            printf ("Il valore massimo %d ricorre %d volta\n", valmax, numocc);
        else
            printf ("Il valore massimo %d ricorre %d volte\n", valmax, numocc);
    }
    
    return 0;
}
