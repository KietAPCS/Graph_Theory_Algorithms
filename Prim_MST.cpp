#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif
#define el cout << "\n"

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;

vector<pii> adj[N];
ll dist[N];
ll n, m; 

int main() {

	cin >> n >> m;

	for (ll i = 1; i <= m; i++) {
		ll x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({ x, w });
	}

	vector<int> key(n, 1e9);
	vector<int> inMST(n, 0);
	vector<int> trace(n, -1);

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, 0 });

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		
		inMST[u] = 1;

		for (auto tmp : adj[u]) {
			int v = tmp.first;
			int weight = tmp.second;
			if (!inMST[v] && weight < key[v]) {
				key[v] = weight;
				trace[v] = u;
				pq.push({ key[v], v });
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		cout << "Edge: " << trace[i] << " - " << i << " with weight: " << key[i] << endl;
	}

	return 0;
}