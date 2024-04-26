#include<iostream> 
using namespace std;

int a[100];
int minn, maxx;

void MaxMinAlgo(int x, int y) {
    int max1, min1, mid;
    if (x == y)
	 {
        minn = maxx = a[x];
    } 
	else if (x == y - 1) 
	{
        if (a[x] < a[y])
		 {
            maxx = a[y];
            minn = a[x];
        } else 
		{
            maxx = a[x];
            minn = a[y];
        }
    } else
	 {
        mid = (x + y) / 2;
        MaxMinAlgo(x, mid);
        min1 = minn;
        max1 = maxx;
        MaxMinAlgo(mid + 1, y);
        if (maxx < max1) {
            maxx = max1;
        }
        if (minn > min1) {
            minn = min1;
        }
    }
}

int main() {
    int n, i;
    cout << "Enter array size:" << endl;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    minn = a[1];
    maxx = a[1];
    MaxMinAlgo(1, n);
    cout << "Minimum element in array is: " << minn << endl;
    cout << "Maximum element in array is: " << maxx << endl;
    return 0;
}
