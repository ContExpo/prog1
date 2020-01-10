/*Scrivere un programma che, ricevuta una frase da riga di comando, la salvi in un vettore e poi tramite funzione
la scriva all'utente al contrario Es "Il cielo è blu -> blu è cielo Il" */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///Counts the occurrences of @character in @string
int strcnt(char character, char * string)
{
    if(string==NULL)
        return 0;
    int cont=0;
    for (int i = 0 ; string[i]!='\0' ; i++ )
    {
        if (string[i]==character)
        {
            cont++;
        }
    }
    return cont;
}
///Ricevuto in input una stringa, la splitta per ogni occorrenza degli spazi e la riscrive al contrario
void scriviInvertito(char* frase)
{
    int parole = strcnt(' ', frase)+1; //Conto quanti spazi (e quindi quante parole) ci sono nella frase
    if (parole<1) //Avendo una sola parola la scrivo e basta
    {
        printf("C'e' una sola parola, %s", frase);
        return;
    }
    printf("Ci sono %d parole\n", parole);
    char * stringaSplittata[parole]; //Diventerà l'array in cui metto tutte le mie parole, un array di string
    char* parola; //Variabile per prendere le parole splittate
    int i=0;
    while ((parola = strsep(&frase, " ")) != NULL)  //Strsep è la versione più "figa" di strtok
    {
        //printf("Parola vale %s \n", parola);
        stringaSplittata[i]= parola;    //
        printf("Ora stringaSplittata[%d] vale %s\n", i, stringaSplittata[i]);
        i++;    //Aumento indice di scorrimento array
    }
    //Faccio un ciclo dalla fine dell'array all'inizio per scrivere la parola al contrario
    for (int i=parole-1; i>=0; i--) //-1 perche' l'array di dimensione i ha indice max i-1
    {
        printf("%s \t", stringaSplittata[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argv[1]==NULL)  //Se non è presente il parametro non posso eseguire
    {
        printf("Frase mancante, non posso eseguire il programma");
        return -1;
    }
    scriviInvertito(argv[1]);

}
