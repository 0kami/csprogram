# cs program
历年考研复试上机题练习 <br>
跟着王道的书练习一下历年的题目

## 总结

1. 排序

    c++ 
        include<algorithm> <br>
        使用sort函数 eg. sort(data,data+n)  data为数组 <br>
        若遇到非常见类型的sort，如自定义的struct、class等，采用2中方法 <br>

        1. 编写cmp函数,`sort(xx,xx+n,cmp)`; <br>

        cmp return true时不改变位置(不确定时可以先写一下，看看排序后的次序)

        2. 重载算符

        给自定义类型加上比较运算<br>
        `bool operator<opt>(xxx)`
    常见排序方法掌握<br>
        冒泡 n^2 注意第一个for循环到n <br>
                    第二个for循环到n-1-i <br>
                    前后交换<br>
        快排 n*log2n 填坑法 左i右j<br> 具体看非递归快排
        ```
                while(i<j&&d[j]>pos)j--;
                d[i]=d[j];
                while(i<j&&d[i]<pos)i++;
                d[j]=d[i];
        ```
            递归分割<br>

2. c++有用的数据类型

    map，queue，stack，vector <br>
    map初试化 `map<string,int> xx={{xx,1},{xx2,2}}` <br>
    queue 默认大根堆  <br>
        小根堆 <br>

        ```
        priority_queue<int, vector<int>, std::greater<int> > q;
        q.top() 获取最小值
        ```

        可用于哈夫曼建树<br> 
    stack解决表达式求值 左右括号 或者消除注释
3. 数学问题
    数位拆解 char类型-‘0’技巧
    最大公约数gcd 除变被除 余变除 被除为0 则结束 a为最大公约数

    ```
        while (b > 0){
			r = a%b;
			a = b;
			b = r;
		}
        ```

    最小公倍数 <br>
        求两者最大公约数，`a*b/gcd(a,b)`<br>
    素数筛法<br>
        普通  从2到sqrt(a)+1,取余为0则非素数<br>
        筛法  申请一个大空间数组(bool)，n从2开始 对n的倍数置false， 剩余的true全是素数<br>
    分解素因数<br>
    二分求幂（还没掌握T^T）<br>
    大整数运算(注意进位)可以用vector来存数字<br>
        进位可以直接就求出来，或者是先求完所有数位后统一进位（这个方法可以减少编写代码时候的思路）<br>
        
4. 图论
    并查集 用来判断是否属于统一集合或是否成环<br>

    ```
    city初始化为-1，表示到根了
    int findRoot(int a){
        if (city[a] == -1)return a;
        else{
            int tmp = findRoot(city[a]);
            city[a] = tmp;//将a的根换成tmp
            return tmp;
        }
    }
    ```

    最小生成树 <br>
        primes 初始化一个集合，每次选择从该集合到其他点最近的一条边，并将新加的边的终点加入集合 O(V^2)<br>
        kruskal 边排序，从小到大，每次选择不是同一集合的（不能成环，用并查集）O(E^2)<br>
    最短路径<br>
        dijkstra  类似primes，但在选择边上，选择的是当前该点到其他点的最短距离，这些距离通过<br>
        `dist[k]>dist[j]+arsc[j][k]`更新  以j为中间点 O(V^2)<br>
        Floyd <br>
    拓扑排序 层次遍历，入度为0的点入队，依次遍历<br>

5. 搜索

    暴力<br>
    BFS 层次遍历 多元组的状态枚举<br>
    递归  归纳<br>
    DFS<br>

<br>
    最小生成树能够保证整个拓扑图的所有路径之和最小，但不能保证任意两点之间是最短路径。<br>
    最短路径是从一点出发，到达目的地的路径最小。<br>

6. STL

    string  字符串查找 删除<br>
            find erase<br>
    
    ```
    while (getline(cin,line)){//接受string流 cin.getline 字符流　允许空格
    ```

if(a%2==1) 等同于 if(a&1==1) <br>
a /= 2 等同于 a >>= 1 <br>
a *= 2 等同于 a <<= 1 <br>