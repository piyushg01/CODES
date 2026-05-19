#include<iostream>
#include<vector>

using namespace std;

class SocialNetwork {

    int users;

    vector<string> userName;
    vector<int> comments;

public:

    SocialNetwork(int n) {

        users = n;

        userName.resize(users);
        comments.resize(users);
    }

    void inputData() {

        for(int i = 0; i < users; i++) {

            cout << "\nEnter User Name: ";
            cin >> userName[i];

            cout << "Enter Number of Comments: ";
            cin >> comments[i];
        }
    }

    void displayData() {

        cout << "\nUser Information:\n";

        for(int i = 0; i < users; i++) {

            cout << "User: "
                 << userName[i]
                 << " -> Comments: "
                 << comments[i]
                 << endl;
        }
    }

    void findMaxMinComments() {

        int maxComments = comments[0];
        int minComments = comments[0];

        string maxUser = userName[0];
        string minUser = userName[0];

        for(int i = 1; i < users; i++) {

            if(comments[i] > maxComments) {

                maxComments = comments[i];
                maxUser = userName[i];
            }

            if(comments[i] < minComments) {

                minComments = comments[i];
                minUser = userName[i];
            }
        }

        cout << "\nUser with Maximum Comments:\n";

        cout << maxUser
             << " -> "
             << maxComments << endl;

        cout << "\nUser with Minimum Comments:\n";

        cout << minUser
             << " -> "
             << minComments << endl;
    }
};

int main() {

    int n;

    cout << "Enter Number of Users: ";
    cin >> n;

    SocialNetwork sn(n);

    sn.inputData();

    sn.displayData();

    sn.findMaxMinComments();

    return 0;
}