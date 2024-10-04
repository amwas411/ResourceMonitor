
#ifndef DATETIME_HELPER_H
#define DATETIME_HELPER_H
#include "windows.h"

int LoadUserLocale(LPWSTR lpLocaleName, int bufSize)
{
	return GetUserDefaultLocaleName(
		lpLocaleName,
		bufSize
	);
}

int LoadCurrentDate(LPWSTR lpLocaleName, LPWSTR lpDateStr, int bufSize)
{
	DWORD dwFlags = DATE_LONGDATE;
	SYSTEMTIME* lpDate = NULL;
	LPCWSTR lpFormat = NULL;
	LPCWSTR lpCalendar = NULL;

	return GetDateFormatEx(
		lpLocaleName,
		dwFlags,
		lpDate,
		lpFormat,
		lpDateStr,
		bufSize,
		lpCalendar
	);
}

int LoadCurrentTime(LPCWSTR lpLocaleName, LPWSTR lpTimeStr, int bufSize)
{
	DWORD dwFlags = TIME_FORCE24HOURFORMAT;
	SYSTEMTIME* lpTime = NULL;
	LPCWSTR lpFormat = NULL;

	return GetTimeFormatEx(
		lpLocaleName,
		dwFlags,
		lpTime,
		lpFormat,
		lpTimeStr,
		bufSize
	);
}

#endif // !DATETIME_HELPER_H