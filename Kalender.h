#ifndef KALENDER_H_
#define KALENDER_H_

#include <set>
#include <vector>
#include "Termin.h"

class Kalender {
public:
    void insert(const Termin &termin);

    void getList(std::vector<Termin> &);

private:
    set<Termin> m_dates;
};

#endif //KALENDER_H_