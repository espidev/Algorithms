#include <bits/stdc++.h>

using namespace std;

/*
 * USACO
 * Friday the Thirteenth
 */

int daysOfWeek[7]; //track the amount of times the 13th lands on each day. Saturday is 
daysOfWeek[0]... Friday is daysOfWeek[6]
int N, dayOfWeek = 2, year = 1900, month;

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    fin >> N;

    for (; year < N+1900; year++) {
        for (month = 1; month <= 12; month++) {
            int numOfDays;
            if (month == 2) { // february
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                    numOfDays = 29;
                } else {
                    numOfDays = 28;
                }
            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                numOfDays = 30;
            } else {
                numOfDays = 31;
            }
            for (int i = 1; i <= numOfDays; i++) {
                if (i == 13) daysOfWeek[dayOfWeek]++;

                dayOfWeek = (dayOfWeek + 1) % 7;
            }
        }
    }

    for (int i = 0; i < 7; i++) fout << daysOfWeek[i] << ((i == 6) ? "" : " ");
    fout << endl;
    return 0;
}
