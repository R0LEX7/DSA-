#include <bits/stdc++.h>
using namespace std;


    struct Job
{
    int id;
    int startTime;
    int deadline;
    int profit;
};

// Comparator to sort jobs by profit in descending order
static bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> help(Job arr[], int n)
{
    // Sort jobs by profit
    // sort(arr, arr + n, compare);

    // Find the maximum deadline
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i].deadline);
    }

    // Initialize slot array
    vector<int> slot(maxi + 1, -1);

    int countJobs = 0, jobProfit = 0;

    // Iterate through jobs
    for (int i = 0; i < n; i++)
    {
        // Find a slot for this job
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return {countJobs, jobProfit};
}
    int jobScheduling(vector<int>& startTime, vector<int>& deadline, vector<int>& profit) {
        int n = startTime.size(); // Number of jobs
        Job arr[n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = {startTime[i], deadline[i], profit[i]};
        }

        vector<int> ans = help(arr, n);

        return ans[1];
    }




int main(){

    return 0;
}
