/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LIBSMART_STM32ITMLOGGER_LOGGABLE_HPP
#define LIBSMART_STM32ITMLOGGER_LOGGABLE_HPP

#include "EmptyLogger.hpp"
#include "Stm32ItmLogger.hpp"

namespace Stm32ItmLogger {
    class Loggable {
    public:
        Loggable(): loggerInstance(&emptyLogger) {
        }

        explicit Loggable(LoggerInterface *logger)
            : loggerInstance(logger) {
        }

        void setLogger(LoggerInterface *logger) { loggerInstance = logger; }
        [[nodiscard]] LoggerInterface *getLogger() const { return loggerInstance; }
        [[nodiscard]] LoggerInterface *log() const { return loggerInstance; }

    private:
        LoggerInterface *loggerInstance;
    };
}

#endif //LIBSMART_STM32ITMLOGGER_LOGGABLE_HPP
