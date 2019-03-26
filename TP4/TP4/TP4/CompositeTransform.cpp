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
	new CompositeTransform(mdd);
}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const {
	/*CompositeTransform* clone = new CompositeTransform;
	clone->m_transforms = this->m_transforms;
	return clone;*/
	return nullptr;
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const {
	//A Completer...
	/*for (auto child : m_transforms)
		child->transform(c, outFile);*/
}

void CompositeTransform::addChild(const AbsTransform& t) {
	//A Completer...
	//m_transforms.push_back(shared_ptr<AbsTransform>(t.clone()));
	addChild(t);
}

void CompositeTransform::removeChild(TransformIterator_const transfIt) {
	//A Completer...
	removeChild(transfIt);
}
