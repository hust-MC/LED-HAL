/*
 * main.c
 *
 *  Created on: 2014年7月3日
 *      Author: root
 */
#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int arc, char **argv)
{
	char *usage = "Usage: test <dev_file> <led0> <led1> <led2> <led3>\n";
	unsigned char cmd[4];
	int i, file_handler;

	if (arc != 6)
	{
		printf(usage);
		return 0;
	}

	char *dev_file = argv[1];
	file_handler = open(dev_file, O_RDWR);
	for (i = 2; i < 6; i++)
	{
		if (!strcmp(argv[i],"1"))
		{
			cmd[i-2] = 0;
		}
		else if (!strcmp(argv[i],"0"))
		{
			cmd[i-2] = 1;
		}
		else
		{
			printf("argv[%d] error\n",i);
		}
	}

	write(file_handler, cmd, strlen(cmd));
	close(file_handler);
	return 0;
}
