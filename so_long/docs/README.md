# so_long

## 구성 함수
- [x] so_long() : so_long 본 함수

- [x] map_init() : game_map 배열 만들고 초기화 시키는 함수
	- [x] open_map() : txt를 read로 읽어오는 함수
	- [x] check_wall_validate() : 읽어온 map의 width 유효성을 판단하는 함수
	- [x] copy_map() : 읽어온 txt를 map으로 copy하는 함수

- [x] check_map() : 초기화된 game_map의 유효성을 판단하는 함수
	- [x] check_wall() : map이 직사각형이며, 1로 둘러싸여 있는 지 확인
		- [x] 직사각형 확인 함수
		- [x] wall로 둘러싸여 있는 지 확인하는 함수
	- [x] check_component() : 출구, 아이템, 플레이어 숫자가 조건을 만족하는 지 확인
	- [x] check_route() : dfs를 활용하여 길이 되는 지 확인

- [x] key_handler : 키보드의 키를 누르면서 조작하는 함수
	- [x] ecs : 누르면 종료
	- [x] KEY_UP : 위로 이동
	- [x] KEY_DOWN : 아래로 이동
	- [x] KEY_LEFT : 왼쪽으로 이동
	- [x] KEY_RIGHT : 오른쪽으로 이동

- [x] handle_close_button() : close 버튼 클릭하여 프로그램 종료

- [ ] move_enemy : 적의 움직임을 담당하는 함수
	- [ ] random으로 음직이는 적 만들기
	- [ ] bfs로 움직이는 적 만들기

- [x] 이미지 파일 만들어서 띄우기