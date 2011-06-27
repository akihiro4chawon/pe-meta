
constexpr long long max_prime_factor_of(long long n, long long max, long long cur)
{
    return (cur > n) ? max
                     : (n % cur) ? max_prime_factor_of(n, max, cur + 1)
                                 : max_prime_factor_of(n / cur, cur, cur);
}

int main()
{
    constexpr int answer = max_prime_factor_of(600851475143LL, 1, 2);
    
    return answer;
}
