#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Header funzioni
void charSwap (char *c1, char *c2);
void rotate(char *str, int k);
int isSumVect(int a[], int b[], int c[], int n, int x);



///Shifts every character in str of k positions
void rotate(char *str, int k)
{
    if (k<1)
    {
        return;
    }
    int length = strlen(str);
    char temp, ultimochar;
  //Variabile di appoggio
    k=k%length;    //Shiftare una stringa lunga N di N posti ottiene la stessa stringa
    for (int h=0; h<k; h++)
    {
        ultimochar=(str[length-1]);
        temp=str[0];
        for (int i=0; i<length-1; i++)   //Il carattere in str[lenght] è \0 che deve rimanere alla fine altrimenti il programma va in segfault
        {
            charSwap(&temp, &str[i+1]);
        }
        str[0]=ultimochar;
    }
}

void charSwap (char *c1, char *c2)
{
    char temporaneo=*c2;
    *c2=*c1;
    *c1=temporaneo;
}

int isSumVect(int a[], int b[], int c[], int n, int x)
{
    int vetAFinito=0, vetBFinito=0, somma=0;    //Flag in caso di tappo di A o B
    for (int i=0; i<n; i++)
    {
        somma=0;            //Somma a[i]+b[i]
        if(vetAFinito || a[i]==-1)        //Se a[i]==-1 ho trovato il tappo
        {
            vetAFinito=1;
            somma+=x;
        }
        else if(!vetAFinito)    //Se A non è finito lo conto nella somma
        {
            somma+=a[i];
        }
        if(vetBFinito || b[i]==-1)        //Se a[i]==-1 ho trovato il tappo
        {
            vetBFinito=1;
            somma+=x;
        }
        else
        {
            somma+=b[i];
        }
        if (somma!=c[i])
        {
            return 0;
        }
    }
    if (vetAFinito && vetBFinito)
    {
        return 1;    //Se ho raggiunto la fine di entrambi i vettori e tutti i controlli a[i]+b[i]==c[1]
                        // sono apposto vuol dire che c'è uguaglianza tra a+b e c
    }
}


int main(int argc, char *argv[])
{
    //Simulo i due parametri da riga di comando, commentare queste due righe per utilizzare la riga di comando
    argv[1]="input.txt";
    argv[2]="output.txt";
    FILE *inputFile=fopen(argv[1], "r");
    if (ferror(inputFile)!=0)
    {
        printf("Errore di apertura file input\n\n");
        return -1;
    }
    FILE *outputFile = fopen(argv[2], "w+");
    if (ferror(outputFile)!=0)
    {
        printf("Errore di apertura file output\n\n");
        return -1;
    }
    char riga[101], *parola, input[50];
    int k;
    printf("Inizio scan file");
    while (fgets(riga, 100, inputFile)!=NULL)
    {
        printf("Ho pescato una riga: %s\n", riga);
        parola = strtok(riga, ",");
        k = atoi(strtok(NULL, ""));
        strcpy(input, parola);    //Mi tengo la parola non shiftata per scriverla nel file di output
        rotate(parola, k);
        printf("La stringa ruotata e' diventata %s\n\n", parola);
        fprintf(outputFile, "Input: %s\nK: %d\nOutput:%s\n\n********\n", input, k, parola);
    }
    fclose(inputFile);
    fclose(outputFile);
}
