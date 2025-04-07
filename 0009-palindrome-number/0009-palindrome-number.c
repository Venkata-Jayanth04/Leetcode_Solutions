bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    char str[12];
    sprintf(str, "%d", x);

    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }

    return true;
}