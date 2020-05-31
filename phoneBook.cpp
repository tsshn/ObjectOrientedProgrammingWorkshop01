#import "phoneBook.h"

using namespace std;

PhoneBook::PhoneBook() : _allocator(QMap<QString, QSet<QString>>())
{
}

PhoneBook::PhoneBook(const QMap<QString, QSet<QString>> &qMap) : _allocator(qMap)
{
}

PhoneBook::~PhoneBook() {}

bool PhoneBook::addContact(const QString &name, const QString &number)
{
    if (_allocator.contains(name))
    {
        addNumber(name, number);
        return true;
    }
    QSet<QString> temporary;
    if (validateName(name) && validateNumber(number))
    {
        temporary.insert(number);
        _allocator.insert(name, temporary);
        return true;
    }
    return false;
}

bool PhoneBook::addNumber(const QString &name, const QString &number)
{
    QSet<QString> *temporary = &_allocator.find(name).value();
    if (!temporary->isEmpty() || validateNumber(number))
    {
        temporary->insert(number);
        return true;
    }
    return false;
}

QMap<QString, QSet<QString>> PhoneBook::findByName(const QString &name)
{
    QMap<QString, QSet<QString>> *temporary = new QMap<QString, QSet<QString>>;
    QMap<QString, QSet<QString>>::iterator i;
    for (i = _allocator.begin(); i != _allocator.end(); ++i)
        if (i.key().toLower().contains(name.toLower()))
            temporary->insert(i.key(), _allocator.find(i.key()).value());
    return *temporary;
}

QMap<QString, QSet<QString>> PhoneBook::findByNumber(const QString &number)
{
    QMap<QString, QSet<QString>> *temporary = new QMap<QString, QSet<QString>>;
    QMap<QString, QSet<QString>>::iterator i;
    for (i = _allocator.begin(); i != _allocator.end(); ++i)
    {
        QSet<QString> *set = &i.value();
        foreach (QString str, *set)
            if (str.contains(number))
            {
                temporary->insert(i.key(), _allocator.find(i.key()).value());
                break;
            }
    }
    return *temporary;
}

bool PhoneBook::deleteContact(const QString &name)
{
    if (_allocator.remove(name) == 0)
        return false;
    return true;
}

bool PhoneBook::deleteNumber(const QString &name, const QString &number)
{
    if (_allocator.find(name).value().remove(number) == 0)
        return false;
    return true;
}

QString PhoneBook::stringify()
{
    QString response;
    response.append("\n==========\n");
    QMap<QString, QSet<QString>>::iterator i;
    for (i = _allocator.begin(); i != _allocator.end(); ++i)
    {
        response.append(i.key() + "\n");
        QSet<QString> *set = &i.value();
        foreach (QString str, *set)
            response.append(str + "\n");
        response.append("==========\n");
    }
    return response;
}

bool PhoneBook::validateNumber(const QString &number)
{
    if (!number.isNull() && number.length() == 10)
        return true;
    return false;
}

bool PhoneBook::validateName(const QString &name)
{
    if (name.isSimpleText())
        return true;
    return false;
}

ostream &operator<<(ostream &os, PhoneBook &phoneBook)
{
    return os << phoneBook.stringify().toStdString();
}
