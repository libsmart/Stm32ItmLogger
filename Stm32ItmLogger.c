/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "Stm32ItmLogger.h"
#include "main.h"

//extern uint32_t ITM_SendChar (uint32_t ch);

// Konstruktor
Debugger *Debugger_create(uint8_t chan) {
    Debugger *debugger = malloc(sizeof(Debugger));
    debugger->chan = chan;
    return debugger;
}

char MSG[STM32_ITM_LOGGER_BUFFER_SIZE];

void Debugger_log(Debugger *debugger, const char *format, ...) {
    va_list args;
    va_start(args, format);

//    time_t now = time(NULL);
//    struct tm* timeinfo = localtime(&now);
//    char timestamp[20];
//    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

//    snprintf(MSG, sizeof(MSG), "[%s] ", timestamp);
//    SWO_PrintString(MSG, debugger->chan);

    vsnprintf(MSG, STM32_ITM_LOGGER_BUFFER_SIZE, format, args);
    SWO_PrintString(MSG, debugger->chan);

    SWO_PrintChar('\n', debugger->chan);

//    fprintf(debugger->log_file, "[%s] ", timestamp);
//    vfprintf(debugger->log_file, format, args);
//    fprintf(debugger->log_file, "\n");

    va_end(args);
}

/**
 * SWO_PrintChar()
 *
 * @brief
 *   Checks if SWO is set up. If it is not, return,
 *    to avoid program hangs if no debugger is connected.
 *   If it is set up, print a character to the ITM_STIM register
 *    in order to provide data for SWO.
 * @param c The Character to be printed.
 * @notes   Additional checks for device specific registers can be added.
 */
void SWO_PrintChar(char c, uint8_t chan) {

#if(1==1)
    //Use CMSIS_core_DebugFunctions. See core_cm3.h
    ITM_SendChar(c);

#else  // modify
    while (!ITM->PORT[chan].u32) ;
    ITM->PORT[chan].u8=(uint8_t)c;
#endif
}


/**
 * SWO_PrintString()
 *
 * @brief Print a string via SWO.
 * @param *s The string to be printed.
 *
 */
void SWO_PrintString(const char *s, uint8_t chan) {

    // Print out characters until \0
    while (*s) {
        SWO_PrintChar(*s++, chan);
    }

}


