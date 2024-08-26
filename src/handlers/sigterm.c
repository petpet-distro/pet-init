#define XOPEN_SOURCE 700

#include <stdio.h>
#include <unistd.h>

#include <sys/reboot.h>
#include <linux/reboot.h>

#include "../../headers/src/helpers/killingSpree.h"

void
sigterm(int signo)
{
	killingSpree();

	dprintf(2, "Syncing..");

	sync();
	dprintf(2, ".\n");

	reboot(LINUX_REBOOT_CMD_POWER_OFF);

	return;
}
