#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int
killingSpree(void)
{
	int fd = 0;
	
	fd = open("/proc/sysrq-trigger", O_WRONLY);
	if (errno != 0) {
		perror("open(2)");
		return 1;
	}

	dprintf(2, "Terminating all processes...\n");

	// Send SIGTERM to all processes, except init
	write(fd, &"e", 1);

	sleep(2);

	dprintf(2, "Killing all processes...\n");

	write(fd, &"i", 1);
	close(fd);

	return 0;
}
