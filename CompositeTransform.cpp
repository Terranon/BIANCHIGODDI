///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"
#include "InvertTransform.h"
#include "RepeatTransform.h"

CompositeTransform::CompositeTransform(const CompositeTransform & mdd)
{
	// A Completer...
	auto it = mdd.begin();
	for (it; it != mdd.end(); it++) {
		addChild(*it);
	}

}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
	CompositeTransform *newObject = new CompositeTransform(*this);
	return newObject;
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{	
	auto it = begin();
	for (it; it != end(); it++) {
		it->transform(c, outFile);
	}
		
		/*if (dynamic_cast<CompositeTransform*>(it.operator*) != nullptr) {
			dynamic_cast<CompositeTransform*>(it.operator*)->transform(c, outFile);
		}
		if (dynamic_cast<InvertTransform*>(it.operator*) != nullptr) {
			dynamic_cast<InvertTransform*>(it.operator*)->transform(c, outFile);
		}
		if (dynamic_cast<RepeatTransform*>(it.operator*) != nullptr) {
			dynamic_cast<RepeatTransform*>(it.operator*)->transform(c, outFile);
		}
	}*/
}

void CompositeTransform::addChild(const AbsTransform& t)
{
	
	m_transforms.push_back(TransformPtr(t.clone()));
}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	m_transforms.erase(transfIt);
}
