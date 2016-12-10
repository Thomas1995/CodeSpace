#pragma once

class Date {
  int day, month, year;

public:
  Date(int dd, int mm, int yyyy);

  int operator - (const Date& other);
  Date& operator += (int days);

private:
  int daysInMonth[13];
  int toDays() const;
};
