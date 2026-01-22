#include "save_opt.h"

#include "externs.h"
#include "fileio.h"
#include "stdio.h"
#include <dos.h>

extern unsigned char tiles_to_draw_max[];

void save_graphic_options()
{
	char buffer[80];
	int buflen;
	buflen = _sprintf(buffer, "detail_level=%d\n", detail_level);
	file_write_nofatal("stunts.ini", buffer, buflen);
}

void load_graphic_options()
{
	// While Stunts' `file_write_*` functions are safe, the `file_read` family
	// does no check for buffer overflows in case of too large file. This is
	// unacceptable in 2025, so use the low-level file API, whose
	// implementation we borrow from Restunts
	char buffer[80];
	int res;
	char temp_detail_level = 0;

	FILE* file = fopen("stunts.ini", "rb");
	if (file == 0)
	{
		// _printf("No file!\n");
		// _printf("Error: %d\n", g_errno);
		return;
	}

	// Check length to avoid truncated reads
	fseek(file, 0, SEEK_END);
	res = ftell(file);
	if (res + 1 > sizeof(buffer))
	{
		_printf("Too long!\n");
		fclose(file);
		return;
	}
	fseek(file, 0, SEEK_SET);

	// Read file into buffer.
	for (res = 0; res < sizeof(buffer); ++res)
		buffer[res] = 0; // memset for safety
	fread(buffer, res, 1, file);

	// Parse graphic level: copy away the number and check
	// that what precedes is the name of the variable
	temp_detail_level = buffer[strlen("detail_level=")];
	buffer[strlen("detail_level=")] = '\0';
	res = strcmp(buffer, "detail_level=");
	if (res != 0)
	{
		_printf("Invalid options file:\n");
		_printf("Expected %s got %s: %d\n", "detail_level=", buffer);
		return;
	}

	// Poor man's atoi. Thankfully it's one digit only
	temp_detail_level -= '0' - 0;
	if (temp_detail_level < 0 || temp_detail_level > 5)
	{
		// _printf("Invalid graphic level:\n", temp_detail_level);
		return;
	}
	if (temp_detail_level == 5) {
		// There is no graphic level 5 in the game. But we offer it as easter egg
		temp_detail_level = 4;
		tiles_to_draw_max[4] = 0;
	}

	detail_level = temp_detail_level;

	fclose(file);
}
