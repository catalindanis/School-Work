#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 
using namespace std;

//int solution(int A, int B) {
//    int count = 0;
//    for (int i = sqrt(A); i <= sqrt(B); i++) {
//        if (i * (i + 1) >= A && i * (i + 1) <= B)
//            count++;
//    }
//    return count;
//}

//int solution(vector<int>& A) {
//    if (A.size() == 1 || A.size() == 2)
//        return 1;
//
//}

int solution(std::vector<int> A) {
    if (A.size() == 1 || A.size() == 2)
        return 1;
    if (A.size() == 3) {
        int res1 = abs(A[0] - A[1]);
        int res2 = abs(A[1] - A[2]);
        int res3 = abs(A[2] - A[0]);
        return min(min(res1, res2), min(res2, res3));
    }
    sort(A.begin(), A.end());
    std::vector<int> results;
    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            int minDist = abs(A[i] - A[j]);
            int copy = minDist;
            bool secondBoard = false;
            bool isOK = true;
            int initialVal = A[0];
            for (int k = 0; k < A.size() - 1; k++) {
                minDist -= abs(A[k + 1] - A[k]);
                if (minDist < 0) {
                    if (secondBoard)
                        isOK = false;
                    else {
                        minDist = copy;
                        secondBoard = true;
                    }
                }
            }
            if (isOK)
                results.push_back(copy);
        }
    }
    
    if (results.size() > 0) {
        int minimumVal = results[0];
        for (int i = 1; i < results.size(); i++) {
            //cout << results[i] << ' ';
            if (results[i] < minimumVal)
                minimumVal = results[i];
        }
        return minimumVal;
    }
    return 0;
}

//int solution(std::vector<int>& A) {
//    std::sort(A.begin(), A.end()); // sort the array in ascending order
//    int max_distance = 0;
//    for (int i = 0; i < A.size(); i++) {
//        int distance = A[i] - A[i - 1];
//        if (distance > max_distance) {
//            max_distance = distance;
//        }
//    }
//    return std::ceil(max_distance / 2.0); // round up to the nearest integer
//}

//int solution(vector<int>& A) {
//    int sum[100001] = { 0 };
//    sum[0] = A[0];
//    for (int i = 1; i < A.size(); i++)
//        sum[i] = sum[i - 1] + A[i];
//    int c1 = 0;
//    bool primul = false;
//    bool ultimul = false;
//    for (int i = 1; i < A.size(); i++)
//        if (i == 1) {
//            if (sum[i] % 2 == 0) {
//                c1++;
//                i++;
//                primul = true;
//            }
//        }
//        else {
//            if ((sum[i] - sum[i - 2]) % 2 == 0) {
//                c1++;
//
//                if (i == A.size()-1)
//                    ultimul = true;
//
//                i++;
//            }
//        }
//    if (!ultimul && !primul)
//        if ((A[0] + A[A.size() - 1]) % 2 == 0)
//            c1++;
//    return c1;
//}

int main()
{
    vector<int> A{9};
    cout << solution(A);
}