class dsu {
 public:
  vector<int> p;
  int n;
  vector<int> sz;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.assign(n, 1);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      sz[x] = 0;
      return true;
    }
    return false;
  }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        dsu d(nums.size() + 1);
        map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                continue;
            }
            if (mp.find(nums[i] - 1) != mp.end()) {
                d.unite(i, mp[nums[i] - 1]);
            }
            if (mp.find(nums[i] + 1) != mp.end()) {
                d.unite(i, mp[nums[i] + 1]);
            }    
            mp[nums[i]] = i;
        }
        
        return *max_element(d.sz.begin(), d.sz.end());
    }
};
