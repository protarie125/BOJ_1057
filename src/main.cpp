#include <iostream>
#include <vector>

using namespace std;

using vb = vector<bool>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	auto ton = vb(n, false);
	ton[a - 1] = true;
	ton[b - 1] = true;

	auto ct = n;
	auto round = int{ 1 };
	while (2 <= ton.size()) {
		if (2 == ton.size()) {
			cout << round;
			return 0;
		}

		const auto& h = ct / 2;
		auto next = vb(h + ct % 2, false);
		for (int i = 0; i < h; ++i) {
			const auto& l = ton[2 * i];
			const auto& r = ton[2 * i + 1];
			if (l && r) {
				cout << round;
				return 0;
			}

			next[i] = l || r;
		}

		if (1 == ct % 2) {
			next[h] = ton[ct - 1];
		}

		ct = h + ct % 2;
		ton = next;
		++round;
	}

	return 0;
}