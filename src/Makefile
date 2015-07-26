main : AcademicBuilding.o Block.o Game.o Gym.o main.o MyInfoBoard.o NonProperty.o Player.o Property.o Residence.o
	g++ AcademicBuilding.o Block.o Game.o Gym.o main.o MyInfoBoard.o NonProperty.o Player.o Property.o Residence.o -o a.out
AcademicBuilding.o : AcademicBuilding.h AcademicBuilding.cpp Property.h
	g++ -c AcademicBuilding.cpp
Block.o : Block.h Block.cpp Player.h MyInfoBoard.h
	g++ -c Block.cpp
Game.o : Game.h Game.cpp Block.h Player.h NonProperty.h AcademicBuilding.h Residence.h Gym.h MyInfoBoard.h
	g++ -c Game.cpp
Gym.o : Gym.h Gym.cpp Property.h
	g++ -c Gym.cpp
main.o : main.cpp Game.h
	g++ -c main.cpp
MyInfoBoard.o : MyInfoBoard.h MyInfoBoard.cpp
	g++ -c MyInfoBoard.cpp
NonProperty.o : NonProperty.h NonProperty.cpp Block.h Player.h
	g++ -c NonProperty.cpp
Player.o : Player.h Player.cpp Property.h
	g++ -c Player.cpp
Property.o : Property.h Property.cpp Block.h Player.h
	g++ -c Property.cpp
Residence.o : Residence.h Residence.cpp Residence.h
	g++ -c Residence.cpp
