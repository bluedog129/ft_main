# so_long

https://imagy.app/image-resizer/

## 구성 함수
- [x] so_long() : so_long 본 함수

--> 2/10일까지
- [x] map_init() : game_map 배열 만들고 초기화 시키는 함수
	- [x] open_map() : txt를 read로 읽어오는 함수
	- [x] check_wall_validate() : 읽어온 map의 width 유효성을 판단하는 함수
	- [x] copy_map() : 읽어온 txt를 map으로 copy하는 함수
--> 2/10일 완료! 

--> 2/11일까지
- [x] check_map() : 초기화된 game_map의 유효성을 판단하는 함수
	- [x] check_wall() : map이 직사각형이며, 1로 둘러싸여 있는 지 확인
		- [x] 직사각형 확인 함수
		- [x] wall로 둘러싸여 있는 지 확인하는 함수
	- [x] check_component() : 출구, 아이템, 플레이어 숫자가 조건을 만족하는 지 확인
	- [x] check_route() : dfs를 활용하여 길이 되는 지 확인
--> 2월 13일 완료! 

--> 2월 14일
- [ ] keyboard_controller : 키보드의 키를 누르면서 조작하는 함수
	- ecs : 누르면 종료
	- 방향키 위 : 위로 이동
	- 아래 : 아래로 이동
	- 왼 : 왼쪽으로 이동
	- 오 : 오른쪽으로 이동
- [ ] move_enemy : 적의 움직임을 담당하는 함수
	- random으로 음직이는 적 만들기
	- bfs로 움직이는 적 만들기
- [ ] 이미지 파일 만들어서 띄우기


- 스크린 카운트
- map 
- [ ] validate_ending() : 게임의 성공, 실패 여부를 확인하고 결정하는 함수
- [ ] player_controller() : 우선 플레이어의 동작 그리고 적, 아이템과의 상호작용을 담당하는 함수
- [ ] enemy_controller() : 적의 동작을 만드는 함수
