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
	Chunk_iterator temp(c);
	for (int i = 0, j = c->size() - 1; i < c->size(); i++, j--)
		temp->get()[i] = c->get()[j];

	outFile.addChunk(temp);
}
