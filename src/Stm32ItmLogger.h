/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LIBSMART_STM32ITMLOGGER_LOGGER_H
#define LIBSMART_STM32ITMLOGGER_LOGGER_H

#include <libsmart_config.hpp>
#include <stdio.h>
#include <stdarg.h>
#include <stdint-gcc.h>
#include <malloc.h>
#include "Stm32ItmLoggerCPPWrapper.hpp"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    uint8_t chan;
} Debugger;

/**
 * @brief Creates a new Debugger instance.
 *
 * This function allocates memory for a new Debugger object and initializes its chan member
 * with the provided channel value.
 *
 * @param chan The channel value for the Debugger.
 * @return A pointer to the newly created Debugger instance.
 * @deprecated Use static struct without constructor.
 */
Debugger *Debugger_create(uint8_t chan);

/**
 * @brief Logs a formatted message to the debugger.
 *
 * This function is used to log a formatted message to the debugger.
 * It takes a variable number of arguments similar to the `printf` function.
 * The message is written to the debugger's channel using the SWO_PrintString function.
 * The channel to write the message to is specified by the `chan` member of the debugger struct.
 *
 * @param debugger A pointer to the Debugger struct.
 * @param format   The format string for the log message.
 * @param ...      Variable arguments to be formatted according to the format string.
 */
void Debugger_log(Debugger *debugger, const char *format, ...);

/**
 * @brief         Prints a character to the ITM_STIM register for SWO output.
 *
 * @param[in]     c    The character to be printed.
 * @param[in]     chan The channel to which the character will be sent.
 *
 * @details       This function checks if SWO is set up. If it is not, the function returns
 *                to avoid program hangs if no debugger is connected. If SWO is set up,
 *                the function prints the given character to the ITM_STIM register in order
 *                to provide data for SWO.
 */
void SWO_PrintChar(char c, uint8_t chan);

/**
 * @brief Print a string via SWO.
 * @param s The string to be printed.
 * @param chan The channel number to be used for SWO.
 *
 * This function prints a null-terminated string to the ITM_STIM register,
 * which provides data for SWO (Serial Wire Output).
 *
 * If SWO is not set up, the function will return to avoid program hangs if no debugger is connected.
 */
void SWO_PrintString(const char *s, uint8_t chan);

#ifdef __cplusplus
}
#endif

#endif //LIBSMART_STM32ITMLOGGER_LOGGER_H
