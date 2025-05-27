#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
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
    sort(arr, arr + n, compare);

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

int main()
{
    int n = 5; // Number of jobs
    Job arr[n];

    vector<int> id = {1, 2, 3, 4, 5}, deadline = {2, 1, 2, 1, 1}, profit = {100, 19, 27, 25, 15};

    for (int i = 0; i < n; i++)
    {
        arr[i] = {id[i], deadline[i], profit[i]};
    }

    vector<int> ans = help(arr, n);
    cout << ans[0] << " " << ans[1] << endl; // Output the number of jobs and total profit

    return 0;
}
