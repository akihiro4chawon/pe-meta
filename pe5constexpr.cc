constexpr int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

constexpr int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

constexpr int fold_range_by(int beg, int end, int seed, int reducer(int, int))
{
    return beg < end ? fold_range_by(beg + 1, end, reducer(seed, beg), reducer) : seed;
}

int main()
{
    constexpr int answer = fold_range_by(1, 20, 1, lcm);
    return answer;
}
