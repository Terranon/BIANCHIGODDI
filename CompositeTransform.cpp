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
   // A Completer...
	for (auto it = mdd.begin;it != mdd.end; it++) {
		addChild(*it);
	}
   
}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
    // A Completer...
	CompositeTransform *newObject = new CompositeTransform (*this);
	return (newObject);
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	for (auto it= m_transforms.begin; it != m_transforms.end; it++)
	it->transform(c,outFile);
}

void CompositeTransform::addChild(const AbsTransform& t)
{ 
	// A Completer...
	m_transforms.push_back(t.clone);
	
}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	// A Completer...
	m_transforms.erase(transfIt);
}
