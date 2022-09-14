##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME			=	my_rpg

TESTS			=	unit_test

CC				=	gcc

RM				=	rm -f

GCOVR			=	gcovr

LIB				=	-L./lib/my -lmy

INC				=	-I./include

CRIT			=	-lcriterion

COVER			=	--coverage

BRANCH			=	--branches

EXCLUD			=	--exclude

CSFML			=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS 			=	-Wall -Wextra

CPPFLAGS	    =	$(INC)

SRC_DIR			=	src/

PLAYER_DIR		=	src/player/

BUTTON_DIR		=	src/button/

INVENTORY_DIR	=	src/inventory/

RPG_DIR			=	src/rpg/

CAMERA_DIR		= 	src/camera/

SCENE_DIR		=	src/scene/

SCORE_DIR		=	src/score/

SOUND_DIR		=	src/sound/

TEXT_DIR		=	src/text/

TIME_DIR		=	src/time/

MAP_DIR			=	src/map/

WINDOW_DIR		=	src/window/

ENTITY_DIR		=	src/init_entity/

PNJ_DIR			=	src/pnj/

PARTICLE_DIR		=	src/particle/

LIB_DIR			=	lib/my/

TESTS_DIR		=	tests/

FIGHT_SYSTEM	=	src/ennemy/

SRC			=	$(RPG_DIR)handle_error.c				\
				$(RPG_DIR)main.c						\
				$(RPG_DIR)rpg.c							\
				$(ENTITY_DIR)init_object.c				\
				$(BUTTON_DIR)button.c					\
				$(BUTTON_DIR)init_button.c				\
				$(BUTTON_DIR)callback.c					\
				$(SCENE_DIR)init_scene.c				\
				$(SCENE_DIR)menu.c						\
				$(SCENE_DIR)game_scene.c				\
				$(TEXT_DIR)init_text.c					\
				$(MAP_DIR)load_file_in_mem.c			\
				$(MAP_DIR)map_callback.c				\
				$(MAP_DIR)init_map.c					\
				$(SOUND_DIR)sound.c						\
				$(TIME_DIR)init_time.c					\
				$(SCORE_DIR)init_score.c				\
				$(SCORE_DIR)init_score_2.c				\
				$(RPG_DIR)init_setting.c				\
				$(SCENE_DIR)end_game.c					\
				$(WINDOW_DIR)window.c					\
				$(WINDOW_DIR)event.c					\
				$(WINDOW_DIR)destroy.c					\
				$(WINDOW_DIR)destroy_bis.c				\
				$(SOUND_DIR)init_sound.c				\
				$(SOUND_DIR)init_music.c				\
				$(PLAYER_DIR)init_player.c				\
				$(PLAYER_DIR)player.c					\
				$(PLAYER_DIR)collision.c				\
				${PLAYER_DIR}display_player.c			\
				${PLAYER_DIR}player_event.c				\
				$(PLAYER_DIR)leveling.c					\
				$(PLAYER_DIR)view.c						\
				$(FIGHT_SYSTEM)attack.c					\
				$(FIGHT_SYSTEM)bouclier.c				\
				$(FIGHT_SYSTEM)damage.c					\
				$(FIGHT_SYSTEM)damage_bis.c				\
				$(FIGHT_SYSTEM)ennemy.c					\
				$(FIGHT_SYSTEM)init_ennemy.c			\
				$(FIGHT_SYSTEM)init_circle_ennemy.c		\
				$(FIGHT_SYSTEM)mouv_ennemy.c			\
				$(FIGHT_SYSTEM)boss.c					\
				$(PNJ_DIR)init_pnj.c					\
				$(PNJ_DIR)create_pnj.c					\
				$(PNJ_DIR)pnj.c							\
				$(PNJ_DIR)quests.c						\
				$(PNJ_DIR)text_quests.c					\
				$(PNJ_DIR)move_pnj.c					\
				$(MAP_DIR)map_boss.c					\
				$(INVENTORY_DIR)init_inventory.c		\
				$(INVENTORY_DIR)obj.c					\
				$(PARTICLE_DIR)particle_generator.c				\
				$(PARTICLE_DIR)particle.c			\

OBJ			=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CSFML) -lm

db:     CFLAGS += -g3
db:		$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CSFML) -lm

unit_tests:
	$(MAKE) -C lib/my
	$(CC) -o $(TESTS) $(UNIT_TEST) $(LIB) $(INC) $(COVER) $(CRIT)

run_tests: unit_tests
	./unit_test
	$(GCOVR) $(EXCLUD) $(TESTS_DIR)
	$(GCOVR) $(EXCLUD) $(TESTS_DIR) $(BRANCH)

clean:
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ) *gc*

fclean:	clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME) $(TESTS)

re:	fclean all

redb: fclean db

.PHONY: all tests fclean re db redb
