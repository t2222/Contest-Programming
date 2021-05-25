#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring> // needed for memsets
#include<cstdio>
#include <cmath>
#include<stack>
#include<utility> // needed for pair
#include<queue>
#include<set>
#include<map>
#include<set>
#include<numeric> // used accumulate
#include <bitset>

#define MAX 1000

using namespace std;

typedef long long int lld;
typedef long double llf;
typedef unsigned long long int ulld;

using namespace std;

struct Activity
{
	int start;
	int finish;
};
/*
1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do the following for the remaining activities in the sorted array.
��.a) If the start time of this activity is greater than or equal to the finish time
of the previously selected activity then select this activity and print it.
In the following C implementation, it is assumed that the activities are already
sorted according to their finish time.
*/
void ActivitySelectionProblem(Activity listOfActivity[], int n)
{
	// sort

	for (int i = 0; i < n - 1; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < n - i - 1; j++) // Last i elements are already in place
		{
			if (listOfActivity[i].finish > listOfActivity[i + 1].finish)
			{
				Activity temp = listOfActivity[i];
				listOfActivity[i] = listOfActivity[i + 1];
				listOfActivity[i + 1] = temp;
				isSwapped = true;
			}
		}

		if (isSwapped == false) // no element has been swapped so array is sorted
		{
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << "(" << listOfActivity[i].start << "," << listOfActivity[i].finish << "), ";
	}
	cout << "\n";

	int totalActivity = 0;
	int i = 0;
	cout << "activities: " << "(" << listOfActivity[0].start << "," << listOfActivity[0].finish << "), ";
	++totalActivity;
	for (int j = 1; j < n; j++)
	{
		if (listOfActivity[j].start >= listOfActivity[i].finish)
		{
			cout << "(" << listOfActivity[j].start << "," << listOfActivity[j].finish << "), ";
			++totalActivity;
			i = j;
		}
	}
	cout << "\n" << totalActivity << endl;


}

struct KnapsackItem
{
	float weight;
	float value;
	KnapsackItem(float value, float weight)
	{
		this->value = value;
		this->weight = weight;
	}
};
void fractionKnapsack(KnapsackItem knapsackItems[], int n, float tw)
{
	// sort
	for (int i = 0; i < n - 1; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			float ratio1 = knapsackItems[j].weight / knapsackItems[j].value;
			float ratio2 = knapsackItems[j + 1].weight / knapsackItems[j + 1].value;
			if (ratio1 > ratio2)
			{
				KnapsackItem temp = knapsackItems[j + 1];
				knapsackItems[j + 1] = knapsackItems[j];
				knapsackItems[j] = temp;
				isSwapped = true;
			}
		}
		if (isSwapped == false)
		{
			break;
		}
	}

	/*for (int i = 0; i < n; i++)
	{
		cout << knapsackItems[i].value << " " << knapsackItems[i].weight << endl;
	}*/

	float currentWeight = 0; // current wweight in knapsack
	float valSum = 0; // current sum of values in knapsack
	for (int i = 0; i < n; i++)
	{
		if (knapsackItems[i].weight + currentWeight <= tw) // if adding current item don't overflows the tw, add it completely
		{
			currentWeight += knapsackItems[i].weight;
			valSum += knapsackItems[i].value;
		}
		else // otherwise add fractional part of it
		{
			int remain = tw - currentWeight;
			if (remain > 0)
			{
				valSum += knapsackItems[i].value * (remain / knapsackItems[i].weight);
				currentWeight += remain;
				break;
			}
		}
	}

	cout << valSum << " " << currentWeight << endl;

}

void coinChangeGreedy(int amount, int currency[], int n)
{
	// sort
	for (int i = 0; i < n - 1; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (currency[j] > currency[j + 1])
			{
				swap(currency[j], currency[j + 1]);
				isSwapped = true;
			}
		}
		if (isSwapped == false)     // if no two elements were swapped by inner loop, then break
			break;
	}

	vector<int> ans;
	// change coin
	for (int i = n - 1; i >= 0; i--)
	{
		while (amount >= currency[i])
		{
			amount -= currency[i];
			ans.push_back(currency[i]);
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

}

struct Job
{
	char id;
	int deadline;
	int profit;
	Job(char id, int dead, int profit)
	{
		this->id = id;
		this->deadline = dead;
		this->profit = profit;
	}
};
bool comparator(Job j1, Job j2)
{
	return j1.profit > j2.profit;
}
/*
1) Sort all jobs in decreasing order of profit.
2) Iterate on jobs in decreasing order of profit.For each job , do the following :
For each job find an empty time slot from deadline to 0. If found empty
slot put the job in the slot and mark this slot filled.
*/
void jobSequencingGreedy(Job joblist[], int n)
{
	sort(joblist, joblist + n, comparator); // sort in decreasing order
	for (int i = 0; i < n; i++)
	{
		cout << joblist[i].id << " " << joblist[i].deadline << " " << joblist[i].profit << endl;
	}


	const int SIZE = 20;
	bool slot[SIZE];
	int sequenced_jobs[SIZE];
	memset(slot, false, sizeof(bool) * SIZE);

	for (int i = 0; i < n; i++) // go through the joblist
	{
		for (int j = min(n, joblist[i].deadline) - 1; j >= 0; j--) // start putting jobs from the end so that if a high profitted job with low deadline appears, it can be allocated
		{
			if (slot[j] == false) // if slot is empty add jobs to slot and sequenced_jobs array and break
			{
				slot[j] = true;
				sequenced_jobs[j] = i;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (slot[i] == true)
			cout << joblist[sequenced_jobs[i]].id << " ";
	}
}

int main()
{
	/*
	Activity listOfActivity[] = { {5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9} };
	int n = sizeof(listOfActivity) / sizeof(Activity);
	ActivitySelectionProblem(listOfActivity, n);
	*/

	/*
	int W = 50; //    Weight of knapsack
	KnapsackItem arr[] = { { 120, 30 }, { 60, 10 }, { 100, 20 },  { 100, 20 }, {220,55}, {44,21}, {10000,41} };
	//KnapsackItem arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	fractionKnapsack(arr, n, W);
	*/

	/*
	int val = 93;
	int currency[] = { 1000, 100, 500, 5, 50, 10, 20, 1, 2};
	int n = sizeof(currency) / sizeof(int);
	coinChangeGreedy(val,currency,n);
	*/

	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
				   {'d', 1, 25}, {'e', 3, 15} };
	int n = sizeof(arr) / sizeof(arr[0]);
	jobSequencingGreedy(arr, n);
}
