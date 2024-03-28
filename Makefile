NAME = philo

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -pthread

SRC_DIR = ./src/
SRC = main.c init_philos.c init_params.c utils.c thread_utils.c run_philo.c monitoring.c
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

HEADER = ./inc/philo.h

all : $(NAME)

$(NAME) : $(SRC_FILES) $(HEADER)
	$(CC) $(CFLAGS) $(SRC_FILES) -I $(HEADER) -o $(NAME)

clean : 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
