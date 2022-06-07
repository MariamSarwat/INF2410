///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

using namespace std;
CompositeTransform::CompositeTransform(const CompositeTransform & mdd) {
	for (auto it = mdd.begin(); it != mdd.end(); it++)
		addChild(*it);
}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const {
	return new CompositeTransform(*this);
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const {
	for (int i = 0; i < m_transforms.size(); i++)
		m_transforms[i].get()->transform(c, outFile);
}

void CompositeTransform::addChild(const AbsTransform& t) {
	m_transforms.push_back(TransformPtr(t.clone()));
}

void CompositeTransform::removeChild(TransformIterator_const transfIt) {
	m_transforms.erase(transfIt);
}
