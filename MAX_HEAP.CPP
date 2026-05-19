#include<iostream>
#include<vector>

using namespace std;

class MaxHeap {

    vector<int> heap;

public:

    void insert(int value) {

        heap.push_back(value);

        int index = heap.size() - 1;

        // Heapify Up
        while(index > 0) {

            int parent = (index - 1) / 2;

            if(heap[parent] < heap[index]) {

                swap(heap[parent],
                     heap[index]);

                index = parent;
            }
            else {

                break;
            }
        }
    }

    void display() {

        cout << "\nMax Heap:\n";

        for(int value : heap) {

            cout << value << " ";
        }

        cout << endl;
    }

    int getMaximum() {

        return heap[0];
    }
};

int main() {

    MaxHeap h;

    int n, marks;

    cout << "Enter Number of Students: ";
    cin >> n;

    for(int i = 0; i < n; i++) {

        cout << "Enter Marks: ";
        cin >> marks;

        h.insert(marks);
    }

    h.display();

    cout << "\nMaximum Marks = "
         << h.getMaximum();

    return 0;
}