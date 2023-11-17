#include <iostream>

using namespace std;

class Date {
private:
	int years = 0;
	int mounth = 0;
	int days = 0;
	int minDays = CountDays(1970, 1, 1);
	int maxDays = CountDays(2099, 12, 31);

	void Normalize() {
		int temp_days = CountDays(years, mounth, days);
		if (temp_days <= minDays or temp_days > maxDays) {
			years = 1970;
			mounth = 1;
			days = 1;
			return;
		}
		years = 0;
		mounth = 0;
		days = 0;
		while (temp_days > 366) {
			if ((years % 4 == 0 or years % 400 == 0) and years % 100 != 0) {
				temp_days -= 366;
			}
			else {
				temp_days -= 365;
			}
			years++;
		}
		while (temp_days > 0) {
			if (mounth == 0 or mounth == 2 or mounth == 4 or mounth == 6 or mounth == 7 or mounth == 9 or mounth == 11) {
				temp_days -= 31;
			}
			else if (mounth == 1) {
				if (((years + 1) % 4 == 0 or (years + 1) % 400 == 0) and (years + 1) % 100 != 0){
					temp_days -= 29;
				}
				else {
					temp_days -= 28;
				}
			}
			else {
				temp_days -= 30;
			}
			mounth++;
		}
		if (temp_days < 0) {
			if (mounth == 1 or mounth == 3 or mounth == 5 or mounth == 7 or mounth == 8 or mounth == 10 or mounth == 12) {
				days = 31;
			}
			else if (mounth == 2) {
				days = 28 + (int)(((years + 1) % 4 == 0 or (years + 1) % 400 == 0) and (years + 1) % 100 != 0);
			}
			else {
				days = 30;
			}
			mounth--;
		}
		return;
	}

public:
	Date() = default;

	Date(int ys, int mh, int ds) {
		years = ys;
		mounth = mh;
		days = ds;
		Normalize();
	}

	Date(int ds) : Date(0, 0, ds) {
	}

	int GetYears() const;
	int GetMounth() const;
	int GetDays() const;

	int CountDays(int y, int m, int d) {
		int temp_year = y, temp_month = m, new_days = 0;

		while (temp_year > 0) {
			if ((temp_year % 4 == 0 or temp_year % 400 == 0) and temp_year % 100 != 0) {
				new_days += 366;
			}
			else {
				new_days += 365;
			}
			temp_year--;
		}
		while (temp_month > 0) {
			if (temp_month == 1 or temp_month == 3 or temp_month == 5 or temp_month == 7 or temp_month == 8 or temp_month == 10 or temp_month == 12) {
				new_days += 31;
			} else if (temp_month == 0) {
				break;
			} else if (temp_month == 2) {
				if (((y + 1) % 4 == 0 or (y + 1) % 400 == 0) and (y + 1) % 100 != 0) {
					new_days += 29;
				}
				else {
					new_days += 28;
				}
			}
			else {
				new_days += 30;
			}
			temp_month--;
		}
		return new_days + d;
	}
	Date& operator += (int ds) {
		// need to repair
		Normalize();
		return *this;
	}

	Date operator + (int ds) const {
		return Date(years, mounth, ds + days);
	}
};


int Date::GetYears() const {
	return years;
}

int Date::GetMounth() const {
	return mounth;
}

int Date::GetDays() const {
	return days;
}

int operator - (const Date& t1, const Date& t2) {
	Date t1_r = Date(t1.GetYears(), t1.GetMounth(), t1.GetDays());
	Date t2_r = Date(t2.GetYears(), t2.GetMounth(), t2.GetDays());
	int temp_days = t1_r.CountDays(t1.GetYears(), t1.GetMounth(), t1.GetDays()) - t2_r.CountDays(t2.GetYears(), t2.GetMounth(), t2.GetDays());
	return temp_days;
}


//==============================================================================
int main() {
	Date d(1970, 1, 1);
	d += 1;
	cout << d.GetDays() << " " << d.GetMounth() << " " << d.GetYears() << endl;
}