#ifndef TIME_H_
#define TIME_H_

#include <iostream>

unsigned short toDay(const unsigned short month, const unsigned short day);

class Time {
public:
	//Time();
	Time(const unsigned int year, const unsigned short month, const unsigned short day, const unsigned short hour, const unsigned short minute);
	Time(const Time & other, unsigned long long timeShiftInMinutes);
	const unsigned long long toMin() const;
	const bool operator<(const Time & other);
	const bool operator<=(const Time & other);
	const bool operator==(const Time & other);
	const bool isValid() const;
	unsigned int m_year;
	unsigned short m_month;
	unsigned short m_day;
	unsigned short m_hour;
	unsigned short m_minute;
};

#endif //TIME_H_
