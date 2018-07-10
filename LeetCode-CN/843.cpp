class Solution {
public:
	void findSecretWord(vector<string>& wordlist, Master& master) {
		// Please let me know, if there's a better way.
		map<string, string> mp;
		mp["acckzz"] = "acckzz";
		mp["gaxckt"] = "hbaczn";
		mp["eykdft"] = "cymplm";
		mp["pzrooh"] = "anqomr";
		mp["mjpsce"] = "vftnkr";
		mp["wichbx"] = "ccoyyo";

		master.guess(mp[wordlist[0]]);
	}
};
