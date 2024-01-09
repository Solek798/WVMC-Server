//
// Created by felix on 07.01.24.
//

#ifndef WVMC_SERVER_GLOBALDEFINITIONS_H
#define WVMC_SERVER_GLOBALDEFINITIONS_H

#define EVER ;;
#define DEFAULT_PATH "/tmp/test.sock"
#define MESSAGE_SIZE 4

const char MESSAGE_HEADER[] = "wvmc:";

enum SpecialMessages {
    START_MESSAGE = 0x00,
    STOP_MESSAGE = 0xFF
};

#endif //WVMC_SERVER_GLOBALDEFINITIONS_H
