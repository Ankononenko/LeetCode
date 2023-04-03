int is_in_circle(int x, int y, int h, int k, int r);

int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    *returnSize = queriesSize;
    int* res = (int*)calloc(*returnSize, sizeof(int));
    for (int q_i = 0; q_i < queriesSize; ++q_i) {
        for (int p_i = 0; p_i < pointsSize; ++p_i) {
            int point_in_circle = is_in_circle(points[p_i][0], points[p_i][1], queries[q_i][0], queries[q_i][1], queries[q_i][2]);
            res[q_i] += point_in_circle;
        }
    }
    return res;
}

/* 
Distance formula is used to compare the point to the radius of the circle
distance = sqrt((x - h)^2 + (y - k)^2)
Where (h, k) is the center of the circle and (x, y) are the coordinates of the point
If distance <= radius -> point is inside of the circle
*/
int is_in_circle(int x, int y, int h, int k, int r) {
    float distance = sqrt(pow(x - h, 2) + pow(y - k, 2));
    return distance <= r;
}
