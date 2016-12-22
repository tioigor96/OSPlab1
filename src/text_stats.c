/*
 * Copyright (C) 2016 Igor 20/11/16.
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

#include "../libs/text_stats.h"

/**
 * Print all text fornatted in MultiLines struct
 *
 * @param MultiLines *lines
 */
void printInputText(MultiLines *lines) {
    SingleLine *line = NULL;

    if (lines == NULL) {
        return;
    }

    while (lines->next != NULL) {
        line = lines->line;
        while (line->next != NULL) {
            printf("%s ", line->word);
            line = line->next;
        }
        printf("\n");
        lines = lines->next;
    }
}

/**
 * Count numbers of char in Multilines structs and print the result.
 *
 * @param lines
 * @return int counterChar
 */
/*
 * <<[...]cnt+=strlen(line->word)+1;[...]>>
 * Conto sempre un carattere in più poiche line->*word "trattiene" nella stringa un
 * '\0' utilzzato come "jolly": potrebbe rappresentare un ' ', o un '\t' o un '\n'.
 */
void charsCount(MultiLines *lines) {
    SingleLine *line = NULL;
    int cnt = 0;

    if (lines == NULL) {
        printf("Conteggio caratteri: 0\n");
        return;
    }

    while (lines->next != NULL) {
        line = lines->line;
        while (line->next != NULL) {
            cnt += strlen(line->word) + 1;
            line = line->next;
        }
        lines = lines->next;
    }

    printf("Conteggio caratteri: %d\n", cnt);
}

/**
 * Count numbers of words in Multilines structs and print the result.
 *
 * @param lines
 * @return int counterChar
 */
void wordCount(MultiLines *lines) {
    SingleLine *line = NULL;
    int cnt = 0;

    if (lines == NULL) {
        printf("Conteggio parole: 0\n");
        return;
    }

    while (lines->next != NULL) {
        line = lines->line;
        while (line->next != NULL) {
            if (strlen(line->word) > 0)
                cnt++;
            line = line->next;
        }
        lines = lines->next;
    }

    printf("Conteggio parole: %d\n", cnt);
}

/**
 * Count numbers of lines in Multilines structs and print the result.
 *
 * @param lines
 * @return int counterChar
 */
void linesCount(MultiLines *lines) {
    int cnt = 0;

    if (lines == NULL) {
        printf("Conteggio linee : 0\n");
        return;
    }

    while (lines != NULL) {
        cnt++;
        lines = lines->next;
    }

    printf("Conteggio linee : %d\n", cnt);
}

/**
 * Count and print occourences number for each word in input text.
 *
 * @param MultiLines *lines
 */
void wordStats(MultiLines *lines) {
    printf("Conteggio frequenza parole :\n");
    printBTWrdTree(makeBTWrdFreq(lines));
}

/**
 * Count and print occourences number for each word in input text in a
 * historigram.
 *
 * @param lines
 */
void wordStatsHist(MultiLines *lines) {
    printf("Frequenza parole :\n");
    printBTWrdTreeHist(makeBTWrdFreq(lines));
}

/**
 * AUXILIARY FUNCTION: Make a Binary Tree for count word frequency.
 *
 * @param BTWrdFreq *root
 * @param char *word
 * @return BTWrdFreq *root
 */
BTWrdFreq *addNBTWrdFreq(BTWrdFreq *root, char *word) {
    if (root == NULL) {
        root = malloc(sizeof(BTWrdFreq));
        root->word = word;
        root->freq = 1;
        root->rg = NULL;
        root->lf = NULL;
    } else {
        if (strcmp(root->word, word) > 0)
            root->lf = addNBTWrdFreq(root->lf, word);
        else if (strcmp(root->word, word) == 0)
            root->freq += 1;
        else if (strcmp(root->word, word) < 0)
            root->rg = addNBTWrdFreq(root->rg, word);
    }

    return root;
}

/**
 * Make a Binary Tree for count word frequency
 *
 * @param MultiLines *lines
 * @return BTWrdFreq *root
 */
BTWrdFreq *makeBTWrdFreq(MultiLines *lines) {
    SingleLine *line = NULL;
    BTWrdFreq *root = NULL;

    if (lines == NULL) {
        return NULL;
    }

    while (lines->next != NULL) {
        line = lines->line;
        while (line->next != NULL) {
            if (strlen(line->word) > 0)
                root = addNBTWrdFreq(root, line->word);
            line = line->next;
        }
        lines = lines->next;
    }

    return root;
}

/**
 * Auxiliary function for print recursively the word frequency.
 *
 * @param BTWrdFreq *root
 */
void printBTWrdTree(BTWrdFreq *root) {
    if (root == NULL) return;
    printBTWrdTree(root->lf);
    printf("%s:%d\n", root->word, root->freq);
    printBTWrdTree(root->rg);

}

/**
 * Auxiliary function for print recursively the word frequency historigram.
 *
 * @param BTWrdFreq *root
 */
void printBTWrdTreeHist(BTWrdFreq *root) {
    if (root == NULL) return;
    printBTWrdTreeHist(root->lf);

    printf("|");
    for (int i = 0; i < root->freq; i++)
        printf("*");
    printf(" %s\n", root->word);

    printBTWrdTreeHist(root->rg);

}

