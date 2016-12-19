MKDIR = mkdir

text_stats: obj main.o optionControl.o readlines.o text_stats.o
	gcc -o text_stats obj/main.o obj/optionControl.o obj/readlines.o obj/text_stats.o -std=c99
obj:
	$(MKDIR) obj
main.o: main.c src/optionControl.c libs/optionControl.h src/readlines.c libs/readlines.h src/text_stats.c libs/text_stats.h
	gcc -c main.c -o obj/main.o -std=c99
optionControl.o: src/optionControl.c libs/optionControl.h
	gcc -c src/optionControl.c -o obj/optionControl.o -std=c99
readlines.o: src/readlines.c libs/readlines.h
	gcc -c src/readlines.c -o obj/readlines.o -std=c99
text_stats.o: src/text_stats.c libs/text_stats.h
	gcc -c src/text_stats.c -o obj/text_stats.o -std=c99
clean:
	rm -f obj/* text_stats
	rmdir obj
