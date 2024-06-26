## 그래프란?
- 데이터(노드)를 잘 정리하는(노드 간의 관계를) 방법중 하나


## 그래프의 정의와 용도
- 데이터들과 그 관계를 보여주는 방법 중 하나
- 서로 연관 있는 노드의 집합
$$G = (N, E)$$
- 네트워크 형태의 관계를 보여주기에 적합
- 복잡한 실세계의 문제를 모델링하기에 적절
	- 네트워크 형태가 명백하게 안 보이는 경우도 있음
	- 그래프 이론을 적절히 활용하면 시간복잡도를 확연히 줄일 수도 있음

### 그래프 관련 용어
- 노드(정점, 꼭짓점)
- 변(간선, 선)
- 차수(degree) - 연결된 선의 개수
- 루프(loop)

### 그래프의 종류
- 방향/무방향(directed/undirected) 그래프
- 순환/비순환(cyclic/acyclic) 그래프
- 가중/비가중(weighted/unweighted) 그래프


## 방향 vs 무방향 그래프
![|218](https://i.imgur.com/syirIqV.png)

- 방향 그래프
	- 변이 한 방향만 가리킴
	- 꼬리 -> 머리로 이동은 불가능
	- 머리 -> 꼬리로 이동은 불가능
- 무방향 그래프
	- 변에 특별한 방향이 없음
	- 따라서 양방향을 가리키는 것과 같음
	- 꼬리 -> 머리, 머리 -> 꼬리 모두 가능

### 무방향 그래프의 최대 변 개수
- 모든 노드가 연결되어 있는 경우
	- 단, 평행 변이나 루프는 없음
- 첫 번째 노드의 변: $N -1$ 개
- 두 번째 노드의 변: $N - 2$ 개 (중복된 것을 다시 세지 않음)
- 세 번째 노드의 변: $N - 3$ 개
$$\sum_{k=0}^{n-1} k = \frac{n(n-1)}{2}$$

## 순환 vs 비순환 그래프
![|275](https://i.imgur.com/E12oxnd.png)

- 비순환 그래프
	- 일단 떠나면 그 노드로 돌아오는 경로가 없음
	- 그래프 안의 모든 노드에 대해
- 순환 그래프
	- 떠난 뒤에도 그 노드로 돌아오는 경로가 있음
	- 그런 노드가 하나만 있어도 순환 그래프


## 가중 vs 비가중 그래프
![|325](https://i.imgur.com/bgMhASD.png)

- 비가중 그래프
	- 모든 변이 동일한 의미를 가짐
	- 각 변의 값이 같음
	- 별도의 표기 불필요
- 가중 그래프
	- 각 변의 관계 정도가 다름 (예: 거리, 시간)
	- 각 변의 값이 다름

### 방향 비순환 그래프(DAG) 예
![|475](https://i.imgur.com/clqW40e.png)

### 방향 가중 그래프 예
![|300](https://i.imgur.com/Bxkv8Ko.png)

### 그래프를 사용해 풀 수 있는 문제들
- 여러 스케줄링 관련
- 두 위치 사이의 여행 경로 관련
- 분자를 구성하는 원자들의 결합 관련
- 인터넷에서 데이터 패킷이 전달되는 경로 관련
- 대규모 프로젝트에서 일감 사이의 의존성 관련
- 도시의 전기 공급 그리드 관련
- SNS에서 친구 솬계 관련

## 그래프의 다양한 표현 방법
### 1. 원과 선
- 사람이 가장 이해하기 쉬운 표현법
	- 한눈에 그래프를 파악 가능
	- 단, 노드와 변의 수가 적당해야 함
- 굳이 코드로 표현하면 트리와 비슷한 구조
```java
public class Node {
	public int data;
	public ArrayList<Node> neighbors = new ArrayList<>();
}
```
- 하지만 대규모 데이터 처리에 적합한 표현법은 아님

### 2. 인접 행렬(adjacency matrix)
- N x N 행렬
	- `G[N][N]`
	- N: 그래프 G 안에 있는 노드 수
- 서로 인접한 노드를 표현
	- 인접: 두 노드 사이를 연결하는 변이 있음
	- i에서 j로 향하는 변이 있다면 `G[i][j] = 1`
	- 없으면 `G[i][j] = 0`
- G가 가중 그래프이면 0/1 대신 실제 가중치를 저장

#### 예시 - 인접행렬 무방향
![|173](https://i.imgur.com/JPLcb2t.png)

#### 예시 - 인접행렬 방향
![|350](https://i.imgur.com/lKSkYCY.png)

#### 인접 행렬의 장단점

| 장점                                                              | 단점                                                    |
| --------------------------------------------------------------- | ----------------------------------------------------- |
| • (일단 알면) 쉽게 구현 가능                                              | • 공간을 더 차지함 O(N^2)                                    |
| • 변 제거의 시간 복잡도가 O(1)                                            | • 언제나 같은 공간을 차지 <br> ▷ 연결된 노드가 망아도 <br> ▷ 연결된 노드가 적어도 |
| • 다음과 같은 관계를 효율적으로 찾음 <br> ▷ 노드 a에서 b로 가는 법이 존재하는가? <br> ▷ O(1) | • 인접 행렬을 만드는 시간은 O(N^2) <br> • 인접 노드를 찾는 시간은 O(N)     |
### 3. 인접 리스트(adjacency list)
-  각 노드마다 이웃의 리스트를 만듦
	- 리스트 N개
	- 보통 연결 리스트 N 개를 배열에 저장
	- 연결 리스트 대신 다른 자료구조도 사용 가능
- 원과 선을 굳이 코드로 구현한 것과 큰 차이 없음(...)

#### 인접리스트의 장단점
| 장점                                                                                     | 단점                                                              |
| -------------------------------------------------------------------------------------- | --------------------------------------------------------------- |
| - 공간을 적게 사용<br>    - O(N + E)<br>    - 최악: O(N^2) = $O(N^2) = O(N + \frac{N(N-1)}{2}$) | - 다음과 같은 관계를 찾는 게 느림<br>- 노드 a에서 b로 가는 변이 존재하는가?<br>- O(1)보다 느림 |
| - 삽입/삭제가 빠름<br>    - 연결 리스트를 사용했을 경우                                                   |                                                                 |

