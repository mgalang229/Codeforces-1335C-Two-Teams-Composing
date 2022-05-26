#include <bits/stdc++.h>

using namespace std;

void test_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	int mx = INT_MIN;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	vector<int> counter(mx + 1, 0);
	for(int i = 0; i < n; i++) {
		counter[a[i]]++;
	}
	
	//for(int i = 0; i < mx + 1; i++) {
		//cout << i << " ";
	//}
	//cout << "\n";
	//for(int i = 0; i < mx + 1; i++) {
		//cout << counter[i] << " ";
	//}
	//cout << "\n\n";
	
	//test 1:
	//given: 5 5 6 7 4 4 4 4 4
	
	//others = 4
	//max_same = 5
	
	//if |others - max_same| > 0, 
	//then add 1 max_same element to the distinct
	
	//[5, 6, 7, 4] -> [4, 4, 4, 4]
	//answer = 4
	
	//test 2:
	//given: 5 5 6 7 4 4 4 4
	
	//others = 3
	//max_same = 4
	
	//[5, 6, 7] -> [4, 4, 4]
	//answer = 3
	
	int max_same = 0;
	int num = 0;
	for(int i = 0; i < mx + 1; i++) {
		if(counter[i] > max_same) { // max freq. of duplicate elements
			max_same = counter[i];
			num = i;
		}
	}
	int distinct = 0;
	for(int i = 0; i < mx + 1; i++) {
		if(counter[i] > 0) {
			distinct++;
		}
	}
	if(distinct == max_same) {
		cout << max_same - 1 << "\n";
		return;
	}
	cout << min(distinct, max_same) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	cin >> T;
	for(int tc = 0; tc < T; tc++) {
		test_case();
	}
}
