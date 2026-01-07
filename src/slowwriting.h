#pragma once
#include <Windows.h>

BOOL SlowWriting(LPVOID pDestBuffer, LPCVOID pSourceBuffer, SIZE_T dwBufferSize, SIZE_T* lpNumberOfBytesWritten, DWORD dwMilliseconds);

