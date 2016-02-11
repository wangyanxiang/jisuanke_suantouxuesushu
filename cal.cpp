//原始有错版本，一旦得到正确的输出之后，found标志位就无法变回false，导致无法产生正确的结果
#include <bits/stdc++.h>
using namespace std;
int n; // 保存读入的整数N
bool opr[10]; // 可以用一个bool数组保存所有n-1个符号，我们用true表示加号"+"，用false表示减号"-"。
bool found = false; // 表示是否找到一组解，如果没找到的话需要在最后输出"None"
// dfs函数，保存两个状态：deep表示递归深度，就是枚举到第几个数字左边的符号；sum表示之前部分表达式的值。
// 如果枚举完成后sum的值刚好为0，则输出这组方案。我们需要在搜索的过程中用opr数组保存状态。
void dfs(int deep, int sum) {
    // 请在下面的条件表达式中填上对应的值。
    if (deep == n) {
        if (sum == 0) {
            found = true;
            // 请在下面将最终方案输出，方案格式参照题目描述。
            // 最后记得换行哦。
            printf("1");
            int i = 1;
            for(i = 1; i < n; i++){
                if (opr[i] == true)
                    printf("+");
                else
                    printf("-");
                printf("%d", i + 1);
            }
            printf("\n");
        }
        return ;
    }
    // 请在下面的语句中填出正确的逻辑。
    opr[deep] = true;
    dfs( deep + 1  , sum + deep + 1  );
    opr[deep] = false;
    dfs( deep + 1  , sum - deep - 1  );
}

// main函数请自己完成哦，加油~
int main() {
    while(scanf("%d", &n) == 1){
        if(n == 0){
            printf("NONE");
            return 0;
        }
	found = false;
        dfs(1, 1);
        if(found == false)
            printf("NONE");
    }
    return 0;
}
