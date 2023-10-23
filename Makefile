LIB = ar rcs
NAME = libftgetnextline.a
BON = libftgetnextlinebonus.a
MY_SOURCES = get_next_line.c get_next_line_utils.c
MY_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_OBJECTS_BONUS = $(MY_BONUS:.c=.o)

CFLAGS += -Wall -Wextra -Werror

$(NAME): $(MY_OBJECTS) get_next_line.h
		$(LIB) $(NAME) $(MY_OBJECTS)

$(BON): $(MY_OBJECTS_BONUS) get_next_line.h
		$(LIB) $(BON) $(MY_OBJECTS_BONUS)

%.o: %.c
		gcc $(CFLAGS) -c -o $@ $<
		
all: $(NAME)

bonus: $(BON)

clean:
		rm -f $(MY_OBJECTS) $(MY_OBJECTS_BONUS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all, clean, fclean, re