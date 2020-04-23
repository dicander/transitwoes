//
// Created by Marcus Dicander on 2020-04-23.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    int S, T, N;
    cin >> S >> T >> N;
    vector<int> transits(N+1, 0);
    for(int i = 0; i <= N; ++i) {
        cin >> transits[i];
    }
    vector<int> travel_times(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> travel_times[i];
    }
    vector<int> offsets(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> offsets[i];
    }
    int answer = transits[0];
    for(int i=0; i<N; ++i) {
        int we_arrived_this_late = answer % offsets[i];
        if(we_arrived_this_late) {
            answer += offsets[i] - we_arrived_this_late;
        }
        answer += travel_times[i];
        answer += transits[i+1];
    }
    if(answer <= T) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}