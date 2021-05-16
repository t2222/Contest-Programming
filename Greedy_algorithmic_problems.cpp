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
…….a) If the start time of this activity is greater than or equal to the finish time
of the previously selected activity then select this activity and print it.
In the following C implementation, it is assumed that the activities are already
sorted according to their finish time.
*/
void ActivitySelectionProblem(Activity listOfActivity[], int n)
{
	// sort
	bool isSwapped = false;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
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

int main()
{
	/*
	Activity listOfActivity[] = { {5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9} };
	int n = sizeof(listOfActivity) / sizeof(Activity);
	ActivitySelectionProblem(listOfActivity, n);
	*/

}