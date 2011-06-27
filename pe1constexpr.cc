
constexpr int sum_of_arith_seq(int beg, int end, int step)
{
    return (beg < end) ? beg + sum_of_arith_seq(beg + step, end, step) : 0;
}

int main()
{
    constexpr int answer = sum_of_arith_seq(3, 1000, 3)
                         + sum_of_arith_seq(5, 1000, 5)
                         - sum_of_arith_seq(15, 1000, 15);
    
    return answer;
}
