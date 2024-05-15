/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LIBSMART_STM32ITMLOGGER_STM32ITMLOGGER_HPP
#define LIBSMART_STM32ITMLOGGER_STM32ITMLOGGER_HPP

#include <libsmart_config.hpp>
#include <main.h>
#include "Print.hpp"
#include "StringBuffer.hpp"
#include "LoggerInterface.hpp"

namespace Stm32ItmLogger {
    class Stm32ItmLogger : public LoggerInterface {
    public:
        Stm32ItmLogger() = default;

        explicit Stm32ItmLogger(Severity printSeverity) : LoggerInterface(printSeverity) {
        }

        explicit Stm32ItmLogger(uint8_t chan) : chan(chan) {
        }

        Stm32ItmLogger(Severity printSeverity, uint8_t chan) : LoggerInterface(printSeverity), chan(chan) {
        }

        size_t write(uint8_t data) override {
            if (!checkSeverity()) return 1;
            ITM_SendChar(data);
            return 1;
        }

        int availableForWrite() override {
            return 0;
        }

        void flush() override {
            while (!stringBuffer.isEmpty()) {
                write(stringBuffer.read());
            }
        }


        /**
         * @brief Retrieves the write buffer and the remaining space in the buffer.
         *
         * This function retrieves the write buffer and the remaining space in the buffer.
         * The write buffer is set to the `buffer` parameter and the remaining space is returned.
         * It is the responsibility of the caller to use the write buffer and update the `buffer` pointer
         * accordingly.
         *
         * @param[out] buffer The write buffer pointer.
         * @return The remaining space in the buffer.
         */
        size_t getWriteBuffer(uint8_t *&buffer) override {
            buffer = stringBuffer.getWritePointer();
            return stringBuffer.getRemainingSpace();
        }


        /**
         * @brief Sets the number of bytes written to the logger.
         *
         * This function sets the number of bytes written to the logger.
         * It updates the internal stringBuffer by adding the given size.
         * If there are any remaining bytes in the stringBuffer, it writes
         * them to the logger using the write() function.
         *
         * @param size The number of bytes to set as written.
         * @return The number of bytes added to the stringBuffer.
         */
        size_t setWrittenBytes(size_t size) override {
            auto added = stringBuffer.add(size);
            int ch;
            while ((ch = stringBuffer.read()) >= 0) {
                write((uint8_t) ch);
            }
            return added;
        }

        LoggerInterface *setSeverity(Severity newSeverity) override {
            LoggerInterface::setSeverity(newSeverity);
            if (!checkSeverity()) return this;
            if (newSeverity == previousSeverity) return this;

#ifdef LIBSMART_LOGGER_ENABLE_ANSI_COLORS_OVER_ITM
            switch (newSeverity) {
                case Severity::EMERGENCY:
                    print("\x1b[1;37;41m"); // White/Red
                    break;

                case Severity::ALERT:
                    print("\x1b[0;30;43m"); // Black/Yellow
                    break;

                case Severity::CRITICAL:
                    print("\x1b[91m"); // Bright Red
                    break;

                case Severity::ERROR:
                    print("\x1b[38;5;220m"); // Yellow-Orange
                    break;

                case Severity::WARNING:
                    print("\x1b[1;33m"); // light Yellow
                    break;

                case Severity::NOTICE:
                    print("\x1b[1;37m"); // White
                    break;

                case Severity::INFORMATIONAL:
                    print("\x1b[0m");
                    break;

                case Severity::DEBUGGING:
                    print("\x1b[0;90m");
                    break;
            }
#endif

            previousSeverity = newSeverity;
            return this;
        }

    private:
        Severity previousSeverity = {};
        uint8_t chan = 0;
        Stm32Common::StringBuffer<LIBSMART_ITM_LOGGER_BUFFER_SIZE> stringBuffer;
    };

    /**
     * Globally defined logger instance.
     */
    inline Stm32ItmLogger logger;
}

#endif //LIBSMART_STM32ITMLOGGER_STM32ITMLOGGER_HPP
