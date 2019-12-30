void mx_foreach(int *arr, int size, void (*f)(int)) {
    if (size < 1)
        return;
    for (int i = 0; i < size; i++) {
        f(arr[i]);
    }
}
