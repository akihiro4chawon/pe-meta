// i believe this program is ok, but gcc 4.6.1 crashes silently

constexpr bool is_prime(int n, int cur)
{
    return n < cur * cur ? true  :
           n % cur == 0  ? false :
                           is_prime(n, cur + 1);
}

constexpr int find_nth_prime(int nth, int cur)
{
    return !is_prime(cur, 2) ? find_nth_prime(nth, cur + 2) :
           nth != 0          ? find_nth_prime(nth - 1, cur + 2) :
                               cur;
}

int main()
{
    constexpr int answer = find_nth_prime(10001-2, 3);
    return answer;
}
