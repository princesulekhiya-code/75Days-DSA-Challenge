class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) freq[t - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCount = 0;
        for (int f : freq) if (f == maxFreq) maxCount++;

        int partCount = maxFreq - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maxFreq * maxCount;
        int idles = max(0, emptySlots - availableTasks);

        return tasks.size() + idles;
    }
};
