#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

#include <QSet>
#include <QMap>
#include <QString>

using namespace std;

class PhoneBook
{
private:
    QMap<QString, QSet<QString>> _allocator;

    bool validateName(const QString &);
    bool validateNumber(const QString &);

public:
    PhoneBook();
    PhoneBook(const QMap<QString, QSet<QString>> &);
    ~PhoneBook();

    bool addContact(const QString &, const QString &);
    bool addNumber(const QString &, const QString &);

    QMap<QString, QSet<QString>> findByName(const QString &);
    QMap<QString, QSet<QString>> findByNumber(const QString &);

    bool deleteContact(const QString &);
    bool deleteNumber(const QString &, const QString &);

    QString stringify();
};

ostream &operator<<(ostream &, PhoneBook &);

#endif // PHONEBOOK_H
