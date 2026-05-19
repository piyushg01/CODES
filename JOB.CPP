#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Job {

    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {

    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs,
                   int n) {

    sort(jobs.begin(),
         jobs.end(),
         compare);

    int maxDeadline = 0;

    for(Job job : jobs) {

        maxDeadline =
        max(maxDeadline,
            job.deadline);
    }

    vector<char> slot(maxDeadline, '-');

    int totalProfit = 0;

    for(Job job : jobs) {

        for(int j = job.deadline - 1;
            j >= 0;
            j--) {

            if(slot[j] == '-') {

                slot[j] = job.id;

                totalProfit += job.profit;

                break;
            }
        }
    }

    cout << "\nSelected Jobs:\n";

    for(char job : slot) {

        if(job != '-')
            cout << job << " ";
    }

    cout << "\n\nTotal Profit = "
         << totalProfit;
}

int main() {

    int n;

    cout << "Enter Number of Jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    for(int i = 0; i < n; i++) {

        cout << "\nEnter Job ID: ";
        cin >> jobs[i].id;

        cout << "Enter Deadline: ";
        cin >> jobs[i].deadline;

        cout << "Enter Profit: ";
        cin >> jobs[i].profit;
    }

    jobSequencing(jobs, n);

    return 0;
}