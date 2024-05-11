/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LIBSMART_STM32ITMLOGGER_LOGGERINTERFACE_HPP
#define LIBSMART_STM32ITMLOGGER_LOGGERINTERFACE_HPP

#include <libsmart_config.hpp>
#include <main.h>
#include "Print.hpp"

namespace Stm32ItmLogger {
    class LoggerInterface : public Stm32Common::Print {
    public:
        enum class Severity {
            /** system is unusable */
            EMERGENCY = 1,
            /** action must be taken immediately */
            ALERT = 2,
            /** critical conditions */
            CRITICAL = 4,
            /** error conditions */
            ERROR = 8,
            /** warning conditions */
            WARNING = 16,
            /** normal but significant condition */
            NOTICE = 32,
            /** informational messages */
            INFORMATIONAL = 64,
            /** debug messages */
            DEBUGGING = 128,
        };
        static constexpr Severity defaultSeverity = (Severity) (
                static_cast<uint8_t>(Severity::NOTICE) | static_cast<uint8_t>(Severity::WARNING) |
                static_cast<uint8_t>(Severity::ERROR) | static_cast<uint8_t>(Severity::CRITICAL) |
                static_cast<uint8_t>(Severity::ALERT) | static_cast<uint8_t>(Severity::EMERGENCY));

        static constexpr Severity allSeverity = (Severity) 255;
        static constexpr Severity noSeverity = (Severity) 0;

        LoggerInterface() = default;

        explicit LoggerInterface(Severity printSeverity) : printSeverity(printSeverity) {}

        /**
         * @brief Sets the severity level for logging.
         *
         * This function updates the current severity level with the provided value.
         *
         * @param newSeverity The new severity level to set.
         */
        virtual void setSeverity(Severity newSeverity) { currentSeverity = newSeverity; }

        /**
         * @brief Check if the current severity level allows logging based on the print severity level.
         *
         * This function checks if the current severity level is enabled for logging based on the
         * print severity level. It performs a bitwise AND operation on the current severity and
         * print severity, and returns true if the result is greater than zero.
         *
         * @return True if the current severity is enabled for logging, false otherwise.
         */
        virtual bool checkSeverity() {
            return (static_cast<uint8_t>(currentSeverity) & static_cast<uint8_t>(printSeverity)) > 0;
        }

        using Print::print;
        using Print::println;
        using Print::flush;

    private:
        Severity currentSeverity = Severity::NOTICE;
        Severity printSeverity = (Severity) defaultSeverity;
    };
}

#endif //LIBSMART_STM32ITMLOGGER_LOGGERINTERFACE_HPP
