#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

#include "config.h"

static void
sigint(int signo)
{
	write(1, "sigint\n", 7);
	return;
}

static void
sigterm(int signo)
{
	write(1, "sigterm\n", 8);
	return;
}

static void
sigusr1(int signo)
{
	write(1, "sigusr1\n", 8);

	execve(initArgv[0], initArgv, NULL);
	if (errno != 0) {
		perror("execve(2)");
	}

	return;
}

void
applySIGINT(void)
{
	struct sigaction sigh = { 0 };

	dprintf(2, "SIGINT");

	sigh.sa_handler = &sigint;
	sigaction(SIGINT, &sigh, NULL);
	if (errno != 0) {
		dprintf(2, ":FAIL");
		return;
	}

	dprintf(2, " ");

	return;
}

void
applySIGTERM(void)
{
	struct sigaction sigh = { 0 };

	dprintf(2, "SIGTERM");

	sigh.sa_handler = sigterm;
	sigaction(SIGTERM, &sigh, NULL);
	if (errno != 0) {
		dprintf(2, ":FAIL");
		return;
	}

	dprintf(2, " ");

	return;
}

void
applySIGUSR1(void)
{
	struct sigaction sigh = { 0 };

	dprintf(2, "SIGUSR1");

	sigh.sa_handler = sigusr1;
	sigaction(SIGUSR1, &sigh, NULL);
	if (errno != 0) {
		dprintf(2, ":FAIL");
		return;
	}

	dprintf(2, " ");

	return;
}

int
applyHandlers(void)
{
	dprintf(2, "Applying handlers... ");

	applySIGINT();
	applySIGTERM();
	applySIGUSR1();

	dprintf(2, "\n");
}

int
main(void)
{
	/*if (getpid() != 1) {
		dprintf(2, "Not running as init, running as %d instead. Exitting.\n", getpid());
		return 1;
	}*/

	applyHandlers();
	getpid();

	while (1) {
		pause();
	}

	// never quits, this is PID 1 after all!
}
