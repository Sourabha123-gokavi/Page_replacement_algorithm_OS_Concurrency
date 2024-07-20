#include <bits/stdc++.h>
using namespace std;

void FIFOPageReplacement(vector<int>& pages, int capacity) {
    unordered_set<int> s;
    vector<int> indexes;

    int page_faults = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (s.size() < capacity) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                page_faults++;
                indexes.push_back(pages[i]);
            }
        } else {
            if (s.find(pages[i]) == s.end()) {
                int val = indexes[0];
                indexes.erase(indexes.begin());
                s.erase(val);
                s.insert(pages[i]);
                indexes.push_back(pages[i]);
                page_faults++;
            }
        }
    }
    cout << "Page Faults: " << page_faults << endl;
}

int main() {
    vector<int> pages = {1, 3, 0, 3, 5, 6, 3};
    int capacity = 3;
    FIFOPageReplacement(pages, capacity);
    return 0;
}
