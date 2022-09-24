void mx_printchar(char c);

void mx_printint(int n) {
    int amount = 0;
    if (n == 0) {
        mx_printchar(48);
    }
    if (n < 0) {
        mx_printchar('-');
        n *= -1;
    }
    int temp = n;
    while (n != 0) {
        n = n / 10;
        amount++;
    }
    char temp1[amount];
    for (int i = 0; i < amount; i++) {
        temp1[i] = temp % 10 + 48;
        temp /= 10;
    }
    for (int i = amount - 1; i >= 0; i--) {
        mx_printchar(temp1[i]);
    }
    // mx_printchar('\n');
}
