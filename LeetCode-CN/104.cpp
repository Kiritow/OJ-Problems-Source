class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		std::queue<std::pair<TreeNode*, int>> bus;
		bus.push(std::make_pair(root, 1));
		int hmax = 1;
		while (!bus.empty())
		{
			std::pair<TreeNode*,int> now = bus.front();
			hmax = std::max(hmax, now.second);
			bus.pop();
			if (now.first->left)
			{
				bus.push(std::make_pair(now.first->left, now.second + 1));
			}
			if (now.first->right)
			{
				bus.push(std::make_pair(now.first->right, now.second + 1));
			}
		}
		return hmax;
	}
};
