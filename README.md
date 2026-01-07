# SlowWriting
A dumb idea to slow down the process of writing your payload into an allocated memory. This could be improved...

SlowWriting is a C++ function to simulate the memmove function. This function writes each byte of the payload based on the `dwMiliseconds` parameter. Why did I write this? I don't know, I just coded 'cause I dreamed about it.

```cpp
BOOL SlowWriting(
    [in] LPVOID pDestBuffer,
    [in] LPCVOID pSourceBuffer,
    [in] SIZE_T dwBufferSize,
    [out] SIZE_T *lpNumberOfBytesWritten,
    [in] DWORD dwMilliseconds
)
```

Ps: this is for Windows... Have fun! Bye :)
