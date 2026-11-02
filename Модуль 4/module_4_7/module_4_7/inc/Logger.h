// logger.h (простой враппер)
#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>

// Можно легко заменить на любой логгер потом!
#define LOG_INFO(...) qDebug() << "[INFO]" << __FUNCTION__ << __VA_ARGS__
#define LOG_WARNING(...) qWarning() << "[WARN]" << __FUNCTION__ << __VA_ARGS__
#define LOG_ERROR(...) qCritical() << "[ERROR]" << __FUNCTION__ << __VA_ARGS__

#endif