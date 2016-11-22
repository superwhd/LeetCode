class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> ans;
        int n = 0;
        map<string, int> dic;
        vector<string> words;
        words.push_back(beginWord);
        dic[beginWord] = n++;
        if (!dic.count(endWord)) {
            dic[endWord] = n++;
            words.push_back(endWord);
        }
        for (auto &word : wordList) {
            if (!dic.count(word)) {
                dic[word] = n++;
                words.push_back(word);
            }
        }
        vector<vector<int>> adj(n);
        auto ck = [] (const string &s1, const string &s2) {
            int s = 0;
            for (int i = 0; i < s1.size(); i++) {
                s += s1[i] != s2[i];
                if (s > 1) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (ck(words[i], words[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> dis(n, -1);
        dis[dic[endWord]] = 0;
        int beginId = dic[endWord], endId = dic[beginWord];
        queue<int> q;
        q.push(beginId);
        while (!q.empty() && -1 == dis[endId]) {
            auto s = q.front();
            q.pop();
            for (auto v : adj[s]) {
                if (-1 == dis[v]) {
                    dis[v] = dis[s] + 1;
                    q.push(v);
                }
            }
        }
        if (dis[endId] != -1) {
            vector<vector<int>> prev(n);
            for (int i = 0; i < n; i++) {
                for (auto v : adj[i]) {
                    if (dis[v] == dis[i] + 1) {
                        prev[v].push_back(i);
                    }
                }
            }
            function<void(vector<int>)> dfs = [&] (vector<int> now) {
                auto s = now.back();
                if (s == beginId) {
                    vector<string> tmp;
                    for (auto t : now) {
                        tmp.push_back(words[t]);
                    }
                    ans.emplace_back(tmp);
                    return ;
                }
                for (auto v : prev[s]) {
                    now.push_back(v);
                    dfs(now);
                    now.pop_back();
                }
            };
            dfs({endId});
        }
        return ans;
    }
};
