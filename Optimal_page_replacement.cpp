#include<bits/stdc++.h>
using namespace std;

int findOptimal(vector<int>& pages, vector<int>& frame, int index) {
    int res = -1, farthest = index;
    for (int i = 0; i < frame.size(); i++) {
        int j;
        for (j = index; j < pages.size(); j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pages.size())
            return i;
    }
    return (res == -1) ? 0 : res;
}

void OptimalPageReplacement(vector<int>& pages, int capacity) {
    vector<int> frame;
    int page_faults = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (find(frame.begin(), frame.end(), pages[i]) != frame.end())
            continue;

        if (frame.size() < capacity)
            frame.push_back(pages[i]);
        else {
            int j = findOptimal(pages, frame, i + 1);
            frame[j] = pages[i];
        }
        page_faults++;
    }
    cout << "Page Faults: " << page_faults << endl;
}

int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3};
    int capacity = 4;
    OptimalPageReplacement(pages, capacity);
    return 0;
}
