#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

void add(PhoneBook& phone_book, std::istream& in);
void store(PhoneBook& phone_book, std::istream& in);
void insertBefore(PhoneBook& phone_book, std::istream& in);
void insertAfter(PhoneBook& phone_book, std::istream& in);
void del(PhoneBook& phone_book, std::istream& in);
void show(PhoneBook& phone_book, std::istream& in);
void move(PhoneBook& phone_book, std::istream& in);

#endif // USER_INTERFACE_HPP
