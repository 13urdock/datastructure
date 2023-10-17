#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void pre_order(vector<int> in, vector<int> post){
	if (in.empty()) return;
	int rootvalue = post.back();
	printf("%d ", post.back());
	post.pop_back();
	
	int idx;
	for (idx = 0; idx <= in.size(); idx++)
		if(in.at(idx) == post.back()) break;
	in.erase(in.begin()+idx-1);
	
	vector<int> in_left;
	vector<int> in_right;
	vector<int> post_left;
	vector<int> post_right;

	for (int i = 0; i <= in.size(); i++){
		if(idx < i){
			if (i == 0){
				in_left.push_back(0);
				post_left.push_back(0);
			}
			else{
				in_left.push_back(in.at(i));
				post_left.push_back(post.back());
			}
		}
		else{
			if (i == idx){
				in_left.push_back(0);
				post_left.push_back(0);
			}
			in_left.push_back(in.at(i));
			post_left.push_back(in.at(i));
		}
	}
	pre_order(in_left, post_left);
	pre_order(in_right, post_right);		
}

int main(){
	int nodes;
	vector<int> in;
	vector<int> post;
	scanf("%d ", &nodes);
	
	for(int i = 0; i <= nodes; i++){
		if(i == 0){
			in.push_back(0);
			continue;
		}	int j;
		scanf("%d", &j);
		in.push_back(j);
	}
	for(int i = 0; i <= nodes; i++){
		if(i == 0){
			post.push_back(0);
			continue;
		}
		int j;
		scanf("%d", &j);
		post.push_back(j);
	}
	pre_order(in, post);

	return 0;
}
