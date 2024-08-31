#define XOPEN_SOURCE 700

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pid_t
spawn(char *const argv[])
{
	pid_t pidRet = 0;

	pidRet = fork();
	if (errno != 0) {
		return 1;
	}

	if (pidRet == 0) {
		execve(argv[0], argv, NULL);
		abort();

		return 1;
	}

	return pidRet;
}
