#include <iostream>
#include <set>
#include "Termin.h"
#include "Kalender.h"
#include "time.h"

using namespace std;

int main() {
    Kalender kal;

    kal.insert(Termin(Time(2020, 2, 12, 12, 12), Time(2020, 2, 12, 12, 12), "asdasd"));
    kal.insert(Termin(Time(2021, 2, 12, 12, 12), Time(2022, 2, 12, 12, 12), "asdasd"));
    kal.insert(Termin(Time(2021, 2, 12, 12, 12), Time(2023, 2, 12, 12, 12), "asdasd"));


    return 0;
}
