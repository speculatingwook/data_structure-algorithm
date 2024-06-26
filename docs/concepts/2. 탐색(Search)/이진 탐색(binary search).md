
## 작동 방법

1. 가운데 위치를 확인
 ![](https://i.imgur.com/weq4Ofj.png)


 2. 가운데 값과 찾으려는 값을 비교
![](https://i.imgur.com/1XO9wAa.png)



3. 다시 가운데 위치를 확인



4. 비교 후 다시 정함
![](/docs/images/binary_search_4.png)



## 이진 탐색의 시간 복잡도

$O(log n)$ 

- 한 단계 거쳐갈수록 탐색의 범위가 2배씩 줄어듬


## 이진 탐색 알고리즘
- **정렬된 배열**에서 어떤 값의 위치를 찾는 알고리즘
- 한 단계 진행할 때마다 탐색범위를 절반으로 줄임
	- 이진(binary)이라는 이름이 탄생한 이유
- 분할 정복(divide-and-conquer) 알고리즘중 하나
	- 정복이라 하기에는 모든 문제 영역을 방문하지 않음
	- 따라서 decrease-and-conquer라고 부르자는 소수설도 있음
- 재귀함수로 쉽게 작성 가능


#### 재귀함수의 경우

- JAVA
```java
public static int binarySearchRecursive(int nums[], int l, int r, int value){
	if(l > r){
		return -1;
	}
	int m = (l + r) / 2;
	if(nums[m] == value){
		return m;
	}
	if(nums[m] < value){
		return binarySearchRecursive(nums, m + 1, r, value);
	}
	if(nums[m] > value){
		return binarySearchRecursive(nums, l, m - 1, value);
	}
	return -1;
}
```

- C
```c
/*
	- `a[]`: 정렬된 배열
	- `n`: 배열의 크기
	- `x`: 찾고자 하는 값
*/
int search(int a[], int n, int x){
	if (n==0) return -1;
	m = n / 2;
	if (x==a[m]) return m;
	else if (x<a[m]) return search(a, m, x);
	else { 
		r = search(a + m + 1, n - m - 1, x);
		if (r==-1) return -1;
		else return r + m + 1;
	}
}

// C 스타일의 수도 코드
int search(int a[], int n, int x){
	if (n == 0) return -1;
	m = n / 2;
	if (x==a[m]) return 1;
	else if (x<a[m]) return search(a, m , x);
	else { return search(a + m + 1, n - m - 1, x);
	}

}
```

#### 재귀함수가 아닌 경우
- C
```c
int search(int a[], int n, int x) {
	int l, r, m;
	l = 0; r = n - 1;
	while (l <= r) {
		m = (l + r) / 2
		if(a[m] < x)
			l = m + 1;
		else if (a[m] < x)
			r = m - 1;
		else // same
			return m;
	}
	return -1;
}

/* 
- r-l 이 계속 줄어든다.
- 그러므로 프로그램은 끝난다.
*/
```

## 정렬된 데이터와 알고리즘
- 정렬된 데이터에 사용할 수 있는 효율적인 알고리즘들이 많음
	- 어떤 값의 위치 찾기: $O(log n)$
	- 최솟값/최댓값 찾기: $O(1)$
- 정렬되지 않은 배열은?
	- 정렬 알고리즘을 사용하여 정렬 가능
	- 일단 정렬하면 효율적인 알고리즘 사용 가능
	- 하지만 배열에 새 요소를 추가하면 다시 정렬해야 함
		- 배보다 배꼽이 더 커질 수도 있음
		- 정렬 알고리즘이 이진탐색 알고리즘보다 시간 복잡도가 높음



## 정렬 후 이진탐색 vs 선형 탐색

| 배열이 안 바뀌는 경우                                                           | 배열이 바뀌는 경우                                                                                                                                                                                                    |
| ---------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| • 탐색할 일이 많은 경우<br>  ▸ 정렬 한 번 후, 이진 탐색 여러 번<br>  ▸ O(정렬) + O(log n) × x | • 요소를 삽입하는 경우만 문제<br>• 보통 선형 탐색을 사용<br>• 이진 탐색을 사용하려면?<br>  ▸ 탐색 전에 배열을 정렬해야 함<br>    • 배열이 바뀔 때마다 곧바로<br>    • 배열이 바뀐 적이 있다면 탐색 직전에<br>  ▸ 선형 탐색보다 느릴 수 있음<br>    • 탐색과 배열 변경 빈도에 따라<br>    • 탐색 빈도가 높을수록 유리 |
| • 탐색을 한 번만 할 경우<br>  ▸ 선형 탐색<br>  ▸ O(n)                               |                                                                                                                                                                                                               |



## 회전된 배열에서의 검색

```java
public class Program{
	public static void main(String[] args){
		int[] arry = new int[]{20, 25, 26, 29, 33, 1, 3, 5, 6, 10, 11, 19};
		
		int index = indexOfRotatedArray(arry, 0, arry.length - 1, 0);
		
	}
	
	
	private static int indexOfRotatedArray(int[] arry, int start, int end, int num){
		if(start > end){
			return -1;
		}
		
		int mid = (start + end) / 2;
		if(arry[mid] == num){
			return mid;
		}
		// start부터 mid까지 있는 숫자들이 정렬된 경우
		if(arry[start] <= arry[mid]){
			// num이 start와 mid 사이에 있는 경우
			if(num >= arry[start] && num <= arry[mid]){
				return indexOfRotatedArray(arry, start, mid -1, num);
			}
			return indexOfRotatedArray(arry, mid + 1, end, num);
		}
		// mid부터 end까지에 있는 숫자들이 정렬된 경우 && 그 사이에 num이 있는 경우
		if(num >= arry[mid] && num <= arry[end]) {
			return indexOfRotatedArrary(arry, mid + 1, end, num);
		}
		return indexOfRotatedArrary(arry, start, mid - 1, num);
	}
}
```

