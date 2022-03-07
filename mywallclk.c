#include <zmeter.h>
#include <platform-header.h>
#include "app/framework/include/af.h"


static uint32_t time, ticks, msec;
static int wait;

uint32_t time_run(sl_zigbee_event_t *e)
{
	utc_t now = emberAfGetCurrentTimeCallback();
	uint32_t last = e->timeToExecute, delay = MILLISECOND_TICKS_PER_SECOND;

	int adjust = wait; // shorten/extend tick until wait is 0
	if (adjust < -4) // we're too slow
		adjust = -4; // limit shorten to ~4mS
	else if (adjust > 4) // we're too fast
		adjust = 4; // limit stretch to ~4mS
	wait -= adjust;
	delay += adjust;

	slxu_zigbee_event_set_delay_ms(e, delay);
	if (last)
		e->timeToExecute = last + delay;

	return now;
}

void emberAfSetTimeCallback(uint32_t t)
{
	ticks = halCommonGetInt32uMillisecondTick();
	msec = 0;

	if (time == 0 || time - t > 60 || t - time > 60)
		time = t;
	else
		wait = (time - t) * MILLISECOND_TICKS_PER_SECOND; // +ve: we're too fast
}

uint32_t emberAfGetCurrentTimeCallback(void)
{
	uint32_t now = halCommonGetInt32uMillisecondTick(), since = now - ticks + msec;
	time += since / MILLISECOND_TICKS_PER_SECOND;
	msec = since % MILLISECOND_TICKS_PER_SECOND;
	ticks = now;
	return time;
}
