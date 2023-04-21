NAME    = ../bomberman

CC    = g++

RM    = rm -f

SRCS    = ../main.cpp \
		  ../src/Character/Character.cpp \
		  ../src/GameCore/GameCore.cpp \
		  ../src/Items/Bomb.cpp \
		  ../src/Items/PowUps.cpp \
		  ../src/Items/Walls.cpp \
		  ../src/map/Map.cpp \
		  ../src/music/Music.cpp \
		  ../src/Screen/Screen.cpp \
		  ../src/Tools/Sleep.cpp \
		  ../src/map/MapCreator.cpp \
		  ../src/menu/EventMenu.cpp \
		  ../src/menu/Menu.cpp

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: clear $(NAME) 

$(NAME):
	$(CC) -g3 $(SRCS) -o $(NAME) $(CFLAGS) -L. -lIrrlicht -lXxf86vm -lGL -lX11 -lsfml-audio -pthread

clear:
	@ $(RM) $(NAME)

clean:
	@ $(RM) $(NAME)
	@echo "\033[0;31m Cleaning. \033[0m" "."".""."
	@sleep 1

fclean:
	@ $(RM) $(NAME)
	@echo "\033[0;31m Cleaning. \033[0m" "."".""."
	@sleep 1

re: fclean all

.PHONY: all clean fclean re