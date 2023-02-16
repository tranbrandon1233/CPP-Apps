
bool anyTrue(const double a[], int n)
{
    if (n == 0) 
        return false;
    return anyTrue(a + 1, n - 1) || somePredicate(a[0]);
}

int countTrue(const double a[], int n)
{
    if (n == 0) 
        return 0;
    return countTrue(a + 1, n - 1) + somePredicate(a[0]);
}

int firstTrue(const double a[], int n)
{
    if (n == 0) 
        return -1;
    if (somePredicate(a[0]))
        return 0;
     return firstTrue(a + 1, n - 1) != -1 ?  1 + firstTrue(a + 1, n - 1) : -1;
}

int indexOfMinimum(const double a[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1) 
        return 0;
    return a[0] >= a[indexOfMinimum(a + 1, n - 1) + 1] ? indexOfMinimum(a + 1, n - 1) + 1 : 0;
}

bool isIn(const double a1[], int n1, const double a2[], int n2)
{
    if (n1 == 0)
        return true;
    if (n1 > n2 || n2 == 0) 
        return false;
    if (a1[0] != a2[0])
        return isIn(a1, n1, a2+1, n2-1);
    else
        return isIn(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
}
