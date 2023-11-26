#include <stdio.h>

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/storage/disk_access.h>
#include <zephyr/logging/log.h>
#include <zephyr/fs/fs.h>

#include <zephyr/drivers/display.h>
#include <errno.h>

LOG_MODULE_REGISTER(main);

void format_n(uint32_t n, uint8_t *buf, size_t bufsz)
{
	const uint8_t table[] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 123};
	for (size_t i = 0; i < bufsz; ++i)
	{
		buf[i] = table[n % 10];
		n /= 10;
	}
}

int main(void)
{
	const struct device *display_dev = DEVICE_DT_GET(DT_NODELABEL(max7219));
	if (!device_is_ready(display_dev))
	{
		LOG_ERR("display not ready");
	}

	struct display_buffer_descriptor buf_desc = 
	{
		.buf_size = 8,
		.height = 8,
		.width = 8,
		.pitch = 8
	};

	uint8_t buf[8];

	for (;;)
	{
		format_n(k_uptime_get(), buf, sizeof(buf));
		display_write(display_dev, 0, 0, &buf_desc, buf);
	}

	return 0;
}
