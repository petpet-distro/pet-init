#include <stdio.h>
#include <unistd.h>

#include "../config.h"
#include "../headers/src/helpers/applyHandlers.h"
#include "../headers/src/helpers/spawn.h"

int
main(void)
{
	applyHandlers();
	getpid();
	spawn(miauArgv);

	while (1) {
		pause();
	}

	// never quits, this is PID 1 after all!
}
