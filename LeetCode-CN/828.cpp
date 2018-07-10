class Solution {
public:
	const static long long MOD = 1000000007;
	int uniqueLetterString(string S) {
		map<char, vector<int>> mp;
		long long cnt = 0;
		int slen = S.size();
		for (int i = 0; i < slen; i++)
		{
			auto iter = mp.find(S[i]);
			if (iter == mp.end())
			{
				tie(iter, ignore) = mp.insert(make_pair(S[i], vector<int>{-1}));
				
			}
			else
			{
				int sz = iter->second.size();
				int k = iter->second[sz - 2];
				int j = iter->second[sz - 1];
				cnt = (cnt + (j - k)*(i - j)) % MOD;
			}
			iter->second.push_back(i);
		}
		for (const auto& pr : mp)
		{
			int sz = pr.second.size();
			int k = pr.second[sz - 2];
			int j = pr.second[sz - 1];
			cnt = (cnt + (j - k)*(slen - j)) % MOD;
		}

		return cnt;
	}
};
