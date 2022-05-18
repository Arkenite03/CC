//By N Purushotam Kumar; 3330; TE-COMP A T2
//Assignment 2 Job Scheduling
#include <bits/stdc++.h>
using namespace std;

struct Job {
  char id; // Job Id
  int dead; // Deadline of job
  int profit;
};

bool comparison(Job a, Job b) {
  return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n){
	
  sort(arr, arr + n, comparison);
  int result[n]; // To store result (Sequence of jobs)
  bool slot[n]; // To keep track of free time slots
  
  for (int i = 0; i < n; i++)
    slot[i] = false;

  
  for (int i = 0; i < n; i++) {
    for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
      // Free slot found
      if (slot[j] == false) {
        result[j] = i; // Add this job to result
        slot[j] = true; // Make this slot occupied
        break;
      }
    }
  }
  
  for (int i = 0; i < n; i++)
    if (slot[i])
      cout << arr[result[i]].id << " ";
      
}

int main() {
    cout<<"Enter count of jobs\n";
    int n;cin>>n;
    Job arr[n];
    cout<<"Enter job id, deadline and profit for "<<n<<" jobs :\n";
    for(int i=0;i<n;i++){
        Job x;
        cin>>x.id;
        cin>>x.dead;
        cin>>x.profit;
        arr[i] = x;
    }
    cout << "Following is maximum profit sequence of jobs :\n";
    printJobScheduling(arr, n);
    cout<<endl;
    return 0;
}
/*Enter the number of Jobs : 6
Enter the Job id, Deadline and Profit for all jobs --> 
0 1 5
1 2 10
2 3 100
3 3 50
4 4 200
5 4 250
6 5 50
*/