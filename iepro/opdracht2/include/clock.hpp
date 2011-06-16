#ifndef CLOCK_H_
#define CLOCK_H_

#include <nds.h>
#include <cstdlib>
#include <ctime>
#include "geometry.hpp"

struct Clock
{
	u8 hour;
	u8 minute;
	u8 second;
};

struct Timezone
{
	s8* city;
	s8 time_diff;
};

struct Time
{
	Timezone* timezone;
	Clock* clock;
	Color color;
	Point position;
};

void update_clock(Clock* cl);	// Verhoogt de tijd in de klok met een seconde (je mag kiezen voor een 12/24 uurs klok).

void display_time(Time*);		// Laat de tijd op de ingestelde positie zien met de naam van de stad met 
								// daaronder de tijd (op basis van de clock samen met het verschil (time_diff)) in de gekozen kleur.
								// (zorg ervoor dat beide methoden elke seconde worden aangeroepen).
#endif