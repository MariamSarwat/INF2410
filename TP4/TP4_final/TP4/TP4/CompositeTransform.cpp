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
CompositeTransform::CompositeTransform(const CompositeTransform & mdd): AbsTransform(mdd)
{}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const {
	CompositeTransform* composite = new CompositeTransform;
	for (int i = 0; i < m_transforms.size(); i++)
		//composite->addChild[m_transforms[i]->clone()];
	return composite;
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const {
	for (int i = 0; i < m_transforms.size(); i++)
		m_transforms[i]->transform(c, outFile);
}

void CompositeTransform::addChild(const AbsTransform& t) {
	m_transforms.push_back(unique_ptr<AbsTransform>(t.clone()));
}

void CompositeTransform::removeChild(TransformIterator_const transfIt) {
	removeChild(transfIt);
}
