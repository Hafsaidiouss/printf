long int _pow(long int a, int b)
{
        if (b == 0)
                return (1);
        return (a * _pow(a, b - 1));
}
