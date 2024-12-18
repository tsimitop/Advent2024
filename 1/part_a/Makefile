################################################################################
#									CONSTANTS								   #
################################################################################
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a

NAME = ex

################################################################################
#									MAIN PART								   #
################################################################################

LIBFT_PATH = ./Libft
LIBFT = $(LIBFT_PATH)/libft.a
SRCS =	main.c
OBJS = $(SRCS:.c=.o)

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)
# $(CC) $(CFLAGS) $^ -L$(LIBFT_PATH) -lft -o $@

# $(NAME) : $(OBJS) $(LIBS)
# 	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(OBJS) : %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ && printf "Compiling: $(notdir $<)\n"

# $(OBJS) : %.o : %.c
# 	$(CC) -c $(CFLAGS) $(LIBFT) $< -o $@ && printf "Compiling: $(notdir $<\n)"

# $(OBJS) : %.o : %.c
# 	@$(CC) -c $(CFLAGS) -I$(LIBFT_PATH) -I include/ $(HEADERS) $< -o $@ && printf "Compiling: $(notdir $<\n)"

clean :
	@echo "Removing $(OBJS)"
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean : clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re : fclean all

################################################################################
#									LIBFT									   #
################################################################################

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_PATH)

.PHONY :
	all clean fclean re