class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> results;
    priority_queue<int> maxHeap; // Max-heap to store the k smallest distances

    for (const auto& query : queries) {
        int x = query[0];
        int y = query[1];
        int distance = abs(x) + abs(y); // Calculate the Manhattan distance

        // Insert the new distance into the max-heap
        if (maxHeap.size() < k) {
            maxHeap.push(distance);
        } else if (distance < maxHeap.top()) {
            maxHeap.pop(); // Remove the largest distance
            maxHeap.push(distance); // Insert the new smaller distance
        }

        // If there are fewer than k elements in the max-heap, result is -1
        if (maxHeap.size() < k) {
            results.push_back(-1);
        } else {
            results.push_back(maxHeap.top()); // The k-th smallest distance
        }
    }

    return results;
    }
};