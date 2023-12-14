#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Contact {
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

public:
    Contact() : fullName(nullptr), homePhone(nullptr), workPhone(nullptr), mobilePhone(nullptr), additionalInfo(nullptr) {}

    Contact(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);

        homePhone = new char[strlen(home) + 1];
        strcpy(homePhone, home);

        workPhone = new char[strlen(work) + 1];
        strcpy(workPhone, work);

        mobilePhone = new char[strlen(mobile) + 1];
        strcpy(mobilePhone, mobile);

        additionalInfo = new char[strlen(info) + 1];
        strcpy(additionalInfo, info);
    }

    Contact(const Contact& other) {
        fullName = new char[strlen(other.fullName) + 1];
        strcpy(fullName, other.fullName);

        homePhone = new char[strlen(other.homePhone) + 1];
        strcpy(homePhone, other.homePhone);

        workPhone = new char[strlen(other.workPhone) + 1];
        strcpy(workPhone, other.workPhone);

        mobilePhone = new char[strlen(other.mobilePhone) + 1];
        strcpy(mobilePhone, other.mobilePhone);

        additionalInfo = new char[strlen(other.additionalInfo) + 1];
        strcpy(additionalInfo, other.additionalInfo);
    }

    ~Contact() {
        delete[] fullName;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] additionalInfo;
    }

    void setFullName(const char* name) {
        delete[] fullName;
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }

    void setHomePhone(const char* home) {
        delete[] homePhone;
        homePhone = new char[strlen(home) + 1];
        strcpy(homePhone, home);
    }

    void setWorkPhone(const char* work) {
        delete[] workPhone;
        workPhone = new char[strlen(work) + 1];
        strcpy(workPhone, work);
    }

    void setMobilePhone(const char* mobile) {
        delete[] mobilePhone;
        mobilePhone = new char[strlen(mobile) + 1];
        strcpy(mobilePhone, mobile);
    }

    void setAdditionalInfo(const char* info) {
        delete[] additionalInfo;
        additionalInfo = new char[strlen(info) + 1];
        strcpy(additionalInfo, info);
    }

    const char* getFullName() const { return fullName; }
    const char* getHomePhone() const { return homePhone; }
    const char* getWorkPhone() const { return workPhone; }
    const char* getMobilePhone() const { return mobilePhone; }
    const char* getAdditionalInfo() const { return additionalInfo; }
};

class PhoneBook {
private:
    Contact* contacts;
    size_t size;
    size_t capacity;

public:
    PhoneBook() : contacts(nullptr), size(0), capacity(0) {}

    ~PhoneBook() {
        clear();
    }

    void displayContacts() const {
        for (size_t i = 0; i < size; ++i) {
            cout << "Контакт " << i + 1 << ":" << endl;
            cout << "Имя: " << contacts[i].getFullName() << endl;
            cout << "Домашний телефон: " << contacts[i].getHomePhone() << endl;
            cout << "Рабочий телефон: " << contacts[i].getWorkPhone() << endl;
            cout << "Мобильный телефон: " << contacts[i].getMobilePhone() << endl;
            cout << "Дополнительная информация: " << contacts[i].getAdditionalInfo() << endl;
            cout << "---------------------" << endl;
        }
    }

    void addContact(const Contact& newContact) {
        if (size == capacity) {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            Contact* newContacts = new Contact[newCapacity];
            for (size_t i = 0; i < size; ++i) {
                newContacts[i] = contacts[i];
            }
            delete[] contacts;
            contacts = newContacts;
            capacity = newCapacity;
        }
        contacts[size++] = newContact;
    }
    void removeContact(size_t index) {
        if (index < size) {
            for (size_t i = index; i < size - 1; ++i) {
                contacts[i] = contacts[i + 1];
            }
            --size;
        }
        else {
            cout << "Некорректный индекс контакта." << endl;
        }
    }
    void clear() {
        delete[] contacts;
        contacts = nullptr;
        size = capacity = 0;
    }
};
int main()
{
    setlocale(LC_ALL, "RUS");
    PhoneBook phoneBook;

    Contact contact1("Иван Иванов", "123-456-7890", "987-654-3210", "555-123-4567", "Друг");
    phoneBook.addContact(contact1);

    Contact contact2("Петр Петров", "111-222-3333", "444-555-6666", "777-888-9999", "Коллега");
    phoneBook.addContact(contact2);

    cout << "Все контакты:" << endl;
    phoneBook.displayContacts();

    phoneBook.removeContact(0);

    cout << "Контакты после удаления:" << endl;
    phoneBook.displayContacts();
    return 0;
}