#include<iostream>
#include<conio.h>
using namespace std;
//way to define a set of symbolic constants that can be used in place of integer values. This 
//can make your code more readable and maintainable, as it allows you to use meaningful names instead of integer values in your code.
//can use like a typename
enum color{RED, GREEN, BLUE};
color returnColor(color);
int main()
{
    color a=GREEN;
    cout<<returnColor(a);

    return 0;
}

color returnColor(color a)
{
    return (a==RED)?GREEN:BLUE;
}