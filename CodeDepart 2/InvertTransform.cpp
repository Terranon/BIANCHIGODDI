///////////////////////////////////////////////////////////
//  InvertTransform.cpp
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

// Methode pour appliquer une transformation d'inversion � un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{ 
   // A Completer...
  
   Chunk_iterator newChunkIt = Chunk_iterator(c);
   for (size_t i = c->size(); i >= 0; i--) {
      newChunkIt->get()[i] = c-> get()[c->size()-1-i];
   }
   outFile.addChunk(newChunkIt);
}

