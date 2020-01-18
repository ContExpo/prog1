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

int numValori (int v[], int n);
int isDiffVect (int A[ ], int B[ ], int C[ ], int n, int x);
void stampaVett (int v[], int n);

int main ()
{
    int n = DIM;
    int x = 0;
    int compare;
    
    int vettA[DIM] = {4, 6, 5, -1};
    int vettB[DIM] = {3, 3, 2, 5, 6, -1};
    int vettC[DIM] = {1, 3, 3, -5, -6, -1};
    
    /* Caso in cui C contenga la differenza tra A - B, con numero valori di A > numero valori di B
    int vettA[DIM] = {4, 6, 5, -1};
    int vettB[DIM] = {3, 3, 2, 5, 6, -1};
    int vettC[DIM] = {1, 3, 3, -5, -6, -1};
    */
    /* Caso in cui C contenga la differenza tra A - B, con numero valori di B > numero valori di A e gestione del valore -1
    int vettA[DIM] = {3, 3, 2, 5, 6, -1};
    int vettB[DIM] = {4, 5, 6, -1};
    int vettC[DIM] = {-1, -2, -4, 5, 6, -1};
    */
    /* Caso in cui C contenga la differenza tra A - B, con numero valori di A = numero valori di B e gestione del valore -1
    int vettA[DIM] = {3, 3, 2, 5, 6, -1};
    int vettB[DIM] = {4, 5, 6, 4, 1, -1};
    int vettC[DIM] = {-1, -2, -4, 1, 5, -1};
    */
    /* Caso in cui C non contenga la differenza tra A - B
    int vettA[DIM] = {3, 5, 6, -1};
    int vettB[DIM] = {1, 7, 4, 4, 1, -1};
    int vettC[DIM] = {2, -2, 2, 1, 5, -1};
    */
    /* Caso in cui C contenga meno valori del piu' lungo tra A e B
    int vettA[DIM] = {4, 6, 5, -1};
    int vettB[DIM] = {3, 3, 2, 5, 6, -1};
    int vettC[DIM] = {1, 3, 3, -5, -1};
    */
    /* Caso in cui uno dei vettori sia privo di tappo
    int vettA[DIM] = {4, 6, 5};
    int vettB[DIM] = {3, 3, 2, 5, 6, -1};
    int vettC[DIM] = {1, 3, 3, -5, -6, -1};
    */
    
    compare = isDiffVect (vettA, vettB, vettC, n, x);
    
    printf ("Vettore A:\t");
    stampaVett (vettA, n);
    printf ("Vettore B:\t");
    stampaVett (vettB, n);
    printf ("Vettore C:\t");
    stampaVett (vettC, n);
    
    printf ("\n");
    printf ("Output: %d\n", compare);
    
    if (compare == -1)
        printf ("Ci sono dei vettori privi di tappo.\n");
    else
        if (compare == 1)
            printf ("C contiene, posizione per posizione, la differenza tra gli elementi di A e di B.\n");
        else
            printf ("C non contiene, posizione per posizione, la differenza tra gli elementi di A e di B.\n");
    
    return 0;
}

/* Funzione che:
 * - riceve in ingreso un vettore di interi (che si assume con tappo = -1, ma che potrebbe contenere anche valori negativi)
 *   e la sua dimensione;
 * - trova l'ultima occorrenza di -1 e equipara l'indice di tale cella al numero di valori contenuti nel vettore;
 * - restituisce il numero di valori contenuti nel vettore;
 * - in caso di vettore vuoto restituisce 0
 * - in caso di assenza del tappo restituisce -1 */
int numValori (int v[], int n)
{
    int nv = n - 1; // Assegno a nv il valore dell'indice dell'ultima cella del vettore
    
    // Visito il vettore partendo dal fondo per trovare l'ultima occorrenza di -1
    while (nv >= 0 && v[nv] != -1)
        nv--;
    
    return nv;
}

/* Funzione che:
 * - riceve in ingresso tre vattori di interi (che si assumono con tappo = -1, ma che potrebbero contenere anche valori negativi),
 *   la loro dimensione e un valore intero x;
 * - calcola il numero di valori contenuti in ciascun vettore, assumendo che i vettori potrebbero contenere anche valori negativi;
 * - controlla se il terzo vettore contiene cella per cella la differenza tra i primi due, utilizzando il valore x nel caso in cui uno dei
 *   vettori tra i primi due contenga meno valori dell'altro;
 * - restituisce -1 se uno dei tre vettori manca del tappo, 1 se il terzo vettore contiene cella per cella la differenza tra i primi due,
 *   0 in caso contrario. */
int isDiffVect (int A[ ], int B[ ], int C[ ], int n, int x)
{
    int i, nvA, nvB, nvC;
    int p = 1; // Assumo che C contenga la differenza tra A e B
    
    nvA = numValori (A, n);
    nvB = numValori (B, n);
    nvC = numValori (C, n);
    
    // Controllo se tutti i vettori abbiano il tappo
    if (nvA == -1 || nvB == -1 || nvC == -1)
    {
        p = -1;
        return p;
    }
    
    // Controllo nel caso in cui A contenga più valori di B
    if (nvA > nvB)
    {
        // Confronto il numero dei valori tra il vettore con più valori A e C; se il numero di valori e' differente, C non e' il vettore differenza
        if (nvA != nvC)
            p = 0;
        
        // Confronto cella per cella i valori della differenza A - B e C fino al termine dei valori di B
        for (i = 0; i < nvB && p == 1; i++)
            if (A[i] - B[i] != C[i])
                p = 0;
        
        // Confronto cella per cella i valori della differenza tra i restanti valori di A - x e C fino al termine dei valori di A
        for(; i < nvA && p == 1; i++)
            if (A[i] - x != C[i])
                p = 0;
    }
    else
        // Controllo nel caso in cui B contenga più valori di A
        if (nvB > nvA)
        {
            // Confronto il numero dei valori tra il vettore con più valori B e C; se il numero di valori e' differente, C non e' il vettore differenza
            if (nvB != nvC)
                p = 0;
            
            // Confronto cella per cella i valori della differenza A - B e C fino al termne dei valori di A
            for (i = 0; i < nvA && p == 1; i++)
                if (A[i] - B[i] != C[i])
                    p = 0;
            
            // Confronto cella per cella i valori della differenza x - i restanti valori di B e C fino al termine dei valori di B
            for (; i < nvB && p == 1; i++)
                if (x - B[i] != C[i])
                    p = 0;
        }
        else
        {
            // Controllo nel caso in cui A e B abbiano lo stesso numero di valori
            // Confronto il numero dei valori tra uno dei due vettori (A o B non cambia, dato che contengono entrambi lo stesso numero
            // di valori) e C; se il numero di valori e' differente, C non e' il vettore differenza
            if (nvA != nvC)
                p = 0;
            
            // Confronto cella per cella i valori della differenza A - B e C fino al termine dei valori
            // (di A o B non cambia, dato che entrambi contengono lo stesso numero di valori)
            for (i = 0; i < nvA && p == 1; i++)
                if (A[i] - B[i] != C[i])
                    p = 0;
        }
        
    return p;
}

void stampaVett (int v[], int n)
{
    int i, nv;
    
    nv = numValori (v, n);
    
    if (nv == -1)
        printf ("Vettore senza tappo!\n");
    else
    {
        for (i = 0; i < nv; i++)
        printf ("[%d]: %d\t", i, v[i]);
        
        printf ("\n");
    }
}
