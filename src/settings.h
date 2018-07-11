#ifndef SETTINGS_H
#define SETTINGS_H

#define SETTINGS_FILE "toxirc.ini"

#include <stdbool.h>
#include <sys/socket.h>
#include <netdb.h>

#ifndef NI_MAXHOST
#define NI_MAXHOST 1025
#endif

#include <tox/tox.h>

#include "irc.h"

enum {
    CHAR_CMD_PREFIX,
    CHAR_NO_SYNC_PREFIX,
    CHAR_MAX,
};

#define MAX_PREFIX 3

struct special_characters {
    char prefix[MAX_PREFIX + 1];
    char *desc;
};

struct Settings {
    char name[TOX_MAX_NAME_LENGTH];
    char status[TOX_MAX_STATUS_MESSAGE_LENGTH];
    bool ipv6;
    bool udp;
    char master[TOX_ADDRESS_SIZE * 2];
    char server[NI_MAXHOST];
    char port[IRC_PORT_LENGTH];
    char default_channel[IRC_MAX_CHANNEL_LENGTH];
    bool verbose;
    struct special_characters characters[CHAR_MAX];
};

typedef struct Settings SETTINGS;

extern SETTINGS settings;

void settings_save(char *file);

bool settings_load(char *file);

#endif
