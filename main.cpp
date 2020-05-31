#include "phoneBook.h"

#include <iostream>
#include <QCoreApplication>
#include <QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PhoneBook phoneBook;
    QTextStream in(stdin);

    phoneBook.addContact("Fitzpamtrick", "9864832485");
    phoneBook.addContact("Hoover", "9895522574");
    phoneBook.addNumber("Hoover", "9895346574");
    phoneBook.addContact("Roman", "9704492299");
    phoneBook.addContact("Dorthy", "8065712745");
    phoneBook.addContact("Tameka", "9005513850");
    phoneBook.addNumber("Tameka", "9000384650");
    phoneBook.addNumber("Tameka", "9065216753");
    phoneBook.addContact("Pamela", "9815603867");
    phoneBook.addContact("Osborne", "8114583381");
    phoneBook.addContact("Belinda", "9744063767");
    phoneBook.addContact("Eunice", "8065712745");
    phoneBook.addNumber("Eunice", "8032561834");
    phoneBook.addContact("Dona", "8984312429");

    cout << "\n+++++ Phone Book +++++\n";
    cout << phoneBook;

    cout << "\n+++++ Find by name \"Tameka\" +++++\n";
    PhoneBook filtered01(phoneBook.findByName("Tameka"));
    cout << filtered01;

    cout << "\n+++++ Find by name part \"am\" +++++\n";
    PhoneBook filtered02(phoneBook.findByName("am"));
    cout << filtered02;

    cout << "\n+++++ Find by number \"8032561834\" +++++\n";
    PhoneBook filtered03(phoneBook.findByNumber("8032561834"));
    cout << filtered03;

    cout << "\n+++++ Delete the contact named \"Osborne\" +++++\n";
    phoneBook.deleteContact("Osborne");
    cout << phoneBook;

    cout << "\n+++++ Delete the number \"8032561834\" of the contact \"Eunice\" +++++\n";
    phoneBook.deleteNumber("Eunice", "8032561834");
    cout << phoneBook;

    return a.exec();
}
