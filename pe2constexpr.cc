
constexpr int sum_fib_until(int f0, int f1, int upto, int sum)
{
    return (f0 >= upto) ? sum : sum_fib_until(f1, f0 + f1, upto, sum + (f0 % 2 ? 0 : f0));
}

int main()
{
    constexpr int answer = sum_fib_until(1, 2, 4000000, 0);
    
    return answer;
}
