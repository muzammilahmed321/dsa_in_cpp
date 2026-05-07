#include<iostream>
using namespace std;
struct Stop {
int location;
int change;
};
void swapStops(Stop &a, Stop &b){
Stop temp =a;
a=b;
b=temp;
}
int partition(Stop arr[], int low, int high){
int pivotValue=arr[high].location;
int i=low-1;
for(int j=low; j<high; j++){
if (arr[j].location <= pivotValue){
i++;
swapStops(arr[i], arr[j]);
}
}
swapStops(arr[i + 1], arr[high]);
return i + 1;
}
void quickSort(Stop arr[], int low, int high){
if(low < high){
int pivotIndex=partition(arr, low, high);
quickSort(arr, low, pivotIndex - 1);
quickSort(arr, pivotIndex + 1, high);
}
}
bool canCarPool(int trips[][3], int totalTrips, int capacity){
int totalStops = totalTrips * 2;
Stop *events = new Stop[totalStops];
int index = 0;
for(int i = 0; i < totalTrips; i++){
int numPassengers = trips[i][0];
int startPoint=trips[i][1];
int endPoint=trips[i][2];
events[index++]={startPoint, numPassengers};
events[index++]={endPoint, -numPassengers};
}
quickSort(events,0,totalStops-1);
int currentPassengers=0;
for(int i = 0; i < totalStops; i++){
currentPassengers+=events[i].change;
if(currentPassengers > capacity){
delete[] events;
return false;
}}
delete[] events;
return true;
}
int main(){
int trips1[2][3]={{1, 2, 4}, {2, 3, 6}};
int capacity1=4;
cout<< "1: Input: trips = [[1,2,4],[2,3,6]], capacity = 4, Output: ";
cout<<(canCarPool(trips1, 2, capacity1) ? "true" : "false")<<endl;
int trips2[2][3]={{1, 2, 4}, {2, 3, 6}};
int capacity2=5;
cout<<"2: Input: trips = [[1,2,4],[2,3,6]], capacity = 5, Output: ";
cout<<(canCarPool(trips2, 2, capacity2) ? "true" : "false")<<endl;
return 0;
}
