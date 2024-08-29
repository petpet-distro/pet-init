#include <unistd.h>

#include <sys/reboot.h>
#include <linux/reboot.h>

void
sigint(int signo)
{
	reboot(LINUX_REBOOT_CMD_RESTART);
	
	return;
}
