/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STM32_ITM_LOGGER_H
#define STM32_ITM_LOGGER_H

#include "config.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint-gcc.h>
#include <malloc.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    uint8_t chan;
} Debugger;

Debugger* Debugger_create(uint8_t chan);
void Debugger_log(Debugger* debugger, const char* format, ...);
void SWO_PrintChar(char c, uint8_t chan);
void SWO_PrintString(const char *s, uint8_t chan);

#ifdef __cplusplus
}
#endif

#endif //STM32_ITM_LOGGER_H
