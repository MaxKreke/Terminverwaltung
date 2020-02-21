#include "Termin.h"

Termin::Termin(const Time start, const Time end, const string &beschreibung) : m_t_start(start), m_t_end(end), m_bescreibung(beschreibung) {
	m_durationInMinutes = int(start.toMin() - end.toMin());
}

bool Termin::operator<(Termin & other) {
    return m_t_start < other.m_t_start || (m_t_start == other.m_t_start && m_t_end < m_t_end);
}

Termin& Termin::operator=(const Termin & other) {
	m_t_start = other.m_t_start;
	m_t_end = other.m_t_end;
	m_durationInMinutes = other.m_durationInMinutes;
	return *this;
}

bool Termin::collidesWith(Termin & other) {
	if ((m_t_start <= other.m_t_start) && other.m_t_start < m_t_end) return true;
	else return (other.m_t_start <= m_t_start) && m_t_start < other.m_t_end;

}