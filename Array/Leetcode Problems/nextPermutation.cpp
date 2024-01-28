class Solution
{
public:
    void nextPermutation(vector<int> &Z)
    {

        int n = Z.size();
        if (n == 1)
            return;

        int ind = -1;
        // Step 1: Find the largest index i such that Z[i] < Z[i + 1]
        for (int i = n - 2; i >= 0; i--)
        {
            if (Z[i] < Z[i + 1])
            {
                ind = i;
                break;
            }
        }

        // Step 2: If no such index exists, reverse the entire sequence

        if (ind == -1)
        {
            reverse(Z.begin(), Z.end());
        }
        else
        {
            // Step 3: Find the largest index j such that Z[j] > Z[ind]

            for (int i = n - 1; i > ind; i--)
            {
                if (Z[i] > Z[ind])
                {
                    swap(Z[i], Z[ind]);
                    break;
                };
            }
            // Step 5: Reverse/sort the subsequence from index ind + 1 to the end
            reverse(Z.begin() + ind + 1, Z.end());
        }
    }
};