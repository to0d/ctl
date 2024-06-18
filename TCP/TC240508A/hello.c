int foo() {
    int x = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 5; j+= 2) {
           x++;
        }
    }
    return x;
}

