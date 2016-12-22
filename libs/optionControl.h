/*
 * Copyright (C) 2016 Igor 19/11/16.
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
