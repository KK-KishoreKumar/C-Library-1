#include "cstring.h"
#include <stdio.h>

cstring* CString(unsigned size){
    cstring* str = malloc(sizeof(cstring));
    str->_str = CVector(sizeof(char), size);
    return str;
}

void CS_append(cstring* str, const char* chars, unsigned size){
    unsigned sz = (size != -1? size : strlen(chars));
    
    if(str->_str->_size){
        CV_erase(str->_str, str->_str->_size-1);
    }
    for(unsigned i=0; i<sz; ++i){
        CV_push_back(str->_str, chars+i);
    }   CV_push_back(str->_str, "\0");
}

char CS_compare(const cstring* str1, const cstring* str2, unsigned size){
    unsigned sz = size<=str1->_str->_size? size : str1->_str->_size;

    if(!size){
        sz = str1->_str->_size;
        if(str1->_str->_size > str2->_str->_size) return 1;
        else if(str1->_str->_size < str2->_str->_size) return -1;
    } else if(size > str1->_str->_size || size > str2->_str->_size){
        if(str1->_str->_size > str2->_str->_size) return 1;
        else if(str1->_str->_size < str2->_str->_size) return -1;
    }

    for(unsigned i=0; i<sz; ++i){
        if(*MCV_at(str1->_str, i, char) > *MCV_at(str2->_str, i, char)){
            return 1;
        }
        if(*MCV_at(str1->_str, i, char) < *MCV_at(str2->_str, i, char)){
            return -1;
        }
    }
    return 0;
}

void CS_copy(cstring* dest, const cstring* src){
    CV_copy(dest->_str, src->_str);
}

// void convert_to(const string* str, __Type type);

cstring* CS_substr(const cstring* str, unsigned beg, unsigned end){
    return 0;
}

cstring* CS_find(const cstring* str, const cstring* token, unsigned offset){
    return 0;
}

char CS_get_char(const cstring* str, unsigned index){
    return *MCV_at(str->_str, index, char);
}

const char* CS_get_strptr(const cstring* str){
    return (const char*)str->_str->_data;
}

unsigned CS_size_of(const cstring* str){
    return str->_str->_size;
}

unsigned CS_capacity(const cstring* str){
    return str->_str->_capacity;
}

void CS_delete(void* str){
    cstring* str_ = (cstring*)str;
    CV_delete(str_->_str);
    free(str_->_str);
    // free((void*)str);
    // str = NULL;
}