#include<iostream>
#include<string>

using namespace std;

class HashTable {

    int size;

    string name[10];
    long long phone[10];

public:

    HashTable() {

        size = 10;

        for(int i = 0; i < size; i++) {

            name[i] = "";
            phone[i] = -1;
        }
    }

    int hashFunction(long long key) {

        return key % size;
    }

    void insert(string n,
                long long num) {

        int index =
        hashFunction(num);

        int originalIndex = index;

        // Linear Probing
        while(phone[index] != -1) {

            index = (index + 1) % size;

            if(index == originalIndex) {

                cout << "Hash Table Full\n";

                return;
            }
        }

        name[index] = n;
        phone[index] = num;

        cout << "Record Inserted Successfully\n";
    }

    void search(long long num) {

        int index =
        hashFunction(num);

        int originalIndex = index;

        while(phone[index] != -1) {

            if(phone[index] == num) {

                cout << "\nRecord Found\n";

                cout << "Name : "
                     << name[index]
                     << endl;

                cout << "Phone : "
                     << phone[index]
                     << endl;

                return;
            }

            index = (index + 1) % size;

            if(index == originalIndex)
                break;
        }

        cout << "\nRecord Not Found\n";
    }

    void display() {

        cout << "\nTelephone Book Database\n";

        for(int i = 0; i < size; i++) {

            cout << i << " -> ";

            if(phone[i] != -1) {

                cout << name[i]
                     << " : "
                     << phone[i];
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