constexpr int or_else(int a, int b)
{
    return a ? a : b;
}

constexpr int put_c(int a, int b, int c, int n)
{
    return a * a + b * b == c * c ? a * b * c : 0;
}

constexpr int put_b(int a, int b, int n)
{
    return b > n / 2 ? 0 : or_else(put_c(a, b, n - a - b, n), put_b(a, b + 1, n));
}

constexpr int put_a(int a, int n)
{
    return a > n / 3 ? 0 : or_else(put_b(a, a + 1, n), put_a(a + 1, n));
}

int main()
{
    constexpr int answer = put_a(1, 1000);
    return answer;
}
