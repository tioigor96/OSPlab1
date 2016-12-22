/*
 * Copyright (C) 2016 Igor 18/11/16.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
