#include "TextStash.hpp"

std::unique_ptr<TextStash> TextStash::m_instance;
std::once_flag TextStash::m_once_flag;

TextStash& TextStash::Instance() {
    std::call_once(m_once_flag, [] {
        m_instance.reset(new TextStash);
    });
    return *m_instance.get();
}

TextStash::TextStash(void) {
    std::cout << "TextStash singelton instantiated." << std::endl;
    if(TTF_Init() == -1) {
        std::cout << TTF_GetError() << std::endl;
    } else {
        std::cout << "TTF inited." << std::endl;
    }
}

TextStash::~TextStash(void) {
    std::cout << "TextStash singleton destroyed." << std::endl;
    TTF_Quit();
}