SRC_CXX=Piece.cxx Joueur.cxx Echiquier.cxx testPiece.cxx Tour.cxx Fou.cxx Cavalier.cxx Roi.cxx Reine.cxx
EXE=jeuEchec

OBJ=${SRC_CXX:.cxx=.o}

all: $(EXE)

$(EXE): $(OBJ)
	g++ $(OBJ) -o $(EXE)

%.o: %.cxx
	g++ -g -c $< 

clean:
	@rm -f $(OBJ) $(EXE) *~

