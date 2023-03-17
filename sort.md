# Sort

[TOC]



#### 冒泡排序（最大的排在後面）

- 每次將相鄰元素作比較，大的排後面
- 然後前後指針後移
- 所以每一輪的比較，最大的排好的數都會多一個

#### 選擇排序（找最小的排在前面） （不需頻繁兩兩交換）

- 每一輪找最小的排在前面

- 需要更新插入的位置

#### 插入排序（插撲克）（需頻繁兩兩交換）

- 將第一個元素看作是有序的
- 後面為排序的元素一個個往前挪比較

#### 希爾排序（用gap來分組使用插入排序）

[[演算法\] 希爾排序法(Shell Sort) (yehyeh.net)](http://notepad.yehyeh.net/Content/Algorithm/Sort/Shell/Shell.php)

- 每次用一個gap來分組，比較
- gap減為一半小，繼續比較；
- 循環上一步，一直到gap=1即可停止

#### 歸并排序（遞歸法） （難點）

- 遞歸分割數組
- 對數組進行排序
- 然後合并

#### 快速排序

選定基準值分割左中右序列，遞歸到下一層繼續選基準值

代碼分爲兩個操作：

1. partition，實現函數分區
2. quicksort，用於排序

```c++
//chatgpt
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot)
            --right;
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot)
            ++left;
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

void quicksort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quicksort(arr, left, p - 1); //處理左子序列
        quicksort(arr, p + 1, right); //處理右子序列
    }
}

```

