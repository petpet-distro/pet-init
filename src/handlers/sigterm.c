#define XOPEN_SOURCE 700

#include <unistd.h>

#include <sys/reboot.h>
#include <linux/reboot.h>

void
sigterm(int signo)
{
	reboot(LINUX_REBOOT_CMD_POWER_OFF);

	return;
}
