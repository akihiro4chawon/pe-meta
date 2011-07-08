constexpr bool is_prime(int n, int cur)
{
    return n < cur * cur ? true  :
           n % cur == 0  ? false :
                           is_prime(n, cur + 1);
}

//123456789012345678901234567890
//oxoxoxoxoxoxoxoxoxoxoxoxoxoxox
//ooxooxooxooxooxooxooxooxooxoox
//ooooxooooxooooxooooxooooxoooox
//oxxxxxoxxxoxoxxxoxoxxxoxxxxxox
constexpr int skip_table[] = {
    6, 4, 2, 4, 2, 4, 6, 2,
};

constexpr int find_nth_prime(int nth, int cur, int mod)
{
    return !is_prime(cur, 2) ? find_nth_prime(nth,     cur + skip_table[mod], (mod + 1) % 8) :
           nth != 0          ? find_nth_prime(nth - 1, cur + skip_table[mod], (mod + 1) % 8) :
                               cur;
}

int main()
{
    constexpr int answer = find_nth_prime(10001-4, 7, 1);
    return answer;
}
