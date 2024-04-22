// Program below illustrates the
// vector::insert() function
  
#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    // initialising the vector
    vector<int> vec = { 10, 20, 70, 80 };
    int x = 50;
  
    // inserting multiple elements
    // at specific positions
    vec.insert(vec.begin() + 2, { 30, 40, x, 60 });
  
    cout << "The vector elements are: ";
    for (auto it : vec)
        cout << it << " ";
  
    return 0;
}