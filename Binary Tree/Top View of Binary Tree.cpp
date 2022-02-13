/* template <typename T>
  class TreeNode {
     public:
      T val;
      TreeNode<T> *left;
      TreeNode<T> *right;

      TreeNode(T val) {
          this->val = val;
          left = NULL;
          right = NULL;
      }
}; */

vector<int> getTopView(TreeNode<int> *root) {
    if (root == NULL) {
        return vector<int>();
    }	
    
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    
    map<int, int> mp;
    
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (!mp.count(u.second)) {
            mp[u.second] = u.first -> val;
        }
        if (u.first -> left) {
            q.push({u.first -> left, u.second - 1});
        }
        if (u.first -> right) {
            q.push({u.first -> right, u.second + 1});
        }
    }
    vector<int> traversal;
    for (auto x: mp) {
        traversal.push_back(x.second);
    }
    return traversal;
}

/*
APPROACH: 
=> Imagine the tree as a grid system
=> For every column the first element that you will get will be in the traversal
=> Map can easily keep track of the first node that we encounter in every column
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
