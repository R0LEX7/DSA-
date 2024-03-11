#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){

	cout<<"hello world";	

	vector<int> arr = {2,1,4,9};

	int prev2 = 0 ;
	int prev = arr[0];

	for(int i = 1 ; i < arr.size() ; i++){
		int take = arr[i];
		if(i>1){
			take += prev2;
		}
		int notTake = prev;
		
		int curr = max(take , notTake);

		prev2 = prev;
		prev = curr;
	}

	cout << prev <<endl;
	return 0;
}