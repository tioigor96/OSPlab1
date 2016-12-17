//
// Created by igor on 18/11/16.
//

#ifndef PROGETTOC_READLINES_H
#define PROGETTOC_READLINES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SingleChar_node {
    char c;
    struct SingleChar_node *next;
};
typedef struct SingleChar_node SingleChar;

/*
 * Struct che contiene una parola finchè non vede un '\n'.
 */
struct SingleLine_node {
    char *word;
    struct SingleLine_node *next;
};
typedef struct SingleLine_node SingleLine;

/*
 * Struct che contiene le linee
 */
struct MultiLines_node {
    SingleLine *line;
    struct MultiLines_node *next;
};
typedef struct MultiLines_node MultiLines;

char *makeWordR(SingleChar *lst);

char *makeWordI(SingleChar *lst);

SingleLine *makeLineList(SingleChar **lst);

MultiLines *makeLinesList(SingleChar *lst);

SingleChar *getInput();

#endif //PROGETTOC_READLINES_H
