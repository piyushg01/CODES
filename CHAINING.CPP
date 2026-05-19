#include<iostream>
#include<list>

using namespace std;

class HashTable {

    int size;

    list<pair<string, long long>> table[10];

public:

    HashTable() {

        size = 10;
    }

    int hashFunction(long long key) {

        return key % size;
    }

    void insert(string name,
                long long phone) {

        int index =
        hashFunction(phone);

        table[index].push_back({name, phone});

        cout << "Record Inserted Successfully\n";
    }

    void search(long long phone) {

        int index =
        hashFunction(phone);

        int comparisons = 0;

        for(auto record : table[index]) {

            comparisons++;

            if(record.second == phone) {

                cout << "\nRecord Found\n";

                cout << "Name : "
                     << record.first
                     << endl;

                cout << "Phone : "
                     << record.second
                     << endl;

                cout << "Comparisons : "
                     << comparisons
                     << endl;

                return;
            }
        }

        cout << "\nRecord Not Found\n";
    }

    void display() {

        cout << "\nTelephone Book Database\n";

        for(int i = 0; i < size; i++) {

            cout << i << " -> ";

            for(auto record : table[i]) {

                cout << "("
                     << record.first
                     << ", "
                     << record.second
                     << ") ";
            }

            cout << endl;
        }
    }
};

int main() {

    HashTable ht;

    int choice;

    string name;

    long long phone;

    do {

        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Phone Number: ";
            cin >> phone;

            ht.insert(name, phone);

            break;

        case 2:

            cout << "Enter Phone Number to Search: ";
            cin >> phone;

            ht.search(phone);

            break;

        case 3:

            ht.display();

            break;

        case 4:

            cout << "Exiting Program\n";

            break;

        default:

            cout << "Invalid Choice\n";
        }

    } while(choice != 4);

    return 0;
}