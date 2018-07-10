class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int bin[26] = { 0 };
		for (const auto& c : magazine) ++bin[c - 'a'];
		for (const auto& c : ransomNote) --bin[c - 'a'];
		return find_if(bin, bin + 26, [](const int& x) {return x < 0; }) == (bin + 26);
	}
};
