/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:07:34 by escura            #+#    #+#             */
/*   Updated: 2023/11/20 14:34:07 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include "../../../libraries/lib.h"

int main(void) {
    int fd = open("example.txt", O_RDONLY);

    yellow();
    printf("==========[ Buffer: %d ]==========\n\n",BUFFER_SIZE);
    reset();
    for(int i = 1; i <= 5; i++){
        char *line = get_next_line(fd);
        printf("%d. %s\n",i, line);
        free(line);
    }

    yellow();
    printf("\n==================================\n");
    close(fd);
    return 0;
}
