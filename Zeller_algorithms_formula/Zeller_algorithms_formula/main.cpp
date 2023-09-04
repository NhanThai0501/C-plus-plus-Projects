#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "\n\n" << setw(5) << "" << "Zeller's algorithms formula by Nhan Thai\n\n";
	cout << setw(5) << "" << "==================================\n\n";

	// Declare the variables
	int year, month, date, dayofWeek, k, j, a;
	int monthFormula = 0;
	string monthName, dayName, suffix, sign, element;

	// Input the year
	cout << setw(5) << "" << "Enter the year (0 to 2020): ";
	cin >> year;
	cin.clear();
	cin.ignore(999, '\n');

	// Set up the input validation for year
	if (year < 0 || year > 2020)
	{
		cout << setw(5) << "" << "INVALID INPUT FOR YEAR. TRY AGAIN\n";
		return EXIT_FAILURE;
	}

	cout << setw(5) << "" << "Enther the month (1 to 12): ";
	cin >> month;
	cin.clear();
	cin.ignore(999, '\n');

	// Set up the input validation for month
	if (month < 0 || month > 12)
	{
		cout << setw(5) << "" << "INVALID INPUT FOR MONTH. TRY AGAIN\n";
		return EXIT_FAILURE;
	}

	cout << setw(5) << "" << "Enter the date (1 to 31): ";
	cin >> date;
	cin.clear();
	cin.ignore(999, '\n');

	// Set up the input validation for date
	if (date < 0 || date > 31)
	{
		cout << setw(5) << "" << "INVALID INPUT FOR DATE. TRY AGAIN\n";
		return EXIT_FAILURE;
	}

	// Set up the condition for months have 31 days or 30 days and special case for February.
	else if (month == 2)
	{
		if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
		{
			date <= 29;
			if (date > 29)
			{
				cout << setw(5) << "" << "INVALID DATE FOR FEBRUARY. TRY AGAIN\n";
				return EXIT_FAILURE;
			}
		}
		else
		{
			date <= 28;
			if (date > 28)
			{
				cout << setw(5) << "" << "INVALID DATE FOR FEBRUARY. TRY AGAIN\n";
				return EXIT_FAILURE;
			}

		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		date <= 31;
		if (date > 31)
		{
			cout << setw(5) << "" << "INVALID DATE FOR MONTHS HAVE 31 DAYS. TRY AGAIN\n";
			return EXIT_FAILURE;
		}

	}
	else
	{
		date <= 30;

		if (date > 30)
		{
			cout << setw(5) << "" << "INVALID DATE FOR MONTHS HAVE 30 DAYS. TRY AGAIN\n";
			return EXIT_FAILURE;
		}

	}

	// Set up the Zeller's algorithm formula

	switch (month)
	{
	case 1: // January
		monthName = "January";
		monthFormula = 13;
		year--;
		break;
	case 2: // February
		monthName = "February";
		monthFormula = 14;
		year--;
		break;
	case 3: // March
		monthName = "March";
		monthFormula = 3;
		break;
	case 4: // April
		monthName = "April";
		monthFormula = 4;
		break;
	case 5: // May
		monthName = "May";
		monthFormula = 5;
		break;
	case 6: // June
		monthName = "June";
		monthFormula = 6;
		break;
	case 7: // July
		monthName = "July";
		monthFormula = 7;
		break;
	case 8: // August
		monthName = "August";
		monthFormula = 8;
		break;
	case 9: // September
		monthName = "September";
		monthFormula = 9;
		break;
	case 10: // October
		monthName = "October";
		monthFormula = 10;
		break;
	case 11: // November
		monthName = "November";
		monthFormula = 11;
		break;
	case 12: // December
		monthName = "December";
		monthFormula = 12;
		break;
	default:
		break;
	}

	j = (year / 100); // j is the century

	k = year % 100; // k is the year of the century

	a = date + 2.6 * (monthFormula + 1) + k + k / 4 + j / 4 + 5 * j; // a is the combination of the Zeller's algorithm

	dayofWeek = a % 7;

	// Display the day in a week
	switch (dayofWeek)
	{
	case 0:
		dayName = "Saturday";
		break;
	case 1:
		dayName = "Sunday";
		break;
	case 2:
		dayName = "Monday";
		break;
	case 3:
		dayName = "Tuesday";
		break;
	case 4:
		dayName = "Wednesday";
		break;
	case 5:
		dayName = "Thursday";
		break;
	case 6:
		dayName = "Friday";
		break;
	default:
		cout << "INVALID DAY OF WEEK. TRY AGAIN\n";
	}

	// Display the long date by adding suffix to the given date
	if (date == 1 || date == 31 || date == 21)
		suffix = "st";
	else if (date == 2 || date == 22)
		suffix = "nd";
	else if (date == 3 || date == 23)
		suffix = "rd";
	else
		suffix = "th";

	if (monthFormula == 13 || monthFormula == 14)
	{
		year++;
		cout << setw(5) << "" << dayName << ", " << monthName << " " << date << suffix << ", " << year << "\n\n";
	}
	else
		cout << setw(5) << "" << dayName << ", " << monthName << " " << date << suffix << ", " << year << "\n\n";
	// Date and Signs
	if (month == 3 && date >= 21 && date <= 31)
	{
		sign = "Aries";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "The presence of Aries always marks the beginning of something energetic and turbulent. They are continuously looking for dynamic, speed and competition, always being the first in everything - from work to social gatherings.\n\n";
	}
	else if (month == 4 && date >= 1 && date <= 19)
	{
		sign = "Aries";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "The presence of Aries always marks the beginning of something energetic and turbulent. They are continuously looking for dynamic, speed and competition, always being the first in everything - from work to social gatherings.\n\n";
	}
	else if (month == 4 && date >= 20 && date <= 30)
	{
		sign = "Taurus";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Practical and well-grounded, Taurus is the sign that harvests the fruits of labor. They feel the need to always be surrounded by love and beauty, turned to the material world, hedonism, and physical pleasures.\n\n";
	}
	else if (month == 5 && date >= 1 && date <= 20)
	{
		sign = "Taurus";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Practical and well-grounded, Taurus is the sign that harvests the fruits of labor. They feel the need to always be surrounded by love and beauty, turned to the material world, hedonism, and physical pleasures.\n\n";
	}
	else if (month == 5 && date >= 21 && date <= 31)
	{
		sign = "Gemini";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Expressive and quick-witted, Gemini represents two different personalities in one and you will never be sure which one you will face. They are sociable, communicative and ready for fun, with a tendency to suddenly get serious, thoughtful and restless.\n\n";
	}
	else if (month == 6 && date >= 1 && date <= 21)
	{
		sign = "Gemini";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Expressive and quick-witted, Gemini represents two different personalities in one and you will never be sure which one you will face. They are sociable, communicative and ready for fun, with a tendency to suddenly get serious, thoughtful and restless.\n\n";
	}
	else if (month == 6 && date >= 22 && date <= 30)
	{
		sign = "Cancer";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Deeply intuitive and sentimental, Cancer can be one of the most challenging zodiac signs to get to know. They are very emotional and sensitive, and care deeply about matters of the family and their home.\n\n";
	}
	else if (month == 7 && date >= 1 && date <= 21)
	{
		sign = "Cancer";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Deeply intuitive and sentimental, Cancer can be one of the most challenging zodiac signs to get to know. They are very emotional and sensitive, and care deeply about matters of the family and their home.\n\n";
	}
	else if (month == 7 && date >= 22 && date <= 31)
	{
		sign = "Leo";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "People born under the sign of Leo are natural born leaders. They are dramatic, creative, self-confident, dominant and extremely difficult to resist, able to achieve anything they want to in any area of life they commit to.\n\n";
	}
	else if (month == 8 && date >= 1 && date <= 22)
	{
		sign = "Leo";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "People born under the sign of Leo are natural born leaders. They are dramatic, creative, self-confident, dominant and extremely difficult to resist, able to achieve anything they want to in any area of life they commit to.\n\n";
	}
	else if (month == 8 && date >= 23 && date <= 31)
	{
		sign = "Virgo";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Virgos are always paying attention to the smallest details and their deep sense of humanity makes them one of the most careful signs of the zodiac.\n\n";
	}
	else if (month == 9 && date >= 1 && date <= 22)
	{
		sign = "Virgo";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Virgos are always paying attention to the smallest details and their deep sense of humanity makes them one of the most careful signs of the zodiac.\n\n";
	}
	else if (month == 9 && date >= 23 && date <= 30)
	{
		sign = "Libra";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "People born under the sign of Libra are peaceful, fair, and they hate being alone. Partnership is very important for them, as their mirror and someone giving them the ability to be the mirror themselves.\n\n";
	}
	else if (month == 10 && date >= 1 && date <= 22)
	{
		sign = "Libra";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "People born under the sign of Libra are peaceful, fair, and they hate being alone. Partnership is very important for them, as their mirror and someone giving them the ability to be the mirror themselves.\n\n";
	}
	else if (month == 10 && date >= 23 && date <= 31)
	{
		sign = "Scorpio";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Scorpio-born are passionate and assertive people. They are determined and decisive, and will research until they find out the truth. Scorpio is a great leader, always aware of the situation and also features prominently in resourcefulness.\n\n";
	}
	else if (month == 11 && date >= 1 && date <= 21)
	{
		sign = "Scorpio";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Scorpio-born are passionate and assertive people. They are determined and decisive, and will research until they find out the truth. Scorpio is a great leader, always aware of the situation and also features prominently in resourcefulness.\n\n";
	}
	else if (month == 11 && date >= 22 && date <= 30)
	{
		sign = "Sagittarius";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Curious and energetic, Sagittarius is one of the biggest travelers among all zodiac signs. Their open mind and philosophical view motivates them to wander around the world in search of the meaning of life.\n\n";
	}
	else if (month == 12 && date >= 1 && date <= 21)
	{
		sign = "Sagittarius";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Curious and energetic, Sagittarius is one of the biggest travelers among all zodiac signs. Their open mind and philosophical view motivates them to wander around the world in search of the meaning of life.\n\n";
	}
	else if (month == 12 && date >= 22 && date <= 31)
	{
		sign = "Capricorn";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Capricorn is a sign that represents time and responsibility, and its representatives are traditional and often very serious by nature. These individuals possess an inner state of independence that enables significant progress both in their personal and professional lives.\n\n";
	}
	else if (month == 1 && date >= 1 && date <= 19)
	{
		sign = "Capricorn";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Capricorn is a sign that represents time and responsibility, and its representatives are traditional and often very serious by nature. These individuals possess an inner state of independence that enables significant progress both in their personal and professional lives.\n\n";

	}
	else if (month == 1 && date >= 20 && date <= 31)
	{
		sign = "Aquarius";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Aquarius-born are shy and quiet , but on the other hand they can be eccentric and energetic. However, in both cases, they are deep thinkers and highly intellectual people who love helping others.\n\n";
	}
	else if (month == 2 && date >= 1 && date <= 20)
	{
		sign = "Aquarius";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Aquarius-born are shy and quiet , but on the other hand they can be eccentric and energetic. However, in both cases, they are deep thinkers and highly intellectual people who love helping others.\n\n";
	}
	else if (month == 2 && date >= 21 && date <= 29)
	{
		sign = "Pisces";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Pisces are very friendly, so they often find themselves in a company of very different people. Pisces are selfless, they are always willing to help others, without hoping to get anything back.\n\n";
	}
	else
	{
		sign = "Pisces";
		cout << setw(5) << "" << "Your sign is " << sign << ".\n\n";
		cout << setw(5) << "" << "Pisces are very friendly, so they often find themselves in a company of very different people. Pisces are selfless, they are always willing to help others, without hoping to get anything back.\n\n";
	}

	// Elements and Compatible Signs
	if (sign == "Aries" || sign == "Leo" || sign == "Sagittarius")
	{
		element = "FIRE";
		cout << setw(5) << "" << "Your element is " << element << ". The compatible signs for " << sign << " are Aries, Leo and Sagittarius.\n";
	}
	else if (sign == "Taurus" || sign == "Virgo" || sign == "Capricorn")
	{
		element = "EARTH";
		cout << setw(5) << "" << "Your element is " << element << ". The compatible signs for " << sign << " are Taurus, Virgo and Capricorn.\n";
	}
	else if (sign == "Gemini" || sign == "Libra" || sign == "Aquarius")
	{
		element = "AIR";
		cout << setw(5) << "" << "Your element is " << element << ". The compatible signs for " << sign << " are Gemini, Libra and Aquarius.\n";
	}
	else
	{
		element = "WATER";
		cout << setw(5) << "" << "Your element is " << element << ". The compatible signs for " << sign << " are Cancer, Scorpio and Pisces.\n";
	}

	return EXIT_SUCCESS;
}