/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LIBSMART_STM32ITMLOGGER_EMPTYLOGGER_HPP
#define LIBSMART_STM32ITMLOGGER_EMPTYLOGGER_HPP
#include "LoggerInterface.hpp"

namespace Stm32ItmLogger {
    /**
     * @class EmptyLogger
     * @brief A logger class that does nothing.
     *
     * This class implements the LoggerInterface and does not perform any logging operations.
     */
    class EmptyLogger final : public LoggerInterface {
    public:
        size_t getWriteBuffer(uint8_t *&buffer) override {
            buffer = nullptr;
            return 0;
        }

        size_t setWrittenBytes(size_t size) override { return size; }

        size_t write(uint8_t data) override { return 1; }

        int availableForWrite() override { return 0; }

        void flush() override {
        }
    };

    /**
     * Globally defined NULL-logger instance.
     */
    inline EmptyLogger emptyLogger;
}


#endif //LIBSMART_STM32ITMLOGGER_EMPTYLOGGER_HPP
