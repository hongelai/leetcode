int reverse(int x) {
    int newX = 0;
    for(;x;x/=10){
        newX = newX*10 + x%10;

    return newX;
}
