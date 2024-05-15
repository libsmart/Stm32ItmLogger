/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "Stm32ItmLoggerCPPWrapper.hpp"
#include "Stm32ItmLogger.hpp"


size_t Logger_print(const char *prnt_cstring) {
    return Stm32ItmLogger::logger.print(prnt_cstring);
}


size_t Logger_println(const char *prnt_cstring) {
    return Stm32ItmLogger::logger.println(prnt_cstring);
}


#ifdef LIBSMART_ENABLE_PRINTF
size_t Logger_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    auto ret = Logger_vprintf(format, args);
    va_end(args);
    return ret;
}

#ifdef LIBSMART_ENABLE_DIRECT_BUFFER_WRITE
size_t Logger_vprintf(const char *format, va_list args) {
    return Stm32ItmLogger::logger.vprintf(format, args);
}
#endif
#endif
