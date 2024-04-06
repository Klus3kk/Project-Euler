#include <iostream>
#include <map>
#include <string>
using namespace std;

string numberToWords1To19(int number) {
    string words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                      "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                      "seventeen", "eighteen", "nineteen"};
    return words[number];
}


string tensPlace(int number) {
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    return tens[number];
}

string numberToWords(int number) {
    if (number == 1000) {
        return "one thousand";
    } else if (number >= 100) {
        int remainder = number % 100;
        string part = numberToWords1To19(number / 100) + " hundred";
        if (remainder > 0) {
            return part + " and " + numberToWords(remainder);
        } else {
            return part;
        }
    } else if (number >= 20) {
        int remainder = number % 10;
        string part = tensPlace(number / 10);
        if (remainder > 0) {
            return part + "-" + numberToWords1To19(remainder);
        } else {
            return part;
        }
    } else {
        return numberToWords1To19(number);
    }
}

int countLetters(string s) {
    int count = 0;
    for (char c : s) {
        if (isalpha(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    int totalLetters = 0;
    for (int i = 1; i <= 1000; ++i) {
        totalLetters += countLetters(numberToWords(i));
    }
    cout << "Total letter count: " << totalLetters << endl;
    return 0;
}
