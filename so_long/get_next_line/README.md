# get_next_line

## 변수
- buffer : read로 받아온 녀셕을 바로 저장할 변수
- save : static변수 (\n 이후에 오는 문자열들을 담아둘거예요!)
	- (보너스의 save는 각 버퍼가 담길 공간을 OPEN_MAX크기 만큼 만들어준다)
- result : return할 변수

## 작동 방식
- [x] save가 NULL이라면 read()에서 받아온 문자열 주소값을 buffer변수에 담아둔다
- [x] save가 NULL이 아니라면 buffer에 옮겨야 함
	- [x] 다시 호출했을 때 NULL이 아니라면 이전의 값이 있다는건데, 여기에 개행이나 널이 있을수도 있는 가능성을 고려!
	- [x] 처음에 save값을 buffer로 옮기고 NULL로 바꾸는 작업
- [x] buffer안에 개행 또는 널 문자가 있는 경우
	- [x] buffer에서 개행 또는 널문자까지 result 뒤에 붙여놓고
		- [x] index 만큼 result에 넣는다
	- [x] save 할당
	- [x] 나머지 문자들은 save에 저장
		- [x] [index + 1] ~ [BUFFER_SIZE - 1] 만큼 save에 넣는다
	- [x] result를 return
- [x] 없는 경우
	- [x] buffer 전체를 result뒤에 붙여 놓고
	- [x] 다시 read함수를 호출해서 새로운 버퍼를 받아온다.

## 예외: 오류 NULL
- [x] read가 실패하는 경우: -1리턴 0이면 eof 
- [x] fd에서 < return
- [x] fd 값이 적절하지 않은 경우 

## 함수
- gnl 본함수
- '\n'의 인덱스를 찾을 함수 -> strchr
- result 뒤에 buffer의 남은 부분을 붙일 함수-> join
- buffer에서 개행까지는 떼어낼 함수 -> cat