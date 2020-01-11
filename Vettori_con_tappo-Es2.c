/*

Esercizio 2

Riprendere i vettori con tappo visti a lezione e aggiungere una funzione uguale, che restituisce TRUE se due vettori parzialmente riempiti sono uguali e FALSE se sono diversi. Definire opportunamente TRUE e FALSE.

*/

#include <stdio.h>
#define DIM 11

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
            scanf ("%d", &v[i]);
            
            if (v[i] < 0 && v[i] != -1)
                printf ("Solo valori positivi!\n");
        }
        while (v[i] < 0 && v[i] != -1);
        
        i++;
    }
    while (i < (DIM - 1) && v[i -1] != -1);
    
    v[i] = -1;
}

int contaValori (int v[])
{
    int i;
    
    for (i = 0; v[i] != -1; i++);
    
    return i;
}

int confrontaVettori (int v1[], int v2[], int nv1, int nv2)
{
    int i, p;
    p = 1;
    
    if (nv1 != nv2)
        p = 0;
    else
        for (i = 0; i < nv1 && p == 1; i++)
            if (v1[i] != v2[i])
                p = 0;
    
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
