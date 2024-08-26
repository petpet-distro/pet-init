#define XOPEN_SOURCE 700

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

#include "../../headers/src/handlers/sigterm.h"

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
