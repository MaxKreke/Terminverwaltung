#ifndef TERMIN_H_
#define TERMIN_H_

#include <string>
#include "time.h"

using namespace std;

class Termin {
public:
	Termin(Time start, Time end, string beschreibung);
	bool operator<(Termin & other);
	Termin operator=(Termin & other);
	bool collidesWith(Termin & other);
private:
	Time m_t_start;
	Time m_t_end;
	int m_durationInMinutes;
	string m_bescreibung;
};

#endif //TERMIN_H_
