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

#ifndef PROGETTOC_TEXT_STATS_H
#define PROGETTOC_TEXT_STATS_H

#include <stdio.h>

#include "../libs/readlines.h"

struct BST_word_freq_node {
    char *word;
    int freq;
    struct BST_word_freq_node *rg;
    struct BST_word_freq_node *lf;
};
typedef struct BST_word_freq_node BTWrdFreq;

void printInputText(MultiLines *lst);

void charsCount(MultiLines *lines);

void wordCount(MultiLines *lines);

void linesCount(MultiLines *lines);

void wordStats(MultiLines *lines);

void wordStatsHist(MultiLines *lines);

BTWrdFreq *addNBTWrdFreq(BTWrdFreq *root, char *word);

BTWrdFreq *makeBTWrdFreq(MultiLines *lines);

void printBTWrdTree(BTWrdFreq *root);

void printBTWrdTreeHist(BTWrdFreq *root);

#endif //PROGETTOC_TEXT_STATS_H
