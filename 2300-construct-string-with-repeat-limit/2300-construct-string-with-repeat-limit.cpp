class Solution {
public:
    string repeatLimitedString(string s, int k) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        priority_queue<pair<char, int>> mh;
        for (auto it : mp) {
            mh.push({it.first, it.second});
        }

        string result = "";

        while (!mh.empty()) {
            auto [ch, ct] = mh.top();
            mh.pop();

            int used = min(k, ct);
            result.append(used, ch);
            ct -= used;

            if (ct > 0) {
                if(mh.size()==0)break;
                 auto [nextch, nextct] = mh.top();
                mh.pop();

                result += nextch;
                nextct--;

                if (nextct > 0) {
                    mh.push({nextch, nextct});
                }

                mh.push({ch, ct});
            }

           
        }

        return result;
    }
};
