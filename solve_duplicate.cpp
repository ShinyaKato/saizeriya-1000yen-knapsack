#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

const int INF = 1 << 28;

int main(void) {
  int n;
  cin >> n;
  vector<string> name(n);
  vector<int> price(n), calorie(n);
  for (int i = 0; i < n; i++) {
    int id;
    string category, type;
    double salt;
    cin >> id >> name[i] >> category >> type >> price[i] >> calorie[i] >> salt;
  }

  vector<vector<int>> dp(n + 1, vector<int>(1001, -INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 1000; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j - price[i] >= 0) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - price[i]] + calorie[i]);
      }
    }
  }

  int best_price = 0, best_calorie = 0;
  for (int i = 0; i <= 1000; i++) {
    if (best_calorie < dp[n][i]) {
      best_price = i;
      best_calorie = dp[n][i];
    }
  }

  vector<int> selected;
  for (int i = n - 1, j = best_price; i != 0 || j != 0;) {
    assert(i >= 0 && j >= 0);
    if (dp[i][j] == dp[i + 1][j]) {
      i--;
    } else if (j - price[i] >= 0 && dp[i + 1][j - price[i]] + calorie[i] == dp[i + 1][j]) {
      selected.push_back(i);
      j -= price[i];
    } else {
      assert(false);
    }
  }
  reverse(selected.begin(), selected.end());

  for (int i : selected) {
    cout << name[i] << ": " << price[i] << "円, " << calorie[i] << " kcal" << endl;
  }
  cout << "合計: " << best_price << "円, " << best_calorie << " kcal" << endl;
}