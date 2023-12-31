#include <iostream>
using namespace std;
void multil(int* a, int* b) {
	int c[1001] = { 0 };
	int temp[1001] = { 0 };
	//以a为基准
	for (int i = 2; i <= 2 * a[0]; i = i + 2) {
		//对a的每一项，遍历完整b的每一项
		//系数乘起来，加起来，存到c中。
		//进行第二遍之后的循环时，每次都要遍历一遍c，合并同类项，若无可合并，则放到最后。
		// （关于按指数降幂排列，可以等最后整理）		

		//第一次	
		if (i == 2) {
			for (int j = 2; j <= 2 * b[0]; j = j + 2) {
				c[j - 1] = a[i - 1] * b[j - 1]; //系数
				c[j] = a[j] * b[j]; //指数
			}
			c[0] = a[0];
		}
		else {
			//其后，每加一项，遍历c，合并同类项。
			for (int j = 2; j < 2 * b[0]; j = j + 2) {
				temp[j - 1] = a[i - 1] * b[j - 1]; //系数
				temp[j] = a[j] * b[j]; //指数
				// 遍历c
				for (int k = 2; k <= 2 * c[0]; k = k + 2) {
					if (temp[j] == c[k]) { //若有同类项，则合并
						c[k] = temp[j - 1] + c[k];
						break;
					}
					else if (k == 2 * c[0]) { //若无同类项，应放到c的最后
						c[0]++;
						c[k + 1] = temp[j - 1]; //系数
						c[k + 2] = temp[j]; //指数
					}

				}

			}
		}
	}

	// 最后，按降幂排列
	for (int l = 0; l < 2 * c[0] + 1; l++) {
		cout << c[l] << " ";
	}


}



int main() {

	// 多项式
	//1、 可以直接通过数组表示，靠奇偶区分系数与指数，加法、乘法的操作，通过对另一个数组的特定元素的查找与组合实现。
	// 重点在于写加法、乘法的规则。
	//
	//2、 通过链表？......表头是指示项数的，在进行加法和乘法操作时，其实同样用到遍历链表，依次比较，只是相比于数组更加直观。
	// 
	// 
	// 
	//3、是否可以定义多项式类？操作有加法、乘法，直接有s1+s2 = ; s1 * s2 = ;
	//   可以通过键入系数来初始化。两个核心，一个是多项式项数，一个是多项式本身。这样设置，比链表更合理。
	//   不过，多项式的实现，还是要依赖于链表。
	//


//多项式定义：
	int a[1001] = { 0 };
	int b[1001] = { 0 };
	int sum[1001] = { 0 };
	int prod[1001] = { 0 };
	//乘法:
	int t1[5] = { 2,1,1,1,0 };
	int t2[5] = { 2,1,1,-1,0 };
	for (int i = 0; i < 5; i++) {
		cout << t1[i] << endl;
	}

	multil(t1, t2);


	return 0;

	//加法


}


