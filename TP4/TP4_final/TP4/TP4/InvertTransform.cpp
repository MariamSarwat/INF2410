///////////////////////////////////////////////////////////
//  InvertTransform.cpp
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"
using namespace std;

// Methode pour appliquer une transformation d'inversion � un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const {
	vector<char> temp;
	temp.resize(c->size()); // Vecteur temporaire de taille �gale au Chunk.

	for (int i = 0; i < c->size(); i++)
		temp[i] = c->get()[c->size() - i - 1]; // Remplissage du vecteur temporaire avec les donn�es en ordre inverse du Chunk.

	Chunk_iterator iterateur(outFile, outFile.getNumberChunks());
	*iterateur = Chunk(temp.size(), temp.data()); // On cr�e un Chunk avec le vecteur contenant les donn�es en ordre inverse.

	outFile.addChunk(iterateur);
}
