##
## EPITECH PROJECT, 2023
## dante
## File description:
## global makefile
##

all:
	cd solver && make && cd ../
	cd generator && make && cd ../

clean:
	cd solver && make clean && cd ../
	cd generator && make clean && cd ../

re:
	cd solver && make re && cd ../
	cd generator && make re && cd ../

fclean:
	cd solver && make fclean && cd ../
	cd generator && make fclean && cd ../
