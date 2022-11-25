#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

int main() {
    // get input: first is random seed, second is vector length
    int seed, length;
    cout << "Input a seed and a vector length: ";
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace


    // initialize and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;
    // sort v
    mergeSort(v, t, 0, v.size()-1);

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));//to check the condition to see if it is true. if not it will print an error message
    }

    // print sorted list
    cout << "Sorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;


    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {

    for (int i = leftPos; i <= rightEnd; i++) {
        tmp.at(i) = a.at(i);
    }

    int b = leftPos;
    int c = rightPos + 1;
    int d = leftPos;

    while (b <= rightPos && c <= rightEnd) {
        if (a.at(b) <= a.at(c)) {
            a.at(d) = tmp.at(b);
            ++b;
        } else {
            a.at(d) = tmp.at(c);
            ++c;
        }
        ++d;
    }

    if (b > rightPos){
        for (int i = c; i <= rightEnd; ++i){
            a.at(d) = tmp.at(i);
            ++d;
        }
    }
    else
    {
        for (int i = b; i <= rightPos; ++i)
        {
            a.at(d) = tmp.at(i);
            ++d;
        }
    }
    for (int i = leftPos; i <= rightEnd; ++i) {
        tmp.at(i) = a.at(i);
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) { //index for beginning of vector and right for index of end of vector

    if (a.size() == 1) {
        return;
    }
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, tmp, left, mid);
        mergeSort(a, tmp, mid + 1, right);
        mergeSortedLists(a, tmp, left, mid, right);
    }
}