#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll binarySearch(const vector<ll>& a, ll n, ll target) {
    ll low = 0, high = n-1;
    while(low <= high) {
        ll mid = low + (high-low)/2;
        if(a[mid] == target) return mid;
        else if(target > a[mid]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main() {
    vector<ll> a = {3, 4, 6, 7, 9, 12, 16, 17};
    ll target = 3;
    ll index = binarySearch(a, a.size(), target);
    cout << target << " found at index: " << index << "\n";
    return 0;
}