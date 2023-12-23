#include "Conto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ANSI_COLOR_YELLOW  "\x1b[33m" // info
#define ANSI_COLOR_CYAN    "\x1b[36m" // utente
#define ANSI_COLOR_RESET   "\x1b[0m" // reset
#define ANSI_COLOR_MAGENTA "\x1b[35m" // banco

void impostaconto(Conto* contopersona){
    printf(ANSI_COLOR_YELLOW "\nQuanto vuoi caricare sul tuo conto? Solo cifre intere\n-" ANSI_COLOR_RESET);
    int valore;
    scanf("%d", &valore);
    contopersona->ammontare = valore;
    contopersona->id = creaidgiocatore();
    char nomefile[20]; //20 utenti
    sprintf(nomefile, "data/%d.txt", contopersona->id);
    FILE *file = fopen(nomefile, "w");
    fprintf(file, "%d", contopersona->ammontare);
    fclose(file);
    printf(ANSI_COLOR_YELLOW "\nBenvenuto giocatore %d, hai caricato %d euro. Buona fortuna!" ANSI_COLOR_RESET, contopersona->id, contopersona->ammontare);
}

void recuperaconto(Conto* contopersona){
    printf(ANSI_COLOR_YELLOW "\nInserisci l'ID\n-" ANSI_COLOR_RESET);
    int recuperaid;
    scanf("%d", &recuperaid);
    contopersona->id = recuperaid;
    char nomefile[20];
    sprintf(nomefile, "data/%d.txt", contopersona->id);
    FILE *file = fopen(nomefile, "r");
    fscanf(file, "%d", &contopersona->ammontare);
    fclose(file);
    printf(ANSI_COLOR_YELLOW "\nBentornato %d! Il tuo conto e' di %d. Buona fortuna!" ANSI_COLOR_RESET, contopersona->id, contopersona->ammontare);
}

void aggiornaammontare(Conto* contopersona){
    printf(ANSI_COLOR_YELLOW "\nQuanto vuoi caricare sul tuo conto? Solo cifre intere\n-" ANSI_COLOR_RESET);
    int valore;
    scanf("%d", &valore);
    contopersona->ammontare = valore;
    char nomefile[20]; //20 utenti
    sprintf(nomefile, "data/%d.txt", contopersona->id);
    FILE *file = fopen(nomefile, "w");
    fprintf(file, "%d", contopersona->ammontare);
    fclose(file);
    printf(ANSI_COLOR_YELLOW "\nHai con successo aggiornato il conto" ANSI_COLOR_RESET);
}
int ottieniid(Conto* contopersona){
    return contopersona->id;
}

int ottieniammontare(Conto* contopersona){
    return contopersona->ammontare;
}

int creaidgiocatore(){
    FILE *file = fopen("data/id.txt", "r+");
    int count = 1;
    if (file == NULL) {
        file = fopen("data/id.txt", "w");
        fputc('1', file);
    } else {
        while (fgetc(file) != EOF) {
            count++;
        }
        fseek(file, 0, SEEK_END);
        fputc('1', file);
    }
    fclose(file);
    return count;
}