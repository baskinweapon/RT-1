# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 14:33:34 by dmelessa          #+#    #+#              #
#    Updated: 2020/12/06 20:23:23 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./RT
CC = gcc
RM = rm -f
CURRENTDIR = .

#UNAME_S = $(shell uname -s)

#SYSTEM:
SYSTEM = $(shell uname)
MACOS = Darwin
LINUX = Linux

CFLAGS = -I$(INCDIR)\
		 -I$(LIBFTINC)\
		 -I$(SDL2INC)\
		 -I/Users/dmelessa/rt2/Libs/SDL2_image.framework/Headers\
		 -I./Libs/SDL2\
		 -I./Libs/SDL2_ttf/include\
		 -g
		#  --analyze\
		#  --analyzer-output html\
#		 -Wall\
		 -Werror\
		 -Wextra
ifeq ($(SYSTEM), $(MACOS))

	LDLIBS = -lm\
			 -lft\
			 -framework SDL2\
			 -framework OpenCL\
			 -framework SDL2_image\
			 -framework SDL2_ttf


	# SDL		= -framework SDL2_image\
	# 		 -framework SDL2_ttf\


	# SDL		= -lSDL2_image\
	# 		 -lSDL2_ttf\
	# 		 -lSDL2_gfx

	LDFLAGS = -L$(LIBFTDIR)\
			  -F $(LIBSDIR)\
			  -rpath $(LIBSDIR)

else ifeq ($(SYSTEM), $(LINUX))

	LDLIBS = -lm\
			 -l SDL2\
			 -l OpenCL
			 -lSDL2_image -lSDL2_ttf -lSDL2_gfx

	LDFLAGS	= $(LIBFT)

endif


LIBSDIR = $(CURRENTDIR)/Libs

LIBFT = $(LIBFTDIR)/libft.a
LIBFTDIR = $(LIBSDIR)/libft
LIBFTINC = $(LIBFTDIR)
LIBFTHEAD = $(LIBFTINC)/libft.h $(LIBFTINC)/get_next_line.h

#MACOS
SDL2DIR = $(LIBSDIR)/SDL2.framework
SDL2INC = ./Libs

INCDIR = $(CURRENTDIR)/include
INCS = *.h
INCS := $(addprefix $(INCDIR)/, $(INCS))

SRCSDIR	= ./srcs/
SRCS =aabb.c                  get_light_type.c        gui_object_vision.c     light_manager.c         pars_texture.c          scene.c\
bvh.c                   get_obj_mat_types.c     gui_render_text.c       logs.c                  parser.c                swap.c\
camera.c                get_second_values.c     gui_tab_bar.c           main.c                  parser_functions.c      texture.c\
catch_event.c           get_tex_cam_types.c     gui_tab_bar_2.c         matrix.c                perlin.c                texture_manager.c\
                     get_tracer_type.c       gui_tab_utils.c         matrix_manager.c        random.c                utils.c\
color.c                 gui.c                   gui_utils.c             object_manager.c        resource_manager.c      vector.c\
create_program.c        gui_button.c            gui_utils_2.c           pars_camera.c           rt.c                    window.c\
error_handling.c        gui_get_data.c          gui_utils_3.c           pars_light.c            rt_ocl.c\
get_default.c           gui_get_data_2.c        init.c                  pars_material.c         rt_options.c\
get_first_values.c      gui_get_data_3.c        init_parsed_scene.c     pars_obj.c              sampler.c\
get_key_value.c         gui_init.c              instance_manager.c      pars_option.c           sampler_manager.c\





OBJSDIR = ./obj/
OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(INCS) $(LIBFTHEAD)
	@echo 'making executable'
	$(CC) -o $@ $(OBJS) $(LDLIBS) $(SDL) $(LDFLAGS)
	@echo DONE!


$(LIBFT):
	@make -C $(LIBFTDIR)

$(OBJS): $(OBJSDIR)%.o: $(SRCSDIR)%.c | $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(INCS)

$(OBJSDIR):
	mkdir $@

clean:
	@echo deliting object files
	@$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@echo deliting executable file
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean

.PHONY: all clean fclean re
re:	fclean all
