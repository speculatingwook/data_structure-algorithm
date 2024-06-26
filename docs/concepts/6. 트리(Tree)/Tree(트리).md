## Tree
- 매우 얼리 사용하는 자료구조 중 하나
- 나무(tree)의 계층적 구조를 표현


## Tree 관련 용어
- 노드(node): 실제로 저장하는 데이터
![|250](https://i.imgur.com/YJOol9I.png)

- 루트(root) 노드: 최상위에 위치한 데이터
	- 시작 노드
	- 모든 노드와 직간접적으로 연결됨
![|275](https://i.imgur.com/m3hKS0k.png)

- 리프(leaf) 노드: 마지막에 위치한 데이터들
	- 더 이상 가지를 치지 않음
![|213](https://i.imgur.com/09BgRmM.png)
- 부모-자식: 연결된 노드들 간의 상대적 관계
	- 자식은 없을 수도, 많이 있을 수도
	- 부모는 언제나 하나
	- 조무보/삼촌/형제자매 등도 있음

![|275](https://i.imgur.com/yZibagF.png)
- 깊이(depth): 노드 -> 루트 경로의 길이
- 높이(height) 노드 -> 리프 경로의 최대 길이

![|282](https://i.imgur.com/VTyOneW.png)

- 하위 트리(subtree): 어떤 노드 아래의 모든 것을 포함하는 트리
	- 재귀적: 하위 트리 그 자체가 트리




## 깊은 트리 복사 코드

```java
public static Node deepCopyTree(Node root) {
    if (root == null) {
        return null;
    }

    // 현재 노드 복사
    Node newNode = new Node(root.data);

    // 왼쪽 서브트리 복사
    newNode.left = deepCopyTree(root.left);

    // 오른쪽 서브트리 복사
    newNode.right = deepCopyTree(root.right);

    return newNode;
}
```


```cpp
Node* deepCopyTree(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // 현재 노드 복사
    Node* newNode = new Node(root->data);

    // 왼쪽 서브트리 복사
    newNode->left = deepCopyTree(root->left);

    // 오른쪽 서브트리 복사
    newNode->right = deepCopyTree(root->right);

    return newNode;
}
```


