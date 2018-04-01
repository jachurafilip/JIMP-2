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

    MemoryChunk::MemoryChunk(size_t sz) {
        this->size_ = sz;
        if (sz > 0) {
            this->memory_ = new(int8_t[sz / sizeof(int8_t)]);
        }
        else {
            this->memory_ = nullptr;
        }
    }

    MemoryChunk::MemoryChunk(const MemoryChunk &mem) {
        size_ = mem.size_;
        memory_ = new int8_t[size_];
        copy(mem.memory_, mem.memory_ + mem.size_, memory_);
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&mem) : memory_(mem.memory_), size_(mem.size_) {
        mem.memory_ = nullptr;
        mem.size_ = 0;
    }

    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &mem) {
        if (this == &mem) {
            return *this;
        }
        delete[] memory_;
        memory_ = new int8_t[mem.size_];
        size_ = mem.size_;
        copy(mem.memory_, mem.memory_ + mem.size_, memory_);
    }

    MemoryChunk &MemoryChunk::operator=(MemoryChunk &&mem) {
        if(this != &mem)
        {
            delete[](this->memory_);
            //this->ptr = new ithnt8_t [other.size];
            //std::copy(other.ptr,other.ptr+other.size,this->ptr);
            this->memory_ = mem.memory_;
            this->size_ = mem.size_;
            //delete[](other.ptr);
            mem.memory_ = nullptr;
            mem.size_ = 0;
        }
        return *this;
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
