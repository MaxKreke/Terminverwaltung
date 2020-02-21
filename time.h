#ifndef TIME_H_
#define TIME_H_

#include <iostream>

unsigned short toDay(const unsigned short month, const unsigned short day);

class Time {
public:
	//Time();
	Time(const unsigned int year, const unsigned long month, const unsigned long long day, const unsigned long long hour, const unsigned long long minute);
	Time(const Time & other, unsigned long long timeShiftInMinutes);
	void correct();
	const unsigned long long toMin() const;
	const bool operator<(const Time & other) const;
	const bool operator<=(const Time & other) const;
	const bool operator==(const Time & other) const;
	const bool isValid() const;
	unsigned int m_year;
	unsigned long m_month;
	unsigned long long m_day;
	unsigned long long m_hour;
	unsigned long long m_minute;
};

#endif //TIME_H_
