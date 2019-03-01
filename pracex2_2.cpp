#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] < x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	
	//Write your code here
	ofstream rank("rank.txt");
	ifstream score("score3.txt");
	string text;
	float order[20] = {};
	int i = 0,x[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	while (getline(score,text))
	{
		order[i] = atof(text.c_str());
		i++;
	}
	sort(order,20);
	for (int j = 1;j < 20;j++)
	{
		if (order[19-j] == order[20-j]) x[j] = x[j-1];
		else x[j] = j+1;
	}
	for (int k = 0;k < 20;k++)
	{
		rank << order[19-k] << "=" << x[k] << "\n";
	}
	return 0;
}

