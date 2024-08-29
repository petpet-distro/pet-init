#define XOPEN_SOURCE 700

#include <stdio.h>

#include "../../headers/src/handlerApplicators/applySIGINT.h"
#include "../../headers/src/handlerApplicators/applySIGTERM.h"

int
applyHandlers(void)
{
	dprintf(2, "Applying handlers... ");

	applySIGINT();
	applySIGTERM();

	dprintf(2, "\n");

	return 0;
}
