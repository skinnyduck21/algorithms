#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll lowerBound(const vector<ll>& a, ll n, ll target) {
    ll low = 0, high = n-1, ans = n;
    while(low <= high) {
        ll mid = low + (high-low)/2;
        if(a[mid] >= target) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}
int main() {
    vector<ll> a = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    ll target = 9;
    ll index = lowerBound(a, a.size(), target);
    cout << "Lower Bound of " << target << " is: " << index << "\n";
    return 0;
}