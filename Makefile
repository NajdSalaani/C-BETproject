CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Liste des fichiers source
SRCS = Evenement.cpp Utilisateur.cpp Pari.cpp Participant.cpp main.cpp

# Liste des fichiers objets générés à partir des fichiers source
OBJS = $(SRCS:.cpp=.o)

# Nom de l'exécutable
EXEC = paris_sportifs

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Règle générique pour la compilation des fichiers source en fichiers objets
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(EXEC)
