/*
Esercizio 1
Implementate la funzione con prototipo
int contains(char *str1, char *str2);
La funzione contains restituisce TRUE se tutti i caratteri di str2, indipendentemente dal loro ordine,
sono anche caratteri di str1, FALSE altrimenti. Definite opportunamente TRUE e FALSE e gestite
il caso in cui le stringhe siano NULL. NON è consentito l’uso di funzioni di libreria.
Esempi:
• str1: dfdgfr str2: fsd output: FALSE
• str1: dfdgfr str2: gfd output: TRUE
• str1: dfdgfr str2: gfg output: TRUE
Caricare l’elenco di stringhe dal file input_stringhe.txt, con il seguente formato:
str1 <space> str2
Supponendo che il vostro eseguibile si chiami contains15Jan20, lanciarlo da linea di comando
./contains15Jan20 input_stringhe.txt output_stringhe.txt
In questo caso, il vostro programma leggerà le stringhe dal file input_stringhe.txt e, nel file
output_stringhe.txt, scriverà il risultato secondo il formato
<str1><space><str2> -> <output>
Esempio:
dfdgfr fds -> FALSE
dfdgfr gfd -> TRUE
dfdgfr gfg -> TRUE
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 30

int contains (char *str1, char *str2);

int main (int argc, char* argv[])
{
    // Gestione dell'errore nel caso in cui l'utente non inserisca almeno due parametri da riga di comando
    if (argc < 3)
    {
        printf ("ERRORE! Sintassi: %s [nome file input] [nome file output]\n", argv[0]);
        exit (EXIT_FAILURE);
    }
    
    // Gestione dell'errore nel caso in cui il file da cui leggere i dati non esista o non sia accessibile
    FILE* fpr = fopen (argv[1], "r");
    if (fpr == NULL)
    {
        printf ("ERRORE! Il file %s non esiste o non e' accessibile.\n", argv[1]);
        exit (EXIT_FAILURE);
    }
    
    // Gestione dell'errore nel caso in cui il file in cui scrivere i dati non sia accessibile
    FILE* fpw = fopen (argv[2], "w");
    if (fpw == NULL)
    {
        printf ("ERRORE! Il file %s non e' accessibile.\n", argv[2]);
        exit (EXIT_FAILURE);
        
        fclose (fpr);
    }
    
    char stringa1[DIM], stringa2[DIM];
    int presente;
            
    while ( (fscanf (fpr, "%s %s", stringa1, stringa2)) != EOF)
    {
        presente = contains (stringa1, stringa2);

        fprintf (fpw, "%s %s -> ", stringa1, stringa2);

        if (presente == 1)
            fprintf (fpw, "TRUE\n");
        else
            fprintf (fpw, "FALSE\n");
    }

    fclose (fpr);
    fclose (fpw);
    
    return 0;
}

int contains (char *str1, char *str2)
{
    int i, j, p;
    
    p = 1;
    
    for (i = 0; *(str2 + i) != '\0' && p == 1; i++)
    {
        p = 0;
        
        for (j = 0; *(str1 + j) != '\0' && p == 0; j++)
        {
            if ( *(str1 + j) == *(str2 + i) )
                p = 1;
        }
    }
    
    return p;
}
