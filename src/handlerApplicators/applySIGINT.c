#define XOPEN_SOURCE 700

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

#include "../../headers/src/handlers/sigint.h"

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
