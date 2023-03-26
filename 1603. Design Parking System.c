/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/

typedef struct {
    int big;
    int medium;
    int small;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* spaces;
    spaces = (ParkingSystem*)malloc(sizeof(ParkingSystem));
    spaces->big = big;
    spaces->medium = medium;
    spaces->small = small;
    return spaces;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    bool res = false;
    if (carType == 1 && obj->big) {
        --obj->big;
        res = true;
    }
    if (carType == 2 && obj->medium) {
        --obj->medium;
        res = true;
    }
    if (carType == 3 && obj->small) {
        --obj->small;
        res = true;
    }
    return res;
}

void parkingSystemFree(ParkingSystem* obj) {
    obj->big = 0;
    obj->medium = 0;
    obj->small = 0;
    free(obj);
    obj = NULL;
}
