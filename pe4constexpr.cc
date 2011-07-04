// one of the two numbers must be divisible by 11. Because
// (1) Any parindrome with an even number of digits are divisible by 11;
// (2) 11 is a prime number.

constexpr int reverse_digits(int in, int out)
{
    return (in == 0) ? out : reverse_digits(in / 10, out * 10 + in % 10);
}

constexpr bool is_parindrome(int cand)
{
    return cand == reverse_digits(cand, 0);
}

constexpr int zero_unless_parindrome(int cand)
{
    return is_parindrome(cand) ? cand : 0;
}

constexpr int max(int a, int b)
{
    return a > b ? a : b;
}

constexpr int search_max_parindrome(int bbeg, int rend, int a, int b, int result)
{
    return
        (a < rend)                     ? result :
        (b < rend) || (a * b < result) ? search_max_parindrome(bbeg, rend, a - 1, bbeg, result) :
                                         search_max_parindrome(bbeg, rend, a, b - 11, max(zero_unless_parindrome(a * b), result));
}

int main()
{
    constexpr int answer = search_max_parindrome(990, 100, 999, 990, 0);
    return answer;
}
