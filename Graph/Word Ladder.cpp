class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        
        for (int i = 0; i < wordList.size(); i++) {
            mp[wordList[i]]++;
        }

        queue<pair<string, int>> wordQueue;
        unordered_map<string, int> vis;
        wordQueue.push({beginWord, 0});
        vis[beginWord] = true;

        auto generateValidWords = [&](string word) -> vector<string> {
            vector<string> validWords;
            for (int i = 0; i < word.size(); i++) {
                string tmpWord = word;
                for (int ch = 'a'; ch <= 'z'; ch++) {
                    tmpWord[i] = ch;
                    if (mp.find(tmpWord) != mp.end() && tmpWord != word) {
                        validWords.push_back(tmpWord);
                    }
                }
            }
            return validWords;
        };

        int ans = 0;
        bool found = false;
        while (!wordQueue.empty()) {
            string currWord = wordQueue.front().first;
            int currLevel = wordQueue.front().second;

            wordQueue.pop();
            if (currWord == endWord) {
                ans = currLevel;
                found = true;
                break;
            }
            
            vector<string> neighbours = generateValidWords(currWord);
            for (int i = 0; i < neighbours.size(); i++) {
                if (!vis[neighbours[i]]) {
                    wordQueue.push({neighbours[i], currLevel + 1});
                    vis[neighbours[i]] = true;
                }
            }
        }

        return found ? ans + 1 : 0;
    }
};

/*
Since we are talking about traveling from one word to another, we can visualize this approach as a graph problem.
We just need to perform a BFS on the startWord and on the fly generate who are the words that differ by one and are present in the list
Once you get to the end word return the level of the graph
*/
