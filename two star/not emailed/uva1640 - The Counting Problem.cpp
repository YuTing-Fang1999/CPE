//uva1640
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> i2v(int n) {
    vector<int> output;

    while (n != 0) {
        output.push_back(n % 10);
        n /= 10;
    }
    reverse(output.begin(), output.end());

    return output;
}

void solve(const int n, vector<int>& result) {
    vector<int> vec_num = i2v(n);
    int digits = vec_num.size();
    int power = pow(10, digits - 1);
	
    for (int i = 0; i < digits; i++) {
    	printf("i=%d\n", i);
        for (int j = 0; j < vec_num[i]; j++) {
        	printf("result[%d] add %d\n",j, power);
            result[j] += power;
        }
		printf("\n");
        for (int j = 0; j < 10; j++) {
        	printf("result[%d] add %d\n",j, power / 10 * (digits - i - 1) * vec_num[i]);
            result[j] += power / 10 * (digits - i - 1) * vec_num[i];
        }
		printf("\n");
        if (i + 1 < digits) {
        	printf("result[%d] add %d\n",vec_num[i], n % power);
            result[vec_num[i]] += n % power;
        }
        printf("\n");
        printf("result[%d] add %d\n",vec_num[i], 1);
        result[vec_num[i]]++;
        

        result[0] -= power;
        power /= 10;
    }
}

int main() {
    int a, b;
    vector<int> result_a(10, 0), result_b(10, 0);

    while (cin >> a >> b && a && b) {
        result_a.assign(10, 0);
        result_b.assign(10, 0);

        if (a > b) swap(a, b);

//        solve(a - 1, result_a);
        solve(b, result_b);
//
//        for (int i = 0; i < 9; i++) {
//            cout << result_b[i] - result_a[i] << " ";
//        }
//        cout << result_b[9] - result_a[9] << endl;
    }
    return 0;
}
