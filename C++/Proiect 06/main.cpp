#include <iostream>
#include <algorithm> // for std::max and std::min
#include <cmath> // for std::ceil
#include <vector>
using namespace std;

int solution(int A[],int N) {
    int min_val = A[0];
    int max_val = A[0];
    for (int i = 1; i < N; i++) {
        min_val = std::min(min_val, A[i]);
        max_val = std::max(max_val, A[i]);
    }
    int lo = 1; // minimum possible board length
    int hi = max_val - min_val; // maximum possible board length
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int last_pos = min_val - 1; // last position covered by the first board
        int boards = 0; // number of boards needed to cover all holes
        for (int i = 0; i < N; i++) {
            if (A[i] > last_pos + mid) {
                // need another board to cover this hole
                last_pos = A[i-1];
                boards++;
            }
        }
        if (boards + 1 <= 2) {
            // can cover all holes with 2 boards of length mid or greater
            hi = mid;
        } else {
            // need more than 2 boards, increase the board length
            lo = mid + 1;
        }
    }
    return lo; // round up to the nearest integer if needed
}

int main(){
    int A[] = {0,44,32,30,42,18,34,16,35};
    int N = 4;
    cout<<solution(A,N);
    return 0;
}
