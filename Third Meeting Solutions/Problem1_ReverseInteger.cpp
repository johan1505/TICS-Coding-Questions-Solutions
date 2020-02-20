int Reverse(int x) {
    bool IsNegative = false;
    if (x < 0){
        IsNegative = true;
        x = x * -1;
    }

    int CurrentAnswer = 0;

    while (x != 0){
        CurrentAnswer *= 10;
        CurrentAnswer += x % 10;
        x /= 10;
    }

    if (IsNegative) CurrentAnswer *= -1;

    return CurrentAnswer;
}