#include <iostream>

using namespace std;

class DayOfYear {
    public:
        void set(int month_new, int day_new);
        friend bool date_equal(DayOfYear date1, DayOfYear date2);
    private:
        int month;
        int day;
};



int main() {
    DayOfYear date_1, date_2;
    date_1.set(7, 4);
    date_2.set(7, 4);

    cout << date_equal(date_1, date_2);

    return 0;
}

bool date_equal(DayOfYear date1, DayOfYear date2) {
    return (date1.month == date2.month &&
            date1.day == date2.day);
}

void DayOfYear::set(int month_new, int day_new) {
    month = month_new;
    day = day_new;
}

