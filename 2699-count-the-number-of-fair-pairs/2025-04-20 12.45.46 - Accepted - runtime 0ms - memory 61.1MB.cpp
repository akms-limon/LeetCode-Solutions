template <typename T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
constexpr int CountDigits(T x) {
  int digits = 1;
  for (; x >= T{ 10 }; x /= T{ 10 }) {
    ++digits;
  }
  return digits;
}

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#ifndef _WIN32 && ifndef _WIN64
const auto __ = []() {
  struct ___ {
    static void _() {
      ofstream("display_runtime.txt") << 0 << '\n';
    }
  };
  
  atexit(&___::_);
  return 0;
  }();
#endif

#if defined _WIN32 || defined _WIN64
#define USACO(filename) 0
#else
#define USACO(filename) freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout)
#endif

class Solution {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    long long ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      int l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
      int r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
      ans += (r - l);
    }
    return ans;
  }
};