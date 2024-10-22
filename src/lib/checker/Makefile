# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 20:27:13 by jonnavar          #+#    #+#              #
#    Updated: 2024/09/26 20:37:23 by jonnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## VARIABLE DECLARATIONS ##
###########################


INCLUDES_PATH	= ./include/
LIBFT_PATH		= ./src/lib/libft/
LIBFT_INC_PATH	= ${LIBFT_PATH}include/
PUSH_SWAP_PATH	= ../../../
OBJECTS_PATH	= ./object/
INST_OBJ_PATH	= ${OBJECTS_PATH}ps_instruction/
STACK_OBJ_PATH	= ${OBJECTS_PATH}ps_stack/
BONUS_OBJ_PATH	= ${OBJECTS_PATH}ps_bonus/
SOURCES_PATH    = ./src/


LIBFT_NAME		= ${LIBFT_PATH}libft.a
NAME			= checker
PUSH_SWAP		= push_swap
PUSH_SWAP_NAME	= ${PUSH_SWAP_PATH}${PUSH_SWAP}


CC				= cc
CFLAGS			= -Wall -Wextra -Werror
DEBUG_SYMBOLS	= -g3
SANITIZE_FLAGS	= -fsanitize=address ${DEBUG_SYMBOLS}
VALGRIND_FLAGS	= --track-origins=yes -s --leak-check=full
INCLUDE_LIBFT	= -I ${LIBFT_INC_PATH}
INCLUDE			= -I ${INCLUDES_PATH} ${INCLUDE_LIBFT}
MAKE_LIB		= make -sC
MOVE_PUSH_SWAP	= mv ${PUSH_SWAP_NAME} ./${PUSH_SWAP}


ALL				= all
DELETE			= delete_library
CLEAN			= clean
FCLEAN			= fclean
RE				= re
CC_SANITIZER	= sanitize
VALGRIND		= valgrind
MOCK_VALGRIND	= mock_valgrind
RUN_MOCK_VALUES	= mock_run
RUN_TEST_ERROR	= test_error
VALGRIND_ARGS	= 9 -4 2 7 -5 0
LIB_DELETE		= lib_${DELETE}
LIB_CLEAN		= lib_${CLEAN}
LIB_FCLEAN		= lib_${FCLEAN}
LIB_RE			= lib_${RE}


PHONY			= .PHONY
STD_PHONY		= ${ALL} ${CLEAN} ${FCLEAN} ${RE}
DEBUG_PHONY		= ${CC_SANITIZER} ${VALGRIND} ${MOCK_VALGRIND} ${RUN_MOCK_VALUES}
LIB_PHONY		= ${LIB_DELETE} ${LIB_CLEAN} ${LIB_FCLEAN} ${LIB_RE}


MAKE_LIBFT		= ${MAKE_LIB} ${LIBFT_PATH}
DELETE_LIBFT	= ${MAKE_LIBFT} ${DELETE}
CLEAN_LIBFT		= ${MAKE_LIBFT} ${CLEAN}
FCLEAN_LIBFT	= ${MAKE_LIBFT} ${FCLEAN}
RE_LIBFT		= ${MAKE_LIBFT} ${RE}


MAKE_PUSH_SWAP	= ${MAKE_LIB} ${PUSH_SWAP_PATH}


INST_SOURCES	= $(wildcard ${SOURCES_PATH}ps_instruction/*.c)
STACK_SOURCES	= $(wildcard ${SOURCES_PATH}ps_stack/*.c)
BONUS_SOURCES	= $(wildcard ${SOURCES_PATH}ps_bonus/*.c)
SOURCE_FILES	= $(wildcard ${SOURCES_PATH}*.c) ${INST_SOURCES} ${STACK_SOURCES} ${BONUS_SOURCES}
OBJECT_FILES	= ${patsubst ${SOURCES_PATH}%.c, ${OBJECTS_PATH}%.o, ${SOURCE_FILES}}


CREATE_PATH		= mkdir -p
DELETE_FILE		= rm -f
DELETE_PATH		= rm -fr


## RULES ##
###########


${ALL}: ${NAME}


${OBJECTS_PATH}:
	@${CREATE_PATH} ${OBJECTS_PATH}
	@${CREATE_PATH} ${INST_OBJ_PATH}
	@${CREATE_PATH} ${STACK_OBJ_PATH}
	@${CREATE_PATH} ${BONUS_OBJ_PATH}


${OBJECTS_PATH}%.o: ${SOURCES_PATH}%.c | ${OBJECTS_PATH}
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@


${NAME}: ${LIBFT_NAME} ${OBJECT_FILES}
	@${CC} ${CFLAGS} ${OBJECT_FILES} ${LIBFT_NAME} -o ${NAME}
	@echo "The program \"${NAME}\" has been compiled."


${CLEAN}: ${LIB_CLEAN}
	@${DELETE_FILE} ${OBJECT_FILES}
	@${DELETE_PATH} ${OBJECTS_PATH}
	@echo "The objects of program \"${NAME}\" have been deleted."


${FCLEAN}: ${LIB_CLEAN} ${LIB_DELETE} ${CLEAN}
	@${DELETE_FILE} ${LIBFT_NAME}
	@${DELETE_FILE} ${PUSH_SWAP}
	@${DELETE_FILE} ${NAME}
	@echo "The program \"${NAME}\" has been deleted."


${RE}: ${FCLEAN} ${ALL}


${PUSH_SWAP}:
	@${MAKE_PUSH_SWAP}
	@${MOVE_PUSH_SWAP}
	@echo "The program \"push_swap\" has been moved to the working directory."


${CC_SANITIZER}: ${LIBFT_NAME} ${OBJECT_FILES}
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} ${OBJECT_FILES} ${LIBFT_NAME} -o ${NAME}
	@echo "C compiler's sanitizer has been added to debug memory issues."


${VALGRIND}: ${NAME} ${PUSH_SWAP}
	@./${PUSH_SWAP} ${VALGRIND_ARGS} | ${VALGRIND} ${VALGRIND_FLAGS} ./${NAME} ${VALGRIND_ARGS}


${MOCK_VALGRIND}: ${NAME} ${PUSH_SWAP}
	@$(eval MOCK_VALUES=$(shell seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '))
	@./${PUSH_SWAP} ${MOCK_VALUES} | ${VALGRIND} ${VALGRIND_FLAGS} ./${NAME} ${MOCK_VALUES}


${RUN_MOCK_VALUES}: ${NAME} ${PUSH_SWAP}
	@$(eval MOCK_VALUES=$(shell seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '))
	@echo "Running checker with a list of mock values..."
	@./${PUSH_SWAP} ${MOCK_VALUES} | ./${NAME} ${MOCK_VALUES}


${RUN_TEST_ERROR}: ${NAME} ${PUSH_SWAP}
	@echo "Running checker in a case where the list is not sorted..."
	@./${PUSH_SWAP} 5 9 0 2 -3 22 | ./${NAME} 1 0 4 2


# library rules
# #############


${LIBFT_NAME}:
	@${MAKE_LIBFT}


${LIB_DELETE}:
	@${DELETE_LIBFT}


${LIB_CLEAN}:
	@${CLEAN_LIBFT}


${LIB_FCLEAN}:
	@${FCLEAN_LIBFT}


${LIB_RE}:
	@${RE_LIBFT}


${PHONY}: ${STD_PHONY} ${DEBUG_PHONY} ${LIB_PHONY}
