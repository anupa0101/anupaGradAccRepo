#include<iostream>
#include<string>
#include<regex>
//regular expressions are ways to match strings

int main(){
    std::string str1="anupa";
    std::regex reg1("anupa");// cant do reg1="anupa"
    std::regex reg1("anupa", std::regex_constants::icase);// will match without looking at the case
    std::regex reg1("abc."); //such as abce match any string that starts with abc followed by ONE any character like abce
    std::regex reg1("abc?");// only ab, abc. ? preceding charcter can be 0 or c
    std::regex reg1("abc*");// ab, abccc,abcccccc any number of precedding characters of *
    std::regex reg1("abc+");// same as * but cant be ab. needs atleast 1
    std::regex reg1("ab[cd]*");//preceding character can be c or d. ex: ab, abc, abd, abccddddcc
    std::regex reg1("ab[^cd]*");//preceding charcter can NOT be c or d. ex: ab, abq, abqw
    std::regex reg1("ab[cd]{3}");//must have exactly 3 charaters of either c or d or both ex: abddd, abcdc
    std::regex reg1("ab[cd]{3,}");//must have 3 or more charaters of either c or d or both ex: abddd,abdddddcc, abcdcccc
    std::regex reg1("ab[cd]{3,5}");//must have 3 or 4 or 5 charaters of either c or d or both ex: abddd,abddddc, abcdcc
    std::regex reg1("abc|ef[gh]");// or | symbol. similar to when available seperately 

 // #####ABOVE IS TRUE FOR regex_match only where the whole string is considered in matching, but regex_search will consider sub strings to match

 //email address matching- will be true when a valid .com email address is input
 std::regex regEmail("[[:w:]]+@[[:w:]]+\.com");//[[:w:]] is a word character class: can accept any digit, number or underscore
// we can also extract parts of the email address - watch  bo quians 2nd video for it

    //all these start with abc
    std::cout<<std::regex_match(str1,reg1);// will search the entire string
    std::cout<<std::regex_search(str1,reg1);// will search substrings too. 

//regex iteators are explained in the bo quians 3rd video

    return 0;
}