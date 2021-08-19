# Aid Management Application (AMA)   
When disaster hits a populated area, the most critical task is to provide immediately affected people with what they need as quickly and as efficiently as possible.<br>
This project creates an application that manages the list of goods that need to be shipped to ae disaster area. The application tracks the quantity of items needed, tracks the quantity on hand, and stores the information in a file for future use. 
<br><br>
There are two categories for the types of goods that need to be shipped:<br>
> \- Non-Perishable goods, such as blankets and tents, which have no expiry date. We refer to goods in this category as Good objects.<br>
> \- Perishable goods, such as food and medicine, that have an expiry date. We refer to goods in this category as Perishable objects.<br>

<br>

## OVERVIEW OF THE CLASSES DEVELOPED
| # | CLASS NAME | DESCRIPTION         |
|---|------------|---------------------|
| 1 | Date       | A class that holds the expiry date of the perishable items.  |
| 2 | Error      | A class that tracks the error state of its client. Errors may occur during data entry and user interaction. |
| 3 | Good       | A class that manages a non-perishable good object |
| 4 | Parishable | A class that manages a perishable good object. This class inherits the structure of the “Good” class and manages a date |
| 5 | iGood      | An interface to the Good hierarchy. This interface exposes the features of the hierarchy available to the application. Any “iGood” class can:<br> \- Read itself from the console or write itself to the console<br> \- Save itself to a text file or load itself from a text file<br> \- Compare itself to a unique C-style string identifier<br> \- Determine if it is greater than another good in the collating sequence<br> \- Report the total cost of the items on hand<br> \- Describe itself<br> \- Update the quantity of the items on hand<br> \- Report its quantity of the items on hand<br> \- Report the quantity of items needed<br> \- Accept a number of items<br> <br> Using this class, the client application can:<br> \- Save its set of iGoods to a file and retrieve that set at a later time<br> \- Read individual item specifications from the keyboard and display them on the screen<br> \- Update information regarding the number of each good on hand<br> |
<br>
## The Client Application - ms5.cpp
The client application manages the iGoods and provides the user with options to:<br>
```    
• List the Goods
• Display details of a Good
• Add a Good
• Add items of a Good
• Update the items of a Good
• Delete a Good
• Sort the set of Goods
```
<br>

___

## Project Class Diagram 
![ms5_image](https://user-images.githubusercontent.com/5942022/129996360-3cd6cc14-1586-4e72-8627-ed82db3a955d.png)
<br><br>

### THE DATE MODULE
The ``Date`` class encapsulates a date that is readable by an ``std::istream`` object and printable by an ``std::ostream`` object using the following format: ``YYYY/MM/DD``, where ``YYYY`` refers to a four-digit value for the year, **MM** refers to a two-digit value for the month and **DD** refers to a two-digit value for the day in the month<br>
<br>
#### THE PRE-DEFINED CONSTANTS:
> •	``min_year`` with the value 2018. This represents the minimum acceptable year for a valid date.<br>
> •	``max_year`` with the value 2038. This represents the maximum acceptable year for a valid date.<br>
> •	``min_date`` with the value 751098. This represents the date 2018/12/30 (see formula below).<br><br>
#### CLASS MEMBERS:
> •	``Year``: a four digit integer between the limits defined above.<br>
> •	``Month``: an integer with the values between 1 and 12 inclusive.<br>
> •	``Day of the Month``: an integer with a value between and the maximum number of days in the month. Use the function int mdays(int year, int month) to find out how many days are in a given month for a given year. Note that February can have 28 or 29 days depending on the year.<br>
> •	``A comparator value`` for comparing the date stored in the current object with the date stored in another Date object. Your constructors set this comparator value and your public relational operators use it to compare dates. (If the value of date one is larger than the value of date two, then date one is more recent than date two; that is, date one is after date two)<br>

> •	``The error state`` which the client of this class can reference to determine if the object holds a valid date, and if not, which part of the date is in error. The possible error states are integer values defined as macros in the ``Date`` class header:

| ERROR      | ERROR NUMBER | DESCRIPTION |
|------------|--------------|------------------------------ |
| NO_ERROR   |       0      | -- No error - the date is valid |
| CIN_FAILED |       1      | -- istream failed on information entry - A class that tracks the error state of its client. Errors may occur during data entry and user interaction. |
| DAY_ERROR  |       2      | -- Day value is invalid |
| MON_ERROR  |       3      | -- Month value is invalid |
| YEAR_ERROR |       4      | -- Year value is invalid An interface to the Good hierarchy. This interface exposes the features of the hierarchy available to the application. Any “iGood” class can:<br> \- Read itself from the console or write itself to the console<br> \- Save itself to a text file or load itself from a text file<br> \- Compare itself to a unique C-style string identifier<br> \- Determine if it is greater than another good in the collating sequence<br> \- Report the total cost of the items on hand<br> \- Describe itself<br> \- Update the quantity of the items on hand<br> \- Report its quantity of the items on hand<br> \- Report the quantity of items needed<br> \- Accept a number of items<br> <br> Using this class, the client application can:<br> \- Save its set of iGoods to a file and retrieve that set at a later time<br> \- Read individual item specifications from the keyboard and display them on the screen<br> \- Update information regarding the number of each good on hand<br> |
| PAST_ERROR |       5      | -- Date value is invalid |

<br>

#### **Private Functions to the class**
> •	``void errCode(int errorCode)``: This function sets the error state variable to one of the values listed above.<br>
> •	``int mdays(int year, int month) const``: This function returns the number of days in a given month for a given year.

#### **Constructors**
•	``No argument (default) constructor``:  initializes the object to a safe empty state and sets the error state to NO_ERROR.<br>
•	``Three-argument constructor``: accepts in its parameters integer values for the year, month and day in that order. This constructor checks if each number is in range, in the order of year, month and day and value. If any of the numbers are not within range, this function sets the error state to the appropriate error code and stops further validation. The month value can be between 1 and 12 inclusive). If all of the data received is valid, this constructor stores the values received in the current object, calculates the comparator value, and sets the error state to NO_ERROR.<br>
If any of the data received is not valid, this constructor initializes the object to a safe empty state and sets the comparator value to 0.<br>
The following formula is to set the comparator value for a valid date:<br>
```
year * 372 + month * 31 + day
```
For the date received to be valid its comparator value must be greater than or equal to min_date and all other conditions must be met.<br>
<br>
#### **Relational Operators**
```cpp
bool operator==(const Date& rhs) const;
bool operator!=(const Date& rhs) const;
bool operator<(const Date& rhs) const;
bool operator>(const Date& rhs) const;
bool operator<=(const Date& rhs) const;
bool operator>=(const Date& rhs) const;
```
These comparison operators return the result of comparing the current object as the left-hand side operand with another Date object as the right-hand side operand if the two objects are not empty.<br>
If one or both of the objects is empty, these operators return false.<br>
**For example:** ``operator<`` returns true if the date stored in the current object is before the date stored in ``rhs``; otherwise, this operator returns false. <br>
#### **QUERIES AND MODIFIERS**
```cpp
•	int errCode() const:
//This query returns the error state as an error code value.

•	bool bad() const: 
//This query returns true if the error state is not NO_ERROR.  

•	std::istream& read(std::istream& istr);
// This function reads the date from the console in the following format: YYYY?MM?DD (e.g. 2016/03/24 or 2016-03-24). 
// This function does not prompt the user. 
// If istr fails at any point (if istr fails, the function istr.fail() returns true), this function sets the error state to CIN_FAILED and does NOT clear istr. 
// If your read() function reads the numbers successfully, and the read values are valid, it stores them into the current object’s instance variables. Otherwise, your function does not change the current object. 
// Regardless of the result of the input process, your function returns a reference to the std::istream object.

•	std::ostream& write(std::ostream& ostr) const;
// This query writes the date to the first parameter in the following format: YYYY/MM/DD, and then returns a reference to the std::ostream object.

```

#### **FREE HELPER FUNCTIONS**
```cpp
•	operator<< // Prints the date to the first parameter (use Date::write()).

•	operator>> // Reads the date from the first parameter (use Date::read()).
```
