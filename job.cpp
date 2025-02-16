#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job> &jobs) {
    sort(jobs.begin(), jobs.end(), compare);
    
    int maxDeadline = 0;
    for (auto job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);
    
    vector<char> schedule(maxDeadline, '-');
    
    for (auto job : jobs) {
        for (int j = job.deadline - 1; j >= 0; j--) {
            if (schedule[j] == '-') {
                schedule[j] = job.id;
                break;
            }
        }
    }
    
    cout << "Job Schedule: ";
    for (char job : schedule)
        if (job != '-')
            cout << job << " ";
    cout << endl;
}

int main() {
    vector<Job> jobs = {{'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27}, {'D', 1, 25}, {'E', 3, 15}};
    jobScheduling(jobs);
    return 0;
}


