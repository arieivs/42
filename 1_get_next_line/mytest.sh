echo "BUFFER_SIZE = 1"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c
./a.out text_file
echo ""
echo "BUFFER_SIZE = 42"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
./a.out text_file
echo ""
echo "BUFFER_SIZE = 10000000"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 main.c get_next_line.c get_next_line_utils.c
./a.out text_file
echo ""
echo "STDIN:"
./a.out
