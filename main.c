#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/readlines.h"
#include "libs/optionControl.h"
#include "libs/text_stats.h"

int main(int argc, char **argv) {

    /* If opSay[i]==1 --> do function
     * opSay[0]: __WRD_CNT
     * opSay[1]: __LNE_CNT
     * opSay[2]: __CHR_CNT
     * opSay[3]: __WRD_STS
     * opSay[4]: __WRD_STS_HST
     */
    unsigned char opSay = 0x00;  //set to do nothing;

    //check options and set operation in bitwise
    if (argc <= 1) {
        opSay = 0x0F; //set to "-c -w -l -i"
    } else {
        int flg = setFlag4OP(argc, argv, &opSay);
        if (flg < 1) {
            printErrorOption(strcat(strcat(malloc((strlen("Invalid value ") + strlen(argv[-flg]))),
                                           "Invalid value "), argv[-flg]));        //TODO: magari semplifica...
            return EXIT_FAILURE;
        }
    }

    SingleChar *text = getInput();
    MultiLines *lines = makeLinesList(text);

    if (isSetParm(opSay, 0))
        wordCount(lines);

    if (isSetParm(opSay, 1))
        linesCount(lines);

    if (isSetParm(opSay, 2))
        charsCount(lines);

    if(isSetParm(opSay,3))
        wordStats(lines);

    if(isSetParm(opSay,4))
        wordStatsHist(lines);

    return EXIT_SUCCESS;
}