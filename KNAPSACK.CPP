#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Item {

    int profit;
    int weight;
};

bool compare(Item a, Item b) {

    double r1 =
    (double)a.profit / a.weight;

    double r2 =
    (double)b.profit / b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int capacity,
                          vector<Item>& items) {

    sort(items.begin(),
         items.end(),
         compare);

    double totalProfit = 0.0;

    for(Item item : items) {

        // Full item can be taken
        if(item.weight <= capacity) {

            capacity -= item.weight;

            totalProfit += item.profit;
        }

        // Take fraction
        else {

            totalProfit +=
            ((double)item.profit /
             item.weight) * capacity;

            break;
        }
    }

    return totalProfit;
}

int main() {

    int n, capacity;

    cout << "Enter Number of Items: ";
    cin >> n;

    vector<Item> items(n);

    for(int i = 0; i < n; i++) {

        cout << "Enter Profit and Weight: ";

        cin >> items[i].profit
            >> items[i].weight;
    }

    cout << "Enter Knapsack Capacity: ";
    cin >> capacity;

    double maxProfit =
    fractionalKnapsack(capacity,
                       items);

    cout << "\nMaximum Profit = "
         << maxProfit;

    return 0;
}