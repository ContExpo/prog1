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
    
    FILE* fpr = fopen (argv[1], "r");
    // Gestione dell'errore nel caso in cui il file da cui leggere i dati non esista o non sia accessibile
    if (fpr == NULL)
    {
        printf ("ERRORE! Il file %s non esiste o non e' accessibile.\n", argv[1]);
        exit (EXIT_FAILURE);
    }
    
    FILE* fpw = fopen (argv[2], "w");
    // Gestione dell'errore nel caso in cui il file in cui scrivere i dati non sia accessibile
    if (fpw == NULL)
    {
        printf ("ERRORE! Il file %s non e' accessibile.\n", argv[2]);
        exit (EXIT_FAILURE);
        
        fclose (fpr);
    }
    
    char riga[100], stringa1[DIM], stringa2[DIM];
    int presente, i;
    
    // Acquisizione di una riga dal file tramite fgets finche' la funzione non ritorna il valore NULL
    while ( (fgets (riga, 100, fpr)) != NULL )
    {
        // Controllo che sia stata acquisita una riga vuota (ovvero contenente solo il carattere '\n')
        if (riga[0] == '\n')
            fprintf (fpw, "**** RIGA VUOTA ****\n");
        else
        {
            // Controllo che nella riga acquisita ci sia almeno uno spazio preceduto da un carattere diverso da spazio
            // e seguito da un carattere diverso da spazio e da newline (condizione perche' nella riga ci siano almeno due parole)
            // Il controllo comincia dal secondo carattere, dato che prima dello spazio deve esserci almeno un altro carattere
            // dunque uno spazio in prima posizione non sarebbe significativo.
            int p = 0;
            
            for (i = 1; riga[i] != '\0' && p == 0; i++)
                if (riga[i] == ' ' && riga[i -1] != ' ' && riga[i + 1] != ' ' && riga[i + 1] != '\n')
                    p = 1;
                
            if (p == 0)
                fprintf (fpw, "**** SECONDA PAROLA MANCANTE ****\n");
            else
            {
                // Acquisizione delle due parole dalla stringa precedentemente acquisita tramite sscanf
                sscanf (riga, "%s %s", stringa1, stringa2);
            
                presente = contains (stringa1, stringa2);
                
                fprintf (fpw, "%s %s -> ", stringa1, stringa2);
                
                if (presente == 1)
                    fprintf (fpw, "TRUE\n");
                else
                    fprintf (fpw, "FALSE\n");
            }
        }
    }

    fclose (fpr);
    fclose (fpw);
    
    return 0;
}

/* Funzione che
 * - riceve due stringhe;
 * - verifica se tutti i caratteri della seconda stringa sono contenuti nella prima, indipendentemente dalla loro posizione;
 * - in caso positivo restituisce 1, altrimenti 0. */
int contains (char *str1, char *str2)
{
    int i, j, p;
    
    p = 1; // Assume che i caratteri precedentemente controllati fossero stati trovati (condizione di partenza)
    
    // Ciclo piu' esterno: seleziona uno per uno in sequenza tutti i caratteri di str2
     // Il ciclo si ripete solo se i caratteri di str2 non sono terminati e i caratteri di str2 precedentemente controllati sono stati trovati in str1
    for (i = 0; *(str2 + i) != '\0' && p == 1; i++)
    {
        p = 0; // Assume che il carattere attuale non sia presente
        
        // Ciclo piu' interno: confronta il carattere selezionato di str2 con tutti i caratteri di str1 uno ad uno
        // Il ciclo prosegue solo se i caratteri di str1 non sono terminati e il carattere di str2 non e' ancora stato trovato
        for (j = 0; *(str1 + j) != '\0' && p == 0; j++)
        {
            // Se il carattere di str2 viene trovato in str1 setta a 1 il flag p
            if ( *(str1 + j) == *(str2 + i) )
                p = 1;
        }
    }
    
    return p;
}
