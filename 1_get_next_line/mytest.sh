echo "BUFFER_SIZE = 1"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c
./a.out text_file
echo ""
echo "One huge line:"
./a.out oneliner
echo ""
echo "Multiple empty lines:"
./a.out emptylines
echo ""
echo "BUFFER_SIZE = 9"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=9 main.c get_next_line.c get_next_line_utils.c
./a.out text_file
echo ""
echo "BUFFER_SIZE = 10"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10 main.c get_next_line.c get_next_line_utils.c
./a.out text_file
echo ""
echo "BUFFER_SIZE = 11"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=11 main.c get_next_line.c get_next_line_utils.c
./a.out text_file
echo ""
echo "BUFFER_SIZE = 10000000"
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 main.c get_next_line.c get_next_line_utils.c
./a.out text_file
echo ""
echo "One huge line:"
./a.out oneliner
echo ""
echo "Multiple empty lines:"
./a.out emptylines
echo ""
echo "INVALID FD & STDIN:"
./a.out
