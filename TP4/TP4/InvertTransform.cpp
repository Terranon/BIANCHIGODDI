///////////////////////////////////////////////////////////
//  InvertTransform.cpp
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

// Methode pour appliquer une transformation d'inversion à un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	Chunk_iterator tmp = c;
	size_t j = 0;
	for (size_t i = (c->size() - 1); i >= 0; i--) {
		tmp.operator[](j) = (c.operator[](i));
		j++;
	}
	outFile.addChunk(tmp);
}
