#include "IO.h"

char* read_file(const char* pathname)
{
    FILE* file = fopen(pathname, "rb");

		if (file == NULL)
		{
			fprintf(stderr, "Failed to open file.\n");
			return NULL;
		}

    ssize_t len;
    fseek(file, 0L, SEEK_END);
    len = ftell(file);
    fseek(file, 0L, SEEK_SET);
    char *buffer = calloc(1, sizeof(char) * len);
    fread(buffer, sizeof(char), len, file);
    fclose(file);
    buffer[len - 1] = '\0';
    return buffer;
}
