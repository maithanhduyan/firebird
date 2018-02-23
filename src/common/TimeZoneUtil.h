/*
 *	PROGRAM:		Firebird interface.
 *	MODULE:			TimeZoneUtil.h
 *	DESCRIPTION:	Time zone utility functions.
 *
 *  The contents of this file are subject to the Initial
 *  Developer's Public License Version 1.0 (the "License");
 *  you may not use this file except in compliance with the
 *  License. You may obtain a copy of the License at
 *  http://www.ibphoenix.com/main.nfs?a=ibphoenix&page=ibp_idpl.
 *
 *  Software distributed under the License is distributed AS IS,
 *  WITHOUT WARRANTY OF ANY KIND, either express or implied.
 *  See the License for the specific language governing rights
 *  and limitations under the License.
 *
 *  The Original Code was created by Adriano dos Santos Fernandes
 *  for the Firebird Open Source RDBMS project.
 *
 *  Copyright (c) 2018 Adriano dos Santos Fernandes <adrianosf@gmail.com>
 *  and all contributors signed below.
 *
 *  All Rights Reserved.
 *  Contributor(s): ______________________________________.
 */

#ifndef COMMON_TIME_ZONE_UTIL_H
#define COMMON_TIME_ZONE_UTIL_H

#include "../common/classes/fb_string.h"

namespace Firebird {

class TimeZoneUtil
{
public:
	static const unsigned ONE_DAY = 24 * 60;	// used for offset encoding
	static const USHORT UTC_ZONE = ONE_DAY + 0;
	static const unsigned MAX_LEN = 6;

public:
	static USHORT getCurrent();

	static USHORT parse(const char* str, unsigned strLen);
	static unsigned format(char* buffer, size_t bufferSize, USHORT timeZone);

	static bool isValidOffset(int sign, unsigned tzh, unsigned tzm);

	static void extractOffset(const ISC_TIMESTAMP_TZ& timeStampTz, int* sign, unsigned* tzh, unsigned* tzm);

	static ISC_TIME timeTzAtZone(const ISC_TIME_TZ& timeTz, USHORT atTimeZone);
	static ISC_TIMESTAMP timeStampTzAtZone(const ISC_TIMESTAMP_TZ& timeStampTz, USHORT atTimeZone);
};

}	// namespace Firebird

#endif	// COMMON_TIME_ZONE_UTIL_H
