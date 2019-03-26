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

// Methode pour appliquer une transformation d'inversion à un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const {
	vector<char> temp;
	temp.resize(c->size()); // Vecteur temporaire de taille égale au Chunk.

	for (int i = 0; i < c->size(); i++)
		temp[i] = c->get()[c->size() - i - 1]; // Remplissage du vecteur temporaire avec les données en ordre inverse du Chunk.

	Chunk_iterator iterateur(outFile, outFile.getNumberChunks());
	*iterateur = Chunk(temp.size(), temp.data()); // On crée un Chunk avec le vecteur contenant les données en ordre inverse.

	outFile.addChunk(iterateur);
}
