#include <iostream>
#include <set>
#include "Termin.h"
#include "Kalender.h"
#include "time.h"

using namespace std;

int main() {
	cout << "Kalender App" << endl << endl;

	short state = -1;

	cout << "Wilkommen in der Kalender App, sie koennen:\nAlle Termine anzeigen Lassen:\t\t\t(1)\nTermin hinzufuegen:\t\t\t\t(2)\nZukuenftige Termine anzeigen lassen\t\t(3)\nVergangene Termine anzeigen lassen\t\t(4)\nTermine zu einem Datum anzeigen lassen\t\t(5)\nTermine in einem Zeitraum anzeigen lassen\t(6)\nKalender App beenden\t\t\t\t(0)" << endl;

    Kalender kal;

    kal.insert(Termin(Time(2020, 2, 12, 12, 12), Time(2020, 2, 12, 12, 12), "asdasd"));
    kal.insert(Termin(Time(2021, 2, 12, 12, 12), Time(2022, 2, 12, 12, 12), "asdasd"));
    kal.insert(Termin(Time(2021, 2, 12, 12, 12), Time(2023, 2, 12, 12, 12), "asdasd"));

	return 0;

}
