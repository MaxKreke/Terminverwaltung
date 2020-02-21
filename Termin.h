#ifndef TERMIN_H_
#define TERMIN_H_

#include <string>
#include "time.h"

using namespace std;

class Termin {
public:

	Termin(const Time start, const Time end, const string &beschreibung);
	Termin(Time start, long long duration, string beschreibung);
	bool operator<(const Termin &other) const;
	Termin &operator=(const Termin &other);
	bool collidesWith(Termin & other);
	friend ostream & operator<<(ostream &,const Termin &);
private:
    Time m_t_start;
    Time m_t_end;
    long long m_durationInMinutes;
    string m_bescreibung;
};
ostream & operator<<(ostream &,const Termin &);
#endif //TERMIN_H_
