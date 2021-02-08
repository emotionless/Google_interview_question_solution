#include <set>
#include <bits/stdc++.h>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k)
{
    unordered_map<string, int> counter;
    for(auto x : words)
    {
        counter[x]++;
    }
    set<pair<int, string>> container;
    for(auto x : counter)
    {
        container.insert(make_pair(x.second, x.first));
        if (container.size() > k)
            container.erase(container.begin());
    }
    vector<string> ans;
    for(auto it = container.rbegin(); it != container.rend(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

int main() {
    int i, jk;
    vector<string> words = {"sdf", "df"};

    topKFrequent(words, 1);

    return 0;
}
