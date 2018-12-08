#include "pch.h"
#include "Solution.h"


itype Solution::maxEnvelopes(vector<pair<itype, itype>>& envelopes)
{
	/*---------------先用基数排序--------*/
	if (envelopes.size() == 0)return 0;
	map<itype, queue< pair<itype, itype>>>bucket;
	map<itype, queue< pair<itype, itype>>>::iterator Ite;
	//对second先排序
	for (int j = 0; j < envelopes.size(); j++) {
		bucket[envelopes[j].second].push(envelopes[j]);//

	}
	envelopes.clear();
	for (Ite = bucket.begin(); Ite != bucket.end(); Ite++) {
		while (!Ite->second.empty()) {
			envelopes.push_back(Ite->second.front());
			Ite->second.pop();
		}
	}
	//再对first排序
	for (int j = 0; j < envelopes.size(); j++) {
		bucket[envelopes[j].first].push(envelopes[j]);//

	}
	envelopes.clear();
	for (Ite = bucket.begin(); Ite != bucket.end(); Ite++) {
		while (!Ite->second.empty()) {
			envelopes.push_back(Ite->second.front());
			Ite->second.pop();
		}
	}

#ifdef COUT
	//输出
	for (int i = 0; i < envelopes.size(); i++) {

		cout << "[" << envelopes[i].first << "," << envelopes[i].second << "] ";
	}
	cout << endl;

#endif // COUT

	

	/*----------------DP开始------------*/

	this->n = envelopes.size();

	//prev构造
	prevs.resize(n);// -1的意思是不存在，当然也可以多一个元素的数组完成
	prevs[0] = {-1};
	for (int i = 1; i < n; i++) {
		prevs[i] = { -1 };

		for (int j = i; j >=0; j--) {
			if (envelopes[j].first < envelopes[i].first
				&&envelopes[j].second < envelopes[i].second) {
				prevs[i].push_back(j);//如果i之前的j能被i装下,记录下来
			}
		
		}
		
	}

#ifdef DEBUG
	cout << endl;
	for (int i = 0; i < prevs.size(); i++) {
		for (int j = 0; j < prevs[i].size(); j++) {
			cout << prevs[i][j] << " ";
		}
		cout << endl;

	}
#endif // DEBUG

	
	//opt_arr
	opt_arr.resize(n, 1);
	for (int i = 0; i < n; i++) {
		if (prevs[i].size() == 1) {
			opt_arr[i] = 1;
			continue;
		}
		else {
		
			opt_arr[i] = maxopt(prevs[i])+1;
		}

		
	}
	//出输出
#ifdef DEBUG

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << opt_arr[i] << " ";
	}cout << endl;
#endif // DEBUG



	return *max_element(opt_arr.begin(),opt_arr.end());
	
}


