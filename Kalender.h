#ifndef KALENDER_H_
#define KALENDER_H_

#include <set>
#include "Termin.h"

class Kalender {
public:
	void insert(Termin & termin);
private:
	set<Termin> m_content;
};

#endif //KALENDER_H_