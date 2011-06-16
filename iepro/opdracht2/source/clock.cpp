#include "clock.hpp"
#include "nintendo_ds.hpp"

time_t rawtime;
tm * ptm;
Clock cclock;

s8 city1[] = "Pago Pago";
s8 city2[] = "Los Angeles";
s8 city3[] = "London";
s8 city4[] = "Amsterdam";
s8 city5[] = "Tokyo";
s8 city6[] = "Wellington";

Timezone SST = {city1, -11};
Timezone PST = {city2, -8};
Timezone PDT = {city2, -7};
Timezone GMT = {city3, 0};
Timezone BST = {city3, 1};
Timezone CET = {city4, 1};
Timezone CEST = {city4, 2};
Timezone JST = {city5, 9};
Timezone NZST = {city6, 12};
Timezone NZDT = {city6, 13};

Time time1 = {&SST, &cclock, white, {2,0}};
Time time2 = {&PDT, &cclock, blue, {4,3}};
Time time3 = {&CEST, &cclock, cyan, {8,6}};
Time time4 = {&NZST, &cclock, red, {16,9}};

// updates the clock
void update_clock(Clock* cl)
{
	cl->second = cl->second + 1;
	if (cl->second >= 60)
	{
		cl->second = 0;
		cl->minute = cl->minute + 1;
	}
	if (cl->minute >= 60)
	{
		cl->minute = 0;
		cl->hour = cl->hour + 1;
	}
	if (cl->hour >= 24)
	{
		cl->hour = 0;
	}
}

// Displays given Time object
void display_time(Time* t)
{
	set_position(t->position.x, t->position.y);
	set_font_color(t->color);
	printf("%s:", t->timezone->city);
	set_position(t->position.x + 1, t->position.y);
	printf("%02d:%02d:%02d", (t->clock->hour + t->timezone->time_diff), t->clock->minute, t->clock->second);
	if (t->timezone->time_diff < 0)
		printf(" (UTC%d)", t->timezone->time_diff);
	else
		printf(" (UTC+%d)", t->timezone->time_diff);
}

int main()
{
	rawtime = time( NULL );
	ptm = gmtime( &rawtime );

	cclock.hour = ((u8)ptm->tm_hour - 2);
	cclock.minute = (u8)ptm->tm_min;
	cclock.second = (u8)ptm->tm_sec;

	prepare_screens();
	loop();

	return 0;
}