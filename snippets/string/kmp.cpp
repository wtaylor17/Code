vector<int> kmp(string txt, string pat) {
    vector<int> toret;
	int m = txt.length(), n = pat.length();

	int next[n + 1];
	for (int i = 0; i < n + 1; i++)
		next[i] = 0;

	for (int i = 1; i < n; i++) {
		int j = next[i + 1];
		while (j > 0 && pat[j] != pat[i])
			j = next[j];
		if (j > 0 || pat[j] == pat[i])
			next[i + 1] = j + 1;
	}

	for (int i = 0, j = 0; i < m; i++) {
		if (txt[i] == pat[j]) {
			if (++j == n)
				toret.push_back(i - j + 1);
		} else if (j > 0) {
			j = next[j];
			i--;
		}
	}
	return toret;
}