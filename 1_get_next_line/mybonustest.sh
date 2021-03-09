echo "BUFFER_SIZE = 1"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
./a.out text_file text_file2
echo ""
echo "BUFFER_SIZE = 42"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
./a.out text_file text_file2
echo ""
echo "BUFFER_SIZE = 10000000"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
./a.out text_file text_file2
echo ""
echo "STDIN:"
./a.out
