/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "Stm32ItmLogger.h"
#include <main.h>

Debugger *Debugger_create(uint8_t chan) {
    Debugger *debugger = malloc(sizeof(Debugger));
    debugger->chan = chan;
    return debugger;
}

char MSG[LIBSMART_ITM_LOGGER_BUFFER_SIZE];

void Debugger_log(Debugger *debugger, const char *format, ...) {
    va_list args;
    va_start(args, format);

//    time_t now = time(NULL);
//    struct tm* timeinfo = localtime(&now);
//    char timestamp[20];
//    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

//    snprintf(MSG, sizeof(MSG), "[%s] ", timestamp);
//    SWO_PrintString(MSG, debugger->chan);

    vsnprintf(MSG, LIBSMART_ITM_LOGGER_BUFFER_SIZE, format, args);
    SWO_PrintString(MSG, debugger->chan);

    SWO_PrintChar('\n', debugger->chan);

//    fprintf(debugger->log_file, "[%s] ", timestamp);
//    vfprintf(debugger->log_file, format, args);
//    fprintf(debugger->log_file, "\n");

    va_end(args);
}


void SWO_PrintChar(char c, uint8_t chan) {
    ITM_SendChar(c);
}


void SWO_PrintString(const char *s, uint8_t chan) {
    // Print out characters until \0
    while (*s) {
        SWO_PrintChar(*s++, chan);
    }
}

