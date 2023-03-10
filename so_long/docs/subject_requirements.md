https://itch.io/game-assets/free/tag-sprites

# so_long
### External Functs
• open, close, read, write, malloc, free, perror, strerror, exit
• All functions of the math library (-lm compiler option, man man 3 math)
• All functions of the MiniLibX
• ft_printf and any equivalent YOU coded

Your program has to take as parameter a map description file ending with the .ber
extension.

### rules
The player’s goal is to collect every collectible present on the map, then escape 
chosing the shortest possible route.
• The W, A, S, and D keys must be used to move the main character.
• The player should be able to move in these 4 directions: up, down, left, right.
• The player should not be able to move into walls.
• At every move, the current number of movements must be displayed in the shell.
• You have to use a 2D view (top-down or profile).
• The game doesn’t have to be real time.
• Although the given examples show a dolphin theme, you can create the world you
want.

### graphic management
Your program has to display the image in a window.
• The management of your window must remain smooth (changing to another window, minimizing, and so forth).
• Pressing ESC must close the window and quit the program in a clean way.
• Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.
• The use of the images of the MiniLibX is mandatory.

### map
The map has to be constructed with 3 components: walls, collectibles, and free
space.
• The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.

The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.  
If the map contains a duplicates characters (exit/start), you should
display an error message.

• The map must be rectangular.
• The map must be closed/surrounded by walls. If it’s not, the program must return
an error.
• You have to check if there’s a valid path in the map.
• You must be able to parse any kind of map, as long as it respects the above rules.
• Another example of a minimal .ber map:
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
• If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return "Error\n" followed by an explicit error message of
your choice.

## bonus
• Make the player lose when they touch an enemy patrol.
• Add some sprite animation.
• Display the movement count directly on screen instead of writing it in the shell.

### mandatory
1. 맵이 직사각형 형태여야 한다.
2. 맵 테두리가 벽으로 이루어져야 한다.
3. 맵에 적어도 하나씩의 collectible, exit, player의 시작 위치가 있어야 한다.
4. collectible을 다 먹어야 player는 exit에 접근할 수 있고 그 후 게임을 끝낼 수 있어야 한다.

### bonus
1. 적에 닿으면 죽음
2. 적이 움직여야 함
3. 스크린에 카운트
4. 플레이어의 움직임이 연속성있어 보여야함