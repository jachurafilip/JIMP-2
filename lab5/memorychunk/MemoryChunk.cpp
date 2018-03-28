//
// Created by jachfili on 28.03.18.
//

#include "MemoryChunk.h"
using std::copy;
namespace memorychunk {
    MemoryChunk::MemoryChunk() {
        memory_ = new int8_t;
        size_ = 1;
    }

    MemoryChunk::MemoryChunk(int size) {
        memory_ = new int8_t[size];
        size_ = size;

    }

    MemoryChunk::MemoryChunk(const MemoryChunk &mem) {
        memory_ = new int8_t[size_];
        copy(mem.memory_, mem.memory_ + mem.size_, memory_);
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&mem) : memory_{nullptr} {
        swap(memory_, mem.memory_);
    }

    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &mem) {
        if (this == &mem) {
            return *this;
        }
        delete[] memory_;
        memory_ = new int8_t[mem.size_];
        copy(mem.memory_, mem.memory_ + mem.size_, memory_);
    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&mem) {
        if (this == &mem) {
            return mem;
        }
        delete[] memory_;
        memory_ = nullptr;
        swap(memory_, mem.memory_);
    }

    MemoryChunk::~MemoryChunk() {
        delete[] memory_;
    }


    int8_t *MemoryChunk::MemoryAt(size_t offset) const {
        return memory_+offset;
    }

    size_t MemoryChunk::ChunkSize() const {
        return size_;
    }
}
