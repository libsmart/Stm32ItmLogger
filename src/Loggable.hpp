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
        virtual ~Loggable() { ; }

        Loggable() : loggerInstance(&emptyLogger) { ; }

        explicit Loggable(LoggerInterface *logger)
                : loggerInstance(logger) { ; }

        virtual void setLogger(LoggerInterface *logger) { loggerInstance = logger; }

        [[nodiscard]] virtual LoggerInterface *getLogger() const { return loggerInstance; }

        [[nodiscard]] virtual LoggerInterface *log() const { return loggerInstance; }

    protected:
        LoggerInterface *loggerInstance;
    };
}

#endif //LIBSMART_STM32ITMLOGGER_LOGGABLE_HPP
