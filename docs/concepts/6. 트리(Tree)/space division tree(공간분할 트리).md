## 여태까지 본 트리는 1차원 공간을 표현
![|275](https://i.imgur.com/AomIceh.png)
- 배열은 선(line)
- 선은 1차원 공간에 존재
- 하지만 실세계는 2D 혹은 3D
	- 사람의 눈은 2차원
		- 평면
		- x/y축(상하좌우)
		- 2차원 배열에 저장 가능
	- 세계는 3차원
		- 2차원 + 깊이
		- x/y/z 축
		- 3차원 배열에 저장 가능



## 쿼드 트리(quadtree)
- 사분 트리라고도 함
- 재귀적으로 2D 공간을 분할
- 각 노드가 4개의 자식을 가짐
	- 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래
	- 현재 노드를 4개의 하위 시각 영역으로 나눔
- 공간 분할 트리!



## 옥 트리(octree)
- 재귀적으로 3D 공간을 분할
- 각 노드가 8개의 자식을 가짐
	- 쿼드 트리의 4자식 x 앞 / 뒤
	- 현재 노드를 8개의 하위 상자로 나눔
- 3D 프로그램에 종종 사용
	- 마인크래프트 같은 게임
	- 글로벌 일루미네이션(전역 조명) 효과
	- 등

## 기타 공간분할 트리
- BSP(이진 공간 분할 트리, binary space partitioning)
- R 트리
- k-d 트리
- 등