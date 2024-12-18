# Nom de l'exécutable
TARGET = simulation

# Compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Options pour SFML (adapter si nécessaire)
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Fichiers sources et objets
SRC = main.cpp Grille.cpp Cellule.cpp Simulation.cpp Vue.cpp
OBJ = $(SRC:.cpp=.o)

# Règle principale (par défaut)
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# Compilation des fichiers .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers temporaires
clean:
	rm -f $(OBJ) $(TARGET)

# Recompiler tout proprement
rebuild: clean all
