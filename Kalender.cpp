#include "Kalender.h"
void Kalender::getList(std::vector<Termin> & dates) {
    for (auto it=m_dates.begin(); it!=m_dates.end(); ++it)
        dates.push_back(*it);

}

void Kalender::insert(const Termin &termin) {
   m_dates.insert(termin);
}
