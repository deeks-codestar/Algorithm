#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN  1000000

int num[50010];
int main() {
  int t;
  cin >> t;

  for (int cas = 1; cas <= t; cas ++) {
    vector<pair<int, int> > a;
    a.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {

      cin >> num[i];
      a.push_back(make_pair(num[i], i));
    }
    sort(a.begin(), a.end());
    int start = 0;
    long long res = 0;
    for (int i = a.size() - 1; i >= 0; i --) {
      if (a[i].second >= start) {
        for (; start <= a[i].second; start ++) {
          res -= num[start];
          res += a[i].first;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
