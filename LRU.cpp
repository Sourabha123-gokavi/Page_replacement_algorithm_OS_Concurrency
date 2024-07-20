#include <bits/stdc++.h>
using namespace std;

void LRUPageReplacement(vector<int>& pages, int capacity) {
    unordered_map<int, vector<int>::iterator> pageMap;
    vector<int> pageVector;
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        if (pageMap.find(pages[i]) == pageMap.end()) {
            if (pageVector.size() == capacity) {
                int last = pageVector.back();
                pageVector.pop_back();
                pageMap.erase(last);
            }
            pageVector.insert(pageVector.begin(), pages[i]);
            pageMap[pages[i]] = pageVector.begin();
            page_faults++;
        } else {
            pageVector.erase(pageMap[pages[i]]);
            pageVector.insert(pageVector.begin(), pages[i]);
            pageMap[pages[i]] = pageVector.begin();
        }
    }
    cout << "Page Faults: " << page_faults << endl;
}

int main() {
    vector<int> pages = {1, 2, 3, 4, 5, 1, 2, 1, 2, 3, 4, 5};
    int capacity = 3;
    LRUPageReplacement(pages, capacity);
    return 0;
}
