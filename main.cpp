#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct User {
    int id;
    string login, password;
};
struct Contact {
    int id, userId; //1 zmiana
    string name, surname, phoneNum, email, adress;
};
string readLine() {
    string line = "";
    cin.sync();
    getline(cin,line);
    return line;
}
char checkChoice() {
    string input = "";
    char sign = {0};

    while(true) {
        cin.sync();
        getline(cin,input);
        if(input.length() == 1) {
            sign = input[0];
            break;
        } else {
            cout << "Enter correct number !" << endl;
        }
    }
    return sign;
}
void loadNotepadUsers(vector <User> &users) {
    User user;
    fstream file;
    string dataInLine = "";

    file.open("Uzytkownicy.txt", ios::app);
    file.close();

    file.open("Uzytkownicy.txt", ios::in);
    if(file.good()) {
        while(getline(file, dataInLine)) {
            string individalPersonalData = "";
            int singlePersonNumber = 1;
            for(unsigned int i = 0; i < dataInLine.length(); i++) {
                if(dataInLine[i] != '|') {
                    individalPersonalData += dataInLine[i];
                } else {
                    switch(singlePersonNumber) {
                    case 1:
                        user.id = stoi(individalPersonalData);
                        break;
                    case 2:
                        user.login = individalPersonalData;
                        break;
                    case 3:
                        user.password = individalPersonalData;
                        break;
                    }
                    individalPersonalData = "";
                    singlePersonNumber++;
                }
            }
            users.push_back(user);
        }
    }
    file.close();
}
void loadNotepadPeople(vector <Contact> &people, int idLoggedUser) {
    Contact person;

    fstream file;
    string dataInLine = "";

    file.open("Uzytkownicy.txt", ios::app);
    file.close();

    file.open("KsiazkaAdresowa.txt", ios::in);

    if(file.good()) {
        while(getline(file, dataInLine)) {
            string individalPersonalData = "";
            int singlePersonNumber = 1;
            for(unsigned int i = 0; i < dataInLine.length(); i++) {
                if(dataInLine[i] != '|') {
                    individalPersonalData += dataInLine[i];
                } else {
                    switch(singlePersonNumber) {
                    case 1:
                        person.id = stoi(individalPersonalData);
                        break;
                    case 2:
                        person.userId = stoi(individalPersonalData);
                        break;
                    case 3:
                        person.name = individalPersonalData;
                        break;
                    case 4:
                        person.surname = individalPersonalData;
                        break;
                    case 5:
                        person.phoneNum = individalPersonalData;
                        break;
                    case 6:
                        person.email = individalPersonalData;
                        break;
                    case 7:
                        person.adress = individalPersonalData;
                        break;
                    }
                    individalPersonalData = "";
                    singlePersonNumber++;
                }
            }
            if(person.userId == idLoggedUser) {
                people.push_back(person);
            } else {
                continue;
            }
        }
    }
    file.close();
}
int loadNotepadPeopleALL(vector <Contact> &peopleALL) {

    peopleALL.clear();
    Contact person;
    User user;

    fstream file;
    string dataInLine = "";

    file.open("KsiazkaAdresowa.txt", ios::in);

    if(file.good()) {
        while(getline(file, dataInLine)) {
            string individalPersonalData = "";
            int singlePersonNumber = 1;
            for(unsigned int i = 0; i < dataInLine.length(); i++) {
                if(dataInLine[i] != '|') {
                    individalPersonalData += dataInLine[i];
                } else {
                    switch(singlePersonNumber) {
                    case 1:
                        person.id = stoi(individalPersonalData);
                        break;
                    case 2:
                        person.userId = stoi(individalPersonalData);
                        break;
                    case 3:
                        person.name = individalPersonalData;
                        break;
                    case 4:
                        person.surname = individalPersonalData;
                        break;
                    case 5:
                        person.phoneNum = individalPersonalData;
                        break;
                    case 6:
                        person.email = individalPersonalData;
                        break;
                    case 7:
                        person.adress = individalPersonalData;
                        break;
                    }
                    individalPersonalData = "";
                    singlePersonNumber++;
                }
            }
            peopleALL.push_back(person);
        }
    }
    file.close();
    return person.id;
}
void searchByName(vector <Contact> &people) {

    Contact person;
    string searchingName = "";
    unsigned int i = 0;
    int nameNumber = 0;

    if(people.size() == 0) {
        cout << endl << "Error! Adress book is empty" << endl;
        Sleep(1500);
    } else if(people.size() != 0) {
        system("cls");
        cout << "-------- SEARCHING BY NAME -------" << endl;
        cout << "==================================" << endl;
        cout << "Enter a name to show people: " << endl;
        searchingName = readLine();
        while(i < people.size()) {
            if(people[i].name == searchingName) {
                cout << "ID number" << "\t" << people[i].id << endl;
                cout << "Name: " << "\t" << "\t" << people[i].name << endl;
                cout << "Surname: " << "\t" << people[i].surname << endl;
                cout << "Phone number: " << "\t" << people[i].phoneNum << endl;
                cout << "Email: " << "\t" << "\t" << people[i].email << endl;
                cout << "Adress: " << "\t" << people[i].adress << endl;
                cout << "- - - - - - - - - - - - - - - - " << endl;
                nameNumber++;
            }i++;
        }if(nameNumber == 0) {
            cout << endl << "None person with that name" << endl;
        }system("pause");
    }
}
void searchBySurname(vector <Contact> &people) {

    Contact person;
    string searchingSurname = "";
    unsigned int i = 0;
    int surnameNumber = 0;

    if(people.size() == 0) {
        cout << endl << "Error! Adress book is empty" << endl;
        Sleep(1500);
    } else if(people.size() != 0) {
        system("cls");
        cout << "------ SEARCHING BY SURNAME ------" << endl;
        cout << "==================================" << endl;
        cout << "Enter a surname to show people: " << endl;
        searchingSurname = readLine();

        while(i < people.size()) {
            if(people[i].surname == searchingSurname) {
                cout << "ID number" << "\t" << people[i].id << endl;
                cout << "Name: " << "\t" << "\t" << people[i].name << endl;
                cout << "Surname: " << "\t" << people[i].surname << endl;
                cout << "Phone number: " << "\t" << people[i].phoneNum << endl;
                cout << "Email: " << "\t" << "\t" << people[i].email << endl;
                cout << "Adress: " << "\t" << people[i].adress << endl;
                cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
                surnameNumber++;
            }i++;
        } if(surnameNumber == 0) {
            cout << "None person with that surname" << endl;
        }system("pause");
    }
}
void displayAllContact(vector <Contact> &people) {

    if(people.size() == 0) {
        cout << endl << "Error! Adress book is empty";
        Sleep(1500);
    } else {
        Contact person;
        system("cls");
        cout << "----- DISPLAYING CONTACTS ----" << endl;
        cout << "==================================" << endl;

        for(unsigned int i = 0; i < people.size(); i++) {
            cout << "ID person: " << "\t" << people[i].id << endl;
            cout << "Name: " << "\t" << "\t" << people[i].name << endl;
            cout << "Surname: " << "\t" << people[i].surname << endl;
            cout << "Phone number: " << "\t" << people[i].phoneNum << endl;
            cout << "Email: " << "\t" << "\t" << people[i].email << endl;
            cout << "Adress: " << "\t" << people[i].adress << endl;
            cout << "- - - - - - - - - - - - - - - - " << endl;
        }
        system("pause");
    }
}
int registration(vector <User>  &users) {
    User user;
    string login, password;
    fstream file;

    cout << endl;
    cout << "Input login: ";
    login = readLine();
    unsigned int i = 0;
    while(i < users.size()) {
        if(users[i].login == login) {
            cout << "Such a user exists. Input another login: ";
            login = readLine();
            i = 0;
        } else {
            i++;
        }
    }
    cout << "Input password: ";
    password = readLine();

    user.login = login;
    user.password = password;
    user.id = users.size() + 1;

    users.push_back(user);

    file.open("Uzytkownicy.txt", ios::app);
    file.close();

    file.open("Uzytkownicy.txt", ios::out | ios::app);
    if(file.good()) {
        file << user.id << "|" << user.login << "|" << user.password << "|" << endl;
        file.close();
    }
    cout << endl << "Account has been created" << endl;
    Sleep(1000);

    return users.size();
}
int logging(vector <User>  &users) {
    User user;
    string login, password;

    cout << "Input login: ";
    login = readLine();
    unsigned int i = 0;
    while(i < users.size()) {
        if(users[i].login == login) {
            for(int attempts = 0; attempts < 3; attempts++) {
                cout << "Input password. Left attempts: " << 3 - attempts << ": ";
                password = readLine();
                if(users[i].password == password) {
                    cout << endl << "Logging suceed" << endl;
                    Sleep(1000);
                    return users[i].id;
                }
            }
            cout << "You entered 3 times incorrect password. Wait 3 sec before next attempt" << endl;
            Sleep(3000);
            return 0;
        } else {
            i++;
        }
    }
    cout << "User with entered login doesn't exist" << endl;
    Sleep(1000);

    return users[i].id;
}
void saveAllUsersToTXT(vector <User> &users) {
    remove("Uzytkownicy.txt");
    fstream file;

    file.open("Uzytkownicy.txt", ios::out | ios::app);
    if(file.good()) {
        for(unsigned int i = 0; i < users.size(); i++) {
            file << users[i].id << "|";
            file << users[i].login << "|";
            file << users[i].password << "|" << endl;
        }
        file.close();
    } else {
        cout << "Can not open file.txt";
    }
}
void changePassword(vector <User>  &users, int idLoggedUser) {
    fstream file;
    string newPassword;
    cout << "Input new password: ";
    newPassword = readLine();
    for(unsigned int i = 0; i < users.size(); i++) {
        if(users[i].id == idLoggedUser) {
            users[i].password = newPassword;
            cout << "Password has been changed" << endl;
            Sleep(1500);
        }
    }
    saveAllUsersToTXT(users);
}
void addContact(vector<Contact> &people, int idLoggedUser, int lastID) {

    string name, surname, phoneNum, email, adress;
    Contact person;
    User user;

    if(lastID == 0) {
        person.id = 1;
    } else {
        person.id = lastID + 1;
    }
    system("cls");
    cout << "-------- ADDING NEW PERSON -------" << endl;
    cout << "==================================" << endl;
    cout << "Enter the name: ";
    person.name = readLine();
    cout << "Enter the surname: ";
    person.surname = readLine();
    cout << "Enter phone number: ";
    person.phoneNum = readLine();
    cout << "Enter email: ";
    person.email = readLine();
    cout << "Enter adress: ";
    person.adress = readLine();
    person.userId = idLoggedUser;

    people.push_back(person);

    fstream file;
    file.open("KsiazkaAdresowa.txt", ios::out | ios::app);
    if(file.good()) {
        file << person.id << "|" << person.userId << "|" << person.name << "|" << person.surname << "|" << person.phoneNum << "|" << person.email << "|" << person.adress << "|" << endl;
        file.close();
    }
    cout << endl;
    cout << "Person has been successfully added to contacts" << endl;
    Sleep(1500);
}
void renameFilesTXT() {
    remove("KsiazkaAdresowa.txt");
    if(rename("KsiazkaAdresowaTEMP.txt","KsiazkaAdresowa.txt") != 0) {
        perror("Error renaming file");
        Sleep(1500);
    } else {
        cout << "File rewrote and renamed successfully" << endl;
        Sleep(1500);
    }
}
void rewriteFunc(string personToModifyAsLine) {
    string lineInTXT = "";
    fstream plik, plikTEMP;

    plik.open("KsiazkaAdresowa.txt",ios::in);
    plikTEMP.open("KsiazkaAdresowaTEMP.txt", ios::app);
    plikTEMP.close();
    plikTEMP.open("KsiazkaAdresowaTEMP.txt",ios::trunc|ios::out);

    string editedPersonId = personToModifyAsLine.substr(0,personToModifyAsLine.find('|'));
    while(getline(plik,lineInTXT)){
        lineInTXT.substr(0,lineInTXT.find('|')) != editedPersonId ? plikTEMP << lineInTXT << endl : plikTEMP << personToModifyAsLine << endl;
   }
    plikTEMP.close();
    plik.close();

    renameFilesTXT();
}
void saveAfterDeleting(int choseID){
    string lineInTXT = "";
    fstream plik, plikTEMP;

    plik.open("KsiazkaAdresowa.txt",ios::in);
    plikTEMP.open("KsiazkaAdresowaTEMP.txt", ios::app);
    plikTEMP.close();
    plikTEMP.open("KsiazkaAdresowaTEMP.txt",ios::trunc|ios::out);

    while(getline(plik,lineInTXT)){
        if(stoi(lineInTXT.substr(0,lineInTXT.find('|'))) != choseID)
        plikTEMP << lineInTXT << endl;
    }
    plikTEMP.close();
    plik.close();

    renameFilesTXT();
}
void deletePerson(vector <Contact> &people){
    Contact person;
    int choseID;
    char confirmChoice;

    if(people.size() == 0) {
        cout << endl <<"Error! Adress book is empty";
        Sleep(1500);
        return;
    }
    else {
        system("cls");
        cout << "Enter person's ID to delete: " << endl;
        cin >> choseID;
        vector <Contact> ::iterator itr = people.begin();
        for(; itr != people.end(); ++itr) {
            if(itr->id == choseID) {
                cout << itr->id << "|" << itr->name << "|" << itr->surname << "|" << itr->phoneNum << "|" << itr->email << "|" << itr->adress << "|" << endl << endl;
                Sleep(1000);
                cout << "Are you sure about deleting contact (y) ? : ";
                cin >> confirmChoice;
                if(confirmChoice == 'y') {
                    people.erase(itr);
                    cout << "Contact was deleted" << endl;
                    Sleep(1000);
                    saveAfterDeleting(choseID);
                } else if(confirmChoice != 'y') {
                    cout << "Deleting was not confirm" << endl;
                    Sleep(1000);
                }
                break;
            }
        }
    }
}
void modifingData (vector <Contact> &people, vector <Contact> &peopleALL) {

    int id2modify = 0;
    char modifyChoice;
    string newName, newSurname, newPhoneNum, newEmail, newAdress, personToModifyAsLine;
    bool isPersonExist = false;

    if(people.size() == 0) {
        cout << endl << "Error! Adress book is empty";
        Sleep(1500);
        return;
    }
    system("cls");
    if(!people.empty()) {
        cout << "------- MODIFING A CONTACT -------" << endl;
        cout << "==================================" << endl;
        cout << "Enter ID Number to change data:  ";
        cin >> id2modify;

        for(vector<Contact>::iterator itr = people.begin(); itr != people.end(); itr++) {
            if(itr->id == id2modify) {
                isPersonExist = true;

                cout << "You are going to change data that person: " << endl << endl;
                cout << itr->id << "|" << itr->userId << "|" << itr->name << "|" << itr->surname << "|" << itr->phoneNum << "|" << itr->email << "|" << itr->adress << endl << endl;
                cout << "Chose information to edit (1/2/3/4/5 or 6): " << endl;
                cout << "1. Name" << endl;
                cout << "2. Surname" << endl;
                cout << "3. Phone Number" << endl;
                cout << "4. E-mail" << endl;
                cout << "5. Adress" << endl << endl;
                cout << "6. Return" << endl;
                modifyChoice = checkChoice();

                switch(modifyChoice) {
                case '1':
                    cout << "Set a new name: ";
                    itr->name = readLine();
                    personToModifyAsLine = to_string(itr->id) + "|" + to_string(itr->userId) + "|" + itr->name + "|" + itr->surname + "|" + itr->phoneNum + "|" + itr->email + "|" + itr->adress + "|";
                    rewriteFunc(personToModifyAsLine);
                    cout << "Name was changed" << endl;
                    Sleep(1500);
                    break;
                case '2':
                    cout << "Set a new surname: ";
                    itr->surname = readLine();
                    personToModifyAsLine = to_string(itr->id) + "|" + to_string(itr->userId) + "|" + itr->name + "|" + itr->surname + "|" + itr->phoneNum + "|" + itr->email + "|" + itr->adress + "|";
                    rewriteFunc(personToModifyAsLine);
                    cout << "Surname was changed" << endl;
                    Sleep(1500);
                    break;
                case '3':
                    cout << "Set a new phone number: ";
                    itr->phoneNum = readLine();
                    personToModifyAsLine = to_string(itr->id) + "|" + to_string(itr->userId) + "|" + itr->name + "|" + itr->surname + "|" + itr->phoneNum + "|" + itr->email + "|" + itr->adress + "|";
                    rewriteFunc(personToModifyAsLine);
                    cout << "Phone number was changed" << endl;
                    Sleep(1500);
                    break;
                case '4':
                    cout << "Set a new email: ";
                    itr->email = readLine();
                    personToModifyAsLine = to_string(itr->id) + "|" + to_string(itr->userId) + "|" + itr->name + "|" + itr->surname + "|" + itr->phoneNum + "|" + itr->email + "|" + itr->adress + "|";
                    rewriteFunc(personToModifyAsLine);
                    cout << "E-mail was changed" << endl;
                    Sleep(1500);
                    break;
                case '5':
                    cout << "Set a new adress: ";
                    itr->adress = readLine();
                    personToModifyAsLine = to_string(itr->id) + "|" + to_string(itr->userId) + "|" + itr->name + "|" + itr->surname + "|" + itr->phoneNum + "|" + itr->email + "|" + itr->adress + "|";
                    rewriteFunc(personToModifyAsLine);
                    cout << "Adress was changed" << endl;
                    Sleep(1500);
                    break;
                case '6':
                    cout << "Returning to main menu" << endl << endl;
                    Sleep(1500);
                    return;
                default:
                    cout << endl << "Incorrect input number" << endl << endl;
                    Sleep(1500);
                    break;
                }
            }
        }
        if(isPersonExist == false) {
            cout << endl << "No such recipient" << endl;
            Sleep(1500);
        }
    } else {
        cout << "Error! Adress book is empty" << endl;
        Sleep(1500);
    }
}
int main() {

    vector <User> users;
    vector <Contact> people;
    vector <Contact> peopleALL;
    int idLoggedUser = 0;
    char choice;

    loadNotepadUsers(users);

    while(true) {
        if(idLoggedUser == 0) {
            system("cls");
            cout << "=== >  MAIN MENU  < ===" << endl << endl;
            cout << "1. Registration" << endl;
            cout << "2. Log in" << endl << endl;
            cout << "9. Exit" << endl << endl;
            cout << "Pick option: ";

            choice = checkChoice();
            if(choice == '1') {
                registration(users);
            } else if(choice == '2') {
                idLoggedUser = logging(users);
                loadNotepadPeople(people, idLoggedUser);
            } else if(choice == '9') {
                exit(0);
            }
        } else {
            unsigned int lastID = loadNotepadPeopleALL(peopleALL);
            system("cls");
            cout << "Logged user's info: " << endl;
            cout << users[idLoggedUser - 1].id << "|" << users[idLoggedUser - 1].login << "|" << users[idLoggedUser - 1].password << endl;
            cout<<"=================================="<<endl;
            cout<<"---------- ADRESS BOOK -----------"<<endl;
            cout<<"=================================="<<endl;
            cout << "   MENU:" << endl << endl;
            cout << "1. Add contact" << endl;
            cout << "2. Find person by name" << endl;
            cout << "3. Find person by surname" << endl;
            cout << "4. Display all contacts" << endl;
            cout << "5. Delete contact" << endl;
            cout << "6. Modify contact" << endl << endl;
            cout << "7. Change password" << endl;
            cout << "8. Log out" << endl << endl;
            cout << "Pick option: ";

            choice = checkChoice();
            switch(choice) {
            case '1':
                addContact(people, idLoggedUser, lastID);
                break;
            case '2':
                searchByName(people);
                break;
            case '3':
                searchBySurname(people);
                break;
            case '4':
                displayAllContact(people);
                break;
            case '5':
                deletePerson(people);
                break;
            case '6':
                modifingData(people, peopleALL);
                break;
            case '7':
                changePassword(users, idLoggedUser);
                break;
            case '8':
                people.clear();
                idLoggedUser = 0;
            }
        }
    }
    return 0;
}
