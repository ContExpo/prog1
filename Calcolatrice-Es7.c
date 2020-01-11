/*
Esercizio 7

Scrivere un programma calcolatrice.c che accetti tre parametri a riga di comando:

- operazione: una stringa "somma", "prodotto", "sottrazione" o "divisione"
- primo operando: un intero
- secondo operando: un intero

e stampi il risultato dell’operazione.
Il programma deve inoltre controllare che i parametri siano corretti e, in caso contrario,
stampare un messaggio di errore con la sintassi corretta.


Esempio 1:

$ ./calcolatrice somma 13 29

La somma è 42.

Esempio 2:
$ ./calcolatrice pippo 32 23

Sintassi: calcolatrice (somma | prodotto | sottrazione | divisione) num1:int num2:int $ 

Esempio 3:

$ ./calcolatrice divisione 42 0
Impossibile dividere per zero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
    int op1, op2;
    if (argc != 4)
        printf ("Errore nella sintassi.\nSintassi: %s (somma | prodotto | sottrazione | divisione) num1:int num2:int\n", argv[0]);
    else
    {
        op1 = atoi (argv[2]);
        op2 = atoi (argv[3]);
        
        if (strcmp (argv[1], "somma") == 0)
            printf ("La somma e' %d\n", op1 + op2);
        else
            if (strcmp (argv[1], "prodotto") == 0)
                printf ("Il prodotto e' %d\n", op1 * op2);
            else
                if (strcmp (argv[1], "sottrazione") == 0)
                    printf ("La differenza e' %d\n", op1 - op2);
                else
                    if (strcmp (argv[1], "divisione") == 0)
                    {
                        if (op2 == 0)
                            printf ("Impossibile dividere per zero.\n");
                        else
                            printf ("Il quoziente e' %d\n", op1 / op2);
                    }
                    else
                        printf ("Errore nella sintassi.\nSintassi: %s (somma | prodotto | sottrazione | divisione) num1:int num2:int\n", argv[0]);
    }
    
    return 0;
}
