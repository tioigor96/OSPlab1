//
// Created by igor on 19/11/16.
//

#include "../libs/optionControl.h"

// PROGRAM OPTION CONSTANT DEFINITION:
///@var: __WRD_CNT: word count
const char *__WRD_CNT = "-w";

///@var: __LNE_CNT: line count
const char *__LNE_CNT = "-l";

///@var: __CHR_CNT: char count
const char *__CHR_CNT = "-c";

///@var: __WRD_STS: statistics for words (counts how many times a word appears)
const char *__WRD_STS = "-i";

///@var: __WRD_STS_HIST: like __WRD_STS, but print a historygram.
const char *__WRD_STS_HST = "-I";

/**
 * Check if the inputOption is Valid
 *
 * @param char *inputOption
 * @return int[0;1]: 1:t, 0:f;
 */
int isValidOption(char *inputOption) {
    if (strcmp(inputOption, __WRD_CNT) == 0) return 1;
    else if (strcmp(inputOption, __LNE_CNT) == 0) return 1;
    else if (strcmp(inputOption, __CHR_CNT) == 0) return 1;
    else if (strcmp(inputOption, __WRD_STS) == 0) return 1;
    else if (strcmp(inputOption, __WRD_STS_HST) == 0) return 1;
    else return 0;
}

/**
 * Return the value of option
 *
 * @param char *inputOption
 * @return int[-1;4]:
 * -1: error
 * 0: __WRD_CNT
 * 1: __LNE_CNT
 * 2: __CHR_CNT
 * 3: __WRD_STS
 * 4: __WRD_STS_HST
 */
int parmToNumber(char *inputOption) {
    if (strcmp(inputOption, __WRD_CNT) == 0) return 0;
    else if (strcmp(inputOption, __LNE_CNT) == 0) return 1;
    else if (strcmp(inputOption, __CHR_CNT) == 0) return 2;
    else if (strcmp(inputOption, __WRD_STS) == 0) return 3;
    else if (strcmp(inputOption, __WRD_STS_HST) == 0) return 4;
    else return -1;
}

/**
 * Print a message error with a string, wt a valid list option
 *
 * @param char *errorDescription
 */
void printErrorOption(char *errorDescription) {
    printf("Error! %s\nValid options are:\n", errorDescription);
    printf("\t%s\tword count\n", __WRD_CNT);
    printf("\t%s\tline count\n", __LNE_CNT);
    printf("\t%s\tchar count\n", __CHR_CNT);
    printf("\t%s\tstatistics for words (counts how many times a word appears)\n", __WRD_STS);
    printf("\t%s\tlike %s, but print a historygram.\n", __WRD_STS_HST, __WRD_STS);

}

/**
 * Set flag for program and return number of flag setted.
 * If opSay==0xFF there is an error and return (-1)(param) in argv;
 * If opSay[i]==1 --> do function
 * opSay[0]: __WRD_CNT
 * opSay[1]: __LNE_CNT
 * opSay[2]: __CHR_CNT
 * opSay[3]: __WRD_STS
 * opSay[4]: __WRD_STS_HST
 *
 * @param int argc
 * @param char **argv
 * @param unsigned char *opSay (pointer)
 *
 * @return int flag counter
 */
int setFlag4OP(int argc, char **argv, unsigned char *opSay) {
    int flagCounter = 0;
    int pos;

    for (int i = 1; i < argc; i++)
        if ((pos = parmToNumber(argv[i])) < 0) {
            (*opSay) = 0xFF;
            return -i;
        } else {
            (*opSay) += ((unsigned char) (1 << pos));
            flagCounter++;
        }

    return flagCounter;
}

/**
 * Check if a bin in position "bitPos" is flagged.
 *
 * @param unsigned char opSay
 * @param int bit
 * @return int [0;1]: false:0, true:1
 */
int isSetParm(unsigned char opSay, int bitPos) {
    return (opSay & (1 << bitPos));
}