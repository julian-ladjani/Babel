##
## EPITECH PROJECT, 2018
## cpp_babel_2018
## File description:
## Makefile
##

NAME		=	babel

BUILD_DIR_DBG	=	cmake-build-debug
BUILD_DIR_REL	=	cmake-build-release

CMAKE		=	cmake
MKDIR		=	mkdir
RM		=	rm -rf

all: $(NAME)

cmake-gen:
	$(MKDIR) $(BUILD_DIR)
	cd $(BUILD_DIR) && \
	$(CMAKE) -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) $(SRC_DIR)

$(BUILD_DIR_DBG):
	$(MAKE) -C . SRC_DIR=$(abspath .) BUILD_DIR=$@ BUILD_TYPE=Debug cmake-gen

$(BUILD_DIR_REL):
	$(MAKE) -C . SRC_DIR=$(abspath .) BUILD_DIR=$@ BUILD_TYPE=Release cmake-gen

$(NAME): | $(BUILD_DIR_DBG)
	$(CMAKE) --build $(BUILD_DIR_DBG) --target babel

install: | $(BUILD_DIR_REL)
	$(CMAKE) --build $(BUILD_DIR_REL) --target install

clean: | $(BUILD_DIR_DBG)
	$(CMAKE) --build $(BUILD_DIR_DBG) --target clean

fclean:
	$(RM) $(BUILD_DIR_DBG) $(BUILD_DIR_REL) $(NAME)

re: fclean all

.PHONY:	all cmake-gen $(NAME) clean fclean re
