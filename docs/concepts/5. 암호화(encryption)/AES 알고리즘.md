## AES
- NSA에서 일급비밀 용으로 승인한 유일한 공개 암호화 알고리즘
- 현재 가장 널리 사용되는 대칭 키 알고리즘
	- 앞에서 든 WPA2 프로토콜의 일부로 사용되기도 함
- 블록 크기: 128비트
- 키 길이: 128, 192 비트 또는 256 비트
- 키 길이에 따라 평문을 암호문으로 변환하는 라운드 수가 다름
	- 128비트: 10라운드
	- 192비트: 12라운드
	- 256비트: 14라운드



## AES의 블록
- AES는 한 번에 16바이트씩 읽어서 암호화
- 16바이트를 다음과 같이 4 X 4 행렬로 배치
![](https://i.imgur.com/yKKL51N.png)
- 그 뒤 여러 처리 과정을 통해 암호화를 진행


