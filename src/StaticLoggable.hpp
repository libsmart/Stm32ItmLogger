/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LIBSMART_STM32ITMLOGGER_STATICLOGGABLE_HPP
#define LIBSMART_STM32ITMLOGGER_STATICLOGGABLE_HPP

#include "EmptyLogger.hpp"
#include "Stm32ItmLogger.hpp"

namespace Stm32ItmLogger {
    class StaticLoggable {
    public:
        StaticLoggable() {
            loggerInstance = &emptyLogger;
        }

        explicit StaticLoggable(LoggerInterface *logger) {
            loggerInstance = logger;
        }

        static void setLogger(LoggerInterface *logger) { loggerInstance = logger; }
        [[nodiscard]] static LoggerInterface *getLogger() { return loggerInstance; }
        [[nodiscard]] static LoggerInterface *log() { return loggerInstance; }

    private:
        static LoggerInterface *loggerInstance;
    };

    inline LoggerInterface *StaticLoggable::loggerInstance = &emptyLogger;
}

#endif //LIBSMART_STM32ITMLOGGER_STATICLOGGABLE_HPP
