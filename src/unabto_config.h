/*
 * Copyright (C) 2008-2013 Nabto - All Rights Reserved.
 */
#ifndef _UNABTO_CONFIG_H_
#define _UNABTO_CONFIG_H_

/**
 * This header contains the specific Nabto settings for this project.
 * All available settings can be read about in "unabto_config_defaults.h".
 * The default value will be used if a specific setting is not set here.
 */

#define NABTO_ENABLE_STREAM             0
#define NABTO_SET_TIME_FROM_ALIVE       0
#define NABTO_ENABLE_LOGGING            1
#define NABTO_CONNECTIONS_SIZE 			4
#define NABTO_ENABLE_UCRYPTO            1

//#define NABTO_ENABLE_REMOTE_CONNECTION  1 //default 1
//#define NABTO_ENABLE_LOCAL_CONNECTION   1 //default 1
//#define NABTO_ENABLE_LOCAL_CONNECTION	0
//#define NABTO_ENABLE_LOCAL_ACCESS		0
//#define NABTO_ENABLE_LOCAL_ACCESS_LEGACY_PROTOCOL	0
//#define NABTO_LOG_ALL					1
//#define NABTO_LOG_SEVERITY_FILTER       NABTO_LOG_SEVERITY_INFO | NABTO_LOG_SEVERITY_TRACE | NABTO_LOG_SEVERITY_LEVEL_DEBUG

#endif
