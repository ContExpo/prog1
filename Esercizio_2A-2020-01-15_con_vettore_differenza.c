/*
Esercizio 2
Implementare la funzione con prototipo
int isDiffVect(int A[ ], int B[ ], int C[ ], int n, int x)
che, dati tre vettori con tappo A, B, C in input, restituisce 1 se, posizione per posizione, il vettore C
contiene la differenza degli elementi in A e B. I vettori devono essere considerati come “riempiti di
x” (ove x è un parametro intero e n è la dimensione dei tre vettori con tappo A, B, C) fino a
raggiungere tutti e tre la lunghezza del vettore più lungo.
Esempio:
A: [ 4 | 6 | 5 | -1 ]
B: [ 3 | 3 | 2 | 5 | 6 | -1 ]
C: [ 1 | 3 | 3 | -5 | -6 | -1 ]
x: 0
output: 1
*/

#include <stdio.h>
#define DIM 11

int lunghezzaVett (int v[]);
int isDiffVect(int A[ ], int B[ ], int C[ ], int n, int x);
void stampaVett (int A[]);

int main ()
{
    int n = 11;
    int x = 0;
    
    int compare;
    
    int vettA[DIM] = {4, 6, 5, -1};
    int vettB[DIM] = {3, 3, 2, 5, 6, -1};
    int vettC[DIM] = {1, 3, 3, -5, -6, -1};
    
    compare = isDiffVect (vettA, vettB, vettC, n, x);
    
    printf ("Vettore A:\t");
    stampaVett (vettA);
    
    printf ("Vettore B:\t");
    stampaVett (vettB);
    
    printf ("Vettore C:\t");
    stampaVett (vettC);
    
    printf ("x: %d\n", x);
    printf ("Output: %d\n", compare);
    
    if (compare == 1)
        printf ("Il vettore con tappo C contiene la differenza tra i vettori con tappo A e B.\n");
    else
        printf ("Il vettore con tappo C non contiene la differenza tra i vettori con tappo A e B.\n");
    
    return 0;
}

/* Funzione che:
 * - riceve in ingresso 3 vettori con tappo, la loro dimensione e un valore x;
 * - conta i valori effettivamente contenuti in ciascun vettore
 * - crea un quarto vettore pari alla differenza cella per cella tra il primo e il secondo vettore,
 *   usando il valore x in caso di valori mancanti nel primo o nel secondo vettore;
 * - verifica se il vettore differenza corrisponde al terzo vettore;
 * - restituisce 1 se il terzo vettore equivale alla differenza cella per cella tra il primo e il secondo, 0 in caso contrario. */
int isDiffVect(int A[ ], int B[ ], int C[ ], int n, int x)
{
    int i, lenghtA, lenghtB, lenghtC, lenghtDiff;
    int vettDiff[n];
    int p = 1; // Flag; assumo che C contenga la differenza tra A e B
    
    lenghtA = lunghezzaVett (A);
    lenghtB = lunghezzaVett (B);
    lenghtC = lunghezzaVett (C);
    
    if (lenghtA > lenghtB)
    {
        // Creazione del vettore differenza nel caso in cui A sia più lungo di B
        for (i = 0; B[i] != -1; i++)
            vettDiff[i] = A[i] - B[i];
        
        for(; A[i] != -1; i++)
            vettDiff[i] = A[i] - x;
        
        vettDiff[i] = -1;
    }
    else
        if (lenghtB > lenghtA)
        {
            // Creazione del vettore differenza nel caso in cui B sia più lungo di A
            for (i = 0; A[i] != -1; i++)
                vettDiff[i] = A[i] - B[i];
            
            for (; B[i] != -1; i++)
                vettDiff[i] = x - B[i];
            
            vettDiff[i] = -1;
        }
        else
        {
            // Creazione del vettore differenza nel caso in cui A e B abbiano la stessa lunghezza
            for (i = 0; A[i] != -1; i++)
                vettDiff[i] = A[i] - B[i];
            
            vettDiff[i] = -1;
        }
        
    lenghtDiff = lunghezzaVett (vettDiff);
    
    // Confronto la lunghezza tra il vettore differenza e C; se la lunghezza e' differente C non e' il vettore differenza tra A e B
    if (lenghtC != lenghtDiff)
        p = 0;
    else
        // Confronto cella per cella i valori del vettore differenza e C; se trovo una coppia di valori non coincidenti C non e' il vettore differenza
        for (i = 0; vettDiff[i] != -1 && p == 1; i++)
            if (vettDiff[i] != C[i])
                p = 0;
    
    return p;
}

/* Funzione che:
 * - riceve in ingresso un vettore con tappo;
 * - calcola la lunghezza effettiva del vettore (cioe' quanti valori effettivamente contiene, con l'esclusione del tappo);
 * - restituisce tale valore.
 * 
 * In pratica la funzione trova l'indice della cella che contiene -1 ed equipara tale indice alla lunghezza del vettore.
 * 
 * Esempio: vettore: [0]: 5   [1]: 7   [2]: 1   [3]: 4   [4]: 9   [5]: -1   ->   lunghezza: 5
 */
int lunghezzaVett (int v[])
{
    // Assegno alla variabile i il valore dell'indice della prima cella del vettore
    int i = 0;
    
    // Incremento i finche' non trovo -1 nel vettore
    while (v[i] != -1)
        i++;
    
    return i;
}

/* Funzione che:
 * - riceve in ingresso un vettore con tappo;
 * - stampa il contenuto del vettore con l'indice di ogni cella;
 * - stampa la lunghezza del vettore.
 */
void stampaVett (int A[])
{
    int i;
    
    for (i = 0; A[i] != -1; i++)
        printf ("[%d]: %d\t", i, A[i]);
    
    printf ("Lunghezza: %d\n", i);
}
