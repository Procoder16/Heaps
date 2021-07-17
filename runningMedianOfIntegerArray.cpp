#include<bits/stdc++.h>
using namespace std;

/*
    First of all remember that the question is about RUNNING MEDIAN and not RUNNING AVERAGE where you would just take the sum and divide 
    by the number of elements.
    So the naive idea could be:
        >> Taking inputs and adding it to the array and then maintain a variable that would count the size of the array being formed.
        >> Then for odd sized array and even sized array, put the formula and then calculate the median.
        >> So this would actually be a time and space consuming process.

    So, we would be using the priority_queue to help us with this question:
        >> We would create two heaps, a left max heap and a right min heap.
        >> We would take an element input and we will push it to the left heap.
        >> And assign the median variable with that element.
        >> Now run a loop for taking inputs and go until we are encountering -1 which denotes the end of inputs.
        >> Now, we will be having 3 cases which would further have subsequent cases.
            -> If the size of the left heap is greater than the size of the right heap and current element is less than the median
                > Push the top element of the left heap to the right heap
                > Then push the new element to the left heap
                > And the median would be the average of the two top elements.
            -> If the size of the left heap is greater than the size of the right heap and current element is greater than the median   
                > Then simply push the element to the right heap and the median would again be the average of the two.

            -> If the sizes of both the heaps are same, then just check for the condition and simply push it to any of the heaps 
               and the median would be that particular element.     

            -> If the size of the right heap is greater than the size of the left heap and current element is greater than the median
                > Push the top element of the right heap to the left heap
                > Then push the new element to the right heap
                > And the median would be the average of the two top elements.  
            -> If the size of the right heap is greater than the size of the left heap and current element is lesser than the median
                > Then simply push the element to the left heap and the median would again be the average of the two.       
*/

