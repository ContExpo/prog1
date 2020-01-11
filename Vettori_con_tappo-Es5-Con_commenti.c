/*
Esercizio 5

Scrivere una funzione che presi in input due vettori con tappo (A, B) metta in un terzo (passato alla funzione vuoto - C) il risultato della concatenazione dei due.

Esempio:

A: [1, 2, 9, 6, 12, -1]
B: [4, 89, 70, -1]
C: [1, 2, 9, 6, 12, 4, 89, 70, -1]
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
 * - riceve un vettore di interi;
 * - conta i valori presenti nel vettore;
 * - restituisce tale valore. */
int contaValori (int v[])
{
    int i;
    
    // Ciclo vuoto che prosegue finche' il valore contenuto in v[i] non e' -1 (cioe' il tappo)
    // Al termine del ciclo il contatore i indicherà quante volte il ciclo e' stato ripetuto, ossia quanti valori il vettore contiene prima di -1
    for (i = 0; v[i] != -1; i++);
    
    return i;
}

/* Funzione che:
 * - ricene tre vettori di interi;
 * - carica nel terzo vettore i valori contenuti nel primo;
 * - carica nel terzo vettore a partire dalla cella immediatamente successiva all'ultima caricata i valori del secondo vettore;
 * - carica nel terzo vettore nella cella immediatamente successiva all'ultima caricata il valore tappo "-1";
 * - non restituisce nulla. */
void concatenaVettori (int v1[], int v2[], int v3[])
{
    int i, j;
    
    for (i = 0; v1[i] != -1; i++)
        v3[i] = v1[i];
    
    j = i;
    
    for (i = 0; v2[i] != -1; i++)
        v3[i + j] = v2[i];
    
    v3[i + j] = -1;
}

/* Funzione main che:
 * - dichiara due vettori di interi;
 * - ricalcola in base a data e ora il punto di partenza per la generazione di valori casuali (seed rand);
 * - richiama due volte la funzione per generare due vettori casuali di interi e li stampa tramite apposita funzione;
 * - richiama la funzione per contare i valori contenuti nei due vettori;
 * - dichiara un terzo vettore di dimensione pari alla somma del numero dei valori contenuti negli altri vettori +1 per il tappo;
 * - richiama la funzione per caricare nel terzo vettore i valori del primo vettore, quindi quelli del secondo;
 * - stampa il terzo vettore. */
int main ()
{
    int vett1[DIM], vett2[DIM], numval1, numval2;
    
    srand (time(NULL));
    
    vettoreCasuale (vett1);
    printf ("Vettore 1:\n");
    stampaVettore (vett1);
    
    vettoreCasuale (vett2);
    printf ("Vettore 2:\n");
    stampaVettore (vett2);
    
    numval1 = contaValori (vett1);
    numval2 = contaValori (vett2);
    
    int vett3[numval1 + numval2 + 1];
    
    concatenaVettori (vett1, vett2, vett3);
    
    printf ("Vettore 3:\n");
    stampaVettore (vett3);
    
    return 0;
}
