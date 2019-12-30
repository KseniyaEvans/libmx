NAME	=	libmx.a

CMPL	=	clang -std=c11 $(addprefix -W, all extra error pedantic)

SRCD	=	src/
INCD	=	inc/
OBJD	=	obj/

SRCS	=	$(addprefix $(SRCD), \
		mx_foreach.c\
		mx_hex_to_nbr.c\
		mx_itoa.c\
		mx_nbr_to_hex.c\
		mx_pow.c\
		mx_print_strarr.c\
		mx_print_unicode.c\
		mx_printchar.c\
		mx_printint.c\
		mx_printstr.c\
		mx_sqrt.c\
		mx_strcmp.c\
		mx_strcpy.c\
		mx_strdup.c\
		mx_strlen.c\
		mx_strnew.c\
		mx_binary_search.c\
		mx_bubble_sort.c\
		mx_quicksort.c\
		mx_swap_char.c\
		mx_str_reverse.c\
		mx_strdel.c\
		mx_del_strarr.c\
		mx_get_char_index.c\
		mx_strndup.c\
		mx_strncpy.c\
		mx_strcat.c\
		mx_strstr.c\
		mx_get_substr_index.c\
		mx_count_substr.c\
		mx_count_words.c\
		mx_strtrim.c\
		mx_isspace.c\
		mx_memset.c\
		mx_memcpy.c\
		mx_memccpy.c\
		mx_memchr.c\
		mx_memrchr.c\
		mx_memmem.c\
		mx_memmove.c\
		mx_realloc.c\
		mx_memcmp.c\
		mx_del_extra_spaces.c\
		mx_strjoin.c\
		mx_file_to_str.c\
		mx_replace_substr.c\
		mx_strsplit.c\
		mx_create_node.c\
		mx_push_front.c\
		mx_push_back.c\
		mx_list_size.c\
		mx_pop_front.c\
		mx_pop_back.c\
		mx_sort_list.c\
		mx_read_line.c)
	

OBJS	=	$(patsubst $(SRCD)%.c, $(OBJD)%.o, $(SRCS))
INCS	=	$(addprefix $(INCD), \
		libmx.h)

all: install

install: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJD)%.o: $(SRCD)%.c $(INCS)
	$(CMPL) -o $@ -c $< -I$(INCD)

$(OBJS): | $(OBJD)

$(OBJD):
	mkdir -p $@

clean:
	rm -rf $(OBJD)

uninstall: clean
	rm -rf $(NAME)

reinstall: uninstall install
