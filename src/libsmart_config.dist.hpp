/*
 * SPDX-FileCopyrightText: 2024 Roland Rusch, easy-smart solution GmbH <roland.rusch@easy-smart.ch>
 * SPDX-License-Identifier: BSD-3-Clause
 */


/**
 * Messages are logged in this severity, if no severity is specified
 */
#define LIBSMART_LOGGER_DEFAULT_SEVERITY Severity::NOTICE


/**
 * Output severity
 */
#define LIBSMART_LOGGER_DEFAULT_PRINT_SEVERITY Stm32ItmLogger::LoggerInterface::allPrintSeverity


/**
 * Enable ANSI colors for the ITM logger
 */
#undef LIBSMART_LOGGER_ENABLE_ANSI_COLORS_OVER_ITM
#define LIBSMART_LOGGER_ENABLE_ANSI_COLORS_OVER_ITM


/**
 * Size of the buffer for printf string preparation.
 */
#define LIBSMART_ITM_LOGGER_BUFFER_SIZE 128
