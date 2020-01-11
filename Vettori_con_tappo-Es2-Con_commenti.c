/*

Esercizio 2

Riprendere i vettori con tappo visti a lezione e aggiungere una funzione uguale, che restituisce TRUE se due vettori parzialmente riempiti sono uguali e FALSE se sono diversi. Definire opportunamente TRUE e FALSE.

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
 * - riceve due vettori di interi e il numero di valori contenuti in ciascuno;
 * - confronta il numero dei valori e i valori contenuti;
 * - se i due vettori hanno lo stesso numero di valori e se i valori coincidono restituisce 1, altrimenti restituisce 0. */
int confrontaVettori (int v1[], int v2[], int nv1, int nv2)
{
    int i, p;
    p = 1; // variabile usata come flag; inizialmente supponiamo che i due vettori siano uguali
    
    // confronto tra il numero di valori contenuti nei vettori: se non hanno lo stesso numero di valori non sono uguali
    if (nv1 != nv2)
        p = 0;
    else
        // confronto dei valori uno ad uno: il ciclo prosegue finche' non sono stati confrontati tutti i valori
        // o finche' non si trova una coppia di valori non coincidenti
        for (i = 0; i < nv1 && p == 1; i++)
            if (v1[i] != v2[i])
                p = 0;
    
    // al termine del confronto p vale 1 se i due vettori sono uguali, 0 se diversi
    return p;
}

int main ()
{
    int vett1[DIM], vett2[DIM], numval1, numval2, flag;
    
    printf ("Primo vettore\n");
    caricaVettore (vett1);
    printf ("Secondo vettore\n");
    caricaVettore (vett2);
    
    numval1 = contaValori (vett1);
    printf ("Il primo vettore contiene %d valori\n", numval1);
    numval2 = contaValori (vett2);
    printf ("Il secondo vettore contiene %d valori\n", numval2);
    
    flag = confrontaVettori (vett1, vett2, numval1, numval2);
    
    if (flag == 1)
        printf ("I due vettori sono uguali.\n");
    else
        printf ("I due vettori sono diversi.\n");
    
    return 0;
}
