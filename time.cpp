#include "time.h"

using namespace std;

Time::Time(const unsigned int year, const unsigned long month, const unsigned long long day, const unsigned long long hour, const unsigned long long minute) {
	m_year = year-1;
	m_month = month-1;
	m_day = day-1;
	m_hour = hour-1;
	m_minute = minute-1;
}

Time::Time(const Time & other, unsigned long long timeShiftInMinutes) {
	*this = other;
	m_minute += timeShiftInMinutes%60;
	if (m_minute >= 60) {
		m_hour+= m_minute / 60;
		m_minute %= 60;
		if (m_hour >= 24) {
			m_day += m_hour / 24;
			m_hour %= 24;
			if (m_day >= 356) {
				m_year += m_day / 356;
				m_day %= 356;
				if (!isValid()) {
					correct();
				}
			}
		}
	}
}

void Time::correct() {
	const int jan = 31, feb = 28, march = 31, april = 30, may = 31, june = 30, july = 31, aug = 31, sep = 30, oct = 31, nov = 30, dec = 31;
	bool tooHigh = true;
	while (tooHigh)
	{
		switch (m_month) {
		case 0:
			if (m_day < jan) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= jan;
				m_month++;
			}
		case 1:
			if (m_day < feb) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= feb;
				m_month++;
			}
		case 2:
			if (m_day < march) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= march;
				m_month++;
			}
		case 3:
			if (m_day < april) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= april;
				m_month++;
			}
		case 4:
			if (m_day < may) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= may;
				m_month++;
			}
		case 5:
			if (m_day < june) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= june;
				m_month++;
			}
		case 6:
			if (m_day < july) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= july;
				m_month++;
			}
		case 7:
			if (m_day < aug) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= aug;
				m_month++;
			}
		case 8:
			if (m_day < sep) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= sep;
				m_month++;
			}
		case 9:
			if (m_day < oct) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= oct;
				m_month++;
			}
		case 10:
			if (m_day < nov)
			{
				tooHigh = false;
				break;
			}
			else {
				m_day -= nov;
				m_month++;
			}
		case 11:
			if (m_day < dec) {
				tooHigh = false;
				break;
			}
			else {
				m_day -= dec;
				m_month++;
			}
		case 12:
			m_year++;
			m_month = 0;
			break;
		default:
			cout << "You are off the goop on this one chief ngl" << endl;
			break;
		}
	}
}

const unsigned long long Time::toMin() const {
	return ((m_year * 356 + toDay(m_month, m_day)) * 24 + m_hour) * 60 + m_minute;
}

const bool Time::operator<(const Time & other) const {
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

const bool Time::operator==(const Time & other) const {
	if (m_year == other.m_year && m_month == other.m_month && m_day == other.m_day && m_hour == other.m_hour && m_minute == other.m_minute) return true;
	else return false;
}

const bool Time::operator<=(const Time & other) const {
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