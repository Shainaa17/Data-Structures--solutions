#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> ans;  
    vector<int> result;    

    for (int i=0;i<n;i++) {
        if (ans.find(arr[i]) == ans.end()) { 
            ans.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }

    cout << "Array after removing duplicates: ";
    for (int num:result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
