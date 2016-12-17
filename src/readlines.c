#include "../libs/readlines.h"

/**
 * Get the text line while EOF.
 * @return list SingleChar_Node
 */
SingleChar *getInput() {
    SingleChar *first = malloc(sizeof(SingleChar));
    first->next = NULL;
    first->c = EOF;
    SingleChar *aux, *last = first;
    char c;

    while ((c = getchar()) != EOF) {
        last->c = c;
        aux = malloc(sizeof(SingleChar));
        last->next = aux;
        last = last->next;

    }

    last->c = EOF;
    last->next = NULL;

    return first;
}

/**
 * RECOURSIVE, UNSTABLE: the function make a word from a list of char.
 * Consider a word everything is separated by ' ', '\t' or '\n'.
 *
 * @param SingleChar *lst
 * @return pointer to char array
 */
/*
 * UNSTABLE because i'm in HEAP OVERFLOW if *(SingleChar)lst it's over 23 chars-->
 * http://stackoverflow.com/questions/3413166/when-does-a-process-get-sigabrt-signal-6
 *
 * ln = (memcpy(malloc(strlen(c_wrd) + 1) + 1, c_wrd, strlen(c_wrd) + 1)) - 1;
 * fa una stringa nuova copiando in memodia da str[1]->str[n-1], n=strlen(c_wrd).
 * porto in posizione tutti  i puntatori, copio, e dopo porto indietro di 1 il
 * puntatore della nuova stringa: se non lo facessi la free va in eccezione poichè
 * la malloc non alloca quello che ritorna la memcpy, ma memcpy(mall+1)-1: in
 * sostanza aggiusto il tiro del puntatore.
 *
 * if (lst == NULL || lst->next == NULL || lst->c == ' ') {[...]}
 * impostato il secondo par (lst->next) in modo da non creare una parola con
 * "EOF" secco.
 */
char *makeWordR(SingleChar *lst) {
    char *ln;
    if (lst == NULL || lst->c == EOF || lst->c == ' ' || lst->c == '\t' || lst->c == '\n') {
        ln = (char *) malloc(1);
        ln[0] = '\0';
    } else {
        char *c_wrd = makeWordR(lst->next);
        ln = (memcpy(malloc(strlen(c_wrd) + 1) + 1, c_wrd, strlen(c_wrd) + 1)) - 1;
        ln[0] = lst->c;
        free(c_wrd);
    }

    return ln;
}
/**
 * ITERATIVE: the function make a word from a list of char.
 * Consider a word everything is separated by ' ', '\t' or '\n'.
 *
 * @param SingleChar lst
 * @return pointer to char array
 */
/*
 * Alloco prima di tutto un byte per il primo carattere, in modo che anche se ho
 * a che fare subito con un EOF o altro posso sempre chiudere la stringa per la
 * funzione strlen (<<[...] ln[len] = '\0'; [...]>>).
 * Quando trova un carattere alla successiva iterazione del while, inserisce il
 * carattere nella successiva allocazione disponibile e libera, avanza con la lista
 * di caratteri e rialloca la dimensione dell'array in vista del prossimo carattere in entrata.
 * NON ELIMINA LE LETTERECHE IMPORTA poichè la funzione CREA e NON MODIFICA la lista.
 */

char *makeWordI(SingleChar *lst) {
    char *ln = malloc(1);
    int len = 0;

    while (lst != NULL && lst->c != EOF && lst->c != ' ' && lst->c != '\t' && lst->c != '\n') {
        ln[len] = lst->c;
        len++;
        lst = lst->next;
        ln = realloc(ln, (size_t)len + 1);
    }

    ln[len] = '\0';

    return ln;
}

/**
 * From list of chars make a list of word in that line. The list'll be
 * interrupt when in lst->c == '\n' or when it's the last word in the
 * chars' list.
 *
 * @param SingleChar **lst: pointer to SingleChar's list ended wt c:EOF+next:NULL
 * @return list of SingleLine
 */
/*
 * + <<[...]for (int i = 0; i <= strlen(last->word); i++)[...]>>:
 * siccome per ogni parola o doppio spazio devo eliminare il suo separatore relativo,
 * devo eliminare strlen(line->word)+1. se tale carattere "+1" non esiste (fine della
 * lista di char), esco dall'iterazione.
 *
 * + <<[...]while ((*lst) != NULL && fg != 1) [...] \
 *          if ((*lst) == NULL || fg == 1) break; \
 *          if ((*lst)->c == '\n') fg = 1;
 *     [...]>>:
 * siccome se finisco alla fine della lista o mi trovo alla fine della linea, faccio
 * in modo di poter uscire tranquillamente dallo stato in cui mi trovo, flaggando
 * anche la linea del while.
 *
 */
SingleLine *makeLineList(SingleChar **lst) {
    SingleChar *auxSC = NULL;
    SingleLine *first = malloc(sizeof(SingleLine));
    SingleLine *last = first;

    int fg = 0;
    while ((*lst) != NULL && fg != 1) {
        last->word = makeWordI((*lst));
        for (int i = 0; i <= strlen(last->word); i++) {
            if ((*lst) == NULL || fg == 1) break;
            if ((*lst)->c == '\n') fg = 1;
            auxSC = (*lst);
            (*lst) = (*lst)->next;
            free(auxSC);
        }

        last->next = malloc(sizeof(SingleLine));
        last = last->next;
        last->word = NULL;
        last->next = NULL;

    }

    return first;
}

/**
 * Make a list of SingleLine (list of word separated by ' '||'\t'||'\n')
 *
 * @param SingleChar *lst
 * @return list of Multilines
 */
MultiLines *makeLinesList(SingleChar *lst) {
    MultiLines *first = malloc(sizeof(SingleChar)), *last = first;

    while (lst != NULL && lst->next != NULL) {
        last->line = makeLineList(&lst);
        last->next = malloc(sizeof(MultiLines));
        last = last->next;
        last->next = NULL;
        last->line = NULL;
    }
    return first;
}