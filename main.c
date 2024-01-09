#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "GlobalDefinitions.h"


int sock_fd, conn_fd;
struct sockaddr_un serv_path;

bool check_header();
void process_message();

int main() {
    int result = 0;

    sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        perror("ERROR opening socket");

        return (EXIT_FAILURE);
    }

    strcpy(serv_path.sun_path, DEFAULT_PATH);
    serv_path.sun_family = AF_UNIX;

    printf("Path: %s \n", serv_path.sun_path);
    printf("Family: %hu \n", serv_path.sun_family);

    unlink(DEFAULT_PATH);

    result = bind(sock_fd, (const struct sockaddr *) &serv_path, sizeof(serv_path));

    if (result < 0) {
        perror("ERROR binding socket");
        return (EXIT_FAILURE);
    }

    struct sockaddr_un target;
    target.sun_family = AF_UNIX;
    strcpy(target.sun_path, "/tmp/Win_VM_Communicator");

    result = connect(sock_fd, (const struct sockaddr *) &target, sizeof(target));

    if (result < 0) {
        perror("ERROR connect command failed");
        return (EXIT_FAILURE);
    }

    unsigned char msg_buffer = 0;

    // header_buffer[0] = 0x00;
    // header_buffer[1] = 0x00;
    //header_buffer[2] = 0x00;
    //header_buffer[3] = 0x00;

    for (EVER) {

        if (check_header()) {
            recv(sock_fd, &msg_buffer, 1, 0);
        }

        switch (msg_buffer) {
            case START_MESSAGE:
                printf("Start! \n");
                break;
            case STOP_MESSAGE:
                printf("Stop! \n");
                break;
            default:
                printf("Msg: 0x%02X \n", msg_buffer);
        }

    }

    printf("Finished \n");

    return (EXIT_SUCCESS);
}

bool check_header() {
    char header_buffer = 0;

    for (int i = 0 ; i < MESSAGE_SIZE ; i++) {
        recv(sock_fd, &header_buffer, 1, 0);

        if (header_buffer != MESSAGE_HEADER[i])
            return false;
    }

    return true;
}
