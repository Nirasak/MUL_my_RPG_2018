##
## EPITECH PROJECT, 2018
## my_runner
## File description:
## Makefile
##

INIT	=	init/

LOOP	=	loop/

DEST	=	destroy/

QUEST	=	loop/quests/

MENU	=	menu/

SHOP	=	loop/shop/

FIGHT	=	loop/fight/

ABI	=	loop/abilities/

MOUSE	=	mouse/

GENE	=	generic_function/

BUTT	=	button/

SRC	=	main.c						\
		rpg.c						\
		update_saves.c					\
		$(INIT)createsprites.c				\
		$(INIT)background_fights.c			\
		$(INIT)init_all.c				\
		$(INIT)init_cara.c				\
		$(INIT)init_menu.c				\
		$(INIT)init_window.c				\
		$(INIT)init_enemy.c				\
		$(INIT)init_sound.c				\
		$(INIT)init_spawn.c				\
		$(INIT)init_stat.c				\
		$(INIT)init_mouse.c				\
		$(INIT)init_cooldown.c				\
		$(INIT)init_button.c				\
		$(INIT)init_shop.c				\
		$(INIT)init_shop_item.c				\
		$(INIT)init_button_annex.c			\
		$(INIT)init_option.c				\
		$(INIT)init_option_annex.c			\
		$(INIT)init_choose_diff.c			\
		$(INIT)init_lore.c				\
		$(INIT)init_profiles.c				\
		$(INIT)init_map.c				\
		$(INIT)init_cara_annex.c			\
		$(INIT)init_pause.c				\
		$(INIT)init_keybinding.c			\
		$(INIT)init_keybinding_annex.c			\
		$(INIT)init_keybinding_second_annex.c		\
		$(INIT)init_particules.c			\
		$(INIT)init_rdm_particules.c			\
		$(INIT)init_report.c				\
		$(INIT)init_htp.c				\
		$(INIT)init_quest.c				\
		$(INIT)animation.c				\
		$(INIT)reinit_instance.c			\
		$(INIT)window.c					\
		$(LOOP)anime_menu.c				\
		$(LOOP)adapt_to_dificulty.c			\
		$(LOOP)move_cara_spawn.c			\
		$(LOOP)draw.c					\
		$(LOOP)rdm_particules.c				\
		$(LOOP)victory.c				\
		$(LOOP)win_or_lose_fight.c			\
		$(LOOP)xp.c					\
		$(LOOP)anime_fighters.c				\
		$(LOOP)anime_mob_spawn.c			\
		$(LOOP)impact_effect.c				\
		$(LOOP)handle_shoot.c				\
		$(LOOP)life.c					\
		$(LOOP)text_hit.c				\
		$(LOOP)loop.c					\
		$(LOOP)loop_map.c				\
		$(LOOP)instance.c				\
		$(LOOP)instance2.c				\
		$(LOOP)display_map.c				\
		$(LOOP)fight_report.c				\
		$(LOOP)check_enemy.c				\
		$(LOOP)anim_perso.c				\
		$(LOOP)move_on_map.c				\
		$(LOOP)particules.c				\
		$(LOOP)markquest_set_place.c			\
		$(LOOP)check_rect_quest.c			\
		$(QUEST)quest1.c				\
		$(QUEST)draw_cara_quest.c			\
		$(FIGHT)jungle_fight.c				\
		$(FIGHT)enemy_attack.c				\
		$(FIGHT)check_mouse_in_rect.c			\
		$(FIGHT)reset_cooldown.c			\
		$(FIGHT)enemy_attack_two.c			\
		$(FIGHT)select_attack_enemy.c			\
		$(FIGHT)change_enemy.c				\
		$(FIGHT)caitlyn_fight.c				\
		$(FIGHT)fight_on_loop.c				\
		$(FIGHT)enemy_turn.c				\
		$(FIGHT)decrease_cooldown.c			\
		$(FIGHT)change_attack_enemy.c			\
		$(FIGHT)fight_loop.c				\
		$(SHOP)buff.c					\
		$(SHOP)secondbuff.c				\
		$(SHOP)hitbox_shop.c				\
		$(SHOP)check_price.c				\
		$(SHOP)item.c					\
		$(SHOP)karma.c					\
		$(SHOP)shop.c					\
		$(ABI)unlock_abilities.c			\
		$(ABI)handle_abi.c				\
		$(ABI)qspell.c					\
		$(ABI)rspell.c					\
		$(ABI)shield.c					\
		$(ABI)handle_stun.c				\
		$(DEST)destroy_all.c				\
		$(MOUSE)mouse.c					\
		$(GENE)generic_function.c			\
		$(GENE)extract_data_file.c			\
		$(GENE)create_stat_enemy_from_file.c		\
		$(GENE)create_sprite_from_file.c		\
		$(GENE)create_text.c				\
		$(GENE)modify_file.c				\
		$(GENE)create_stat_enemy_from_file_annex.c	\
		$(BUTT)active_button.c				\
		$(BUTT)music_bar.c				\
		$(BUTT)cursor.c					\
		$(MENU)menu.c					\
		$(MENU)pseudo.c					\
		$(MENU)annex_pseudo.c				\
		$(MENU)option.c					\
		$(MENU)annex_option.c				\
		$(MENU)display_option.c				\
		$(MENU)icon_menu.c				\
		$(MENU)lore.c					\
		$(MENU)saved.c					\
		$(MENU)choose_diff.c				\
		$(MENU)keybinding.c				\
		$(MENU)pause.c					\
		$(MENU)display_keybinding.c			\
		$(MENU)how_to_play.c				\
		$(MENU)discution.c				\

SRCDIR	=	src/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

CSFML	=	-lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-graphics

CPPFLAGS	=	-I./include/ -Wall -Wextra -g3

LIB	=	-L./lib/my -lmy

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(OBJ) $(CSFML) $(CPPFLAGS) $(LIB)

clean:
	rm -f $(OBJ)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make clean
	rm -f $(shell find $(SOURCEDIR) -name '*.o')
	rm -f $(shell find $(SOURCEDIR) -name '*~')
	rm -f $(shell find $(SOURCEDIR) -name '*#')
	rm -f $(shell find $(SOURCEDIR) -name 'vgcore.*')

fclean: clean
	rm -f $(NAME)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make fclean

re:	fclean all

.PHONY: all clean fclean re
