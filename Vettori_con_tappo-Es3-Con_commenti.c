/*
Esercizio 3

Scrivere una funzione che presi in input due vettori con tappo e il nome di un file,
scriva sul file la parte eccedente del vettore più lungo (un elemento per riga).

int vettoriConTappoFile (int A[], int B[], int n, char *nomeFile)

Nel caso che i vettori contengano lo stesso numero di elementi, creare un file vuoto.
Restituire come valore di ritorno il numero di elementi salvati, oppure -1 nel caso di errore di scrittura del file.
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
 * - riceve due vettori di interi e una stringa;
 * - apre in scrittura il file con il nome indicato nella stringa ricevuta; se non è possibile aprire in scrittura il file
 *   pone -1 in una apposita variabile;
 * - confronta la lunghezza dei due vettori di interi e scrive nel file i eccedenti di quello piu' lungo, uno per riga;
 * - chiude il file;
 * - restituisce il valore della differenza di lunghezza tra i due vettori, o -1 se non e' stato possibile aprire il file in lettura. */
int vettoriConTappoFile (int v1[], int v2[], char nomeFile[])
{
    int p;
    FILE* fp;
    fp = fopen (nomeFile, "w");
    
    // Gestione dell'errore: caso in cui non sia possibile aprire il file in scrittura
    if (fp == NULL)
        p = -1;
    
    else
    {
        int i, nv1, nv2, diff;
        nv1 = 0;
        nv2 = 0;
        
        // Conteggio dei valori presenti nel primo vettore
        for (i = 0; v1[i] != -1; i++);
        nv1 = i;
        
        // Conteggio dei valori presenti nel secondo vettore
        for (i = 0; v2[i] != -1; i++);
        nv2 = i;
        
        
        if (nv1 > nv2)
        {
            // Caso in cui il primo vettore contenga piu' valori del secondo:
            // la copia comincia dalla casella del primo vettore di indice uguale al numero dei valori contenuti nel secondo
            // e termina quando si trova il valore tappo "-1" nel primo vettore
            for (i = nv2; v1[i] != -1; i++)
                fprintf (fp, "%d\n", v1[i]);
            
            p = nv1 - nv2;
        }
        else
            if (nv2 > nv1)
            {
                // Caso in cui il secondo vettore contenga piu' valori del primo:
                // la copia comincia dalla casella del secondo vettore di indice uguale al numero dei valori contenuti nel primo
                // e termina quando si trova il valore tappo "-1" nel secondo vettore
                for (i = nv1; v2[i] != -1; i++)
                    fprintf (fp, "%d\n", v2[i]);
                
                p = nv2 - nv1;
            }
            else
            {
                // Caso in cui il primo e il secondo vettore contengano lo stesso numero di valori
                p = 0;
            }
            
    fclose (fp);
    }
    
    // viene restituito il valore della differenza tra il numero dei valori dei due vettori
    // oppure -1 in caso di errore nell'apertura in scrittura del file
    return p;
}

/* Funzione main che:
 * - dichiara due vettori di interi;
 * - ricalcola in base a data e ora il punto di partenza per la generazione di valori casuali (seed rand);
 * - richiama due volte la funzione per generare due vettori casuali di interi e li stampa tramite apposita funzione;
 * - chiede all'utente il nome per un file;
 * - passa i due vettori e il nome del file alla funzione che stampa nel file i valori eccedenti del vettore piu' lungo;
 * - in base al valore ricevuto dalla funzione stampa a schermo il numero di valori eccedenti o un messaggio di errore
 *   se non e' stato possibile aprire il file in lettura. */
int main ()
{
    int vett1[DIM], vett2[DIM], differenza;
    char nomefile[31];
    
    srand (time(NULL));
    
    vettoreCasuale (vett1);
    stampaVettore (vett1);
    
    vettoreCasuale (vett2);
    stampaVettore (vett2);
    
    printf ("Digita il nome per il file nel quale salvero' i valori eccedenti del vettore piu' lungo\n(max 30 caratteri): ");
    scanf ("%s", nomefile);
    
    differenza = vettoriConTappoFile (vett1, vett2, nomefile);
    
    if (differenza == -1)
        printf ("ERRORE! Non e' possibile scrivere sul file %s\n", nomefile);
    else
        printf ("La differenza di lunghezza tra i due vettori e' di %d valori\n", differenza);
}
