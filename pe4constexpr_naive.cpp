// algorithmically ok, I belive. but gcc 4.6.1 silently crashes...

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

constexpr int search_max_parindrome(int end, int a, int b, int result)
{
    return a >= end ? result :
           b >= a   ? search_max_parindrome(end, a + 1, 1, result)
                    : search_max_parindrome(end, a, b + 1, max(zero_unless_parindrome(a * b), result));
}

int main()
{
    constexpr int answer = search_max_parindrome(1000, 1, 1, 0);
    return answer;
}
