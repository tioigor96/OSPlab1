//
// Created by igor on 20/11/16.
//

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
