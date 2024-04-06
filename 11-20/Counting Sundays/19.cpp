#include <iostream>

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main() {
    int dayOfWeek = 2; 
    int sundayCount = 0;

    for (int year = 1901; year <= 2000; ++year) {
        for (int month = 1; month <= 12; ++month) {
            if (dayOfWeek == 0) { 
                ++sundayCount;
            }

            switch (month) {
                case 4: case 6: case 9: case 11: 
                    dayOfWeek += 30;
                    break;
                case 2: 
                    dayOfWeek += isLeapYear(year) ? 29 : 28;
                    break;
                default: 
                    dayOfWeek += 31;
            }

            dayOfWeek %= 7; 
        }
    }

    std::cout << "Number of Sundays that fell on the first of the month during the 20th century: " << sundayCount << std::endl;

    return 0;
}
