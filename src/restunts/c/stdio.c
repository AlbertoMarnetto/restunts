#include "stdio.h"

#include "externs.h"

#include <dos.h>

int g_errno;

FILE* fopen(const char* path, const char* mode)
{
	unsigned short segm = FP_SEG(path);
	unsigned short offs = FP_OFF(path);
	FILE* handle;

	g_errno = 0;

	if (mode[0] == 'w') { // Create new file for writing
		__asm {
			push ds
			mov  ah, 3Ch // Create file
			mov  cx, 0 // No attributes
			mov  ds, segm
			mov  dx, offs
			int  21h
			jnc  short create_ok
			mov  ax, 0
			mov  g_errno, 1
		create_ok:
			mov  handle, ax
			pop  ds
		}
	}
	else { // Open existing file for reading
		__asm {
			push ds
			mov  ah, 3Dh // Open file
			mov  al, 0 // Read only
			mov  ds, segm
			mov  dx, offs
			int  21h
			jnc  short open_ok
			mov  ax, 0
			mov  g_errno, 1
		open_ok:
			mov  handle, ax
			pop  ds
		}
	}

	return handle;
}

int fclose(FILE* file)
{
	int res;

	__asm {
		mov  ah, 3Eh // Close file
		mov  bx, file
		int  21h
		jnc  short close_ok
		mov  ax, 0
		mov  g_errno, 1
	close_ok:
		mov  res, ax
	}

	return res;
}

size_t fread(void far* dst, size_t size, size_t nmemb, FILE* file)
{
	unsigned short segm = FP_SEG(dst);
	unsigned short offs = FP_OFF(dst);

	size_t res;
	size *= nmemb;

	__asm {
		push ds
		mov  ah, 3Fh // Read from file
		mov  bx, file
		mov  ds, segm
		mov  dx, offs
		mov  cx, size
		int  21h
		jnc  short read_ok
		mov  ax, 0
		mov  g_errno, 1
	read_ok:
		mov  res, ax
		pop  ds
	}

	return res;
}

size_t fwrite(const void far* src, size_t size, size_t nmemb, FILE* file)
{
	unsigned short segm = FP_SEG(src);
	unsigned short offs = FP_OFF(src);

	size_t res;
	size *= nmemb;

	__asm {
		push ds
		mov  ah, 40h // Write to file
		mov  bx, file
		mov  ds, segm
		mov  dx, offs
		mov  cx, size
		int  21h
		jnc  short write_ok
		mov  ax, 0
		mov  g_errno, 1
	write_ok:
		mov  res, ax
		pop  ds
	}

	return res;
}

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

int fseek(FILE *file, long offset, int origin)
{
	unsigned short ol = offset;
	unsigned short oh = offset >> 16;

	origin |= (0x42 << 8); // Seek file cmd as high byte

	__asm {
		mov  ax, origin
		mov  bx, file
		mov  cx, oh
		mov  dx, ol
		int  21h
		jnc  short seek_ok
		mov  g_errno, 1
	seek_ok:
	}

	return 0;
}
long ftell(FILE *file)
{
	unsigned short ol;
	unsigned short oh;

	__asm {
		mov  ah, 42h // Seek file
		mov  al, SEEK_CUR
		mov  bx, file
		mov  cx, 0
		mov  dx, 0
		int  21h
		jnc  short tell_ok
		mov  word ptr g_errno, 1
	tell_ok:
		mov  oh, dx
		mov  ol, ax
	}

	return ((long)oh << 16) | ol;
}

int ferror(FILE* file)
{
	int res = g_errno;
	(void)file;
	g_errno = 0;
	return res;
}
