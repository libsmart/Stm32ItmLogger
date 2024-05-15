/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LIBSMART_STM32ITMLOGGER_STM32ITMLOGGERCPPWRAPPER_HPP
#define LIBSMART_STM32ITMLOGGER_STM32ITMLOGGERCPPWRAPPER_HPP

#include <libsmart_config.hpp>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t Logger_print(const char *prnt_cstring);
size_t Logger_println(const char *prnt_cstring);

#ifdef LIBSMART_ENABLE_PRINTF
/**
 * @brief Writes formatted output to the underlying device using a variable argument list.
 *
 * This function is similar to the standard C library function vprintf().
 * It takes a format string and a variable argument list to generate formatted output.
 * The formatted output is written to the underlying device.
 *
 * @param format The format string.
 * @param args The variable argument list.
 * @return The number of bytes written to the underlying device.
 * @note This function is an extension to the class Print in arduino.
 */
size_t Logger_printf(const char *format, ...);

#ifdef LIBSMART_ENABLE_DIRECT_BUFFER_WRITE
/**
 * @brief Writes formatted output to the underlying device using a variable argument list.
 *
 * This function is similar to the standard C library function vprintf().
 * It takes a format string and a variable argument list to generate formatted output.
 * The formatted output is written to the underlying device.
 *
 * @param format The format string.
 * @param args The variable argument list.
 * @return The number of bytes written to the underlying device.
 * @note This function is an extension to the class Print in arduino.
 */
size_t Logger_vprintf(const char *format, va_list args);
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif //LIBSMART_STM32ITMLOGGER_STM32ITMLOGGERCPPWRAPPER_HPP
