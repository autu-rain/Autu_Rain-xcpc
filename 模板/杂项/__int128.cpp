std::ostream &operator<<(std::ostream &os, i128 n) {
	std::string s;
	if (!n) s = "0";
	int flg = 0;
	if (n < 0) {
		flg = 1;
		n *= -1;
	}
	while (n) {
		s += '0' + n % 10;
		n /= 10;
	}
	if (flg) {
		s += '-';
	}
	std::reverse(s.begin(), s.end());
	return os << s;
}