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
OBJECTS_PATH	= ./object/
INST_OBJ_PATH	= ${OBJECTS_PATH}ps_instruction/
SORT_OBJ_PATH	= ${OBJECTS_PATH}ps_sort/
STACK_OBJ_PATH	= ${OBJECTS_PATH}ps_stack/
SOURCES_PATH    = ./src/


LIBFT_NAME		= ${LIBFT_PATH}libft.a
NAME			= push_swap


CC				= cc
CFLAGS			= -Wall -Wextra -Werror
# both "-g" or "-g3" flags can be used.
# "-g3" includes everything included with "-g", but with 
# additional information to debug preprocessor directives
DEBUG_SYMBOLS	= -g3
SANITIZE_FLAGS	= -fsanitize=address ${DEBUG_SYMBOLS}
VALGRIND_FLAGS	= --track-origins=yes -s --leak-check=full
COUNT_LINES		= | wc -l
INCLUDE_LIBFT	= -I ${LIBFT_INC_PATH}
INCLUDE			= -I ${INCLUDES_PATH} ${INCLUDE_LIBFT}
MAKE_LIB		= make -sC


ALL				= all
DELETE			= delete_library
CLEAN			= clean
FCLEAN			= fclean
RE				= re
CC_SANITIZER	= sanitize
VALGRIND		= valgrind
MOCK_VALGRIND	= mock_valgrind
RUN_MOCK_VALUES	= mock_run
RUN_COUNT_LINES = count_run
VALGRIND_ARGS	= 9 -4 2 7 -5 0
LIB_DELETE		= lib_${DELETE}
LIB_CLEAN		= lib_${CLEAN}
LIB_FCLEAN		= lib_${FCLEAN}
LIB_RE			= lib_${RE}


MAKE_LIBFT		= ${MAKE_LIB} ${LIBFT_PATH}
DELETE_LIBFT	= ${MAKE_LIBFT} ${DELETE}
CLEAN_LIBFT		= ${MAKE_LIBFT} ${CLEAN}
FCLEAN_LIBFT	= ${MAKE_LIBFT} ${FCLEAN}
RE_LIBFT		= ${MAKE_LIBFT} ${RE}


INST_SOURCES	= $(wildcard ${SOURCES_PATH}ps_instruction/*.c)
SORT_SOURCES	= $(wildcard ${SOURCES_PATH}ps_sort/*.c)
STACK_SOURCES	= $(wildcard ${SOURCES_PATH}ps_stack/*.c)
SOURCE_FILES	= $(wildcard ${SOURCES_PATH}*.c) ${INST_SOURCES} ${SORT_SOURCES} ${STACK_SOURCES}
# "patsubst": pattern substitution
# parameters: pattern, replacement, text
#
# pattern: the pattern to match. Supports wildcards
# replacement: the string to replace the pattern with. By using wildcards, 
#              Make keeps the original text matched by the same 
#              wildcard in the pattern
# text: the list of strings on which the substitution will be performed
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
	@${CREATE_PATH} ${SORT_OBJ_PATH}
	@${CREATE_PATH} ${STACK_OBJ_PATH}


# "$@" refers to the target (%.o)
# "$<" refers to the dependency (%.c)
#
# "|" the pipe syntax indicates that the ${OBJECTS_PATH} is 
#     an Order-Only Prerequisite of the "${OBJECTS_PATH}%.o" target.
#     Order-Only Prerequisites are required, but don't trigger a rebuild.
#     This means that if an Order-Only Prerequisite changes, its target 
#     is not built again
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
	@${DELETE_FILE} ${NAME}
	@echo "The program \"${NAME}\" has been deleted."


${RE}: ${FCLEAN} ${ALL}


${CC_SANITIZER}: ${LIBFT_NAME} ${OBJECT_FILES}
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} ${OBJECT_FILES} ${LIBFT_NAME} -o ${NAME}
	@echo "C compiler's sanitizer has been added to debug memory issues."


${VALGRIND}: ${NAME}
	@${VALGRIND} ${VALGRIND_FLAGS} ./${NAME} ${VALGRIND_ARGS}


${MOCK_VALGRIND}: ${NAME}
	@$(eval MOCK_VALUES=$(shell seq -49 50 | sort -R | tail -n 500 | tr '\n' ' '))
	@${VALGRIND} ${VALGRIND_FLAGS} ./${NAME} ${MOCK_VALUES}


${RUN_MOCK_VALUES}: ${NAME}
	@$(eval MOCK_VALUES=$(shell seq -1 5 | sort -R | tail -n 500 | tr '\n' ' '))
	@echo "Running push_swap with a list of mock values..."
	@./${NAME} ${MOCK_VALUES}


${RUN_COUNT_LINES}: ${NAME}
	@$(eval MOCK_VALUES=$(shell seq 1 500 | sort -R | tail -n 500 | tr '\n' ' '))
	@./${NAME} ${MOCK_VALUES} ${COUNT_LINES}


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


.PHONY: ${ALL} ${CLEAN} ${FCLEAN} ${RE} ${LIB_DELETE} ${LIB_CLEAN} ${LIB_FCLEAN} ${LIB_RE}
