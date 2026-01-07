#include "slowwriting.h"

BOOL SlowWriting(LPVOID pDestBuffer, LPCVOID pSourceBuffer, SIZE_T dwBufferSize, SIZE_T* lpNumberOfBytesWritten, DWORD dwMilliseconds)
{

	if (lpNumberOfBytesWritten)
	{
		*lpNumberOfBytesWritten = 0;
	}

	if (dwBufferSize == 0)
	{
		return TRUE;
	}

	if (!pDestBuffer || !pSourceBuffer)
	{
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (pDestBuffer == (LPVOID)pSourceBuffer)
	{
		if (lpNumberOfBytesWritten)
		{
			*lpNumberOfBytesWritten = dwBufferSize;
		}
		return TRUE;
	}

	volatile unsigned char* d = (volatile unsigned char*)pDestBuffer;
	const unsigned char* s = (const unsigned char*)pSourceBuffer;

	if ((uintptr_t)d < (uintptr_t)s || (uintptr_t)d >= (uintptr_t)(s + dwBufferSize))
	{
		// Forward copy
		for (SIZE_T i = 0; i < dwBufferSize; i++)
		{
			d[i] = s[i];
			if (lpNumberOfBytesWritten)
				(*lpNumberOfBytesWritten)++;
			if (dwMilliseconds)
				Sleep(dwMilliseconds);
		}
	}
	else
	{
		// Backword copy
		for (SIZE_T i = dwBufferSize; i != 0; i--)
		{
			d[i - 1] = s[i - 1];
			if (lpNumberOfBytesWritten)
				(*lpNumberOfBytesWritten)++;
			if (dwMilliseconds)
				Sleep(dwMilliseconds);
		}
	}

	return TRUE;
}
