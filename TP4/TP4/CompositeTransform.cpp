///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

CompositeTransform::CompositeTransform(const CompositeTransform & mdd)
{
	auto it = mdd.begin();
	for (it; it != mdd.end(); it++) {
		addChild(*it);
	}
}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform* CompositeTransform::clone(void) const
{
	CompositeTransform* tmp = new CompositeTransform(*this);
	return tmp;
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	auto it = begin();
	for (it; it != end(); it++) {
		it->transform(c, outFile);
	}
}

void CompositeTransform::addChild(const AbsTransform& t)
{
	m_transforms.push_back(TransformPtr(t.clone()));
}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	m_transforms.erase(transfIt);
}
