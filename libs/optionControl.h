//
// Created by igor on 19/11/16.
//

#ifndef PROGETTOC_OPTIONCONTROL_H
#define PROGETTOC_OPTIONCONTROL_H

#include <stdio.h>
#include <string.h>

extern const char *__WRD_CNT;

extern const char *__LNE_CNT;

extern const char *__CHR_CNT;

extern const char *__WRD_STS;

extern const char *__WRD_STS_HST;

int isValidOption(char *inputOption);

int parmToNumber(char *inputOption);

void printErrorOption(char *errorDescription);

int setFlag4OP(int argc, char **argv, unsigned char *opSay);

int isSetParm(unsigned char opSay, int bitPos);

#endif //PROGETTOC_OPTIONCONTROL_H
