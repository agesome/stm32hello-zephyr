#include <stdio.h>

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/storage/disk_access.h>
#include <zephyr/logging/log.h>
#include <zephyr/fs/fs.h>

#include <zephyr/drivers/display.h>

LOG_MODULE_REGISTER(main);

int main(void)
{
	const struct device *display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev))
	{
		LOG_ERR("display not ready");
	}
	else
	{
		LOG_INF("display seems ok?");
	}

	return 0;
}
