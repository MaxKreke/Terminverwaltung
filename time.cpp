#include "time.h"

using namespace std;

Time::Time(const unsigned int year, const unsigned short month, const unsigned short day, const unsigned short hour, const unsigned short minute) {
	m_year = year-1;
	m_month = month-1;
	m_day = day-1;
	m_hour = hour-1;
	m_minute = minute-1;
}

const unsigned long long Time::toMin() const {
	return ((m_year * 356 + toDay(m_month, m_day)) * 24 + m_hour) * 60 + m_minute;
}

const bool Time::operator<(const Time & other) {
	if (m_year < other.m_year) return true;
	else if (m_year > other.m_year) return false;
	else if (m_month < other.m_month) return true;
	else if (m_month > other.m_month) return false;
	else if (m_day < other.m_day) return true;
	else if (m_day > other.m_day) return false;
	else if (m_hour < other.m_hour) return true;
	else if (m_hour > other.m_hour) return false;
	else if (m_minute < other.m_minute) return true;
	else if (m_minute > other.m_minute) return false;
	else return false;
}

const bool Time::operator==(const Time & other) {
	if (m_year == other.m_year && m_month == other.m_month && m_day == other.m_day && m_hour == other.m_hour && m_minute == other.m_minute) return true;
	else return false;
}

const bool Time::operator<=(const Time & other) {
	return ((*this < other)||(*this == other));
}

const bool Time::isValid() const {
	if (m_hour < 24 && m_minute < 60) {
		switch (m_month) {
		case 0:
			if (m_day < 31) return true;
		case 1:
			if (m_day < 28) return true;
		case 2:
			if (m_day < 31) return true;
		case 3:
			if (m_day < 30) return true;
		case 4:
			if (m_day < 31) return true;
		case 5:
			if (m_day < 30) return true;
		case 6:
			if (m_day < 31) return true;
		case 7:
			if (m_day < 31) return true;
		case 8:
			if (m_day < 30) return true;
		case 9:
			if (m_day < 31) return true;
		case 10:
			if (m_day < 30) return true;
		case 11:
			if (m_day < 31) return true;
		default: return false;
		}

		return true;
	}
	else return false;
}

unsigned short toDay(const unsigned short month, const unsigned short day) {
	//januar = 31		31
	//februar = 28		59
	//märz = 31			90
	//april = 30		120
	//mai = 31			151
	//juni = 30			181
	//juli = 31			212
	//august = 31		243
	//september = 30	273
	//oktober = 31		304
	//november = 30		334

	switch (month) {
	case 0:	return day;
	case 1: return day + 31;
	case 2: return day + 59;
	case 3: return day + 90;
	case 4: return day + 120;
	case 5: return day + 151;
	case 6: return day + 181;
	case 7: return day + 212;
	case 8: return day + 243;
	case 9: return day + 273;
	case 10: return day + 304;
	case 11: return day + 334;
	default:
		cout << "You are off the goop on this one chief ngl" << endl;
		return 0;
	}

}