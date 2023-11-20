BUFFER_SIZE=1

cc ./main.c ./get_next_line.c ./get_next_line_utils.c -D BUFFER_SIZE=$BUFFER_SIZE ../../../libraries/lib.a && ./a.out && rm ./a.out