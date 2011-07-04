constexpr int sum_of_squares(int beg, int end, int sum)
{
    return beg < end ? sum_of_squares(beg + 1, end, sum + beg) : sum * sum;
}

constexpr int square_of_sum(int beg, int end, int sum)
{
    return beg < end ? square_of_sum(beg + 1, end, sum + beg * beg) : sum;
}

constexpr int difference(int beg, int end)
{
    return sum_of_squares(beg, end, 0) - square_of_sum(beg, end, 0);
}

int main()
{
    constexpr int answer = difference(1, 101);
    return answer;
}
