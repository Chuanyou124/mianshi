#include <iostream>
#include <vector>
#include <map>

using namespace std;

int partition(vector<int>& ratings, int begin, int end, map<int, int>& idxMap) {
    int pivot = begin;
    int traverse = begin;
    int comp = ratings[end];

    for (int i = begin; i < end; ++i) {
        if (ratings[i] < comp) {
            int tmp = ratings[pivot];
            ratings[pivot] = ratings[i];
            ratings[i] = tmp;

            int tmpIdx = idxMap[pivot];
            idxMap[pivot] = idxMap[i];
            idxMap[i] = tmpIdx;
            pivot++;
        }
    }

    ratings[end] = ratings[pivot];
    ratings[pivot] = comp;

    int tmpIdx = idxMap[pivot];
    idxMap[pivot] = idxMap[end];
    idxMap[end] = tmpIdx;

    return pivot;
}

void quickSort(vector<int>& ratings, int begin, int end, map<int, int>& idxMap) {
    if (begin >= end) {
        return;
    }
    int division = partition(ratings, begin, end, idxMap);
    quickSort(ratings, begin, division-1, idxMap);
    quickSort(ratings, division+1, end, idxMap);
}

int candy(vector<int> &ratings) {
    int size = ratings.size();
    if (size < 2) {
        return size;
    }
    vector<int> cpyR = ratings;
    map<int, int> idxMap;
    for (int i = 0; i < size; ++i) {
        idxMap[i] = i;
    }
    quickSort(cpyR, 0, size-1, idxMap);
    // below I should create another vector to store the num of candies, but to save space
    // I will use cpyR to store them
    int totalNum = 0;
    for (int i = 0; i < size; ++i) {
        int idx = idxMap[i];
        int leftV = 0;
        int rightV = 0;
        if (idx > 0 && ratings[idx] > ratings[idx-1]) {
            leftV = cpyR[idx-1];
        }
        if (idx < size - 1 && ratings[idx] > ratings[idx+1]) {
            rightV = cpyR[idx+1];
        }
        cpyR[idx] = leftV > rightV ? (leftV + 1) : (rightV + 1);
        totalNum += cpyR[idx];
    }
    return totalNum;
}

int main () {
    int a[] = {2,1,3,7,2,5,5,4,9};
    vector<int> ratings(a, a+sizeof(a)/sizeof(int));
    for (int i = 0; i < ratings.size(); ++i) {
        cout << ratings[i];
    }
    cout << endl;
    cout << candy(ratings) << endl;

    return 0;
}
