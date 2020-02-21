#ifndef TERMIN_H_
#define TERMIN_H_

#include <string>
#include "time.h"

using namespace std;

class Termin {
public:

	Termin(const Time start, const Time end, const string &beschreibung);
	Termin(Time start, long long duration, string beschreibung);
	bool operator<(Termin &other);
	Termin &operator=(const Termin &other);
	bool collidesWith(Termin & other);
private:
    Time m_t_start;
    Time m_t_end;
    long long m_durationInMinutes;
    string m_bescreibung;
};

#endif //TERMIN_H_
