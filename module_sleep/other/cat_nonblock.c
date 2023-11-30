/*
 * cat_nonblock.c - open a file and display its content, but exit rather
 * than wait for input.
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

#define MAX_BYTES 1024 * 4

int main(int argc, char *argv[])
{
	int fd;                 /* The file descriptor for the file to read */
	size_t bytes;           /* The number of bytes read */
	char buffer[MAX_BYTES]; /* The buffer for the bytes */

	/* Usage */
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		puts("Reads the content of the fule, but does not wait for input");
		exit(-1);
	}

	/* Open the file for reading in non blocking mode */
	fd = open(argv[1], O_RDONLY | O_NONBLOCK);

	/* If open failed */
	if (fd == -1)
	{
		puts(errno == EAGAIN ? "Open would block" : "Open failed");
		exit(-1);
	}

	/* Read the file and output its contents */
	do
	{
		/* Read characters from the file */
		bytes = read(fd, buffer, MAX_BYTES);

		/* If there is an error, report it and die */
		if (bytes == -1)
		{
			if (errno == EAGAIN)
			{
				puts("Normally I would block, but you told me not to");
			}
			else
			{
				puts("Another read error");
				exit(-1);
			}
		}

		/* Print the characteers */
		if (bytes > 0)
		{
			for (int i = 0; i < bytes; i++)
			{
				putchar(buffer[i]);
			}

			/* While there are no errors and the file is not over */
		}
	} while (bytes > 0);

	return 0;
}
