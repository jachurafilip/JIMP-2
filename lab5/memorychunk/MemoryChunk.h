//
// Created by jachfili on 28.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdlib>
#include <algorithm>
using std::swap;
namespace memorychunk {
    class MemoryChunk {
    public:
        MemoryChunk();

        MemoryChunk(size_t size);


        MemoryChunk(const MemoryChunk &mem);

        MemoryChunk(MemoryChunk &&mem);

        MemoryChunk &operator=(const MemoryChunk &mem);

        MemoryChunk &operator=(MemoryChunk &&mem);

        ~MemoryChunk();

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;

    private:
        int8_t *memory_;
        size_t size_;
    };

}
#endif //JIMP_EXERCISES_MEMORYCHUNK_H
