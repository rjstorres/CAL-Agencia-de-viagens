#include "Date.h"

//cria uma date do dia atual
Date::Date(){
	time_t t = time(0);   // get time now
	struct tm  now;
	localtime_s(&now,&t);

	year = (now.tm_year + 1900);
	month = (now.tm_mon + 1);
	day = now.tm_mday;
}

Date::Date(string dateStr){
	string tmp;
	size_t pos;
	pos = dateStr.find('/');
	
	if (pos == -1)
		throw exception_or_error("Data nao tem o formato DD/MM/YY");
		
	tmp = dateStr.substr(0, pos);
	day = stoi(tmp);
	dateStr.erase(0, pos + 1);
	pos = dateStr.find('/');
	
	if (pos == -1)
		throw exception_or_error("Data nao tem o formato DD/MM/YY");
	
	tmp = dateStr.substr(0, pos);
	month = stoi(tmp);
	dateStr.erase(0, pos + 1);
	year = stoi(dateStr);
	
	Date currentyear;

	if (month > 12 || day > maxmonthday(month)||year<1970)
		throw exception_or_error("Data nao tem o formato DD/MM/YY");
}

Date::Date(int day, int month)
{
	this->day = day;
	this->month = month;
	this->year = NULL;
}

int Date::getDay() const{
	return day;
}

int Date::getMonth() const{
	return month;
}

int Date::getYear() const{
	return year;
}

void Date::save(ofstream & out) const{
	out << day << '/' << month << '/' << year;
	return;
}

ostream& operator<<(ostream& out, const Date & date){
	out << date.day << '/' << date.month << '/' << date.year;
	return out;
}

bool operator<(const Date &date1, const Date &date2){
	if (date1.getYear() < date2.getYear())
		return true;
	else if (date1.getYear() > date2.getYear())
		return false;

	if (date1.getMonth() < date2.getMonth())
		return true;
	else if (date1.getMonth() > date2.getMonth())
		return false;

	return date1.getDay() < date2.getDay();
}

bool Date::operator==(const Date &date) const {
	return (day == date.getDay() && month == date.getMonth() && year == date.getYear());
}

bool Date::isLessDayMonth(const Date & date2) const
{
	if (month < date2.getMonth())
		return true;
	else if (month > date2.getMonth())
		return false;

	return day < date2.getDay();
}

int Date::getDayofTheWeek() const {
	int k, m, C, Y, W;

	Y = year % 100;

	if (month == 1 || month == 2) {
		m = month + 10;
		Y--;
	} else
		m = month - 2;

	C = year / 100;

	k = day;

	W = (k + (int) floor(2.6 * m - 0.2) - 2 * C + Y + Y / 4 + C / 4) % 7;

	return W;
}
