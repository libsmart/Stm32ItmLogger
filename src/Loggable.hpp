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

        Loggable() = default;

        explicit Loggable(LoggerInterface *logger)
            : loggerInstance(logger) { ; }

        virtual void setLogger(LoggerInterface *logger) { loggerInstance = logger; }

        [[nodiscard]] virtual LoggerInterface *getLogger() const { return loggerInstance; }

        [[nodiscard]] virtual LoggerInterface *log() {
            return loggerInstance->setSeverity(Stm32ItmLogger::defaultSeverity);
        }

        [[nodiscard]] virtual LoggerInterface *log(Stm32ItmLogger::Severity severity) {
            return loggerInstance->setSeverity(severity);
        }

    private:
        LoggerInterface *loggerInstance = &emptyLogger;
    };
}

#endif //LIBSMART_STM32ITMLOGGER_LOGGABLE_HPP
