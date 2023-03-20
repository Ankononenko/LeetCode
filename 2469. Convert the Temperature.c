double* convertTemperature(double celsius, int* returnSize){
    *returnSize = 2;
    double* kel_fah = (double*)malloc(*returnSize * sizeof(double));
    kel_fah[0] = celsius + 273.15;
    kel_fah[1] = celsius * 1.8 + 32.00;
    return kel_fah;
}
