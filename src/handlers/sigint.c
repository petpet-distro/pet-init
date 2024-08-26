#include <unistd.h>

#include <sys/reboot.h>
#include <linux/reboot.h>

#include "../../headers/src/helpers/killingSpree.h"

void
sigint(int signo)
{
	killingSpree();

	sync();

	reboot(LINUX_REBOOT_CMD_RESTART);
	
	return;
}
