/*

Esercizio 8

Scrivere un programma che accetti due parametri, il nome di un file di testo e un numero n,
e che legga, carattere per carattere, il file di testo indicato e spezzi le righe più lunghe di n andando a capo.

L’output deve essere salvato in un altro file di testo.

Ad esempio se legge dal file la riga:

Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi

con n=34, lanciando il programma

$ ./testoACapo fileInput.txt 34


il file di output dovrà contenere:

Quel ramo del lago di Como, che vo

lge a mezzogiorno, tra due catene

non interrotte di monti, tutto a s

eni e a golfi

*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    int i, n;
    char c;
    
    if (argc != 3)
    {
        printf ("Errore nella sintassi.\nSintassi: %s [nome file] num:int\n", argv[0]);
        exit (EXIT_FAILURE);
    }
    
    n = atoi (argv[2]);
    if (n <= 0)
    {
        printf ("Errore! Il valore digitato deve essere maggiore di 0.\n");
        exit (EXIT_FAILURE);
    }
    
    FILE* fpr = fopen (argv[1], "r");
    if (fpr == NULL)
    {
        printf ("Errore! Il file indicato non esiste.\n");
        exit (EXIT_FAILURE);
    }
        
    FILE* fpw = fopen ("output.txt", "w");
    if (fpw == NULL)
    {
        printf ("Errore! Il file di output non e' accessibile.\n");
        fclose (fpr);
        exit (EXIT_FAILURE);
    }
    
    c = fgetc (fpr);
    
    for (i = 0; c != EOF; i++)
    {
        if (c == '\n')
        {
            c = fgetc (fpr);
            i--;
        }
        else
        {
            fputc (c, fpw);
            
            c = fgetc (fpr);
            
            if ( (i + 1) % n == 0)
                fputc ('\n', fpw);
        }
    }
    
    fclose (fpr);
    fclose (fpw);
    
    return (EXIT_SUCCESS);
}
